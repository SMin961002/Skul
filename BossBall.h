#pragma once
#include "Component.h"
class BossBall : public Component
{
	enum BallState
	{
		eStart,
		eIdle,
		eDis,
		eEnd
	};
	float startX, startY;
	int m_state;
	float rot;
	float dist;
public:
	BossBall();
	~BossBall();
	vImage* img[3];
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void Setting(float rot);
};

