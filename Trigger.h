#pragma once
#include "Component.h"
class Trigger
{
public:
	int nowTriggerIndex;
	RECT trigger[10];
	vector<StructureData*> m_structureData[10];

	Trigger();
	~Trigger() {}


	// Component을(를) 통해 상속됨
	void Init();
	void Update();
	void Render();
	void Release();

	void OnTrigger();

	void SpawnEnemy();
};

