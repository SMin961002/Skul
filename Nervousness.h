#pragma once
#include "Component.h"

class LeftImpact : public Component
{
private:
	vImage* _imgPhase1NervousEffectImpactRight;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	LeftImpact() {}
	~LeftImpact() {}
};

class RightImpact : public Component
{
private:
	vImage* _imgPhase1NervousEffectImpactLeft;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	RightImpact() {}
	~RightImpact() {}
};

class ImpactShine : public Component
{
private:
	vImage* _imgPhase1NervousEffectShine;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	ImpactShine() {}
	~ImpactShine() {}
};