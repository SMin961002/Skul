#pragma once
class Enemy : public Component
{

private:

	

protected:
	float m_hp; // 멤버변수
	float m_attack; 
	float m_power;


public:
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg) {}
	// 부모 에너미 -> 자식들 만들어서 하나씩 넣어주면됨
};

