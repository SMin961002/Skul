#pragma once
#include"Enemy.h"
class AngelStatue : public Enemy
{
	enum ImageState
	{
		eIdle,
		eAttack,
		eAttackReadyEffect,
		eAttackEffect,
		eEndAttack,
		eEnd
	};

	int m_state2;
	int m_state;
	float m_effecttimer;
	vImage* m_vimage[eEnd];
	bool m_attack;
	float m_hitpoint;
	CollisionComponent* m_collision;
	CollisionComponent* m_hitpointcollision;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;



};

