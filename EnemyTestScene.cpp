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
	m_speed = 0;
	m_backGround = IMAGEMANAGER->FindImage("Background");
	m_castle = IMAGEMANAGER->FindImage("Castle");
	m_cloude = IMAGEMANAGER->FindImage("Cloud");

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
	m_speed += 100 * DELTA_TIME;
	float RenderPos = (int)m_speed % (m_cloude->GetWidth() * 2);
	IMAGEMANAGER->Render(m_backGround, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
	IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
	IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos + (m_cloude->GetWidth() * 2), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
	IMAGEMANAGER->Render(m_castle, IMAGEMANAGER->GetCameraPosition().x * 0.9, IMAGEMANAGER->GetCameraPosition().y - 100, 2, 2);

	IMAGEMANAGER->DrawMapStructureBack(m_sturctDatas);

	IMAGEMANAGER->DrawMapTile(m_tiles);

	IMAGEMANAGER->DrawMapStructureFoward(m_sturctDatas);

	if (KEYMANAGER->GetToggleKey(VK_F2))
	{
		IMAGEMANAGER->DrawMapTilePixel(m_tiles);
	}

}

void EnemyTestScene::Release()
{
	for (auto iter : m_sturctDatas)
	{
		SAFE_DELETE(iter);
	}
	m_sturctDatas.clear();
}
