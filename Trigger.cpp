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
}
void Trigger::Init()
{
	
	nowTriggerIndex = 0;
	SpawnEnemy();
}

void Trigger::Update()
{
	if (nowTriggerIndex < 3 && OBJECTMANAGER->GetEnemyCount() == 0)
	{
		OnTrigger();
	}
}

void Trigger::Render()
{
}

void Trigger::Release()
{
	m_structureData->clear();
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
		if (iter->key == "AStatue")
		{
			OBJECTMANAGER->AddObject("Enemy", iter->x, iter->y, ObjectTag::eEnemy)->AddComponent<AngelStatue>();
		}
		if (iter->key == "Lfanatic")
		{
			OBJECTMANAGER->AddObject("Enemy", iter->x, iter->y, ObjectTag::eEnemy)->AddComponent<LampFanatic>();
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
