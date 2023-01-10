#pragma once
#include "Head.h"
class Roulette;
class Gambler : public Head
{
	/*
	3타짜리 일반공격 3타(Attack_B3) 들어갈 때 현재 보고있는 방향으로 캐릭터 사이즈만큼 이동함
	(nowframe이 3번째(0,1,2. 2번이미지)일때부터 자리에 고정)
	운명의 룰렛, 다트레인 스킬사용시 나오는 동작은 Attack_B1.
	*/
private:
	bool m_effectOverap;
	bool m_blackJackOn;
	int m_blackJackShotCount;
	int m_blackJack;
	float m_blackJackDelay;
	float m_blackJackNowDelay;

	Roulette* m_roulette;

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
	virtual bool GetIsAttack() override;

	virtual void DrawCharactor() override;

};