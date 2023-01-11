#pragma once
#include "Component.h"

#define PI		3.141592654f

class Baptism : public Component
{
private:
	vImage* _imgPhase1BossBaptismProjectile;
	vImage* _imgPhase1BossBaptismProjectileDespawn;

	int _randX;
	float _deltaMove;

	CollisionComponent* _collision;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;

	Baptism() {}
	~Baptism() {}
};