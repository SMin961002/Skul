#pragma once
#include "Scene.h"
class MapToolMapSelectScene : public Scene
{
private:
	vector<string> m_maps;
public:
	MapToolMapSelectScene();
	~MapToolMapSelectScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

