#pragma once
class Enemy : public Component
{

private:

	

protected:
	float m_maxhp; // �������
	float m_currenthp;
	float m_hpbar;
	float m_attack; 
	float m_power;


public:
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg) {}
	// �θ� ���ʹ� -> �ڽĵ� ���� �ϳ��� �־��ָ��
};

