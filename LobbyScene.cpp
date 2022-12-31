#include "stdafx.h"
#include "LobbyScene.h"
#include "Player.h"
#include"LeoniaSoldier.h"
#include"Fanatic.h"
#include"BlackFanatic.h"
LobbyScene::LobbyScene()
{
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	OBJECTMANAGER->AddObject("Example", WINSIZE_X / 2, WINSIZE_Y / 2, 0)->AddComponent<Player>();
	OBJECTMANAGER->AddObject("Enemy", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<LeoniaSoldier>();
	OBJECTMANAGER->AddObject("Enemy2", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<Fanatic>();
	OBJECTMANAGER->AddObject("Enemy3", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<BlackFanatic>();
	img = IMAGEMANAGER->FindImage("Frame_1SKill");
}

void LobbyScene::Update()
{
}

void LobbyScene::Render()
{
	IMAGEMANAGER->Render(img, WINSIZE_X / 2, WINSIZE_Y / 2);
	//IMAGEMANAGER->CenterRender(img, WINSIZE_X / 2, WINSIZE_Y / 2,1,1,90);
	TIMERMANAGER->Render();
}

void LobbyScene::Release()
{
}
