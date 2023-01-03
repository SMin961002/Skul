#include "stdafx.h"
#include "ShopScene.h"
#include "NpcObject.h"
#include "Player.h"

void ShopScene::Init()
{
	m_backGround = IMAGEMANAGER->FindImage("ShopBackGround");
	m_cloude = IMAGEMANAGER->FindImage("ShopCloud");
	m_structure = IMAGEMANAGER->FindImage("ShopStruecture");

	FILEMANAGER->SetNowStageFile("shop");

	FILEMANAGER->TileFileRead(&m_tiles);

	string strData;
	strData = FILEMANAGER->GetFileData("Structure", "batch");
	MY_UTILITY::ConvertStructureString2Vec(&m_struectures, strData);

	string strData2;
	strData2 = FILEMANAGER->GetFileData("Object", "batch");
	MY_UTILITY::ConvertStructureString2Vec(&m_objects, strData2);
	SCENEMANAGER->m_tiles = m_tiles;
	for (auto iter : m_objects)
	{
		if (iter->key == "Basic")
		{
			OBJECTMANAGER->AddObject("player", iter->x, iter->y, ePlayer)->AddComponent<Player>();
		}
	}
}

void ShopScene::Update()
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

	if (IMAGEMANAGER->GetCameraPosition().x < 0)
	{
		IMAGEMANAGER->SetCameraPosition(WINSIZE_X / 2,IMAGEMANAGER->GetCameraPosition().y) ;
	}
	cout << IMAGEMANAGER->GetCameraPosition().x << endl;
	IMAGEMANAGER->SetCameraPosition(v.x, v.y);
}

void ShopScene::Render()
{
	IMAGEMANAGER->UIRender(m_backGround, 0, -200, 1.6, 1.6);
	IMAGEMANAGER->Render(m_structure,200 - IMAGEMANAGER->GetCameraPosition().x*0.2, 0 + 100 , 1, 1);
	IMAGEMANAGER->Render(m_cloude, 500 - IMAGEMANAGER->GetCameraPosition().x * 0.1, 0, 1.5, 1.5);

	IMAGEMANAGER->DrawMapStructureBack(m_struectures);
	IMAGEMANAGER->DrawMapTile(m_tiles);
	IMAGEMANAGER->DrawMapStructureFoward(m_struectures);

}

void ShopScene::Release()
{
}
