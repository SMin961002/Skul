#pragma once
class NpcObject : public Component
{
public:
	NpcObject();
	~NpcObject();
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

