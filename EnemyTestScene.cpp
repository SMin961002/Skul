#include "stdafx.h"
#include "EnemyTestScene.h"
#include "Player.h"
EnemyTestScene::EnemyTestScene()
{
}

EnemyTestScene::~EnemyTestScene()
{
}

void EnemyTestScene::Init()
{
	FILEMANAGER->SetNowStageFile("map_0");
	FILEMANAGER->TileFileRead(&m_tiles);

	string strData;
	strData = FILEMANAGER->GetFileData("Structure", "batch");
	MY_UTILITY::ConvertStructureString2Vec(&m_sturctDatas, strData);

	OBJECTMANAGER->AddObject("player", 200, 200, ePlayer)->AddComponent<Player>();
}

void EnemyTestScene::Update()
{
}

void EnemyTestScene::Render()
{
	IMAGEMANAGER->Render(IMAGEMANAGER->FindImage("exBg"), IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 1);

	IMAGEMANAGER->DrawMapStructureBack(m_sturctDatas);

	IMAGEMANAGER->DrawMapTile(m_tiles);

	IMAGEMANAGER->DrawMapStructureFoward(m_sturctDatas);

}

void EnemyTestScene::Release()
{
}
