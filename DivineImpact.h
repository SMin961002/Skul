#pragma once
class DivineImpact : public Component
{
public:
	vImage* img;
	DivineImpact() {}
	~DivineImpact() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	int count = 0;
	virtual void Render() override;
	virtual void Release() override;
	bool isHit = false;
	CollisionComponent* coll;
	void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)  override;
};

