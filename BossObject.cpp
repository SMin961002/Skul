#include "stdafx.h"
#include "BossObject.h"

void BossObject::Init()
{
	_imgBoss = IMAGEMANAGER->FindImageVector("Boss");
	_imgBoss->Setting(0.1, true);

}

void BossObject::Update()
{

}

void BossObject::Render()
{
	_imgBoss->Render(WINSIZE_X/2, WINSIZE_Y/1.5, 1, 1, 0);

	TIMERMANAGER->Render();

}

void BossObject::Release()
{
}
