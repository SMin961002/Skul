#include "stdafx.h"
#include "stdafx.h"
#include "Trigger.h"
#include "Player.h"
#include "LeoniaSoldier.h"
#include "CandleFanatic.h"
#include "TentaclesOfLight.h"
#include "Fanatic.h"
#include "LampFanatic.h"
#include "AngelStatue.h"
#include "GoldResult.h"
#include "HeadResult.h"
#include "CandleFanatic.h"
#include "DoorObject.h"
Trigger::Trigger()
{
	trigger[0] = { 0,0,0,0 };
	trigger[1] = { 0,0,0,0 };
	trigger[2] = { 0,0,0,0 };
	trigger[3] = { 0,0,0,0 };
	trigger[4] = { 0,0,0,0 };
	trigger[5] = { 0,0,0,0 };
	trigger[6] = { 0,0,0,0 };
	trigger[7] = { 0,0,0,0 };
	trigger[8] = { 0,0,0,0 };
	trigger[9] = { 0,0,0,0 };
}
void Trigger::Init()
{

	nowTriggerIndex = 0;
	SpawnEnemy();
}

void Trigger::Update()
{
	int size = GAMEMANAGER->enemyCount;
	if (nowTriggerIndex < 3 && size <= 0)
	{
		OnTrigger();
	}
}

void Trigger::Render()
{
}

void Trigger::Release()
{
	for (int i = 0; i < 10; i++)
	{
		for (auto iter : m_structureData[i])
		{
			SAFE_DELETE(iter);
		}
		m_structureData[i].clear();
	}
}

void Trigger::OnTrigger()
{
	if (PtInRect(&trigger[nowTriggerIndex], { (int)OBJECTMANAGER->m_player->GetplayerX(),(int)OBJECTMANAGER->m_player->GetplayerY() }))
	{
		nowTriggerIndex++;
		SpawnEnemy();
	}
}

void Trigger::SpawnEnemy()
{
	for (auto iter : m_structureData[nowTriggerIndex])
	{
		GAMEMANAGER->allEnemycount--;
		if (iter->key == "AStatue")
		{
			OBJECTMANAGER->AddObject("Enemy", iter->x, iter->y, ObjectTag::eEnemy)->AddComponent<AngelStatue>();
		}
		if (iter->key == "Cfanatic")
		{
			OBJECTMANAGER->AddObject("Enemy", iter->x, iter->y, ObjectTag::eEnemy)->AddComponent<CandleFanatic>();
		}
		if (iter->key == "Fanatic")
		{
			OBJECTMANAGER->AddObject("Enemy", iter->x, iter->y, ObjectTag::eEnemy)->AddComponent<Fanatic>();
		}
		if (iter->key == "Leon")
		{
			OBJECTMANAGER->AddObject("Enemy", iter->x, iter->y, ObjectTag::eEnemy)->AddComponent<LeoniaSoldier>();
		}
	}
}
