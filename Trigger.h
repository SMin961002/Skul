#pragma once
#include "Component.h"
class Trigger
{
public:
	int nowTriggerIndex;
	RECT trigger[3];
	vector<StructureData* > m_structureData[4];

	Trigger();
	~Trigger() {}


	// Component��(��) ���� ��ӵ�
	void Init();
	void Update();
	void Render();
	void Release();

	void OnTrigger();

	void SpawnEnemy();
};

