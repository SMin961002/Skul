#include "stdafx.h"
#include "Fanatic.h"
#include "RigidBodyComponent.h"
#include "CollisionComponent.h"
#include "Player.h"
#include"EnemyEffect.h"
#include"TentaclesOfLight.h"
#include"Gold.h"
#include"Hporb.h"
void Fanatic::Init()
{
	m_hpbartimer = 0;
	m_maxhp = 35.0f;
	m_currenthp = 35.0f;
	m_hpbar = 0;
	m_hitTimer = 0;
	m_motiontimer = 0;
	m_isHit = false;
	m_hit = false;
	m_die = false;
	m_sercrifice = false;
	m_sercrieffect = false;
	m_state = eIdle;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_lastX = m_obj->x;
	m_lastY = m_obj->y;
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Idle");
	m_vimage[eIdle]->Setting(0.1f, true);
	m_vimage[eAttackIdle] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_AttackIdle");
	m_vimage[eAttackIdle]->Setting(0.1f, true);
	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eRunAttack] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Runattack");
	m_vimage[eRunAttack]->Setting(0.1f, true);
	m_vimage[eRun] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Run");
	m_vimage[eRun]->Setting(0.1f, true);
	m_vimage[Setcrifice] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Setcrifice");
	m_vimage[Setcrifice]->Setting(0.2f, false);
	m_vimage[SetcrificeLoop] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Setcrificeloop");
	m_vimage[SetcrificeLoop]->Setting(0.2f, false);
	m_vimage[SetcrificeReady] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Setcrificeready");
	m_vimage[SetcrificeReady]->Setting(0.2f, false);
	m_vimage[eHit] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Hit");
	m_vimage[eHit]->Setting(0.2f, false);

	m_vimage[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	m_vimage[eHPbarEmpty]->Setting(0.4f, false);
	m_vimage[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	m_vimage[eHpbarDown]->Setting(0.4f, false);
	m_vimage[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	m_vimage[eHpbarUp]->Setting(0.4f, false);

	m_isReverse = false;
	m_isAttack = false;

	m_hitCollision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointCollision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_hitCollision);
	m_obj->AddCollisionComponent(m_hitpointCollision);
}

void Fanatic::Update()
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
	m_hitCollision->Setting(30, m_obj->x + 15, m_obj->y - 10, "HitCollision");
	if (m_hit)
	{
		m_hpbartimer += DELTA_TIME;
	}
	if (m_isHit == true)
	{
		m_hitTimer += DELTA_TIME;
	}
	else
	{
	}
	float xDest = m_obj->x - OBJECTMANAGER->m_player->GetplayerX();
	if (m_vimage[eAttack]->GetFrame() >= 9 && m_vimage[eAttack]->GetFrame() <= 10)
	{
		m_hitpointCollision->SetIsActive(true);
	}
	else
	{
		m_hitpointCollision->SetIsActive(false);
	}
	if (m_isAttack == false && m_isHit == false)
	{

		if (xDest < 300 && xDest > -300)
		{
			if (xDest < 100 && xDest > -100)
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
				m_vimage[eAttack]->Reset();

				m_isAttack = true;
			}
			else
			{
				m_state = eRun;
				m_obj->x += m_isReverse ? -DELTA_TIME * 50 : DELTA_TIME * 50;
			}
			m_isReverse = xDest > 0;
		}
		else
		{
			m_state = eIdle;
		}
	}
	if (m_currenthp <= 30 && !m_die2)
	{

		m_sercrifice = true;
		m_state = SetcrificeReady;
		if (m_vimage[SetcrificeReady]->GetIsImageEnded())
		{
			m_state = SetcrificeLoop;
			if (m_vimage[SetcrificeLoop]->GetIsImageEnded())
			{

				if (!m_sercrieffect && 0 == m_isReverse)
				{
					EFFECTMANAGER->AddEffect<Secrifice>(m_obj->x + 50, m_obj->y - 20, 0, 1.5);
				}
				if (!m_sercrieffect && 1 == m_isReverse)
				{
					EFFECTMANAGER->AddEffect<Secrifice>(m_obj->x - 50, m_obj->y - 20, 1, 1.5);
				}
				m_sercrieffect = true;
				m_motiontimer += 0.1f;
				m_state = Setcrifice;
				if (m_vimage[Setcrifice]->GetIsImageEnded())
				{
					m_hitpointCollision->SetIsActive(false);
					m_hitCollision->SetIsActive(false);
					OBJECTMANAGER->AddObject("Enemy", m_obj->x, m_obj->y, ObjectTag::eSummons)->AddComponent<TentaclesOfLight>();
					m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
					m_obj->GetComponent< PixelCollisionComponent>()->SetIsActive(false);
					m_die2 = true;
				}
			}
		}
	}
	if (m_isAttack == false)
	{
		m_hitpointCollision->SetIsActive(false);
	}
	m_hpbar = (1 / m_maxhp);
	ImageResetCheck();
	m_hiteffecttimer += DELTA_TIME;
	m_dietimer += DELTA_TIME;
}

void Fanatic::Render()
{

	if (m_currenthp >= 0)
	{
		m_vimage[m_state]->CenterRender(m_obj->x, m_obj->y - 55, 2, 2, 0, m_isReverse);

			if (m_hpbartimer <= 2 && !m_die2 && (m_hit == true || m_sercrifice == true))
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
			if (!m_die && m_dietimer >= 1&&!m_die2)
			{
				EFFECTMANAGER->AddEffect<DeadEffect>(m_obj->x, m_obj->y, 1, 1.5);
				m_dietimer = 0;
				for (int i = 0; i < 4; i++)
				{
					OBJECTMANAGER->AddObject("Gold", m_obj->x, m_obj->y - 50, ObjectTag::eItem)->AddComponent<Gold>();
				}
					OBJECTMANAGER->AddObject("Hporb", m_obj->x, m_obj->y, ObjectTag::eItem)->AddComponent<Hporb>();
			}
			m_die = true;
			if (m_dietimer >= 0.5f&&!m_die2)
			{
				
				m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
				m_obj->GetComponent< PixelCollisionComponent>()->SetIsActive(false);
				m_hitpointCollision->SetIsActive(false);
				m_hitCollision->SetIsActive(false);
				m_obj->ObjectDestroyed();
			}
			
		}
		cout << m_currenthp << endl;
	

}

void Fanatic::Release()
{
}

void Fanatic::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_hitpointCollision->GetName())
	{
		cout << "파나틱 공격" << endl;
		if (other->GetName() == "player")
		{
			Player* ply = other->GetComponent<Player>();
			ply->HitPlayerMagicAttack(10);
			ply->HitPlayerKnockBack(5, 5);
			cout << "파나틱이 플레이어를 때렸다(마법공격)" << endl;
		}
	}
}

void Fanatic::HitEnemy(float dmg)
{
	m_hitpointCollision->SetIsActive(false);
	if (!m_die2)
	{
		if (m_currenthp >= 50)
			m_isAttack = false;
		m_isHit = true;
		m_state = eHit;
		m_vimage[eHit]->Reset();
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
	if (m_hiteffecttimer >= 0.7f)
	{
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
		dmg = 40; //-= 플레이어 어택 데미지 상의
		m_currenthp -= dmg;
	}
}

void Fanatic::ImageResetCheck()
{
	if (m_isAttack == true && m_vimage[eAttack]->GetIsImageEnded() == true)
	{
		m_isAttack = false;
	}
	else if (m_hitTimer >= 0.3f)
	{
		m_isHit = false;
		m_hitTimer = 0;
	}
}
