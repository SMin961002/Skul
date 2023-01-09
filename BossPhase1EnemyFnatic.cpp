#include "stdafx.h"
#include "BossPhase1EnemyFnatic.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"

void BossPhase1EnemyFnatic::Init()
{
	m_maxhp = 100;
	m_currenthp = 100;
	m_dietimer = 0;
	m_attackcount = 0;

	m_ratherImg = IMAGEMANAGER->FindImage("Rather");
	m_ratherY = 200;

	m_state = eUp;
	m_isL = false;
	m_die = false;

	img[eUp] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Up");
	img[eUp]->Setting(0.1, false);

	img[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Attack");
	img[eAttack]->Setting(0.1, false);

	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Idle");
	img[eIdle]->Setting(0.1, false);

	img[eWalk] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Move");
	img[eWalk]->Setting(0.1, true);

	img[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	img[eHPbarEmpty]->Setting(0.4f, false);

	img[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	img[eHpbarDown]->Setting(0.4f, false);

	img[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	img[eHpbarUp]->Setting(0.4f, false);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_hitCollision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointCollision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_hitCollision);
	m_obj->AddCollisionComponent(m_hitpointCollision);
}

void BossPhase1EnemyFnatic::Update()
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

		if (img[eIdle]->GetIsImageEnded() == true)
		{
			if (abs(OBJECTMANAGER->m_player->GetplayerX() - m_obj->x) < 100 || m_state == eAttack)
			{
				m_state = eAttack;
				if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
				{
					m_hitpointCollision->Setting(40, m_obj->x - 17, m_obj->y - 20, "AttackPoint");
				}
				else
				{
					m_hitpointCollision->Setting(40, m_obj->x + 65, m_obj->y - 20, "AttackPoint");
				}
				if (img[eAttack]->GetFrame() >= 9 && img[eAttack]->GetFrame() <= 10)
				{
					m_attackcount = 0;
					m_hitpointCollision->SetIsActive(true);

				}
				else
				{
					m_hitpointCollision->SetIsActive(false);
					m_attackcount = 0;
				}
				if (img[eAttack]->GetIsImageEnded() == true)
				{
					img[eIdle]->Reset();
					img[eAttack]->Reset();
				}
			}
			else
			{
				m_obj->x += DELTA_TIME * (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x ? 150 : -150);
				m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
				m_state = eWalk;
			}

		}
		else
		{
			m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
			m_state = eIdle;
			m_ratherY += 9;
		}
		m_hiteffecttimer += DELTA_TIME;
		m_dietimer += DELTA_TIME;
		m_hpbartimer += DELTA_TIME;
		m_hpbar = (1 / m_maxhp);
	}
}

void BossPhase1EnemyFnatic::Render()
{
	IMAGEMANAGER->CenterRender(m_ratherImg, m_obj->x, m_obj->y + 80 + m_ratherY, 2, 2, 0, 0);
	if (m_currenthp >= 0)
	{
		img[m_state]->CenterRender(m_obj->x, m_obj->y + 70, 2, 2, 0, m_isL);
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
			m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(false);
			m_hitpointCollision->SetIsActive(false);
			m_hitCollision->SetIsActive(false);
			m_obj->ObjectDestroyed();
		}

	}

}



void BossPhase1EnemyFnatic::Release()
{
}

void BossPhase1EnemyFnatic::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_hitpointCollision->GetName())
	{
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

void BossPhase1EnemyFnatic::HitEnemy(float dmg, float time)
{
	img[eIdle]->Reset();
	img[eAttack]->Reset();
	m_state = eIdle;
	m_hitpointCollision->SetIsActive(false);
	if (!m_die2)
	{
		//if (m_currenthp >= 50) 희생 이미지 없음
		m_isAttack = false;
		m_isHit = true;
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

