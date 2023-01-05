#pragma once
#include "Component.h"

class BossPhase1EnemyCandle : public Component
{
private:
	float m_ratherY;
	CImage* m_ratherImg;
	int m_state = 0;
	enum State
	{
		eUp,
		eIdle,
		eAttack,
		eAttackReady,
		eWalk,
		eEnd
	};
	bool m_isL;

	vImage* img[State::eEnd];
public:
	BossPhase1EnemyCandle() {}
	~BossPhase1EnemyCandle() {}

	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

