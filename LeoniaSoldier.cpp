#include "stdafx.h"
#include "LeoniaSoldier.h"

void LeoniaSoldier::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("leonidle");
	m_vimage[eIdle]->Setting(0.3f,true);
	
	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("leonattack");
	m_vimage[eAttack]->Setting(0.8f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("leonrun");
	m_vimage[eRun]->Setting(0.8f, true);
}

void LeoniaSoldier::Update()
{

}

void LeoniaSoldier::Render()
{
	m_vimage[eIdle]->Render(WINSIZE_X / 2, WINSIZE_Y / 2,1,1,0);
	m_vimage[eAttack]->Render(WINSIZE_X / 2+100, WINSIZE_Y / 2, 1, 1, 0);
}

void LeoniaSoldier::Release()
{

}
