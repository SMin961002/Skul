#pragma once
class Enemy : public Component
{

private:

	

protected:
	float m_maxhp; // 멤버변수
	float m_currenthp;
	float m_hpbar;
	float m_attack; 
	float m_power;
	Effect* effect;


public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	inline float GetX() { return m_obj->x; }
	inline float GetY() { return m_obj->y; }
	virtual void HitEnemy(float dmg, float time) {}
	// 부모 에너미 -> 자식들 만들어서 하나씩 넣어주면됨
};

