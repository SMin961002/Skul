#pragma once
#include "Component.h"

class WorshipLeft : public Component
{
private:
	vImage* _imgPhase1BossWorshipLeft;

	CollisionComponent* _collision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;

	WorshipLeft() {}
	~WorshipLeft() {}
};

class WorshipRight : public Component
{
private:
	vImage* _imgPhase1BossWorshipRight;

	CollisionComponent* _collision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;

	WorshipRight() {}
	~WorshipRight() {}
};
