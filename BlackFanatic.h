#pragma once
#include"Enemy.h"
class BlackFanatic :public Enemy
{
private:
	enum IamgeState
	{
		eIdle,
		eAttackIdle,
		eRunAttack,
		eRun,
		eEnd
	};

	vImage* m_vimage[eEnd];

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	BlackFanatic() {}
	~BlackFanatic() {}
};

