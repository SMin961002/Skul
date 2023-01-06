#pragma once
#include "Component.h"
class FireKnife : public Component
{
private:
	float rot;
	const float speed = 500;
	CImage* img;
	CollisionComponent* collision;
public:
	int x;
	FireKnife() {}
	~FireKnife() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other)override;
};

