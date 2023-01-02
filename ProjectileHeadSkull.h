#pragma once

class ProjectileHeadSkull : public Component
{
	CollisionComponent* m_colHeadSkull;
	CImage* m_img;
	bool m_isThrowed;
	bool m_isReverse;
	bool m_hit;
	float m_speed;
	float m_rot;

public:
	float GetX() { return m_obj->x; }
	float GetY() { return m_obj->y; }

	void SetSkullThrow(float x, float y, bool reversed)
	{
		m_obj->x = x;
		m_obj->y = y;
		m_isReverse = reversed;
		m_isThrowed = true;
		m_hit = false;
		m_rot = 0;
	}

	void Init();
	void Update()
	{
		if (!m_hit)
		{
			if (m_isReverse)
			{
				m_obj->x -= 60 * DELTA_TIME;
				m_obj->y += 1;
				m_rot += 30;
			}
			else
			{
				m_obj->x += 60 * DELTA_TIME;
				m_obj->y += 1;
				m_rot -= 30;
			}
		}//end nonhit
	}//end update
	void Render()
	{
		IMAGEMANAGER->CenterRender(m_img, m_obj->x, m_obj->y, 2, 2, m_rot, m_isReverse);
	}
	void Release() {}

	void OnCollision(string collisionName, Object* other);

};

