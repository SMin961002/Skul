#pragma once
class HitDamageEffect : public Component
{
public:
	float Dmg;
	HitDamageEffect() {}
	~HitDamageEffect() {}
	float rot;
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void Setting(float dmg);
};

