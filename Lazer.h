#pragma once
class Lazer : public Component
{
public:
	enum LazerState
	{
		eStart,
		eLoop,
		eLast,
		eEnd
	};
	vImage* img[eEnd];
	int m_state;
	Lazer() {}
	~Lazer() {}

	CollisionComponent* collll1;
	CollisionComponent* collll2;
	CollisionComponent* collll3;
	CollisionComponent* collll4;
	// Component��(��) ���� ��ӵ�

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

