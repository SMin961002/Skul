#include "stdafx.h"
#include "CandleFanatic.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "FireKnife.h"

void CandleFanatic::Init()
{
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
	m_state = eIdle;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	m_obj->AddComponent<RigidBodyComponent>();
}

void CandleFanatic::Update()
{
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
}

void CandleFanatic::Render()
{
	m_vimage[m_state]->CenterRender(m_obj->x, m_obj->y-60, 2, 2, 0, m_isL);
}

void CandleFanatic::Release()
{
}

void CandleFanatic::OnCollision(string collisionName, Object* other)
{
}
