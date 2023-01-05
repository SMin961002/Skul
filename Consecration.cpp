#include "stdafx.h"
#include "Consecration.h"

void Consecration::Init()
{
	_imgPhase1BossConsecrationLoop = IMAGEMANAGER->FindImageVector("Boss_Consecration_Loop");
	_imgPhase1BossConsecrationLoop->Setting(0.1, true);
}

void Consecration::Update()
{
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_obj->x -= 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_obj->x += 3;
	}

	if (_deltaTime > 2)
	{
		m_obj->ObjectDestroyed();
	}
}

void Consecration::Render()
{
	_imgPhase1BossConsecrationLoop->CenterRender(m_obj->x, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	_deltaTime += DELTA_TIME;
}

void Consecration::Release()
{
}
