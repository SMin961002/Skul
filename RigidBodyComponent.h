#pragma once
class RigidBodyComponent : public Component
{
private:
	float m_gravity;
	float m_speed;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void AddForce();

	RigidBodyComponent();
	~RigidBodyComponent();
};

