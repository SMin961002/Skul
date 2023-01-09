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
	Effect* effect;


public:
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	inline float GetX() { return m_obj->x; }
	inline float GetY() { return m_obj->y; }
	virtual void HitEnemy(float dmg, float time) {}
	// �θ� ���ʹ� -> �ڽĵ� ���� �ϳ��� �־��ָ��
};

