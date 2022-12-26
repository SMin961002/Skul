#pragma once
#include "Component.h"

//#define MOVE_SPEED				3
//#define JUMP_SPEED				3
//#define DASH_MULTIPLE			2
//#define DASH_COLLTIME			
//#define COMMAND_ReENTRY_TIME	
//#define HISTORY_MAX				10

enum SkulTag
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler
};
class Player : public Component
{
	/*
	����2ȸ, ���2ȸ ���Ⱑ��
	������ ��� �� ���ƿ��� �� ��� ��Ʈ ����,
	1����->2�ܴ��->2����->2�ܴ��->����������� 2�ܴ�� ����
	(�߶����� ������ �߰���� �� ����)
	ù ��� ������ �������� 2ȸ�� ��� ����
	
	1ȸ�� ��� ���� �����ð� �̳��� ���Ű ������ 2ȸ�� ��� ����
	(�ȱ׷��� �� ���ư�. �� ���������� ��� �Ұ�)
	��� ��Ž�м���
	���������� ��ȸ���� �Ǵ��� �м� �ʿ�
	*/

public:
	virtual enum ActionTag
	{
		eIdle=0,
		eWalk,
		eDash,
		eAutoAttack_1,
		eAutoAttack_2,
		eJump,
		eJumpDown,
		eSkill_1,
		eSkill_2,

		eActionTagNumber
	};

protected:
	vImage* img[eActionTagNumber];
	vImage* img_reborn;
	vImage* img_jumpFall;
	vImage* nowImg;
	RECT m_hitBox;

	//�̹���, �ð����� ����
	ActionTag m_action;
	ActionTag m_action_prev;
	float m_actionTick;		//�ൿ���ӽð�

	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_down;
	bool  m_commandInput;
		  
	float m_dashSpeed;		//��� �ӵ� (����->���� ����ʿ�)
	float m_dashDelay;		//��� ������ ���� ��ü�Ʈ ���۱��� �ɸ��� ��Ÿ��
	float m_dashTime;		//��� �ߵ��Ǵ� �ð� (�� �ȿ� �Է��ؾ� 2�ܴ�� ����)
	short m_dashCount;		//���� ��ȸ�� �������
	short m_dashMax;		//�ִ� ��� ���� Ƚ��
		  
	float m_jumpSpeed;		//���� ���ۼӵ�
	float m_jumpGravity;	//���� �ӵ� (����->����, �ӵ� -�Ǹ� jumpDown 2���� ����ʿ�)
	short m_jumpCount;		//���� ���� ��ȸ����
	short m_jumpMax;		//�ִ� ���� ���� Ƚ��		  
		  
	float m_attackWaitingTime;
	short m_attackCount;
		  
	float m_skillCoolA;
	float m_skillCoolS;
	float m_skillCoolD;

//���ݽ�ų 2����
//�Ϲݰ���
//����
//��������
//���
//�̵�

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void Move();
	//virtual void Action();
	virtual void Draw();
};