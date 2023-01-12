#pragma once
class GodRay : public Component
{
public:
	int m_state;
	CollisionComponent* coll;
	vImage* img[2];
	GodRay();
	~GodRay();

	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
	bool isEnd;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;
};

