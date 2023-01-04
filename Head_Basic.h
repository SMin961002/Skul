#pragma once
#include "Head.h" //94,64 BasicAttack_BasicSkul���� x-30~x+42(�߽��� x+6, ���������� 36). y-56~y+8(�߽��� y-24, ���������� 32)
#include "Enemy.h"
class ProjectileHeadSkull;
class Head_Basic : public Head
{
private:
	vImage* img_headless[eActionTagNumber];
	ProjectileHeadSkull* m_projectileHead;	//�Ӹ������� ����ü ����ü
	bool m_headThrow;

public:
	void ImageSetting() override;
	void ParameterSetting() override;
	void CollisionSetting() override;

	void CoolDown() override;

	void ActionArrangement() override;
	void CollisionUpdate() override;

	void InputAttackKey() override;

	void DrawCharactor() override;

	void InputSkillKey();
};

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
	float GetX(){ return m_obj->x; }
	float GetY(){ return m_obj->y; }

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
				m_rot +=30;
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