#pragma once
#include "Component.h"

class LeftImpact : public Component
{
private:
	vImage* _imgPhase1NervousEffectImpactRight;

	CollisionComponent* _collisionLeft;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(string collisionName, Object* other) override;

	LeftImpact() {}
	~LeftImpact() {}
};

class RightImpact : public Component
{
private:
	vImage* _imgPhase1NervousEffectImpactLeft;

	CollisionComponent* _collisionRight;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(string collisionName, Object* other) override;

	RightImpact() {}
	~RightImpact() {}
};

class ImpactShine : public Component
{
private:
	vImage* _imgPhase1NervousEffectShine;

	CollisionComponent* _collisionShine;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	
	ImpactShine() {}
	~ImpactShine() {}
};