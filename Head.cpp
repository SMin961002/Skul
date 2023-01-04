#include "stdafx.h"
#include "Head.h"
#include "RigidBodyComponent.h"
//#include "Player.h"

void Head::Init()
{
	ImageSetting();
	ParameterSetting();
	CollisionSetting();
}

void Head::Update()
{
	m_imageChange = false;

	CoolDown();
	if (!m_skillUsing)	//스킬 끝날 때까지 다른 동작이 들어가지 못하게 하기 위함
	{
		Move();
		Act();
	}
	ActionArrangement();
	CollisionUpdate();
}

void Head::Render()
{
	DrawCharactor();
}

void Head::Release()
{
}

void Head::Move()
{
}

void Head::Act()
{
	if (m_attackCount < m_attackMax)
	{
		InputAttackKey();
	}
	InputSkillKey();
}


void Head::DrawCharactor()
{
	nowImg->CenterRender(*m_x, *m_y, 2, 2, 0, *m_isLeft);
}
