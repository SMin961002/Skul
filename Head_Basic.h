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