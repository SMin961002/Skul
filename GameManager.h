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
	GameManager() { Init(); }
	~GameManager() {}
	vector<Head* >m_headList;
	Head* m_nowHead;
	int tag;

	void Init() {
		tag = -1;
		m_nowHead = nullptr;
		m_headList.clear();
		enemyCount = 0;
		goldValue = 0;
		isHeadCheck = 0;
		playerHp = 0;
	}
	int GetEnemyCount() { OBJECTMANAGER->GetEnemyCount(); }
};

#define GAMEMANAGER GameManager::GetInstance()