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
	float alphaHit = 0;
	vImage* m_vimage[eEnd];
	bool m_attack;
	bool m_isAttack;
	bool m_effect;
	bool m_isHit;
	bool m_hit;
	bool m_move;
	bool m_die2;
	bool m_sercrifice;
	bool m_sercrieffect;
	bool m_die;

	CollisionComponent* m_collision;
	float m_dietimer;
	float m_hpbartimer;
	float m_hitTimer;
	float m_motiontimer;
	float m_hiteffecttimer;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg, float time) override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
	void ImageResetCheck();
};

