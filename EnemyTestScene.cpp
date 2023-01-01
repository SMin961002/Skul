#include "stdafx.h"
#include "EnemyTestScene.h"
#include "Player.h"
#include"LeoniaSoldier.h"
#include"CandleFanatic.h"
#include"TentaclesOfLight.h"
#include "Fanatic.h"
#include"LampFanatic.h"
#include"BallFanatic.h"
#include"AngelStatue.h"
EnemyTestScene::EnemyTestScene()
{
}

EnemyTestScene::~EnemyTestScene()
{
}

void EnemyTestScene::Init()
{
	m_speed = 0;
	m_backGround = IMAGEMANAGER->FindImage("Background");
	m_castle = IMAGEMANAGER->FindImage("Castle");
	m_cloude = IMAGEMANAGER->FindImage("Cloud");

	FILEMANAGER->SetNowStageFile("map_0");
	FILEMANAGER->TileFileRead(&SCENEMANAGER->m_tiles);

	string strData;
	strData = FILEMANAGER->GetFileData("Structure", "batch");
	MY_UTILITY::ConvertStructureString2Vec(&m_sturctDatas, strData);

	OBJECTMANAGER->AddObject("player", 500, -100, ePlayer)->AddComponent<Player>();
	for (int i = 0; i < 5; i++)
	{
	OBJECTMANAGER->AddObject("Enemy", WINSIZE_X / 2 + (100*i), 180, ObjectTag::eEnemy)->AddComponent<LeoniaSoldier>();
	}
	for (int i = 0; i < 5; i++)
	{
		OBJECTMANAGER->AddObject("Enemy", WINSIZE_X / 2 + (200*i), 180, ObjectTag::eEnemy)->AddComponent<Fanatic>();
	}
	
	//BJECTMANAGER->AddObject("Enemy2", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<CandleFanatic>();
	//OBJECTMANAGER->AddObject("Enemy3", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<TentaclesOfLight>();
	//OBJECTMANAGER->AddObject("Enemy4", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<LampFanatic>();
	//BJECTMANAGER->AddObject("Enemy5", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<BallFanatic>();
	//OBJECTMANAGER->AddObject("Enemy6", WINSIZE_X / 2, WINSIZE_Y / 2, ObjectTag::eEnemy)->AddComponent<AngelStatue>();
}

void EnemyTestScene::Update()
{
}

void EnemyTestScene::Render()
{
	m_speed += 100 * DELTA_TIME;
	float RenderPos = (int)m_speed % (m_cloude->GetWidth() * 2);
	IMAGEMANAGER->Render(m_backGround, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
	IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
	IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos + (m_cloude->GetWidth() * 2), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
	IMAGEMANAGER->Render(m_castle, IMAGEMANAGER->GetCameraPosition().x * 0.9, IMAGEMANAGER->GetCameraPosition().y - 100, 2, 2);

	IMAGEMANAGER->DrawMapStructureBack(m_sturctDatas);

	IMAGEMANAGER->DrawMapTile(SCENEMANAGER->m_tiles);

	IMAGEMANAGER->DrawMapStructureFoward(m_sturctDatas);

	if (IMAGEMANAGER->GetViewCollision())
	{
		IMAGEMANAGER->DrawMapTilePixel(SCENEMANAGER->m_tiles);
	}

	IMAGEMANAGER->DrawColorRender(m_backGround, WINSIZE_X / 2, WINSIZE_Y / 2, 2, 2, 0, false, { 255,0,255,0.5 });
}

void EnemyTestScene::Release()
{
	SCENEMANAGER->m_tiles.clear();
	for (auto iter : m_sturctDatas)
	{
		SAFE_DELETE(iter);
	}
	m_sturctDatas.clear();
}
