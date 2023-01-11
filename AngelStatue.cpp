#include "stdafx.h"
#include "AngelStatue.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include"Gold.h"
#include"Effect.h"
#include"PlayerEffect.h"
#include"BlackRock.h"
#include"CSound.h"
void AngelStatue::Init()
{
	m_maxhp = 200.0f;
	m_currenthp = 200.0f;
	m_die = false;
	m_hit = false;
	m_effect = false;
	m_attackcount = 0;
	m_attacksound = false;
	m_attacksound2 = false;
	m_attacksoundtimer = 0;
	GAMEMANAGER->enemyCount++;
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

	m_vimage[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	m_vimage[eHPbarEmpty]->Setting(0.4f, false);

	m_vimage[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	m_vimage[eHpbarDown]->Setting(0.4f, false);

	m_vimage[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	m_vimage[eHpbarUp]->Setting(0.4f, false);



	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	effect = EFFECTMANAGER->AddEffect<Appear>(m_obj->x, m_obj->y, false, 1.5f);
	effect->Init();
	effect->SetEffectStart(m_obj->x, m_obj->y, false, 1.5);

	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddCollisionComponent(m_hitpointcollision);
}

void AngelStatue::Update()
{
	m_attacksoundtimer += DELTA_TIME;
	if (m_attacksound == true)
	{
		SOUNDMANAGER->FindSound("AngleStatueAttackReady")->Play(false);
		m_attacksound = false;
		m_attacksoundtimer = 0;
		m_attacksound2 = true;
	}
	if (m_attacksoundtimer >= 2.9 && m_attacksound2 == true)
	{
		SOUNDMANAGER->FindSound("AngleStatueAttack")->Play(false);
		m_attacksound2 = false;
	}
	if (m_effect == false)
	{

		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	}

	if (m_effect == false)
	{
		try
		{
			if (effect->GetIsEffectEnded())
			{
				m_effect = true;
			}
		}
		catch (const std::exception&)
		{
			effect = nullptr;
		}
	}

	if (m_effect == true)
	{
		if (m_hit)
		{
			m_hpbartimer += DELTA_TIME;
		}

		m_state = eIdle;
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		m_collision->Setting(100, m_obj->x + 48, m_obj->y - 30, "hitBox");

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

			if (m_attack == true)
			{
				m_state2 = eAttackEffect;
			}
		}
		if (m_vimage[eAttackEffect]->GetFrame() >= 1 && m_vimage[eAttackEffect]->GetFrame() <= 16)
		{
			m_hitpointcollision->SetIsActive(true);
			m_hitpointcollision->Setting(150, m_obj->x + 70, m_obj->y - 10, "AttackPoint");
		}
		else
		{
			m_hitpointcollision->SetIsActive(false);
			m_attackcount = 0;
		}
		if (m_vimage[eAttackEffect]->GetIsImageEnded())
		{
			m_attack = false;
			m_collision->SetIsActive(true);
			m_vimage[eAttack]->Reset();
			m_vimage[eAttackReadyEffect]->Reset();
			m_vimage[eEndAttack]->Reset();
		}
		if (m_attack == false)
		{
			m_vimage[eAttackEffect]->Reset();
		}

		m_hpbar = (1 / m_maxhp);
		m_hiteffecttimer += DELTA_TIME;
		m_dietimer += DELTA_TIME;
	}
}



void AngelStatue::Render()
{
	if (m_effect == true)
	{
		if (m_currenthp >= 0)
		{
			m_vimage[m_state]->CenterRender((int)m_obj->x, (int)m_obj->y - 80, 1.5, 1.5, 0, 1);
			if (m_attack == true)
			{
				m_vimage[m_state2]->CenterRender((int)m_obj->x, (int)m_obj->y - 80, 1.5, 1.5, 0, 1);
			}
			if (m_hpbartimer <= 2 && m_hit == true)
			{
				m_vimage[eHPbarEmpty]->Render(m_obj->x - 35, m_obj->y + 15, 1, 1, 0);
				m_vimage[eHpbarDown]->Render(m_obj->x - 35, m_obj->y + 15, 1, 1, 0);
				m_vimage[eHpbarUp]->Render(m_obj->x - 35, m_obj->y + 15, (m_currenthp * m_hpbar), 1, 0);
			}
			else
			{
				m_hit = false;
				m_hpbartimer = 0;
			}
		}
		else
		{
			if (!m_die && m_dietimer >= 1)
			{
				EFFECTMANAGER->AddEffect<DeadEffect>(m_obj->x, m_obj->y, 1, 1.5);
				m_dietimer = 0;
			}
			m_die = true;
			if (m_dietimer >= 0.5f)
			{
				m_hitpointcollision->SetIsActive(false);
				for (int i = 0; i < 4; i++)
				{
					OBJECTMANAGER->AddObject("BlackRock", m_obj->x, m_obj->y - 50, ObjectTag::eItem)->AddComponent<BlackRock>();
					OBJECTMANAGER->AddObject("Gold", m_obj->x, m_obj->y - 50, ObjectTag::eItem)->AddComponent<Gold>();
				}
				m_obj->ObjectDestroyed();
			}

		}
	}
	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
	}
}


void AngelStatue::Release()
{
	GAMEMANAGER->enemyCount--;
}


void AngelStatue::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName() == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			//other->GetComponent<Player>()-플레이어 상태쉉
			m_attacksound = true;
			m_attack = true;
			m_collision->SetIsActive(false);
		}
	}

	if (coll1->GetName() == m_hitpointcollision->GetName())
	{
		if (coll2->GetName() == "PlayerHitRange")
		{
			if (other->GetName() == "player")
			{
				//m_hitpoint = true;
				if (m_attackcount < 1)
				{
					Player* ply = other->GetComponent<Player>();
					ply->HitPlayerMagicAttack(1);
					m_hiteffecttimer = 0;
					m_attackcount = 1;
				}
			}
		}
	}
}
void AngelStatue::HitEnemy(float dmg, float time)
{

	if (m_hiteffecttimer >= time)
	{
		dmg = 10;
		m_currenthp -= dmg;
		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
		{
			EFFECTMANAGER->AddEffect<PlayerHit>(m_obj->x - 5, m_obj->y - 60, 0, 2);
		}
		else
		{
			EFFECTMANAGER->AddEffect<PlayerHit>(m_obj->x - 5, m_obj->y - 60, 0, 2);
		}
		m_hit = true;
		m_hiteffecttimer = 0;
	}
}
