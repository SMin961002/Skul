#pragma once
#include"Enemy.h"
class Fanatic :public Enemy
{
private:
	bool m_isReverse;
	bool m_isHit;
	bool m_isAttack;
	enum IamgeState
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
	float m_hitTimer;
	int m_state;
	CollisionComponent* m_hitCollision;

	vImage* m_vimage[eEnd];
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;
	void HitEnemy(float dmg) override;
	void ImageResetCheck();
	Fanatic() {}
	~Fanatic() {}
};


