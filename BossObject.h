#pragma once
#include "Component.h"

class BossObject : public Component
{
private:
	vImage* _imgBoss;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void Pattern();

	BossObject() {}
	~BossObject() {}
};

