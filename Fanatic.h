#pragma once
#include"Enemy.h"
class Fanatic :public Enemy
{
private:
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
		eEnd
	};

	vImage* m_vimage[eEnd];

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	Fanatic() {}
	~Fanatic() {}
};


