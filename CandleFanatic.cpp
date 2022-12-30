#include "stdafx.h"
#include "CandleFanatic.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"

void CandleFanatic::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Cfanatic_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttackReady] = IMAGEMANAGER->FindImageVector("Cfanatic_AttackReady");
	m_vimage[eAttackReady]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("Cfanatic_Attack");
	m_vimage[eAttack]->Setting(0.3f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("Cfanatic_Run");
	m_vimage[eRun]->Setting(0.3f, true);

	m_vimage[eHit] = IMAGEMANAGER->FindImageVector("Cfanatic_Hit");
	m_vimage[eHit]->Setting(0.3f, true);

	m_vimage[eSatcrifice] = IMAGEMANAGER->FindImageVector("Cfanatic_Satcrifice");
	m_vimage[eSatcrifice]->Setting(0.3f, true);

	m_vimage[eSatcrificeReady] = IMAGEMANAGER->FindImageVector("Cfanatic_SatcrificeReady");
	m_vimage[eSatcrificeReady]->Setting(0.3f, true);

	m_vimage[eSatcrificeLoop] = IMAGEMANAGER->FindImageVector("Cfanatic_SatcrificeLoop");
	m_vimage[eSatcrificeLoop]->Setting(0.3f, true);
}

void CandleFanatic::Update()
{
}

void CandleFanatic::Render()
{
	m_vimage[eIdle]->CenterRender((int)m_obj->x, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eAttackReady]->CenterRender((int)m_obj->x+50, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eAttack]->CenterRender((int)m_obj->x+100, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eRun]->CenterRender((int)m_obj->x+150, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eHit]->CenterRender((int)m_obj->x+200, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eSatcrifice]->CenterRender((int)m_obj->x+250, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eSatcrificeReady]->CenterRender((int)m_obj->x+300, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
	m_vimage[eSatcrificeLoop]->CenterRender((int)m_obj->x+350, (int)m_obj->y - 26, 1.5, 1.5, 0, 1);
}

void CandleFanatic::Release()
{
}

void CandleFanatic::OnCollision(Object* other)
{
}
