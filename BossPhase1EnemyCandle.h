#pragma once
#include "Component.h"

class BossPhase1EnemyCandle : public Component
{
private:
	float m_ratherY;
	CImage* m_ratherImg;
	vImage * img;
public:
	BossPhase1EnemyCandle() {}
	~BossPhase1EnemyCandle() {}

	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

