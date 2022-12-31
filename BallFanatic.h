#pragma once
#include"Enemy.h"
class BallFanatic : public Enemy
{
	enum IamgeState
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
	virtual void OnCollision(string collisionName, Object* other) override;

};

