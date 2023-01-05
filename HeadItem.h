#pragma once
class HeadItem : public Component
{
private:
	int m_kind;
	CImage* img;
public:
	HeadItem() {}
	~HeadItem() {}
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

