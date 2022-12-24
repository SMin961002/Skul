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
	
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	LeoniaSoldier() {}
	~LeoniaSoldier() {}
};

