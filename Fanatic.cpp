#include "stdafx.h"
#include "Fanatic.h"

void Fanatic::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Fanaticidle");
	m_vimage[eIdle]->Setting(0.3f, true);
	
	m_vimage[eAttackIdle] = IMAGEMANAGER->FindImageVector("FanaticattackIdle");
	m_vimage[eAttackIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("Fanaticattack");
	m_vimage[eAttack]->Setting(0.3f, true);

	m_vimage[eRunAttack] = IMAGEMANAGER->FindImageVector("Fanaticrunattack");
	m_vimage[eRunAttack]->Setting(0.3f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("Fanaticrun");
	m_vimage[eRun]->Setting(0.3f, true);

	m_vimage[Setcrifice] = IMAGEMANAGER->FindImageVector("Fanaticsetcrifice");
	m_vimage[Setcrifice]->Setting(0.3f, true);
		

	m_vimage[SetcrificeLoop] = IMAGEMANAGER->FindImageVector("Fanaticsetcrificeloop");
	m_vimage[SetcrificeLoop]->Setting(0.3f, true);
	
	m_vimage[SetcrificeReady] = IMAGEMANAGER->FindImageVector("Fanaticsetcrificeready");
	m_vimage[SetcrificeReady]->Setting(0.3f, true);

	m_vimage[eHit] = IMAGEMANAGER->FindImageVector("Fanatichit");
	m_vimage[eHit]->Setting(0.3f, true);
	
}

void Fanatic::Update()
{
}

void Fanatic::Render()
{
	m_vimage[eIdle]->Render(WINSIZE_X / 2 + 50, WINSIZE_Y / 2+100, 1, 1, 0);
	m_vimage[eAttackIdle]->Render(WINSIZE_X / 2 + 50, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[eAttack]->Render(WINSIZE_X / 2 + 100, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[eRunAttack]->Render(WINSIZE_X / 2 + 150, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[eRun]->Render(WINSIZE_X / 2 + 200, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[Setcrifice]->Render(WINSIZE_X / 2 + 250, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[SetcrificeLoop]->Render(WINSIZE_X / 2 + 300, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[SetcrificeReady]->Render(WINSIZE_X / 2 + 350, WINSIZE_Y / 2 + 100, 1, 1, 0);
	m_vimage[eHit]->Render(WINSIZE_X / 2 + 400, WINSIZE_Y / 2 + 100, 1, 1, 0);
}

void Fanatic::Release()
{
}
