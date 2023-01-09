#pragma once
class CollisionComponent : public Component
{
public:
	string m_collisionName;
	float m_range;
	float m_collisionX, m_collisionY;
	bool m_multiHit;
	CollisionComponent();
	~CollisionComponent();
public:

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	//����(�̸�,����, �߽��� ����)
	void Setting(float range, float x, float y, string name);
	void Setting(float range, float x, float y);
	//����(�浹�߽��� �ű��)
	void Setting(float x, float y);

	float GetCollisionPosX() { return m_collisionX; }
	float GetCollisionPosY() { return m_collisionY; }
	float GetRange() { return m_range; }
	string GetName() { return m_collisionName; }
};

