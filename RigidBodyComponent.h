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
	bool m_isGold;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void AddForce();

	RigidBodyComponent();
	~RigidBodyComponent();

	
	float GetGravity() { return m_gravity; }
	float GetGravityPower() { return m_speed; }
	void SetGravityOnOff(bool isGravity) 
	{
		m_isGravity = isGravity;
	}
	void SetGravityPower(float power) { m_speed = power; }
};

