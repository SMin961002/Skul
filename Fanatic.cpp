#include "stdafx.h"
#include "Fanatic.h"
#include "RigidBodyComponent.h"
#include "CollisionComponent.h"
#include "Player.h"
#include"EnemyEffect.h"
#include"TentaclesOfLight.h"
#include"Gold.h"
#include"Hporb.h"
#include"BlackRock.h"
#include"CSound.h"
void Fanatic::Init()
{
	m_attackcount = 0;
	m_hpbartimer = 0;
	m_maxhp = 100.0f;
	m_currenthp = 100.0f;
	m_hpbar = 0;
	m_hitTimer = 0;
	m_motiontimer = 0;
	m_effect = false;
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

	effect = EFFECTMANAGER->AddEffect<Appear>(m_obj->x, m_obj->y, false, 1.4f);
	//effect = new Appear;
	//effect->Init();
	//effect->SetEffectStart(m_obj->x, m_obj->y, false, 1.5);

	m_hitCollision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointCollision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_hitCollision);
	m_obj->AddCollisionComponent(m_hitpointCollision);

	GAMEMANAGER->enemyCount++;
}

void Fanatic::Update()
{	
	if (SCENEMANAGER->m_tiles.size() * 31 < m_obj->y)
	{
		m_obj->ObjectDestroyed();
	}
	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
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
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		m_hitCollision->Setting(30, m_obj->x + 15, m_obj->y - 10, "hitBox");
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
			m_attackcount = 0;
		}
		if (m_isAttack == false && m_isHit == false)
		{

			if (xDest < 300 && xDest > -300)
			{
				if (xDest < 100 && xDest > -100)
				{
					SOUNDMANAGER->FindSound("FanaticAttackReady")->Play(false);
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
						SOUNDMANAGER->FindSound("Sacrifice")->Play(false);
						EFFECTMANAGER->AddEffect<Secrifice>(m_obj->x + 50, m_obj->y - 20, 0, 1.5);
					}
					if (!m_sercrieffect && 1 == m_isReverse)
					{
						SOUNDMANAGER->FindSound("Sacrifice")->Play(false);
						EFFECTMANAGER->AddEffect<Secrifice>(m_obj->x - 50, m_obj->y - 20, 1, 1.5);
					}
					m_sercrieffect = true;
					m_motiontimer += 0.1f;
					m_state = Setcrifice;
					if (m_vimage[Setcrifice]->GetIsImageEnded())
					{
						m_hitpointCollision->SetIsActive(false);
						m_hitCollision->SetIsActive(false);
						GAMEMANAGER->enemyCount--;
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
}

void Fanatic::Render()
{
	if (alphaHit >= 0)
	{
		alphaHit -= 0.05;
	}
	if (m_effect == true)
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
			if (!m_die && m_dietimer >= 1 && !m_die2)
			{
				EFFECTMANAGER->AddEffect<DeadEffect>(m_obj->x, m_obj->y, 1, 1.5);
				m_dietimer = 0;
				for (int i = 0; i < 4; i++)
				{
					OBJECTMANAGER->AddObject("Gold", m_obj->x, m_obj->y - 50, ObjectTag::eItem)->AddComponent<Gold>();
					OBJECTMANAGER->AddObject("BlackRock", m_obj->x, m_obj->y - 50, ObjectTag::eItem)->AddComponent<BlackRock>();
				}
				OBJECTMANAGER->AddObject("Hporb", m_obj->x, m_obj->y, ObjectTag::eItem)->AddComponent<Hporb>();
			}
			m_die = true;
			if (m_dietimer >= 0.5f && !m_die2)
			{

				m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
				m_obj->GetComponent< PixelCollisionComponent>()->SetIsActive(false);
				m_hitpointCollision->SetIsActive(false);
				m_hitCollision->SetIsActive(false);
				m_obj->ObjectDestroyed();
				GAMEMANAGER->enemyCount--;
			}

		}
	}
	IMAGEMANAGER->CenterRender(m_vimage[m_state]->GetNowImage(), m_obj->x, m_obj->y - 50, { 255,255,255,alphaHit }, 2, 2, 0, m_isReverse);

}

void Fanatic::Release()
{
}

void Fanatic::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName()  == m_hitpointCollision->GetName())
	{
		if(coll2->GetName() == "PlayerHitRange")
		if (other->GetName() == "player")
		{
			if (m_attackcount < 1)
			{
				SOUNDMANAGER->FindSound("FanaticAttack")->Play(false);
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

void Fanatic::HitEnemy(float dmg, float time)
{
	alphaHit = 1;
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
	if (m_hiteffecttimer >= time)
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
