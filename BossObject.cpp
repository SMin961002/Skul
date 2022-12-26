#include "stdafx.h"
#include "BossObject.h"

void BossObject::Init()
{
	_imgBoss = IMAGEMANAGER->FindImageVector("Boss_Idle");
	_imgBoss->Setting(0.1, true);
}

void BossObject::Update()
{
	Pattern();
}

void BossObject::Render()
{
	_imgBoss->Render(WINSIZE_X/2, WINSIZE_Y/1.5, 1, 1, 0);
}

void BossObject::Release()
{
}

void BossObject::Pattern()
{
}
