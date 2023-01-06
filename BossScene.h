#pragma once
#include "Scene.h"

class BossScene : public Scene
{
private:
	CImage* _imgMoon;
	CImage* _imgBuilding;
	CImage* _imgLion;
	vector<StructureData*> m_sturctDatas;
	vector<StructureData*> m_objectDatas;

	CImage* _imgFence;
public:
	BossScene() {}
	~BossScene() {}

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

