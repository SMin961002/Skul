#pragma once
#include "Scene.h"
class MapToolMapSelectScene : public Scene
{
private:
	vector<string> m_maps;
public:
	MapToolMapSelectScene();
	~MapToolMapSelectScene();
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

