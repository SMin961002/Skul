#pragma once
#include "Component.h"

class ProjectileHeadSkull : public Component
{
	CollisionComponent* m_colHeadSkull;
	CImage* m_img;
	bool m_isThrowed;
	bool m_isReverse;
	bool m_hit;

	float m_startX;
	float m_startY;
	float m_speed;
	float m_rot;

public:
	float GetX() { return m_obj->x; }
	float GetY() { return m_obj->y; }
	void SetIsntActive() { m_obj->SetIsActive(false); }

	void SetSkullThrow(float x, float y, bool reversed);

	void Init();
	void Update();
	void Release() {}
	void Render();

	void OnCollision(string collisionName, Object* other);

};

