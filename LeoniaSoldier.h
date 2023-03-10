#pragma once
#include"Enemy.h"

class LeoniaSoldier :public Enemy
{
private:
	enum ImageState
	{
		eIdle,
		eAttack,
		eRun,
		eHit,
		eHpbarUp,
		eHpbarDown,
		eHPbarEmpty,
		eEnd
	};
	float m_lastY;
	float m_lastX;

	
	float alphaHit;
	vImage* m_vimage[eEnd];
	
	bool m_attack;
	bool m_move;
	bool m_attackleft;
	bool m_hit;
	bool m_hitpoint;
	bool m_die;
	bool m_effect; 
	bool m_hitmotion;

	int m_attackcount;
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

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

	LeoniaSoldier() {}
	~LeoniaSoldier() {}
};

