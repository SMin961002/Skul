#pragma once
class NpcObject : public Component
{
public:
	NpcObject();
	~NpcObject();
	vImage* m_npcImage;
	vImage* m_shopImage;
	string m_name;
	// Component을(를) 통해 상속됨
	void Setting(string name);
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

