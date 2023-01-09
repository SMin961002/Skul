#pragma once
#include "Component.h"

class BossObject;

class HolyFountainLeft : public Component
{
private:
	vImage* _imgLeftFountainActivate;
	CImage* _imgLeftFountainDeActivate;

	CollisionComponent* _collisionLeft;

	BossObject* _boss;

	bool _isLeftPlayOn;
public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	
	HolyFountainLeft() {}
	~HolyFountainLeft() {}
};

class HolyFountainRight : public Component
{
private:
	vImage* _imgRightFountainActivate;
	CImage* _imgRightFountainDeActivate;

	CollisionComponent* _collisionRight;

	bool _isRightPlayOn;
public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	HolyFountainRight() {}
	~HolyFountainRight() {}
};

class HolyOrbLeft : public Component
{
	vImage* _imgLeftOrbStart;
	vImage* _imgLeftOrbActing;
	vImage* _imgLeftOrbEnd;

	bool _isLeftPlayOn;
	bool _isLeftOrbActing;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	
	HolyOrbLeft() {}
	~HolyOrbLeft() {}
};

class HolyOrbRight : public Component
{
	vImage* _imgRightOrbStart;
	vImage* _imgRightOrbActing;
	vImage* _imgRightOrbEnd;

	bool _isRightPlayOn;
	bool _isRightOrbActing;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	HolyOrbRight() {}
	~HolyOrbRight() {}
};