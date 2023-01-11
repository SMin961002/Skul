#pragma once
#include "Component.h"
class BossBall : public Component
{
	enum BallState
	{
		eStart,
		eIdle,
		eDis,
		eEnd
	};
	float startX, startY;
	int m_state;
	float rot;
	float dist;
public:
	bool ldist;
	BossBall();
	~BossBall();
	vImage* img[3];
	CollisionComponent* coll;
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

	void Setting(float rot);
};

