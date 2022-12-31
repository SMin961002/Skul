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
		eEnd
	};
	
	vImage* m_vimage[eEnd];
	bool m_attack;
	bool m_move;
	bool m_attackleft;
	CollisionComponent* collision;
	CollisionComponent* collision2;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void OnCollision(string collisionName,Object * other) override;

	LeoniaSoldier() {}
	~LeoniaSoldier() {}
};

