#pragma once
#include"Enemy.h"
class TentaclesOfLight :public Enemy
{
private:
	enum ImageState
	{
		eIdle,
		eAttack,
		eRecovery,
		eMemerge,
		eEnd
	};

	vImage* m_vimage[eEnd];
	int m_state;
	int m_attackcount;

	bool m_attack;
	bool m_memergeend;
	bool m_isleft;
	bool m_recovery;
	bool m_attacksound;
	bool m_attacksound2;

	float m_hiteffecttimer;

	CollisionComponent* m_collision;
	CollisionComponent* m_hitpointcollision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg, float time) override;

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

};

