#pragma once
#include "singleton.h"
#include "Object.h"

class BossObject;
class Item;
class Player;
class ObjectManager : public Singleton<ObjectManager>
{
public:
	Player* m_player;
	BossObject* m_boss;
	Item* m_item;
	ObjectManager();
	~ObjectManager();
public:
	vector<Object*> m_objects[eEndTag];
	Object* AddObject(string name, float x, float y, int tagNum);
	void Update();
	void Render();
	void UIRender();
	void Release();
	int GetEnemyCount() { return m_objects[eEnemy].size(); }
};

#define OBJECTMANAGER ObjectManager::GetInstance()