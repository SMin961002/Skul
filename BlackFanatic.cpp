#include "stdafx.h"
#include "BlackFanatic.h"

void BlackFanatic::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Bfanatic_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);
	
	m_vimage[eAttackIdle] = IMAGEMANAGER->FindImageVector("Bfanatic_AttackIdle");
	m_vimage[eAttackIdle]->Setting(0.3f, true);
	
	m_vimage[eRunAttack] = IMAGEMANAGER->FindImageVector("BFanatic_Runattack");
	m_vimage[eRunAttack]->Setting(0.3f, true);
	
	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("BFanatic_Run");
	m_vimage[eRun]->Setting(0.3f, true);
	m_state = 0;
}

void BlackFanatic::Update()
{
}

void BlackFanatic::Render()
{
	m_vimage[m_state]->Render(WINSIZE_X / 2 + 50, WINSIZE_Y / 2 - 50, 2, 2, 0);
}

void BlackFanatic::Release()
{
}
