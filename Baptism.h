#pragma once
#include "Component.h"

#define PI		3.141592654f

class Baptism : public Component
{
private:
	vImage* _imgPhase1BossBaptismProjectile;
	vImage* _imgPhase1BossBaptismProjectileDespawn;

	bool _createLock;
	bool _downCheck;

	int _randX;
	int _angle;
	float _deltaMove;

	CollisionComponent* _collision;
	CollisionComponent* _hitCollision;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(string collisionName, Object* other)override;

	Baptism() {}
	~Baptism() {}
};


