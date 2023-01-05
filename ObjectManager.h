#pragma once
#include "singleton.h"
#include "Object.h"

class Item;
class Player;
class ObjectManager : public Singleton<ObjectManager>
{
public:
	Player* m_player;
	Item* m_item;
	ObjectManager();
	~ObjectManager();
	vector<Object*> m_objects[eEndTag];
public:
	Object* AddObject(string name, float x, float y, int tagNum);
	void Update();
	void Render();
	void UIRender();
	void Release();
};

#define OBJECTMANAGER ObjectManager::GetInstance()