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
#include"CSound.h"

void Stage::Init()
{
	if (FILEMANAGER->GetFileName() == "map_5")
	{
		GAMEMANAGER->Init();
	}
	IMAGEMANAGER->SetCameraPosition(0, 0);
	GAMEMANAGER->enemyCount = 0;
	trigger = new Trigger;
	isFade = false;
	isStart = false;
	m_speed = 0;
	m_backGround = IMAGEMANAGER->FindImage("Background");
	m_backGround2 = IMAGEMANAGER->FindImage("Background2");
	m_backGround3 = IMAGEMANAGER->FindImage("Background3");
	m_backGround4 = IMAGEMANAGER->FindImage("Background4");
	m_backGround5 = IMAGEMANAGER->FindImage("Background5");
	m_backGround6 = IMAGEMANAGER->FindImage("Background6");
	m_backGround7 = IMAGEMANAGER->FindImage("Background7");
	m_backGround8 = IMAGEMANAGER->FindImage("Background8");
	m_moon = IMAGEMANAGER->FindImage("Moon2");
	m_castle = IMAGEMANAGER->FindImage("Castle2");
	m_castle2 = IMAGEMANAGER->FindImage("Castle3");
	m_cloude = IMAGEMANAGER->FindImage("Cloud");
	m_cloude2 = IMAGEMANAGER->FindImage("Cloud2");
	m_cloude3 = IMAGEMANAGER->FindImage("Cloud3");
	m_cloude4 = IMAGEMANAGER->FindImage("Cloud4");
	m_ChandelierBack = IMAGEMANAGER->FindImage("ChandelierBack");
	m_ChandelierBack2 = IMAGEMANAGER->FindImage("ChandelierBack2");
	m_Demoncastle = IMAGEMANAGER->FindImage("Demoncastle");
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
		else if (iter->key == "Trigger4")
		{
			if (trigger->trigger[3].left == 0)
			{
				trigger->trigger[3].left = iter->x;
				trigger->trigger[3].top = iter->y;
			}
			else
			{
				trigger->trigger[3].right = iter->x;
				trigger->trigger[3].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger5")
		{
			if (trigger->trigger[4].left == 0)
			{
				trigger->trigger[4].left = iter->x;
				trigger->trigger[4].top = iter->y;
			}
			else
			{
				trigger->trigger[4].right = iter->x;
				trigger->trigger[4].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger6")
		{
			if (trigger->trigger[5].left == 0)
			{
				trigger->trigger[5].left = iter->x;
				trigger->trigger[5].top = iter->y;
			}
			else
			{
				trigger->trigger[5].right = iter->x;
				trigger->trigger[5].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger7")
		{
			if (trigger->trigger[6].left == 0)
			{
				trigger->trigger[6].left = iter->x;
				trigger->trigger[6].top = iter->y;
			}
			else
			{
				trigger->trigger[6].right = iter->x;
				trigger->trigger[6].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger8")
		{
			if (trigger->trigger[7].left == 0)
			{
				trigger->trigger[7].left = iter->x;
				trigger->trigger[7].top = iter->y;
			}
			else
			{
				trigger->trigger[7].right = iter->x;
				trigger->trigger[7].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger9")
		{
			if (trigger->trigger[8].left == 0)
			{
				trigger->trigger[8].left = iter->x;
				trigger->trigger[8].top = iter->y;
			}
			else
			{
				trigger->trigger[8].right = iter->x;
				trigger->trigger[8].bottom = iter->y;
			}
		}
		else if (iter->key == "Trigger10")
		{
			if (trigger->trigger[9].left == 0)
			{
				trigger->trigger[9].left = iter->x;
				trigger->trigger[9].top = iter->y;
			}
			else
			{
				trigger->trigger[9].right = iter->x;
				trigger->trigger[9].bottom = iter->y;
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
			OBJECTMANAGER->AddObject("Spider", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<Spider>();
		}
		else if (iter->key == "LobbyNpc")
		{
			OBJECTMANAGER->AddObject("LobbyNpc", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<LobbyNpc1>();
		}
		else if (iter->key == "LobbyNpc2")
		{
			OBJECTMANAGER->AddObject("LobbyNpc2", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<LobbyNpc2>();
		}
		else if (iter->key == "LobbyNpc3")
		{
			OBJECTMANAGER->AddObject("LobbyNpc3", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<LobbyNpc3>();
		}
		else if (iter->key == "LobbyNpc4")
		{
			OBJECTMANAGER->AddObject("LobbyNpc4", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<LobbyNpc4>();
		}
		else if (iter->key == "LobbyNpc5")
		{
			OBJECTMANAGER->AddObject("LobbyNpc5", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<LobbyNpc5>();
		}
		else if (iter->key == "CatIdle")
		{
			OBJECTMANAGER->AddObject("CatIdle", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<Cat>();
		}
		else if (iter->key == "SpaerSkul")
		{
			OBJECTMANAGER->AddObject("SpaerSkul", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<SpaerSkul>();
		}
		else if (iter->key == "Elevator")
		{
			OBJECTMANAGER->AddObject("Elevator", iter->x, iter->y, ObjectTag::eNPC)->AddComponent<Elevator>();
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
	if (FILEMANAGER->GetFileName() == "map_5")
	{
		IMAGEMANAGER->SetCameraPosition(v.x, 350);
	}
	else
	{
		IMAGEMANAGER->SetCameraPosition(v.x, v.y);
	}
	if (IMAGEMANAGER->GetCameraPosition().x <= 0)
	{
		IMAGEMANAGER->SetCameraPosition(0, IMAGEMANAGER->GetCameraPosition().y);
	}
	trigger->Update();
}

void Stage::Render()
{   
	m_speed += 100 * DELTA_TIME;
	float RenderPos = (int)m_speed % (m_cloude->GetWidth() * 2);
	if (FILEMANAGER->GetFileName() == "map_5")
	{
		IMAGEMANAGER->Render(m_backGround2, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y-200, 2, 2);
		IMAGEMANAGER->Render(m_cloude3, IMAGEMANAGER->GetCameraPosition().x + (RenderPos*0.5), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude4, (IMAGEMANAGER->GetCameraPosition().x*0.7), IMAGEMANAGER->GetCameraPosition().y+200, 3, 3);
		IMAGEMANAGER->Render(m_Demoncastle, IMAGEMANAGER->GetCameraPosition().x*0.2, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_ChandelierBack2, (IMAGEMANAGER->GetCameraPosition().x*0.2)+450, IMAGEMANAGER->GetCameraPosition().y-200, 2, 2);
		IMAGEMANAGER->Render(m_ChandelierBack2, (IMAGEMANAGER->GetCameraPosition().x * 0.2) + 1800, IMAGEMANAGER->GetCameraPosition().y - 140, 2, 2);
		IMAGEMANAGER->Render(m_ChandelierBack, (IMAGEMANAGER->GetCameraPosition().x *0.2)+1100, IMAGEMANAGER->GetCameraPosition().y-70, 2, 2);	
	}
	if (FILEMANAGER->GetFileName() == "map_3")
	{
		IMAGEMANAGER->Render(m_backGround, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_moon, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude2, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos + (m_cloude->GetWidth() * 2), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_castle, IMAGEMANAGER->GetCameraPosition().x * 0.9, IMAGEMANAGER->GetCameraPosition().y - 800, 2, 2);
	}
	if (FILEMANAGER->GetFileName() == "map_6")
	{
		IMAGEMANAGER->Render(m_backGround, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_moon, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude2, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos + (m_cloude->GetWidth() * 2), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_castle, IMAGEMANAGER->GetCameraPosition().x * 0.9, IMAGEMANAGER->GetCameraPosition().y - 800, 2, 2);
	}
	if (FILEMANAGER->GetFileName() == "map_2")
	{
		IMAGEMANAGER->Render(m_backGround, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_moon, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude2, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_cloude, IMAGEMANAGER->GetCameraPosition().x - RenderPos + (m_cloude->GetWidth() * 2), IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_castle, IMAGEMANAGER->GetCameraPosition().x * 0.9, IMAGEMANAGER->GetCameraPosition().y - 800, 2, 2);
	}
	if (FILEMANAGER->GetFileName() == "map_4")
	{
		IMAGEMANAGER->Render(m_backGround3, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 2);
		IMAGEMANAGER->Render(m_castle2, IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y-250, 2, 2);
		IMAGEMANAGER->Render(m_backGround4, (IMAGEMANAGER->GetCameraPosition().x*0.2)-300,-1000, 2, 2);
		IMAGEMANAGER->Render(m_backGround5, (IMAGEMANAGER->GetCameraPosition().x * 0.2)+150,100, 2, 2);
		IMAGEMANAGER->Render(m_backGround6,(IMAGEMANAGER->GetCameraPosition().x * 0.2) + 850,100, 3, 3);
		IMAGEMANAGER->Render(m_backGround7, (IMAGEMANAGER->GetCameraPosition().x * 0.2) + 1350,150, 3, 3);
		IMAGEMANAGER->Render(m_backGround8, (IMAGEMANAGER->GetCameraPosition().x * 0.2) + 1350,0, 3, 3);

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
