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
	m_state = 0;
}

void AngelStatue::Update()
{
}

void AngelStatue::Render()
{
	m_vimage[m_state]->CenterRender((int)m_obj->x, (int)m_obj->y, 2, 2, 0, 1);
}

void AngelStatue::Release()
{
}

void AngelStatue::OnCollision(string collisionName, Object* other)
{
}
