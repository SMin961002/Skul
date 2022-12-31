#pragma once
#include "PixelCollisionComponent.h"

class RigidBodyComponent : public Component
{
private:
	bool m_isGravity;
	float m_gravity;
	float m_speed;
	PixelCollisionComponent* pixelCollisionComponent;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void AddForce();

	RigidBodyComponent();
	~RigidBodyComponent();



	void SetGravity(bool isGravity)
	{
		m_isGravity = isGravity;
	}
	void SetGravityPower(float power) { m_speed = power; }
};

