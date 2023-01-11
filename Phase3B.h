#pragma once
class Phase3B : public Component
{
public:
	vImage* img;
	Phase3B() {}
	CollisionComponent* coll;
	~Phase3B() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
};

