#pragma once
#include "Component.h"

class HolyFountainLeft : public Component
{
private:
	vImage* _imgLeftOrbStart;
	vImage* _imgLeftOrbActing;
	vImage* _imgLeftOrbEnd;
	vImage* _imgLeftFountainActivate;
	CImage* _imgLeftFountainDeActivate;

	bool _isLeftPlayOn;
	bool _isLeftOrbActing;
public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	//virtual void OnCollision(string collisionName, Object* other) override;
};

class HolyFountainRight : public Component
{
private:
	vImage* _imgRightOrbStart;
	vImage* _imgRightOrbActing;
	vImage* _imgRightOrbEnd;
	vImage* _imgRightFountainActivate;
	CImage* _imgRightFountainDeActivate;

	bool _isRightPlayOn;
	bool _isRightOrbActing;
public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	//virtual void OnCollision(string collisionName, Object* other) override;
};