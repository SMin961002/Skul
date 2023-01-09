#include "stdafx.h"
#include "Worship.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"

void WorshipLeft::Init()
{
	_imgPhase1BossWorshipLeft = IMAGEMANAGER->FindImageVector("Boss_Worship");
	_imgPhase1BossWorshipLeft->Setting(0.1, true);

	_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision);

}

void WorshipLeft::Update()
{
	m_obj->x += 3;

	if (m_obj->x > 1800)
	{
		m_obj->ObjectDestroyed();
	}

	_collision->Setting(100, m_obj->x, m_obj->y, "Attack");
}

void WorshipLeft::Render()
{
	_imgPhase1BossWorshipLeft->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
}

void WorshipLeft::Release()
{
}

void WorshipRight::Init()
{
	_imgPhase1BossWorshipRight = IMAGEMANAGER->FindImageVector("Boss_Worship");
	_imgPhase1BossWorshipRight->Setting(0.1, true);
	
	_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collision);
}

void WorshipRight::Update()
{
	m_obj->x -= 3;

	if (m_obj->x < 0)
	{
		m_obj->ObjectDestroyed();
	}
	_collision->Setting(100, m_obj->x, m_obj->y, "Attack");

}

void WorshipRight::Render()
{
	_imgPhase1BossWorshipRight->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, true);
}

void WorshipRight::Release()
{
}
