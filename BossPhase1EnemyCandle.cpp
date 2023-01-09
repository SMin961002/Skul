#include "stdafx.h"
#include "BossPhase1EnemyCandle.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "Player.h"
#include "FireKnife.h"
void BossPhase1EnemyCandle::Init()
{
	m_maxhp = 100;
	m_currenthp = 100;
	m_dietimer = 0;
	m_state = eUp;
	m_die = false;
	m_hit = false;
	m_isL = false;
	m_ratherImg = IMAGEMANAGER->FindImage("Rather");
	m_ratherY = 200;
	img[eUp] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Up");
	img[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Fire");
	img[eAttackReady] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_FireReady");
	img[eWalk] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Move");
	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Idle");
	img[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	img[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	img[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");




	img[eAttack]->Setting(0.1, false);
	img[eAttackReady]->Setting(0.1, false);
	img[eWalk]->Setting(0.1, true);
	img[eIdle]->Setting(0.1, false);
	img[eUp]->Setting(0.1, false);
	img[eHPbarEmpty]->Setting(0.4f, false);
	img[eHpbarDown]->Setting(0.4f, false);
	img[eHpbarUp]->Setting(0.4f, false);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_hitCollision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_hitCollision);
}

void BossPhase1EnemyCandle::Update()
{
	if (img[eUp]->GetIsImageEnded() == false)
	{
		if (m_ratherY > 0)
		{
			m_ratherY -= 3;
		}
	}
	else
	{
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		m_hitCollision->Setting(30, m_obj->x + 15, m_obj->y - 10, "HitCollision");
		if (abs(m_obj->x - OBJECTMANAGER->m_player->GetplayerX()) < 200 || m_state == eAttackReady || m_state == eAttack)
		{
			if (img[eIdle]->GetIsImageEnded() == true)
			{
				if (img[eAttackReady]->GetIsImageEnded() == true)
				{
					if (m_state == eAttackReady)
					{
						OBJECTMANAGER->AddObject("Knife", m_obj->x, m_obj->y - 100, eObject)->AddComponent<FireKnife>();
					}
					m_state = eAttack;
					if (img[m_state]->GetIsImageEnded() == true)
					{
						img[eAttackReady]->Reset();
						img[eAttack]->Reset();
						img[eIdle]->Reset();
						m_state = eIdle;
					}
				}
				else
				{
					m_state = eAttackReady;
				}
			}
			else
			{
				m_state = eIdle;
				m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
			}
		}
		else if (img[eIdle]->GetIsImageEnded() == true)
		{
			m_state = eWalk;
			m_obj->x += DELTA_TIME * (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x ? 30 : -30);
			m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
		}
		else
		{
			m_state = eIdle;
		}
		m_ratherY += 9;
		m_hiteffecttimer += DELTA_TIME;
		m_dietimer += DELTA_TIME;
		m_hpbartimer += DELTA_TIME;
		m_hpbar = (1 / m_maxhp);

	}
	
}

void BossPhase1EnemyCandle::Render()
{
	IMAGEMANAGER->CenterRender(m_ratherImg, m_obj->x, m_obj->y + 100 + m_ratherY, 2, 2, 0, 0);
	if (m_currenthp >= 0)
	{
		img[m_state]->CenterRender(m_obj->x, m_obj->y + 30, 2, 2, 0, m_isL);
		if (m_hpbartimer <= 2 && !m_die2 && m_hit == true)//|| m_sercrifice == true))
		{
			img[eHPbarEmpty]->Render(m_obj->x - 35, m_obj->y + 15, 1, 1, 0);
			img[eHpbarDown]->Render(m_obj->x - 35, m_obj->y + 15, 1, 1, 0);
			img[eHpbarUp]->Render(m_obj->x - 35, m_obj->y + 15, (m_currenthp * m_hpbar), 1, 0);
		}
		else
		{
			m_hit = false;
			m_hpbartimer = 0;
		}
	}
	else
	{
		if (!m_die && m_dietimer >= 1 && !m_die2)
		{
			EFFECTMANAGER->AddEffect<DeadEffect>(m_obj->x, m_obj->y, 1, 1.5);
			m_dietimer = 0;
		}
		m_die = true;
		if (m_dietimer >= 0.5f && !m_die2)
		{

			m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
			m_obj->GetComponent< PixelCollisionComponent>()->SetIsActive(false);
			m_hitCollision->SetIsActive(false);
			m_obj->ObjectDestroyed();
		}

	}
}


void BossPhase1EnemyCandle::Release()
{
}

void BossPhase1EnemyCandle::HitEnemy(float dmg, float time)
{
	img[eAttack]->Reset();
	img[eIdle]->Reset();
	img[eAttackReady]->Reset();
	m_state = eIdle;
	if (!m_die2)
	{

		//if (m_currenthp >= 50) 희생 이미지 없음
		//m_state = eHit; 히트이미지 없음
		//img[eHit]->Reset();
		if (m_obj->x >= OBJECTMANAGER->m_player->GetplayerX())
		{
			m_obj->x += DELTA_TIME * 500;
		}
		else
		{
			m_obj->x -= DELTA_TIME * 500;
		}
		m_obj->y -= 30;
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	}

	if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 0, 1.5);
	}
	else
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 1, 1.5);
	}
	m_hit = true;
	m_hiteffecttimer = 0;
	m_currenthp -= dmg;

}
