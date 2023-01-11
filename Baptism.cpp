#include "stdafx.h"
#include "Baptism.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "BossObject.h"

void Baptism::Init()
{
	_imgPhase1BossBaptismProjectile = IMAGEMANAGER->FindImageVector("Boss_Baptism_Projectile");
	_imgPhase1BossBaptismProjectile->Setting(0.1, true);

	//_imgPhase1BossBaptismProjectileDespawn = IMAGEMANAGER->FindImageVector("Boss_Baptism_Projectile_Despawn");
	//_imgPhase1BossBaptismProjectileDespawn->Setting(0.1, false);

	_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision);
	_collision->SetIsActive(false);

	_randX = MY_UTILITY::getFromIntTo(-50, 50);
	_deltaMove = 5;
}

void Baptism::Update()
{
	if (OBJECTMANAGER->m_boss->_patternCheck == 1)
	{
		_collision->SetIsActive(true);
		if (_randX < 25)
		{
			m_obj->x -= cosf((_randX - 90) * PI / 180.0f) * 2;
		}
		else if (_randX >= 25)
		{
			m_obj->x += cosf((_randX - 90) * PI / 180.0f) * 2;
		}

		m_obj->y -= _deltaMove;

		_deltaMove -= 4 * DELTA_TIME;
	}

	_collision->Setting(20, m_obj->x, m_obj->y, "Attack");

	if (m_obj->y > 600)
	{
		m_obj->ObjectDestroyed();
	}
}

void Baptism::Render()
{
	_imgPhase1BossBaptismProjectile->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);

}

void Baptism::Release()
{
}

void Baptism::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		if (coll2->GetName() == "PlayerHitRange")
		{
			Player* player = other->GetComponent<Player>();
			player->HitPlayerMagicAttack(10);
			player->HitPlayerEffect();
			if (OBJECTMANAGER->m_player->GetplayerX() < m_obj->x)
			{
				player->HitPlayerKnockBack(-15, -5);
			}
			else if (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x)
			{
				player->HitPlayerKnockBack(-15, -5);
			}
		}
	}
}