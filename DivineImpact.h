#pragma once
class DivineImpact : public Component
{
public:
	vImage* img;
	DivineImpact() {}
	~DivineImpact() {}
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

