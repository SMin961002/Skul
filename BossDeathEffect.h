#pragma once

#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
class BossDeathEffect : public Component
{
public:
	BossDeathEffect() {}
	~BossDeathEffect() {}
public:
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Release() override;



};

