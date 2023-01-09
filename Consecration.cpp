#include "stdafx.h"
#include "Consecration.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"

void Consecration::Init()
{
	_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision);
	_collision2 = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision2);
	_collision3 = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision3);
	_collision4 = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision3);
	_hitCollision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_hitCollision);

	_imgPhase1BossConsecrationLoop = IMAGEMANAGER->FindImageVector("Boss_Consecration_Loop");
	_imgPhase1BossConsecrationLoop->Setting(0.1, true);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);
}

void Consecration::Update()
{
	if (_deltaTime > 2)
	{
		m_obj->ObjectDestroyed();
	}
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);

	_collision->Setting(100, m_obj->x + 30, m_obj->y - 200, "Attack");
	_collision2->Setting(100, m_obj->x + 30, m_obj->y , "Attack");
	_collision3->Setting(100, m_obj->x + 30, m_obj->y + 200, "Attack");
	_collision4->Setting(100, m_obj->x + 30, m_obj->y + 300, "Attack");

}

void Consecration::Render()
{
	_imgPhase1BossConsecrationLoop->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
	_deltaTime += DELTA_TIME;
}

void Consecration::Release()
{
}

void Consecration::OnCollision(string collisionName, Object* other)
{
	if (other->GetName() == "player")
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
