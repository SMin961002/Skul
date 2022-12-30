#pragma once
#include"Enemy.h"
class TentaclesOfLight :public Enemy
{
private:
	enum IamgeState
	{
		eIdle,
		eAttack,
		eRecovery,
		eEnd
	};

	vImage* m_vimage[eEnd];
	bool m_attack;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(Object* other) override;

};

