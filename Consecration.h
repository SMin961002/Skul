#pragma once
#include "Component.h"

class Consecration : public Component
{
private:
	vImage* _imgPhase1BossConsecrationLoop;
	float _deltaTime;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	Consecration() {}
	~Consecration() {}
};

