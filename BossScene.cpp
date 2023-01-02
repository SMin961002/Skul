#include "stdafx.h"
#include "BossScene.h"
#include "BossObject.h"
#include "HollyFountain.h"

void BossScene::Init()
{
	_imgMoon = IMAGEMANAGER->FindImage("Moon");
	_imgBuilding = IMAGEMANAGER->FindImage("Building");
	_imgLion = IMAGEMANAGER->FindImage("Lion");

	OBJECTMANAGER->AddObject("Joanna", WINSIZE_X / 2, 400, 0)->AddComponent<BossObject>();
	//OBJECTMANAGER->AddObject("Fountain", 300, 400, 0)->AddComponent<HollyFountain>();
}

void BossScene::Update()
{
}

void BossScene::Render()
{
	IMAGEMANAGER->Render(_imgMoon, 0, 0, 1, 1, 0);
	IMAGEMANAGER->Render(_imgBuilding, 0, 0, 1, 1, 0);
	IMAGEMANAGER->Render(_imgLion, 0, 0, 1, 1, 0);
}

void BossScene::Release()
{
}
