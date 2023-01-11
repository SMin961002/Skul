#pragma once
#include"Enemy.h"
class BallFanatic : public Enemy
{
	enum ImageState
	{
		eIdle,
		eSacrifice,
		eSacrificeLoop,
		eSummonLoop,
		eSummonReady,
		eEnd
	};

	vImage* m_vimage[eEnd];
	bool m_attack;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

};

