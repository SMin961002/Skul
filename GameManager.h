#pragma once
#include "singleton.h"
#include "Head.h"
class GameManager : public Singleton <GameManager>
{
public:
	int goldValue;
	bool isHeadCheck;
	int playerHp;
	int enemyCount;
	vector<int> itemList;
	GameManager() { Init(); }
	~GameManager() {}
	vector<Head* >m_headList;
	Head* m_nowHead;
	int tag;
	int allEnemycount = 0;

	void Init() {
		allEnemycount = 0;
		itemList.clear();
		tag = -1;
		m_nowHead = nullptr;
		m_headList.clear();
		enemyCount = 0;
		goldValue = 0;
		isHeadCheck = false;
		playerHp = 0;
	}
	int GetEnemyCount() { OBJECTMANAGER->GetEnemyCount(); }
};

#define GAMEMANAGER GameManager::GetInstance()