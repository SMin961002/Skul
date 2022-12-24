#include "stdafx.h"
#include "LobbyScene.h"
#include "Player.h"
LobbyScene::LobbyScene()
{
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	OBJECTMANAGER->AddObject("Example",WINSIZE_X/2,400,0)->AddComponent<Player>();
}

void LobbyScene::Update()
{
}

void LobbyScene::Render()
{
	IMAGEMANAGER->Render(IMAGEMANAGER->FindImage("Frame_1SKill"), WINSIZE_X / 2, WINSIZE_Y/2);

	TIMERMANAGER->Render();
}

void LobbyScene::Release()
{
}
