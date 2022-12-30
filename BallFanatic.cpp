#include "stdafx.h"
#include "BallFanatic.h"

void BallFanatic::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Befanatic_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);
	
	m_vimage[eSacrifice] = IMAGEMANAGER->FindImageVector("Befanatic_Sacrifice");
	m_vimage[eSacrifice]->Setting(0.3f, true);
	
	m_vimage[eSacrificeLoop] = IMAGEMANAGER->FindImageVector("Befanatic_SacrificeLoop");
	m_vimage[eSacrificeLoop]->Setting(0.3f, true);
	
	m_vimage[eSummonLoop] = IMAGEMANAGER->FindImageVector("Befanatic_SummonLoop");
	m_vimage[eSummonLoop]->Setting(0.3f, true);

	m_vimage[eSummonReady] = IMAGEMANAGER->FindImageVector("Befanatic_SummonReady");
	m_vimage[eSummonReady]->Setting(0.3f, true);
}

void BallFanatic::Update()
{
}

void BallFanatic::Render()
{
	m_vimage[eIdle]->CenterRender((int)m_obj->x + 50, (int)m_obj->y + 226, 1.5, 1.5, 0, 1);
	m_vimage[eSacrifice]->CenterRender((int)m_obj->x + 100, (int)m_obj->y + 226, 1.5, 1.5, 0, 1);
	m_vimage[eSacrificeLoop]->CenterRender((int)m_obj->x + 150, (int)m_obj->y + 226, 1.5, 1.5, 0, 1);
	m_vimage[eSummonLoop]->CenterRender((int)m_obj->x + 200, (int)m_obj->y + 226, 1.5, 1.5, 0, 1);
	m_vimage[eSummonReady]->CenterRender((int)m_obj->x + 250, (int)m_obj->y + 226, 1.5, 1.5, 0, 1);
}

void BallFanatic::Release()
{
}

void BallFanatic::OnCollision(Object* other)
{
}
