#pragma once
#include "singleton.h"
#include "Object.h"
class ObjectManager : public Singleton<ObjectManager>
{
public:
	ObjectManager();
	~ObjectManager();
	vector<Object*> m_objects[eEndTag];
public:
	Object* AddObject(string name, float x, float y, int tagNum);
	void Update();
	void Render();
	void Release();
};

#define OBJECTMANAGER ObjectManager::GetInstance()