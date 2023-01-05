#pragma once
#include "Component.h"

#define PI		3.141592654f

class CollisionComponent;

class Baptism : public Component
{
private:
	vImage* _imgPhase1BossBaptismProjectile;
	vImage* _imgPhase1BossBaptismProjectileDespawn;

	bool _createLock;

	int _angle;

	//CollisionComponent* _collision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	Baptism() {}
	~Baptism() {}
};


