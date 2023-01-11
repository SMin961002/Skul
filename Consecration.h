#pragma once
#include "Component.h"

class BossObject;

class Consecration : public Component
{
private:
	vImage* _imgPhase1BossConsecrationLoop;
	vImage* endImg;
	float _deltaTime;

	CollisionComponent* _collision;
	CollisionComponent* _collision2;
	CollisionComponent* _collision3;
	CollisionComponent* _collision4;

	CollisionComponent* _hitCollision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

	Consecration() {}
	~Consecration() {}
};

