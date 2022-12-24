#include "stdafx.h"
#include "LobbyScene.h"
#include "Player.h"
#include"LeoniaSoldier.h"
LobbyScene::LobbyScene()
{
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	OBJECTMANAGER->AddObject("Example",WINSIZE_X/2,400,0)->AddComponent<Player>();
	OBJECTMANAGER->AddObject("Enemy", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<LeoniaSoldier>();
	img = IMAGEMANAGER->FindImage("Frame_1SKill");
}

void LobbyScene::Update()
{
}

void LobbyScene::Render()
{
	IMAGEMANAGER->Render(img, WINSIZE_X / 2, WINSIZE_Y/2);
	IMAGEMANAGER->CenterRender(img, WINSIZE_X / 2, WINSIZE_Y / 2,1,1,90);

	TIMERMANAGER->Render();
}

void LobbyScene::Release()
{
}