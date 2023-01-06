#include "stdafx.h"
#include "HolyFountain.h"

void HolyFountainLeft::Init()
{
	_imgLeftFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgLeftFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgLeftFountainActivate->Setting(0.1, true);

	_imgLeftOrbStart = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Start");
	_imgLeftOrbStart->Setting(0.05, false);

	_imgLeftOrbActing = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Orb");
	_imgLeftOrbActing->Setting(0.1, true);

	_imgLeftOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End");

	_isLeftPlayOn = false;
	_isLeftOrbActing = false;
}

void HolyFountainLeft::Update()
{
	if (KEYMANAGER->GetToggleKey('Z'))
	{
		_isLeftPlayOn = true;
	}
}

void HolyFountainLeft::Render()
{
	if (_isLeftPlayOn == false)
	{
		IMAGEMANAGER->CenterRender(_imgLeftFountainDeActivate, 100, WINSIZE_Y / 2 + 120, 2, 2, 0, false);
	}
	if (_isLeftPlayOn == true)
	{
		if (_isLeftOrbActing == false)
		{
			_imgLeftOrbStart->CenterRender(100, WINSIZE_Y / 2 - 30, 2, 2, 0, false);
		}

		_imgLeftFountainActivate->CenterRender(100, WINSIZE_Y / 2 + 120, 2, 2, 0, false);
	}
	if (_imgLeftOrbStart->GetIsImageEnded() == true)
	{
		_imgLeftOrbActing->CenterRender(98, WINSIZE_Y / 2 - 28, 2, 2, 0, false);

		_isLeftOrbActing = true;
	}
}

void HolyFountainLeft::Release()
{

}

void HolyFountainRight::Init()
{
	_imgRightFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgRightFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgRightFountainActivate->Setting(0.1, true);

	_imgRightOrbStart = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Start");
	_imgRightOrbStart->Setting(0.05, false);

	_imgRightOrbActing = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Orb");
	_imgRightOrbActing->Setting(0.1, true);

	_imgRightOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End");

	_isRightPlayOn = false;
	_isRightOrbActing = false;
}

void HolyFountainRight::Update()
{
	if (KEYMANAGER->GetToggleKey('X'))
	{
		_isRightPlayOn = true;
	}
}

void HolyFountainRight::Render()
{
	if (_isRightPlayOn == false)
	{
		IMAGEMANAGER->CenterRender(_imgRightFountainDeActivate, WINSIZE_X - 100, WINSIZE_Y / 2 + 120, 2, 2, 0, false);
	}
	if (_isRightPlayOn == true)
	{
		if (_isRightOrbActing == false)
		{
			_imgRightOrbStart->CenterRender(WINSIZE_X - 100, WINSIZE_Y / 2 - 30, 2, 2, 0, false);
		}

		_imgRightFountainActivate->CenterRender(WINSIZE_X - 100, WINSIZE_Y / 2 + 120, 2, 2, 0, false);
	}
	if (_imgRightOrbStart->GetIsImageEnded() == true)
	{
		_imgRightOrbActing->CenterRender(WINSIZE_X - 102, WINSIZE_Y / 2 - 28, 2, 2, 0, false);

		_isRightOrbActing = true;
	}
}

void HolyFountainRight::Release()
{
}
