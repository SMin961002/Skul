#include "stdafx.h"
#include "AngelStatue.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include"Gold.h"
#include"Effect.h"
#include"BlackRock.h"

void AngelStatue::Init()
{
	m_effecttimer = 0;
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("AStatue_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("AStatue_Attack");
	m_vimage[eAttack]->Setting(0.035f, false);

	m_vimage[eAttackReadyEffect] = IMAGEMANAGER->AddImageVectorCopy("AStatue_AttackRedadyEffect");
	m_vimage[eAttackReadyEffect]->Setting(0.1f, false);

	m_vimage[eAttackEffect] = IMAGEMANAGER->AddImageVectorCopy("AStatue_AttackEffect");
	m_vimage[eAttackEffect]->Setting(0.1f, false);

	m_vimage[eEndAttack] = IMAGEMANAGER->AddImageVectorCopy("AStatue_End");
	m_vimage[eEndAttack]->Setting(0.1f, false);
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddCollisionComponent(m_hitpointcollision);
}

void AngelStatue::Update()
{

	if (m_effecttimer <= 1.0f)
	{
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	}
	m_effecttimer += DELTA_TIME;
	if (m_effecttimer <= 0.1f)
	{
		EFFECTMANAGER->AddEffect<Appear>(m_obj->x, m_obj->y, 1, 1.5);
	}
	if (m_effecttimer >= 1.1f)
	{
		m_state = eIdle;
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		m_collision->Setting(100, m_obj->x + 48, m_obj->y - 30, "Attack");
		
			if (m_attack == true)
			{
				m_state2 = eAttackReadyEffect;
				m_state = eAttack;
			}
			if (m_vimage[eAttack]->GetIsImageEnded())
			{
				m_state = eEndAttack;
			}
			if (m_vimage[eAttackReadyEffect]->GetIsImageEnded())
			{
				m_state2 = eAttackEffect;
			}
			if (m_vimage[eAttackEffect]->GetIsImageEnded())
			{
				m_vimage[eAttack]->Reset();
				m_vimage[eAttackReadyEffect]->Reset();
				m_vimage[eAttackEffect]->Reset();
				m_vimage[eEndAttack]->Reset();
				m_attack = false;
			}
		
	}

}

void AngelStatue::Render()
{
	if (m_effecttimer >= 1.1f)
	{
		m_vimage[m_state]->CenterRender((int)m_obj->x, (int)m_obj->y - 80, 1.5, 1.5, 0, 1);
		m_vimage[m_state2]->CenterRender((int)m_obj->x, (int)m_obj->y - 80, 1.5, 1.5, 0, 1);
	}
}

void AngelStatue::Release()
{
}

void AngelStatue::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			//other->GetComponent<Player>()-플레이어 상태쉉
			m_attack = true;
		}
	}

	if (collisionName == m_hitpointcollision->GetName())
	{
		if (other->GetName() == "player")
		{
			//m_hitpoint = true;
			Player* ply = other->GetComponent<Player>();
			ply->HitPlayerMagicAttack(1);
		}
	}
}
