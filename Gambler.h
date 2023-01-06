#pragma once
#include "Head.h"
class Gambler : public Head
{
	/*
	3타짜리 일반공격 3타(Attack_B3) 들어갈 때 현재 보고있는 방향으로 캐릭터 사이즈만큼 이동함
	(nowframe이 3번째(0,1,2. 2번이미지)일때부터 자리에 고정)
	운명의 룰렛, 다트레인 스킬사용시 나오는 동작은 Attack_B1.
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
		//=↑=↑=여기까진 앵간하면 고정행동=↑=↑=//
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