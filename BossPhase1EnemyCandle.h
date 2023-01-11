#pragma once
#include "Component.h"
#include "Enemy.h"
class BossPhase1EnemyCandle : public Enemy
{
private:
	float m_maxhp;
	float m_currenthp;
	float m_hpbartimer;
	float m_hpbar;
	float m_dietimer;
	float m_hiteffecttimer;
	float m_ratherY;
	CImage* m_ratherImg;
	int m_state = 0;
	enum State
	{
		eUp,
		eIdle,
		eAttack,
		eAttackReady,
		eWalk,
		eHPbarEmpty,
		eHpbarDown,
		eHpbarUp,
		eEnd
	};
	bool m_isL;
	bool m_die2;
	bool m_hit;
	bool m_die;
	vImage* img[State::eEnd];
	CollisionComponent* m_hitCollision;

public:
	BossPhase1EnemyCandle() {}
	~BossPhase1EnemyCandle() {}

	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override {};
	virtual void HitEnemy(float dmg, float time) override;
};

