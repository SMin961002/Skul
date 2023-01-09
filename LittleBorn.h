#pragma once
#include "Head.h" //94,64 BasicAttack_BasicSkul���� x-30~x+42(�߽��� x+6, ���������� 36). y-56~y+8(�߽��� y-24, ���������� 32)
#include "Enemy.h"
#include "ProjectileHeadSkull.h"
class LittleBorn : public Head
{
private:
	vImage* img_headless[eActionTagNumber];
	ProjectileHeadSkull* m_projectileHead;	//�Ӹ������� ����ü ����ü
	bool m_headThrow;
	int count = 0;
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
	virtual bool GetIsAttack()override;

	void DrawCharactor() override;
	void OnCollisionAutoAttack(Component* enemy, Object* obj, float dmg, float delay) override;

	void PutOnHead()
	{
		m_headThrow = false;
		m_imageChange = true;
		m_skillUsing = false;
		m_skillNowCoolA = 0;
		m_projectileHead->Off();
	};
	virtual void ResetAll() override
	{
		Head::ResetAll();
		m_projectileHead->Off();
	}
};