#include "stdafx.h"
#include "TentaclesOfLight.h"
#include "CollisionComponent.h"
#include "Player.h"
#include "PixelCollisionComponent.h"

void TentaclesOfLight::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Tentacles_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("Tentacles_Attack");
	m_vimage[eAttack]->Setting(0.3f, true);

	m_vimage[eRecovery] = IMAGEMANAGER->FindImageVector("Tntackles_Recovery");
	m_vimage[eRecovery]->Setting(0.3f, true);
}

void TentaclesOfLight::Update()
{
}

void TentaclesOfLight::Render()
{
	m_vimage[eIdle]->CenterRender((int)m_obj->x, (int)m_obj->y + 56, 1.5, 1.5, 0, 1);
	m_vimage[eAttack]->CenterRender((int)m_obj->x+50, (int)m_obj->y + 26, 1.5, 1.5, 0, 1);
	m_vimage[eRecovery]->CenterRender((int)m_obj->x+100, (int)m_obj->y + 26, 1.5, 1.5, 0, 1);
}

void TentaclesOfLight::Release()
{
}

void TentaclesOfLight::OnCollision(string collisionName, Object* other)
{
}
