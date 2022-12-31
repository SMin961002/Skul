#include "stdafx.h"
#include "AngelStatue.h"

void AngelStatue::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("AStatue_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);
	
	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("AStatue_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	
	m_vimage[eEndAttack] = IMAGEMANAGER->FindImageVector("AStatue_End");
	m_vimage[eEndAttack]->Setting(0.1f, true);
}

void AngelStatue::Update()
{
}

void AngelStatue::Render()
{
	m_vimage[eIdle]->CenterRender((int)m_obj->x + 50, (int)m_obj->y - 126, 1.5, 1.5, 0, 1);
	m_vimage[eAttack]->CenterRender((int)m_obj->x + 100, (int)m_obj->y - 126, 1.5, 1.5, 0, 1);
	m_vimage[eEndAttack]->CenterRender((int)m_obj->x + 150, (int)m_obj->y - 126, 1.5, 1.5, 0, 1);
}

void AngelStatue::Release()
{
}

void AngelStatue::OnCollision(string collisionName, Object* other)
{
}
