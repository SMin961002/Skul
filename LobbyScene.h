#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	//캐릭터 이동 실험하려고 임시로 만듦
	RECT floor;
	RECT blockA;
	RECT blockB;

	LobbyScene();
	~LobbyScene();
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

