#pragma once
#include "Component.h"

enum class eSkulSpecies
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler
};

//�Ӹ����� ��¹޴� ����Ŭ����
class Head : public Component
{
public:
	virtual enum ActionTag
	{
		eIdle = 0,
		eWalk,
		eDash,
		eJump,
		eJumpDown,
		eJumpLand,
		eBasicActionTagNumberCount,
		//=��=��=������� �ް��ϸ� �����ൿ=��=��=//
		eAutoAttack_1 = eBasicActionTagNumberCount,
		eAutoAttack_2,
		eJumpAttack,
		eSkill_1,
		eSkill_2,
		eAppearEffect,

		eReborn,

		eActionTagNumber
	};

	virtual enum eCollisionArrTag
	{
		eAutoAttack_1coll,
		eAutoAttack_2coll,
		eSkill_1coll,
		eSkill_2coll,

		eCollisionArrTagNumCount
	};

protected:
	eSkulSpecies m_species;

	vImage* img[eActionTagNumber];
	vImage* img_reborn;
	vImage* nowImg;

	//�̹���, �ð����� ����
	ActionTag m_action;

	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_isDown;

	float m_dashSpeed;		//��� �ӵ� (����->���� ����ʿ�)
	float m_dashCool;		//��� ������ ���� ��ü�Ʈ ���۱��� �ɸ��� ��Ÿ��
	float m_dashNowCool;	//���� ��� ��Ÿ�� (0 �Ǹ� ���� ��� ����)
	float m_dashTime;		//��� �ߵ��Ǵ� �ð� (�� �ȿ� �Է��ؾ� 2�ܴ�� ����)
	float m_dashNowTime;	//��� �� ������ �ð�
	short m_dashCount;		//���� ��ȸ�� �������
	short m_dashMax;		//�ִ� ��� ���� Ƚ��
	bool  m_dashing;

	float m_jumpSpeed;		//���� ���ۼӵ�
	float m_jumpNowSpeed;	//���� �ӵ� (����->����, �ӵ� -�Ǹ� jumpDown 2���� ����ʿ�)
	short m_jumpCount;		//���� ���� ��ȸ����
	short m_jumpMax;		//�ִ� ���� ���� Ƚ��		
	bool  m_jumpping;

	short m_attackCount;
	short m_attackMax;
	bool  m_attackCast;		//1Ÿ�� �ƹ����� ����Ű 1ȸ ������ �׼� ������ 2Ÿ�� �̾ �ߵ��ȴ�.

	float m_skillCoolA;
	float m_skillNowCoolA;
	float m_skillCoolS;
	float m_skillNowCoolS;
	bool  m_skillUsing;

	bool  m_imageChange;	//���� ������ �Է��ϸ� true�� �ȴ�.

public:
	void Init();
	void Update();
	void Render();
	void Release();

	virtual void ImageSetting();
	virtual void ParameterSetting();
	virtual void CollisionSetting();

	virtual void CoolDown();
	virtual void Move();
	virtual void Act();

	//Update �ȿ� ���� �Լ�
	virtual void ActionArrangement();
	virtual void CollisionUpdate();
	//	in move
	virtual void InputJumpKey();
	virtual void InputDashKey();
	virtual void InputArrowKey();
	//	in act
	virtual void InputSkillKey();
	virtual void InputAttackKey();


	//Render �ȿ� ���� �Լ�
	virtual void DrawCharactor();
	virtual void DrawEffect();	//����Ʈ�� ������Ʈ��� �����ϰ� �����Ҹ��Ű��.

	void ResetAll()
	{
		ResetJump();
		ResetDash();
		ResetAttack();
		ResetSkill();
		m_imageChange = false;
		m_action = eIdle;
	}
	void ResetJump() {
		m_jumpCount = 0;
		m_jumpping = false;
		m_jumpNowSpeed = 0;
	}
	void ResetDash() {
		m_dashCount = 0;
		m_dashing = false;
		m_dashNowTime = 0;
		m_dashNowCool = 0;
	}
	void ResetAttack() {
		m_attackCast = false;
		m_attackCount = 0;
	}
	void ResetSkill() {
		m_skillNowCoolA = 0;
		m_skillNowCoolS = 0;
		m_skillUsing = false;
	}
};

