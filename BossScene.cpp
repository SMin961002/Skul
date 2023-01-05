#include "stdafx.h"
#include "BossScene.h"
#include "BossObject.h"
#include "HolyFountain.h"

void BossScene::Init()
{
	_imgMoon = IMAGEMANAGER->FindImage("Moon");
	_imgBuilding = IMAGEMANAGER->FindImage("Building");
	_imgLion = IMAGEMANAGER->FindImage("Lion");
	_imgFence = IMAGEMANAGER->FindImage("Fence");

	OBJECTMANAGER->AddObject("Joanna", WINSIZE_X / 2, 400, 0)->AddComponent<BossObject>();

	OBJECTMANAGER->AddObject("FountainLeft", 300, 400, 0)->AddComponent<HolyFountainLeft>();
	OBJECTMANAGER->AddObject("FountainRight", 300, 400, 0)->AddComponent<HolyFountainRight>();
}

void BossScene::Update()
{
}

void BossScene::Render()
{
	IMAGEMANAGER->Render(_imgMoon, 0, 0, 1, 1, 0);
	IMAGEMANAGER->Render(_imgBuilding, 0, 0, 1, 1, 0);
	IMAGEMANAGER->Render(_imgLion, 0, 0, 1, 1, 0);
	IMAGEMANAGER->Render(_imgFence, 0, 0, 1, 1, 0);
}

void BossScene::Release()
{
}
