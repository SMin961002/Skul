#include "stdafx.h"
#include "CandleFanatic.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "FireKnife.h"
#include"BlackRock.h"
#include"Gold.h"
#include"Effect.h"

void CandleFanatic::Init()
{
	m_maxhp = 100.0f;
	m_currenthp = 100.0f;
	m_isL = false;
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
	effect = new Appear;
	effect->Init();
	effect->SetObject(m_obj);
	effect->SetEffectStart(m_obj->x, m_obj->y, false, 1.5);
	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>();
}

void CandleFanatic::Update()
{
	if (m_effect == false)
	{
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	}
	if (effect->GetIsEffectEnded())
	{
		m_effect = true;
	}
	
	if (m_effect == true)
	{
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
		m_collision->Setting(40, m_obj->x + 17, m_obj->y - 20, "Attack");
		if ((abs(m_obj->x - OBJECTMANAGER->m_player->GetplayerX()) < 400) || m_state == eAttackReady || m_state == eAttack)
		{
			if (m_vimage[eAttackReady]->GetIsImageEnded() == true)
			{
				if (m_state == eAttackReady)
				{
					OBJECTMANAGER->AddObject("Knife", m_obj->x, m_obj->y - 100, eObject)->AddComponent<FireKnife>();
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
		m_hpbar = (1 / m_maxhp);
		m_hiteffecttimer += DELTA_TIME;
	}
	cout << m_currenthp << endl;
	
}

void CandleFanatic::Render()
{
	effect->Render();
	if (m_effect == true)
	{
		m_vimage[m_state]->CenterRender(m_obj->x, m_obj->y - 60, 2, 2, 0, m_isL);
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
			//other->GetComponent<Player>()-플레이어 상태쉉
			m_attack = true;
			m_move = false;
		}
	}

}

void CandleFanatic::HitEnemy(float dmg)
{
	if (m_hiteffecttimer >= 0.7f)
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
