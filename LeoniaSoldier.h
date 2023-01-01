#pragma once
#include"Enemy.h"

class LeoniaSoldier :public Enemy
{
private:
	enum IamgeState
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

	
	vImage* m_vimage[eEnd];
	bool m_attack;
	bool m_move;
	bool m_attackleft;
	CollisionComponent* m_collision;
	CollisionComponent* m_hitpointcollision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg) override;

	virtual void OnCollision(string collisionName, Object* other) override;

	LeoniaSoldier() {}
	~LeoniaSoldier() {}
};

