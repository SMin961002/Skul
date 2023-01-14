#pragma once

#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
class BossDeathEffect : public Component
{
public:
	BossDeathEffect() {}
	~BossDeathEffect() {}
public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Release() override;



};

