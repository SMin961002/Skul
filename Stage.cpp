#include "stdafx.h"
#include "Stage.h"
#include "stdafx.h"
#include "EnemyTestScene.h"
#include "Player.h"
#include "LeoniaSoldier.h"
#include "CandleFanatic.h"
#include "TentaclesOfLight.h"
#include "Fanatic.h"
#include "LampFanatic.h"
#include "DoorObject.h"
#include "BallFanatic.h"
#include "Gold.h"
#include "AngelStatue.h"
#include "GoldResult.h"
#include "HeadResult.h"
#include "CandleFanatic.h"
#include"Fountain.h"
#include"LobbyObject.h"

void Stage::Init()
{
	trigger = new Trigger;
	isFade = false;
	isStart = false;
	m_speed = 0;
	m_backGround = IMAGEMANAGER->FindImage("Background");
	m_castle = IMAGEMANAGER->FindImage("Castle2");
	m_cloude = IMAGEMANAGER->FindImage("Cloud");
	m_moon = IMAGEMANAGER->FindImage("Moon2");
	m_cloude2 = IMAGEMANAGER->FindImage("Cloud2");
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
	for (auto iter : m_objectDatas)
	{
		if (iter->key == "Trigger1")
		{
			if (trigger->trigger[0].left == 0)
			{
				trigger->trigger[0].left = iter->x;
				trigger->trigger[0].top = iter->y;
			}
			else
			{
				trigger->trigger[0].right = iter->x;
				trigger->trigger[0].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger2")
		{
			if (trigger->trigger[1].left == 0)
			{
				trigger->trigger[1].left = iter->x;
				trigger->trigger[1].top = iter->y;
			}
			else
			{
				trigger->trigger[1].right = iter->x;
				trigger->trigger[1].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger3")
		{
			if (trigger->trigger[2].left == 0)
			{
				trigger->trigger[2].left = iter->x;
				trigger->trigger[2].top = iter->y;
			}
			else
			{
				trigger->trigger[2].right = iter->x;
				trigger->trigger[2].bottom = iter->y;
			}
		}
		else if (iter->key == "NormalRoom")
		{
			OBJECTMANAGER->AddObject("DoorObject", iter->x, iter->y, ObjectTag::eObject)->AddComponent<DoorObject>()->Setting(0);
		}
		else if (iter->key == "SkulRoom")
		{
			OBJECTMANAGER->AddObject("DoorObject", iter->x, iter->y, ObjectTag::eObject)->AddComponent<DoorObject>()->Setting(1);
		}
		else if (iter->key == "ShopRoom")
		{
			OBJECTMANAGER->AddObject("DoorObject", iter->x, iter->y, ObjectTag::eObject)->AddComponent<DoorObject>()->Setting(2);
		}
		else if (iter->key == "SpirderRoom")
		{
			OBJECTMANAGER->AddObject("DoorObject", iter->x, iter->y, ObjectTag::eObject)->AddComponent<DoorObject>()->Setting(3);
		}
		else if (iter->key == "BossRoom")
		{
			OBJECTMANAGER->AddObject("DoorObject", iter->x, iter->y, ObjectTag::eObject)->AddComponent<DoorObject>()->Setting(4);
		}
		else if (iter->key == "GoldResoult")
		{
			OBJECTMANAGER->AddObject("GoldResult", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<GoldResult>();
		}
		else if (iter->key == "HeadResult")
		{
			OBJECTMANAGER->AddObject("HeadResult", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<HeadResult>();
		}
		else if (iter->key == "Fountain")
		{
			OBJECTMANAGER->AddObject("Fountain", iter->x, iter->y, ObjectTag::eItem)->AddComponent<Fountain>();
		}
		else if (iter->key == "Spider")
		{
			OBJECTMANAGER->AddObject("Spider", iter->x, iter->y, ObjectTag::eItem)->AddComponent<Spider>();
		}
		else if (iter->key == "LobbyNpc")
		{
			OBJECTMANAGER->AddObject("LobbyNpc", iter->x, iter->y, ObjectTag::eItem)->AddComponent<LobbyNpc1>();
		}
		else if (iter->key == "LobbyNpc2")
		{
			OBJECTMANAGER->AddObject("LobbyNpc2", iter->x, iter->y, ObjectTag::eItem)->AddComponent<LobbyNpc2>();
		}
		else if (iter->key == "LobbyNpc3")
		{
			OBJECTMANAGER->AddObject("LobbyNpc3", iter->x, iter->y, ObjectTag::eItem)->AddComponent<LobbyNpc3>();
		}
		else if (iter->key == "LobbyNpc4")
		{
			OBJECTMANAGER->AddObject("LobbyNpc4", iter->x, iter->y, ObjectTag::eItem)->AddComponent<LobbyNpc4>();
		}
		else if (iter->key == "LobbyNpc5")
		{
			OBJECTMANAGER->AddObject("LobbyNpc5", iter->x, iter->y, ObjectTag::eItem)->AddComponent<LobbyNpc5>();
		}
		else
		{
			trigger->m_structureData[iter->page].push_back(iter);
		}
	}
	trigger->Init();
}

void Stage::Update()
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
	trigger->Update();
}

void Stage::Render()
{
	m_speed += 100 * DELTA_TIME;
	float RenderPos = (int)m_speed % (m_cloude->GetWidth() * 2);
	if (FILEMANAGER->GetFileName() == "map_5")
	{
		IMAGEMANAGER->Render(m_backGround, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_moon, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude2, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos + (m_cloude->GetWidth() * 2), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_castle, IMAGEMANAGER->GetCameraPosition().x * 0.9, IMAGEMANAGER->GetCameraPosition().y - 800, 2, 2);
	}

	IMAGEMANAGER->DrawMapStructureBack(m_sturctDatas);

	IMAGEMANAGER->DrawMapTile(SCENEMANAGER->m_tiles);

	IMAGEMANAGER->DrawMapStructureFoward(m_sturctDatas);

	if (IMAGEMANAGER->GetViewCollision())
	{
		IMAGEMANAGER->DrawMapTilePixel(SCENEMANAGER->m_tiles);
	}

	//IMAGEMANAGER->DrawColorRender(m_backGround, WINSIZE_X / 2, WINSIZE_Y / 2, 2, 2, 0, false, { 255,0,255,0.5 });
}


void Stage::Release()
{
	trigger->Release();
	SAFE_DELETE(trigger);
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

void Stage::UIRender()
{
	for (auto iter : m_sturctDatas)
	{
		if (iter->key == "DoorBack")
		{
			float x = abs((iter->x + 300) - OBJECTMANAGER->m_player->GetplayerX());

			if (x < 50)
				IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage("Light"), iter->x + 300, iter->y - 40, 1, 1, 0, 0, 0.5 / 500.f * (500 - 50));

			else if (x < 500)
				IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage("Light"), iter->x + 300, iter->y - 40, 1, 1, 0, 0, 0.5 / 500.f * (500 - x));
		}
	}
	if (isStart == false)
	{
		SCENEMANAGER->FadeIn(0.02, [&]() {isStart = true; }, 15);
	}
}
