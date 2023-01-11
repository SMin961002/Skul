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
		eHpbarUp,
		eHpbarDown,
		eHPbarEmpty,
		eEnd
	};
	vImage* m_vimage[eEnd];
	

	bool m_attack;
	bool m_hit;
	bool m_die;
	bool m_effect;
	bool m_attacksound;
	bool m_attacksound2;

	int m_state2;
	int m_state;
	int cheack;
	int m_attackcount;

	float m_attacksoundtimer;
	float m_hitpoint;
	float m_dietimer;
	float m_hiteffecttimer;
	float m_hpbartimer;
	CollisionComponent* m_collision;
	CollisionComponent* m_hitpointcollision;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg, float time) override;

	virtual void OnCollision(string collisionName, Object* other) override;



};

