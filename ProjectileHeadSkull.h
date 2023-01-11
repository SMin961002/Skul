#pragma once
#include "Component.h"

class LittleBorn;
class ProjectileHeadSkull : public Component
{
	CollisionComponent* m_colHeadSkull;
	CImage* m_img;
	LittleBorn* m_Head;

	bool m_isReverse;
	bool m_hit;
	bool m_on;

	float m_startX;
	float m_startY;
	float m_speed;
	float m_rot;

public:
	float GetX() { return m_obj->x; }
	float GetY() { return m_obj->y; }
	void SetIsntActive() { m_obj->SetIsActive(false); }
	void DestroyProjectileHead() { m_obj->ObjectDestroyed(); }

	void SetSkullThrow(float x, float y, bool reversed);
	bool GetSkullOnOff() { return m_on; }

	void Init();
	void Update();
	void Release() {}
	void Render();
	void Off(); // 머리 안 던졌을때
	void On(); // 머리 던졌을때

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
};

