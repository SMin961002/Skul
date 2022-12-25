#include "stdafx.h"
#include "LeoniaSoldier.h"

void LeoniaSoldier::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("leonidle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("leonattack");
	m_vimage[eAttack]->Setting(0.1f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("leonrun");
	m_vimage[eRun]->Setting(0.1f, true);
}

void LeoniaSoldier::Update()
{

}

void LeoniaSoldier::Render()
{
	if (KEYMANAGER->GetToggleKey(VK_F2))
	{
		m_vimage[eIdle]->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1, 1, 0);
		m_vimage[eAttack]->CenterRender(WINSIZE_X / 2 + 100, WINSIZE_Y / 2, 1, 1, 0);
	}
	else
	{

		m_vimage[eIdle]->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1, 1, 0,true);
		m_vimage[eAttack]->CenterRender(WINSIZE_X / 2 + 100, WINSIZE_Y / 2, 1, 1, 0,true);
	}
}

void LeoniaSoldier::Release()
{

}
