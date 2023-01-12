#pragma once
#include "Component.h"
#include "Enemy.h"

class HolyOrbLeft;
class HolyOrbRight;
class HolyFountainLeft : public Enemy
{
private:
	vImage* _imgLeftFountainActivate;
	CImage* _imgLeftFountainDeActivate;

	CollisionComponent* _collisionLeft;
	HolyOrbLeft* left;
	HolyOrbLeft* leftEnd;
	bool _isLeftPlayOn;

	float m_MaxHP;
	float m_CurrentHP;
	float m_HPBarTimer;
	float m_HPBar;
	float m_DieTimer;

	bool m_Hit;
	float alpha = 0;

public:
	float getLeftCurrentHP() { return m_CurrentHP; }
	void setLeftCurrentHP(float a) { m_CurrentHP = a; }
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg, float time);
	HolyFountainLeft() {}
	~HolyFountainLeft() {}
};

class HolyFountainRight : public Enemy
{
private:
	vImage* _imgRightFountainActivate;
	CImage* _imgRightFountainDeActivate;
	HolyOrbRight* right;
	HolyOrbRight* rightEnd;
	CollisionComponent* _collisionRight;

	bool _isRightPlayOn;

	float m_MaxHP;
	float m_CurrentHP;
	float m_HPBarTimer;
	float m_HPBar;
	float m_DieTimer;

	bool m_Hit;
	float alpha = 0;
public:

	void setRightCurrentHP(float a) { m_CurrentHP = a; }
	float getRightCurrentHP() { return m_CurrentHP; }
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg, float time);

	HolyFountainRight() {}
	~HolyFountainRight() {}
};

class HolyOrbLeft : public Component
{
	vImage* _imgLeftOrbStart;
	vImage* _imgLeftOrbActing;
	vImage* _imgLeftOrbEnd;

	bool _isLeftPlayOn;
	bool _isLeftOrbActing;
public:
	bool isLeftDes;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	HolyOrbLeft() {}
	~HolyOrbLeft() {}
};

class HolyOrbRight : public Component
{
	vImage* _imgRightOrbStart;
	vImage* _imgRightOrbActing;
	vImage* _imgRightOrbEnd;

	bool _isRightPlayOn;
	bool _isRightOrbActing;
public:
	bool isRightDes;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	HolyOrbRight() {}
	~HolyOrbRight() {}
};