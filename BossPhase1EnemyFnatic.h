#pragma once
#include "Component.h"
class BossPhase1EnemyFnatic : public Component
{
private:
	CImage* m_ratherImg;
	float m_ratherY;
	int m_state = 0;
	enum State
	{
		eUp,
		eIdle,
		eAttack,
		eWalk,
		eEnd
	};

	vImage* img[State::eEnd];
public:

	BossPhase1EnemyFnatic() {}
	~BossPhase1EnemyFnatic() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

