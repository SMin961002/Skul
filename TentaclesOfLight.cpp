#include "stdafx.h"
#include "TentaclesOfLight.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include"CSound.h"

void TentaclesOfLight::Init()
{
	GAMEMANAGER->enemyCount++;

	m_attackcount = 0;
	m_attacksound2 = false;
	m_maxhp = 1;
	m_memergeend = false;
	m_attack = false;
	m_recovery = false;
	m_hiteffecttimer = 0;
	m_attacksound = false;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Tentacles_Idle");
	m_vimage[eIdle]->Setting(0.1f, true);

	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Tentacles_Attack");
	m_vimage[eAttack]->Setting(0.15f, false);

	m_vimage[eRecovery] = IMAGEMANAGER->AddImageVectorCopy("Tntackles_Recovery");
	m_vimage[eRecovery]->Setting(0.1f, false);

	m_vimage[eMemerge] = IMAGEMANAGER->AddImageVectorCopy("Tentacles_Emerge");
	m_vimage[eMemerge]->Setting(0.1f, false);

	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddCollisionComponent(m_hitpointcollision);
}

void TentaclesOfLight::Update()
{
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_collision->Setting(40, m_obj->x + 17, m_obj->y - 20, "hitBox");

	if (m_attacksound == true)
	{
		SOUNDMANAGER->FindSound("TentacleAttack")->Play(false);
		m_attacksound = false;
	}
	if (m_vimage[eAttack]->GetFrame() >= 4 && m_vimage[eAttack]->GetFrame() <= 7)
	{
		m_hitpointcollision->SetIsActive(true);
		if (m_isleft)
		{
			m_hitpointcollision->Setting(50, m_obj->x - 35, m_obj->y - 20, "AttackPoint");
		}
		else
		{
			m_hitpointcollision->Setting(50, m_obj->x + 80, m_obj->y - 20, "AttackPoint");
		}
	}
	if (m_vimage[eAttack]->GetFrame() >= 7)
	{
		m_attackcount = 0;
		m_hitpointcollision->SetIsActive(false);
	}
	if (m_memergeend == false)
	{
		m_state = eMemerge;
	}
	if (m_vimage[eMemerge]->GetIsImageEnded())
	{
		m_memergeend = true;
	}
	if (m_memergeend == true && m_attack == false)
	{
		m_state = eIdle;
	}
	else if (m_attack == true)
	{
		m_state = eAttack;
		if (m_vimage[eAttack]->GetIsImageEnded())
		{
			m_recovery = true;
			m_state = eRecovery;
		}
		if (m_vimage[eRecovery]->GetIsImageEnded())
		{
			m_attacksound2 = false;
			m_attack = false;
			m_recovery = false;
			m_collision->SetIsActive(true);
		}
	}
	m_hiteffecttimer += DELTA_TIME;
	if (m_maxhp <= 0)
	{
		m_obj->ObjectDestroyed();
	}

}

void TentaclesOfLight::Render()
{
	m_vimage[m_state]->CenterRender((int)m_obj->x, (int)m_obj->y - 63, 1.5, 1.5, 0, m_isleft);
}

void TentaclesOfLight::Release()
{
	GAMEMANAGER->enemyCount--;
}


void TentaclesOfLight::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName() == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			if (m_attack == false)
			{
				m_attacksound = true;
			}
			m_attacksound2 = true;
			if (m_attack == false)
			{
				m_vimage[eAttack]->Reset();
				m_vimage[eRecovery]->Reset();
				if (m_attack == false && m_recovery == false)
				{
					if (OBJECTMANAGER->m_player->GetplayerX() < m_obj->x)
					{
						m_isleft = true;
					}
					else if (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x)
					{
						m_isleft = false;
					}
				}
			}
			m_attack = true;
			//other->GetComponent<Player>()-플레이어 상태쉉
		}
	}

	if (coll1->GetName() == m_hitpointcollision->GetName())
	{
		if (coll2->GetName() == "PlayerHitRange")
			if (other->GetName() == "player")
			{
				if (m_attackcount < 1)
				{
					Player* ply = other->GetComponent<Player>();
					ply->HitPlayerMagicAttack(10);
					ply->HitPlayerEffect();
					if (OBJECTMANAGER->m_player->GetplayerX() < m_obj->x)
					{
						ply->HitPlayerKnockBack(-15, -5);
					}
					else if (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x)
					{
						ply->HitPlayerKnockBack(15, -5);
					}
					m_attackcount = 1;
				}
			}
	}
}

void TentaclesOfLight::HitEnemy(float dmg, float time)
{
	if (m_hiteffecttimer >= time)
	{
		m_maxhp -= dmg;
	}
}