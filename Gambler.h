#pragma once
#include "Head.h"
class Roulette;
class Gambler : public Head
{
	/*
	3Ÿ¥�� �Ϲݰ��� 3Ÿ(Attack_B3) �� �� ���� �����ִ� �������� ĳ���� �����ŭ �̵���
	(nowframe�� 3��°(0,1,2. 2���̹���)�϶����� �ڸ��� ����)
	����� �귿, ��Ʈ���� ��ų���� ������ ������ Attack_B1.
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