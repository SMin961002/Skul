#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
private:
	CImage* img;
public:
	LobbyScene();
	~LobbyScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	
};

