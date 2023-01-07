#pragma once
#include "Head.h"
class Gambler : public Head
{
	/*
	3Ÿ¥�� �Ϲݰ��� 3Ÿ(Attack_B3) �� �� ���� �����ִ� �������� ĳ���� �����ŭ �̵���
	(nowframe�� 3��°(0,1,2. 2���̹���)�϶����� �ڸ��� ����)
	����� �귿, ��Ʈ���� ��ų���� ������ ������ Attack_B1.
	*/
protected:
	enum ActionTag
	{
		eIdle,
		eWalk,
		eDash,
		eJump,
		eJumpDown,
		eJumpLand,
		eBasicActionTagNumberCount,
		//=��=��=������� �ް��ϸ� �����ൿ=��=��=//
		eAutoAttack_A1 = eBasicActionTagNumberCount,
		eAutoAttack_A2,
		eAutoAttack_B1,
		eAutoAttack_B2,
		eAutoAttack_B3,
		eJumpAttack,
		eSkill_1,
		eSkill_2,
		eTagAction,

		eReborn,

		eActionTagNumber
	};

public:
	bool m_can[eActionTagNumber];
	virtual void ImageSetting() override;
	virtual void ParameterSetting() override;
	virtual void CollisionSetting() override;

	virtual void CoolDown() override;
	virtual void ActionArrangement() override;
	virtual void CollisionUpdate() override;

	virtual void InputSkillKey() override;
	virtual void InputAttackKey() override;

	virtual void TagAction() override;

	virtual void DrawCharactor() override;


};