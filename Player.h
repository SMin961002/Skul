#pragma once
#include "Component.h"

//��/��/Comment at End of Page/��/��/

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

	�ൿ���� �̹��� delay
	*/

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
		eAutoAttack_1= eBasicActionTagNumberCount,
		eAutoAttack_2,
		eJumpAttack,
		eSkill_1,
		eSkill_2,
		eAppearEffect,

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

	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_down;
		  
	float m_dashSpeed;		//��� �ӵ� (����->���� ����ʿ�)
	float m_dashCool;		//��� ������ ���� ��ü�Ʈ ���۱��� �ɸ��� ��Ÿ��
	float m_dashNowCool;	//���� ��� ��Ÿ�� (0 �Ǹ� ���� ��� ����)
//�������� �̿� ������� ���Ÿ�ӵ��� ƽ�� �̵��Ÿ� ����� �� �ʿ��� ���� ���� �� ���Ƽ� ���ܵ�
	float m_dashTime;		//��� �ߵ��Ǵ� �ð� (�� �ȿ� �Է��ؾ� 2�ܴ�� ����)
	float m_dashNowTime;	//��� �� ������ �ð�
//�������� �̿� �������
	short m_dashCount;		//���� ��ȸ�� �������
	short m_dashMax;		//�ִ� ��� ���� Ƚ��
	bool  m_dashing;

	float m_jumpSpeed;		//���� ���ۼӵ�
	float m_jumpNowSpeed;	//���� �ӵ� (����->����, �ӵ� -�Ǹ� jumpDown 2���� ����ʿ�)
	short m_jumpCount;		//���� ���� ��ȸ����
	short m_jumpMax;		//�ִ� ���� ���� Ƚ��		
	bool  m_jumpping;
		  
	short m_attackCount;
	bool  m_attackCast;		//1Ÿ�� �ƹ����� ����Ű 1ȸ ������ �׼� ������ 2Ÿ�� �̾ �ߵ��ȴ�.

	float m_skillCoolA;
	float m_skillNowCoolA;
	float m_skillCoolS;
	float m_skillNowCoolS;
	bool  m_skillUsing;
	float m_artifactCoolD;
	float m_artifactNowCoolD;
	bool  m_haveArtifact;

	bool  m_commandInput;	//���� ������ �Է��ϸ� true�� �ȴ�.
		  
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
	virtual void OnCollision(Object* other) override;
	float GetplayerX(void) { return m_obj->x; }

	virtual void Move();
	virtual void Act();

	//Update �ȿ� ���� �Լ�
	virtual void InputArtifactKey();
	//	in move
	virtual void InputJumpKey();
	virtual void InputDashKey();
	virtual void InputArrowKey();
	//	in act
	virtual void InputAttackKey();
	virtual void InputSkillKey();

	//Render �ȿ� ���� �Լ�
	virtual void DrawCharactor();
	virtual void DrawEffect();	//����Ʈ�� ������Ʈ��� �����ϰ� �����Ҹ��Ű��.

	void ResetAll()
	{
		ResetJump();
		ResetDash();
		ResetSkill();
		m_commandInput = false;
		m_down = false;
		m_action = eIdle;
	}
	void ResetJump() {
		m_jumpCount = 0;
		m_jumpping = false;
		m_jumpNowSpeed = 0;
		m_down = false;
	}
	void ResetDash() {
		m_dashCount = 0;
		m_dashing = false;
		m_dashNowTime = 0;
		m_dashNowCool = 0;
	}
	void ResetSkill() {
		m_skillNowCoolA = 0;
		m_skillNowCoolS = 0;
		m_skillUsing = false;
	}
};


/*
	/ C / O / M / M / E / N / T /

# �߰��۾� �ʿ��� �κ��� �ڵ� �߰��� ##�� ǥ���صξ���.

# jump, dash�κ� ���� �ʿ�
 - jump ��ü �����ؾ���
 - ���ݸ�� ���
 - ��ų ���
 
 - effect ���
 - �߻�ȭ





�� �۾����� ��
12/30

12/29
1. ��ü������ ��� �۵� ��� �����Ͽ����ϴ�.
	- Ŀ��� �Է½� ���ۺ� tick �ְ�, update�ÿ� -DELTA_TIME �� �� 0�� �Ǹ� Idle�� ������ ��Ŀ���
	  Image delay�� �̿��� ���� �����ϴ� ������� ����
	  | ���ڿ������� �ȱ��� ������
	  | 
	- Ű�Է½� action�� ������ �ִ´�
	  : �� ���� �켱������ ���� ������ �Է��� �ڿ��� �޾ƿ´� (���������� �ڿ� �Է��� ������ ��µ�)
	    ���, ������ ��� �̹����� ĵ���ŵ� ����, ���� ������ �����ִ� ��찡 �ټ��� ���� bool���� �־���
2. �̹����� �����Ӻ� ü���ð��� �־����ϴ�. (�¿��� ���� �Ϸ�)
*/