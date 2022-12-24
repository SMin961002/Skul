#pragma once
class CollisionComponent : public Component
{
public:
	float m_range;
	float m_collisionX, m_collisionY;
	CollisionComponent();
	~CollisionComponent();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void Setting(float range, float x, float y);

	float GetCollisionPosX() { return m_collisionX; }
	float GetCollisionPosY() { return m_collisionY; }
	float GetRange() { return m_range; }
};
