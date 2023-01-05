#pragma once
#include "Component.h"

class WorshipLeft : public Component
{
private:
	vImage* _imgPhase1BossWorshipLeft;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	WorshipLeft() {}
	~WorshipLeft() {}
};

class WorshipRight : public Component
{
private:
	vImage* _imgPhase1BossWorshipRight;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	WorshipRight() {}
	~WorshipRight() {}
};
