#include "stdafx.h"
#include "BlackFanatic.h"

void BlackFanatic::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Bfanaticidle");
	m_vimage[eIdle]->Setting(0.3f, true);
	
	m_vimage[eAttackIdle] = IMAGEMANAGER->FindImageVector("BfanaticattackIdle");
	m_vimage[eAttackIdle]->Setting(0.3f, true);
	
	m_vimage[eRunAttack] = IMAGEMANAGER->FindImageVector("BFanaticrunattack");
	m_vimage[eRunAttack]->Setting(0.3f, true);
	
	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("BFanaticrun");
	m_vimage[eRun]->Setting(0.3f, true);
}

void BlackFanatic::Update()
{
}

void BlackFanatic::Render()
{
	m_vimage[eIdle]->Render(WINSIZE_X / 2 + 50, WINSIZE_Y / 2 - 50, 1, 1, 0);
	m_vimage[eAttackIdle]->Render(WINSIZE_X / 2 + 100, WINSIZE_Y / 2 - 50, 1, 1, 0);
	m_vimage[eRunAttack]->Render(WINSIZE_X / 2 + 150, WINSIZE_Y / 2 - 50, 1, 1, 0);
	m_vimage[eRun]->Render(WINSIZE_X / 2 + 200, WINSIZE_Y / 2 - 50, 1, 1, 0);
}

void BlackFanatic::Release()
{
}
