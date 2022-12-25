#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	//ĳ���� �̵� �����Ϸ��� �ӽ÷� ����
	RECT floor;
	RECT blockA;
	RECT blockB;

	LobbyScene();
	~LobbyScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

