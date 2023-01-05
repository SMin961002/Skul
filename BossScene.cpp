#include "stdafx.h"
#include "BossScene.h"
#include "BossObject.h"
#include "HolyFountain.h"
#include "Player.h"
#include "BossPhase1EnemyCandle.h"
#include "BossPhase1EnemyFnatic.h"

void BossScene::Init()
{
	_imgMoon = IMAGEMANAGER->FindImage("Moon");
	_imgBuilding = IMAGEMANAGER->FindImage("Building");
	_imgLion = IMAGEMANAGER->FindImage("Lion");
	_imgFence = IMAGEMANAGER->FindImage("Fence");

	
	OBJECTMANAGER->AddObject("Joanna", 850, 475, 0)->AddComponent<BossObject>();

	OBJECTMANAGER->AddObject("FountainLeft", 100, 580, 0)->AddComponent<HolyFountainLeft>();
	OBJECTMANAGER->AddObject("FountainRight", 1500, 580, 0)->AddComponent<HolyFountainRight>();

	FILEMANAGER->SetNowStageFile("map_1");
	FILEMANAGER->TileFileRead(&SCENEMANAGER->m_tiles);

	string strData;
	strData = FILEMANAGER->GetFileData("Structure", "batch");
	MY_UTILITY::ConvertStructureString2Vec(&m_sturctDatas, strData);

	string strData2;
	strData2 = FILEMANAGER->GetFileData("Object", "batch");
	MY_UTILITY::ConvertStructureString2Vec(&m_objectDatas, strData2);

	for (auto iter : m_objectDatas)
	{
		if (iter->key == "Basic")
		{
			OBJECTMANAGER->AddObject("player", iter->x, iter->y, ePlayer)->AddComponent<Player>();
		}
	}

	OBJECTMANAGER->AddObject("Enemy", 500, 670, eEnemy)->AddComponent<BossPhase1EnemyCandle>();
	OBJECTMANAGER->AddObject("Enemy", 600, 670, eEnemy)->AddComponent<BossPhase1EnemyFnatic>();


}

void BossScene::Update()
{
	Vector2 v;
	float a = (150 + IMAGEMANAGER->GetCameraPosition().y + WINSIZE_Y * 0.5f) - (OBJECTMANAGER->m_player->GetplayerY());
	if (a > 150 || a < -0.1f)
	{
		Vector2 v2;
		MY_UTILITY::GetLerpVec2(&v, { OBJECTMANAGER->m_player->GetplayerX() - WINSIZE_X / 2,OBJECTMANAGER->m_player->GetplayerY() - WINSIZE_Y / 2 - 150 }, { IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y }, 0.96f);
		MY_UTILITY::GetLerpVec2(&v2, { OBJECTMANAGER->m_player->GetplayerX() - WINSIZE_X / 2,IMAGEMANAGER->GetCameraPosition().y }, { IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y }, 0.5);
		v.x = v2.x;
	}
	else
	{
		MY_UTILITY::GetLerpVec2(&v, { OBJECTMANAGER->m_player->GetplayerX() - WINSIZE_X / 2,IMAGEMANAGER->GetCameraPosition().y }, { IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y }, 0.5);
	}
	IMAGEMANAGER->SetCameraPosition(v.x, v.y);
	if (IMAGEMANAGER->GetCameraPosition().x <= 0)
	{
		IMAGEMANAGER->SetCameraPosition(0, IMAGEMANAGER->GetCameraPosition().y);
	}
	if (IMAGEMANAGER->GetCameraPosition().x >= WINSIZE_X / 2 - 50)
	{
		IMAGEMANAGER->SetCameraPosition(WINSIZE_X / 2-50, IMAGEMANAGER->GetCameraPosition().y);
	}
	cout << IMAGEMANAGER->GetCameraPosition().x - WINSIZE_X / 2 << endl;
}

void BossScene::Render()
{
	IMAGEMANAGER->Render(_imgMoon, 0, -350, 1.5f, 1.5f, 0);
	IMAGEMANAGER->Render(_imgBuilding, 0, -350, 1.5f, 1.5f, 0);
	IMAGEMANAGER->Render(_imgFence, 0, 520, 1.5f, 1.5f, 0);
	IMAGEMANAGER->Render(_imgLion, 0, -350, 1.5f, 1.5f, 0);

	IMAGEMANAGER->DrawMapStructureBack(m_sturctDatas);

	IMAGEMANAGER->DrawMapTile(SCENEMANAGER->m_tiles);

	IMAGEMANAGER->DrawMapStructureFoward(m_sturctDatas);


}

void BossScene::Release()
{
	SCENEMANAGER->m_tiles.clear();
	for (auto iter : m_sturctDatas)
	{
		SAFE_DELETE(iter);
	}
	m_sturctDatas.clear();

	for (auto iter : m_objectDatas)
	{
		SAFE_DELETE(iter);
	}
	m_objectDatas.clear();
}
