#include "stdafx.h"
#include "CandleFanatic.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "FireKnife.h"
#include"TentaclesOfLight.h"
#include"BlackRock.h"
#include"Gold.h"
#include"Hporb.h"
#include"Effect.h"

void CandleFanatic::Init()
{
	m_hpbartimer = 0;
	m_maxhp = 100.0f;
	m_hitTimer = 0;
	m_currenthp = 100.0f;
	m_sercrifice = false;
	m_isHit = false;
	m_sercrieffect = false;
	m_isL = false;
	m_die = false;
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Cfanatic_Idle");
	m_vimage[eIdle]->Setting(0.1f, true);

	m_vimage[eAttackReady] = IMAGEMANAGER->FindImageVector("Cfanatic_AttackReady");
	m_vimage[eAttackReady]->Setting(0.1f, false);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("Cfanatic_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("Cfanatic_Run");
	m_vimage[eRun]->Setting(0.1f, true);

	m_vimage[eHit] = IMAGEMANAGER->FindImageVector("Cfanatic_Hit");
	m_vimage[eHit]->Setting(0.1f, false);

	m_vimage[eSatcrifice] = IMAGEMANAGER->FindImageVector("Cfanatic_Satcrifice");
	m_vimage[eSatcrifice]->Setting(0.1f, false);

	m_vimage[eSatcrificeReady] = IMAGEMANAGER->FindImageVector("Cfanatic_SatcrificeReady");
	m_vimage[eSatcrificeReady]->Setting(0.1f, false);

	m_vimage[eSatcrificeLoop] = IMAGEMANAGER->FindImageVector("Cfanatic_SatcrificeLoop");
	m_vimage[eSatcrificeLoop]->Setting(0.1f, false);

	m_vimage[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	m_vimage[eHPbarEmpty]->Setting(0.4f, false);

	m_vimage[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	m_vimage[eHpbarDown]->Setting(0.4f, false);

	m_vimage[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	m_vimage[eHpbarUp]->Setting(0.4f, false);

	m_state = eIdle;
	effect = EFFECTMANAGER->AddEffect<Appear>(m_obj->x, m_obj->y, false, 1.5f);
	effect->Init();
	effect->SetEffectStart(m_obj->x, m_obj->y, false, 1.5);
	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>();
}

void CandleFanatic::Update()
{
	ImageResetCheck();
	if (m_effect == false)
	{
		m_vimage[eSatcrifice]->Reset();
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
	if (m_hit)
	{
		m_hpbartimer += DELTA_TIME;
	}
	if (m_isHit == true)
	{
		m_hitTimer += DELTA_TIME;
	}
	if (m_effect == true && m_die2 == false)
	{
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		m_collision->Setting(40, m_obj->x + 17, m_obj->y - 20, "Attack");
		if (m_isHit == false)
		{

			if ((abs(m_obj->x - OBJECTMANAGER->m_player->GetplayerX()) < 400) || m_state == eAttackReady || m_state == eAttack)
			{
				if (m_vimage[eAttackReady]->GetIsImageEnded() == true)
				{
					if (m_state == eAttackReady)
					{
						OBJECTMANAGER->AddObject("Knife", m_obj->x, m_obj->y - 100, eObject)->AddComponent<FireKnife>();
						m_isAttack = true;
					}
					m_state = eAttack;
					if (m_vimage[m_state]->GetIsImageEnded() == true)
					{
						m_vimage[eAttackReady]->Reset();
						m_vimage[eAttack]->Reset();
						m_vimage[eIdle]->Reset();
						m_state = eIdle;
					}
				}
				else
				{
					m_state = eAttackReady;
					m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
				}
			}
			else if (abs(m_obj->x - OBJECTMANAGER->m_player->GetplayerX()) < 600)
			{
				m_state = eRun;
				m_obj->x += DELTA_TIME * (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x ? 30 : -30);
				m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
			}
			else
			{
				m_state = eIdle;
			}
		}
		if (m_currenthp <= 30 && !m_die2)
		{
			m_sercrifice = true;
			m_state = eSatcrificeReady;
			if (m_vimage[eSatcrificeReady]->GetIsImageEnded())
			{
				m_state = eSatcrificeLoop;
				if (m_vimage[eSatcrificeLoop]->GetIsImageEnded())
				{

					if (!m_sercrieffect && 0 == m_isL)
					{
						EFFECTMANAGER->AddEffect<Secrifice>(m_obj->x + 50, m_obj->y - 20, 0, 1.5);
					}
					if (!m_sercrieffect && 1 == m_isL)
					{
						EFFECTMANAGER->AddEffect<Secrifice>(m_obj->x - 50, m_obj->y - 20, 1, 1.5);
					}
					m_sercrieffect = true;
					m_motiontimer += 0.1f;
					m_state = eSatcrifice;
					if (m_vimage[eSatcrifice]->GetIsImageEnded() == true)
					{
						m_collision->SetIsActive(false);
						OBJECTMANAGER->AddObject("Enemy", m_obj->x, m_obj->y, ObjectTag::eSummons)->AddComponent<TentaclesOfLight>();
						m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
						m_obj->GetComponent< PixelCollisionComponent>()->SetIsActive(false);
						m_die2 = true;
					}
				}
			}
		}
		m_hpbar = (1 / m_maxhp);
		m_hiteffecttimer += DELTA_TIME;
		m_dietimer += DELTA_TIME;
	}
}

void CandleFanatic::Render()
{
	if (m_effect == true)
	{
		if (m_currenthp > 0)
		{
			m_vimage[m_state]->CenterRender(m_obj->x, m_obj->y - 60, 2, 2, 0, m_isL);

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
			if (!m_die && m_dietimer >= 1 && m_die2 == false)
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
			if (m_dietimer >= 0.5f && m_die2 == false)
			{

				m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
				m_obj->GetComponent< PixelCollisionComponent>()->SetIsActive(false);
				m_collision->SetIsActive(false);
				m_obj->ObjectDestroyed();
			}

		}
	}
}

void CandleFanatic::Release()
{
}

void CandleFanatic::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			//m_attack = true;
			//m_move = false;
		}
	}
}


void CandleFanatic::HitEnemy(float dmg, float time)
{
	if (m_hiteffecttimer >= time)
	{
		m_isAttack = false;
		m_isHit = true;
		m_state = eHit;
		m_vimage[eAttackReady]->Reset();
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
void CandleFanatic::ImageResetCheck()
{
	if (m_isAttack == true && m_vimage[eAttack]->GetIsImageEnded() == true)
	{
		m_isAttack = false;
	}
	if (m_hitTimer >= 0.3f)
	{
		m_isHit = false;
		m_hitTimer = 0;
	}
}
