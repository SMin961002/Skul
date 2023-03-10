#include "stdafx.h"
#include "LeoniaSoldier.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include"EnemyEffect.h"
#include"Gold.h"
#include"BlackRock.h"
#include"CSound.h"


void LeoniaSoldier::Init()
{
	GAMEMANAGER->enemyCount++;

	m_maxhp = 70.0f;
	m_attackcount = 0;
	m_currenthp = 70.0f;
	m_hiteffecttimer = 0;
	m_hpbartimer = 0;
	m_hpbar = 0;
	m_hitmotion = false;
	m_die = false;
	m_effect = false;
	m_attackleft = false;
	m_attack = false;
	m_move = false;
	m_hit = false;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Leon_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Leon_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eAttack]->Setting(0, 1.0f);

	m_vimage[eRun] = IMAGEMANAGER->AddImageVectorCopy("Leon_Run");
	m_vimage[eRun]->Setting(0.1f, true);

	m_vimage[eHit] = IMAGEMANAGER->AddImageVectorCopy("Leon_Hit");
	m_vimage[eHit]->Setting(0.4f, false);

	m_vimage[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	m_vimage[eHPbarEmpty]->Setting(0.4f, false);

	m_vimage[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	m_vimage[eHpbarDown]->Setting(0.4f, false);

	m_vimage[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	m_vimage[eHpbarUp]->Setting(0.4f, false);

	effect = EFFECTMANAGER->AddEffect<Appear>(m_obj->x, m_obj->y, false, 1.5f);
	effect->Init();
	effect->SetEffectStart(m_obj->x, m_obj->y, false, 1.5);

	m_lastX = m_obj->x;
	m_lastY = m_obj->y;
	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();
	alphaHit = 0;
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddCollisionComponent(m_hitpointcollision);
}

void LeoniaSoldier::Update()
{
	if (SCENEMANAGER->m_tiles.size() * 31 < m_obj->y)
	{
		m_obj->ObjectDestroyed();
	}
	if (alphaHit >= 0)
	{
		alphaHit -= 0.05;
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
		catch (const std::exception& eex)
		{
			cout << eex.what();
			effect = nullptr;
		}
	}

	if (m_effect == true)
	{
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		if (m_lastX != m_obj->x || m_lastY != m_obj->y)
		{
			m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
			m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);

			m_lastX = m_obj->x;
			m_lastY = m_obj->y;
		}
		else
		{
			m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
			m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(false);
		}

		m_collision->Setting(30, m_obj->x + 17, m_obj->y - 20, "hitBox");
		if (m_hit)
		{
			m_hpbartimer += DELTA_TIME;
		}
		if (m_vimage[eAttack]->GetFrame() >= 1)
		{
			SOUNDMANAGER->FindSound("LeoniaSolderAttack")->Play(false);
			m_hitpointcollision->SetIsActive(true);
			if (m_attackleft)
			{
				m_obj->x -= DELTA_TIME * 50.0f;
				m_hitpointcollision->Setting(40, m_obj->x - 17, m_obj->y - 20, "AttackPoint");
			}
			else
			{
				m_obj->x += DELTA_TIME * 50.0f;
				m_hitpointcollision->Setting(40, m_obj->x + 40, m_obj->y - 20, "AttackPoint");
			}
		}


		if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x - 400 && OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x + 400)
		{
			if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false)
			{
				m_obj->x -= DELTA_TIME * 150.0f;
				m_move = true;
			}
			if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false)
			{
				m_obj->x += DELTA_TIME * 150.0f;
				m_move = true;
			}
		}
		else
		{
			m_move = false;
		}
		if (m_vimage[eAttack]->GetIsImageEnded())
		{
			m_vimage[eAttack]->Reset();
			m_attack = false;
		}
		if (m_attack == false)
		{
			m_hitpointcollision->SetIsActive(false);
			m_attackcount = 0;
		}
		m_hpbar = (1 / m_maxhp);
		m_hiteffecttimer += DELTA_TIME;
		m_dietimer += DELTA_TIME;
	}
}

void LeoniaSoldier::Render()
{
	if (m_effect == true)
	{
		if (m_currenthp >= 0)
		{
			if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false && m_move == true && m_hitmotion == false)
			{
				m_attackleft = true;
				m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, 1);
			}
			else if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false && m_move == true && m_hitmotion == false)
			{
				m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, 0);
				m_attackleft = false;
			}
			if (!m_attack && m_move == false && m_hitmotion == false)
				m_vimage[eIdle]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0);
			if (m_attack && m_move == false && m_hitmotion == false)
			{
				m_vimage[eAttack]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, m_attackleft);
			}
			if (m_hitmotion == true)
			{
				m_vimage[eHit]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, m_attackleft);
				m_hitmotion = false;
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
	if (alphaHit >= 0)
	{
	}
	IMAGEMANAGER->CenterRender(m_vimage[eHit]->GetNowImage(), m_obj->x, m_obj->y - 50, { 255,255,255,alphaHit }, 2, 2, 0, m_attackleft);
}

void LeoniaSoldier::Release()
{
	GAMEMANAGER->enemyCount--;
}

void LeoniaSoldier::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName() == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			m_attack = true;
			m_move = false;
		}
	}

	else if (coll1->GetName() == m_hitpointcollision->GetName())
	{
		if (coll2->GetName() == "PlayerHitRange")
		{
			if (other->GetName() == "player")
			{
				if (m_attackcount < 1)
				{
					SOUNDMANAGER->FindSound("LeonialSolderAttackHit")->Play(false);
					m_hitpoint = true;
					Player* ply = other->GetComponent<Player>();
					ply->HitPlayerMagicAttack(5);
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


}

void LeoniaSoldier::HitEnemy(float dmg, float time)
{
	/*m_isAttack = false;
	m_isHit = true;
	m_state = eHit;*/
	m_hitmotion = true;
	alphaHit = 1;
	if (m_hiteffecttimer >= time)
	{
		m_vimage[eHit]->Reset();
		m_obj->x += m_obj->x > OBJECTMANAGER->m_player->GetplayerX() ? DELTA_TIME * 500 : -DELTA_TIME * 500;
		m_obj->y -= 10;
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
		m_currenthp -= dmg;

		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
		{
			EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 0, 2);
		}
		else
		{
			EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 1, 2);
		}
		m_hit = true;
		m_hiteffecttimer = 0;

	}
}