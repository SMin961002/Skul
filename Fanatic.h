#pragma once
#include"Enemy.h"
class Fanatic :public Enemy
{
private:
	Effect* effect;

	float m_lastX, m_lastY;
	enum ImageState
	{
		eIdle,
		eAttackIdle,
		eAttack,
		eRunAttack,
		eRun,
		Setcrifice,
		SetcrificeLoop,
		SetcrificeReady,
		eHit,
		eHPbarEmpty,
		eHpbarDown,
		eHpbarUp,
		eEnd
	};
	float alphaHit = 0;
	bool m_isReverse;
	bool m_isHit;
	bool m_isAttack;
	bool m_hit;
	bool m_hitpoint;
	bool m_sercrifice;
	bool m_sercrieffect;
	bool m_die;
	bool m_die2;
	bool m_effect;

	int m_attackcount;
	int m_state;
	float m_hitTimer;
	float m_hpbartimer;
	float m_motiontimer;
	float m_hiteffecttimer;
	float m_dietimer;

	CollisionComponent* m_hitCollision;
	CollisionComponent* m_hitpointCollision;

	vImage* m_vimage[eEnd];
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
	void HitEnemy(float dmg, float time) override;
	void ImageResetCheck();
	Fanatic() {}
	~Fanatic() {}
};


