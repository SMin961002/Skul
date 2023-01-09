#pragma once
#include "Component.h"
#include "Enemy.h"

class BossPhase1EnemyFnatic : public Enemy
{
private:
	float m_maxhp; 
	float m_currenthp;
	float m_hpbar;
	CImage* m_ratherImg;
	float m_ratherY;
	int m_attackcount;
	int m_state = 0;
	enum State
	{
		eUp,
		eIdle,
		eAttack,
		eWalk,
		eHit,
		eHPbarEmpty,
		eHpbarDown,
		eHpbarUp,
		eEnd
	};
	bool m_isL;
	bool m_die2;
	bool m_isHit;
	bool m_isAttack;
	bool m_hit;
	bool m_die;

	float m_dietimer;
	float m_hpbartimer;
	float m_hiteffecttimer;
	float m_hitTimer;
	vImage* img[State::eEnd];


	CollisionComponent* m_hitCollision;
	CollisionComponent* m_hitpointCollision;
public:

	BossPhase1EnemyFnatic() {}
	~BossPhase1EnemyFnatic() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;
	void HitEnemy(float dmg, float time) override;
};

