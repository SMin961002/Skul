#include "stdafx.h"
#include "Idle.h"

void Idle::Init()
{
	_imgBoss = IMAGEMANAGER->FindImageVector("Boss_Idle");
	_imgBoss->Setting(0.1, true);

}

void Idle::Update()
{
}

void Idle::Render()
{
	_imgBoss->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 91.5 * 2, 2, 2, 0, false);
}

void Idle::Release()
{
}
