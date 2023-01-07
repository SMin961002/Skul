#pragma once
#include "Component.h"
class Card : public Component
{
private:
	const float m_speed = 500;
	CollisionComponent* m_coll;
	vector<Object*> m_vectorCollisionList;
	CImage* m_img;
	float m_startX;
	bool m_isLeft;
	bool m_isJoker;
	bool m_isJokerHit;
	Effect* m_jokerExplosion;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other)override;
	Card(){}
	~Card(){}
};

