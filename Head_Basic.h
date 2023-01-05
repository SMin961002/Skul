#pragma once
#include "Head.h" //94,64 BasicAttack_BasicSkul���� x-30~x+42(�߽��� x+6, ���������� 36). y-56~y+8(�߽��� y-24, ���������� 32)
#include "Enemy.h"
#include "ProjectileHeadSkull.h"
class Head_Basic : public Head
{
private:
	vImage* img_headless[eActionTagNumber];
	ProjectileHeadSkull* m_projectileHead;	//�Ӹ������� ����ü ����ü
	bool m_headThrow;

	CollisionComponent* m_BasicHeadAttack;
	CollisionComponent* m_TagAttack;

public:
	void ImageSetting() override;
	void ParameterSetting() override;
	void CollisionSetting() override;

	void Release() override;

	void CoolDown() override;

	void ActionArrangement() override;
	void CollisionUpdate() override;

	void InputAttackKey() override;
	void InputSkillKey() override;

	void TagAction() override;

	void DrawCharactor() override;
	void OnCollisionAutoAttack(Enemy* obj, float dmg) override;

	void PutOnHead()
	{
		m_skillNowCoolA = 0;
		m_headThrow = false;
		m_imageChange = true;
		m_skillUsing = false;
		m_projectileHead->Off();
	};
	void OnCollision(string collisionName, Object* other)
	{}
};