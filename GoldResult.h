#pragma once
class GoldResult : public Component
{
public:
	vImage* img;
	GoldResult() {}
	~GoldResult() {}
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

