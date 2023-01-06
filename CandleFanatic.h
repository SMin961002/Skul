#pragma once
#include"Enemy.h"
class CandleFanatic :public Enemy
{
private:
	int m_state;
	bool m_isL;
	enum ImageState
	{
		eIdle,
		eAttackReady,
		eAttack,
		eRun,
		eHit,
		eSatcrifice,
		eSatcrificeReady,
		eSatcrificeLoop,
		eHpbarUp,
		eHpbarDown,
		eHPbarEmpty,
		eEnd
	};

	vImage* m_vimage[eEnd];
	bool m_attack;
	bool m_effect;
	bool m_hit;
	bool m_move;
	

	CollisionComponent* m_collision;

	float m_hiteffecttimer;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg) override;
	virtual void OnCollision(string collisionName, Object* other) override;
};

