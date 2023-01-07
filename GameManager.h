#pragma once
#include "singleton.h"
class GameManager : public Singleton <GameManager>
{
public:
	int enemyCount;
	GameManager() { Init(); }
	~GameManager() {}

	void Init() { enemyCount = 0; }
	int GetEnemyCount() { OBJECTMANAGER->GetEnemyCount(); }
};

