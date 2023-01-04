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
	if (!m_skillUsing)	//��ų ���� ������ �ٸ� ������ ���� ���ϰ� �ϱ� ����
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
