#include "stdafx.h"
#include "LampFanatic.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"

void LampFanatic::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Lfanatic_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eMass] = IMAGEMANAGER->FindImageVector("Lfanatic_Mass");
	m_vimage[eMass]->Setting(0.3f, true);

	m_vimage[eMassLoop] = IMAGEMANAGER->FindImageVector("Lfanatic_MassLoop");
	m_vimage[eMassLoop]->Setting(0.3f, true);

	m_vimage[eMassReady] = IMAGEMANAGER->FindImageVector("Lfanatic_MassReady");
	m_vimage[eMassReady]->Setting(0.3f, true);

	m_vimage[eMassReadyLoop] = IMAGEMANAGER->FindImageVector("Lfanatic_MassReadyLoop");
	m_vimage[eMassReadyLoop]->Setting(0.3f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("Lfanatic_Run");
	m_vimage[eRun]->Setting(0.3f, true);

	m_vimage[eSummonReady] = IMAGEMANAGER->FindImageVector("Lfanatic_SummonReady");
	m_vimage[eSummonReady]->Setting(0.3f, true);

	m_vimage[eSummons] = IMAGEMANAGER->FindImageVector("Lfanatic_Summons");
	m_vimage[eSummons]->Setting(0.3f, true);
}

void LampFanatic::Update()
{
}

void LampFanatic::Render()
{
	m_vimage[eIdle]->CenterRender((int)m_obj->x + 50, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eMass]->CenterRender((int)m_obj->x + 100, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eMassLoop]->CenterRender((int)m_obj->x + 150, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eMassReady]->CenterRender((int)m_obj->x + 200, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eMassReadyLoop]->CenterRender((int)m_obj->x + 250, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eRun]->CenterRender((int)m_obj->x + 300, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eSummonReady]->CenterRender((int)m_obj->x + 350, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
	m_vimage[eSummons]->CenterRender((int)m_obj->x + 350, (int)m_obj->y + 126, 1.5, 1.5, 0, 1);
}

void LampFanatic::Release()
{
}

void LampFanatic::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
}
