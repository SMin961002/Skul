#pragma once
#include "Component.h"

class HollyFountain : public Component
{
private:
	vImage* _imgOrbStart;
	vImage* _imgOrbActing;
	vImage* _imgOrbEnd;
	vImage* _imgFountainActivate;
	CImage* _imgFountainDeActivate;
public:
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	//virtual void OnCollision(string collisionName, Object* other) override;


};

