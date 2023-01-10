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
	~Lazer() { }
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

