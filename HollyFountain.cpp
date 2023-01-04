#include "stdafx.h"
#include "HollyFountain.h"

void HollyFountain::Init()
{
	_imgFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgFountainActivate->Setting(0.1, true);

	_imgOrbStart = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Start");
	_imgFountainActivate->Setting(0.1, true);

	_imgOrbActing = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Orb");
	_imgOrbActing->Setting(0.1, true);

	_imgOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End");
}

void HollyFountain::Update()
{
}

void HollyFountain::Render()
{
	IMAGEMANAGER->CenterRender(_imgFountainDeActivate, 100, WINSIZE_Y - 100, 1.5, 1.5, 0, false);
	IMAGEMANAGER->CenterRender(_imgFountainDeActivate, WINSIZE_X - 100, WINSIZE_Y - 100, 1.5, 1.5, 0, false);
	_imgOrbStart->CenterRender(200, WINSIZE_Y - 100, 1, 1, 0, false);
	_imgOrbStart->CenterRender(WINSIZE_X - 200, WINSIZE_Y - 100, 1, 1, 0, false);

	_imgFountainActivate->CenterRender(100, WINSIZE_Y - 200, 1.5, 1.5, 0, false);
	_imgFountainActivate->CenterRender(WINSIZE_X - 100, WINSIZE_Y - 200, 1.5, 1.5, 0, false);
	_imgOrbActing->CenterRender(200, WINSIZE_Y - 200, 1.0, 1.0, 0, false);
	_imgOrbActing->CenterRender(WINSIZE_X - 200, WINSIZE_Y - 200, 1.0, 1.0, 0, false);
}

void HollyFountain::Release()
{
}
