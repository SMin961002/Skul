#include "stdafx.h"
#include "Worship.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "BossObject.h"

void WorshipLeft::Init()
{
	_imgPhase1BossWorshipLeft = IMAGEMANAGER->FindImageVector("Boss_Worship");
	_imgPhase1BossWorshipLeft->Setting(0.1, true);

	_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision);
	_collision->SetIsActive(false);
}

void WorshipLeft::Update()
{
	m_obj->x += 3;

	if (m_obj->x > 1800)
	{
		m_obj->ObjectDestroyed();
	}

	_collision->Setting(60, m_obj->x+100, m_obj->y, "Attack");

	if (OBJECTMANAGER->m_boss->_patternCheck == 2)
	{
		_collision->SetIsActive(true);
		cout << "ÆÐÅÏ : " << OBJECTMANAGER->m_boss->_patternCheck << endl;
	}

}

void WorshipLeft::Render()
{
	_imgPhase1BossWorshipLeft->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
}

void WorshipLeft::Release()
{
}

void WorshipLeft::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
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

void WorshipRight::Init()
{
	_imgPhase1BossWorshipRight = IMAGEMANAGER->FindImageVector("Boss_Worship");
	_imgPhase1BossWorshipRight->Setting(0.1, true);
	
	_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision);
	_collision->SetIsActive(false);
}

void WorshipRight::Update()
{
	m_obj->x -= 3;

	if (m_obj->x < 0)
	{
		m_obj->ObjectDestroyed();
	}
	_collision->Setting(50, m_obj->x, m_obj->y, "Attack");

	if (OBJECTMANAGER->m_boss->_patternCheck == 2)
	{
		_collision->SetIsActive(true);
	}
}

void WorshipRight::Render()
{
	_imgPhase1BossWorshipRight->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, true);
}

void WorshipRight::Release()
{
}

void WorshipRight::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
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
