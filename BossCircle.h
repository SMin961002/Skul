#pragma once
#include "Component.h"
class BossCircle : public Component
{
private:
	int cicle;
	CollisionComponent* coll;
	enum BossCircleState
	{
		eCreate,
		eIdle,
		eDis,
		eEnd
	};
	int m_state;
	vImage* img[eEnd];
public:
	BossCircle() {}
	~BossCircle() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;
};

