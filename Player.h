#pragma once
#include "LittleBorn.h"
#include "Gambler.h"
//!!!!���Ͱ� ������!!!!//
//��/��/Comment at End of Page/��/��/
//.......!...
class Player : public Component
{
private:
	enum UITag
	{
		ePlayerStatus,
		eEnd
	};
	CImage* m_UIImage[UITag::eEnd];

	Head* m_headList[static_cast<int>(eSkulSpecies::Empty) +1];
	eSkulSpecies m_headSlot;
	Head* m_nowHead;
	float m_headTagCool;

	int m_HpMax;
	int m_life;
	float m_attack;
	float m_deffendence;

	float m_artifactCoolD;
	float m_artifactNowCoolD;

	//=============�̵��� �ʿ��� ����===========
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
	short m_jumpCount;		//���� ���� ��ȸ����
	short m_jumpMax;		//�ִ� ���� ���� Ƚ��		
	bool  m_jumpping;

	int m_knockBackY;
	bool m_knockBack;
	//============�̵��� �ʿ��� ����end==========
	
	//========================
	float m_supperArmarTime;
	float m_supperArmarNowTime;
	//============end==========
	TeleportationToHead* effect = new TeleportationToHead;

public:
	CollisionComponent* m_playerHitBox;
	CollisionComponent* m_collAutoAttack;
	CollisionComponent* m_collSkillA;
	CollisionComponent* m_collSkillS;
	CollisionComponent* m_collSkillTag;

	bool  m_haveArtifact;
public:
	float GetplayerX(void) { return m_obj->x; }
	float GetplayerY(void) { return m_obj->y; }
	bool GetplayerIsLeft(void) { return m_isLeft; }
	Head* GetNowHead() { return m_nowHead; }

	//�������� �������� �Է����ּ���
	void HitPlayerPhysicAttack(float dmg);
	//�������� �������� �Է����ּ���
	void HitPlayerMagicAttack(float dmg);
	//�÷��̾� �ǰݽ� �и�(�÷��̾ x+moveX, y+moveY����Ʈ�� �Ű����ϴ�)
	void HitPlayerKnockBack(float moveX, float moveY);

	//�÷��̾� �ǰݽ� ����Ʈ(�Ϲ�Ÿ)
	void HitPlayerEffect();
	//�÷��̾� �ǰݽ� ����Ʈ(ũ��Ƽ��)(���� ��ä���� ������ �ȶ�ϴ�)
	void CritialHitPlayerEffect();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;
	virtual void UIRender() override;

	virtual void OnCollision(string collisionName, Object* other) override;
	void InputArtifactKey();

	//��====PlayerMove.cpp�� �ֽ��ϴ�====��//
	void Move();
	//	in move
	void InputJumpKey();
	void InputDashKey();
	void InputArrowKey();
	//��====PlayerMove.cpp�� �ֽ��ϴ�====��//
	void ResetJump() {
		m_jumpCount = 0;
		m_jumpping = false;
	}
	void ResetDash() {
		m_dashCount = 0;
		m_dashing = false;
		m_dashNowTime = 0;
		m_dashNowCool = 0;
	}

	void CoolDown();
	void ChangeHead();
	void GetHead(eSkulSpecies type)
	{
		if (m_headSlot == eSkulSpecies::Empty)
		{

		}
		else
		{
			Head* tmp = m_nowHead;
		}
	}
	void HeadChangeCollResetting(bool collDelete)
	{
		if (collDelete)
		{
		}
	}
	Player() : m_life(100) {};
};


/*
	/ C / O / M / M / E / N / T /

# �߰��۾� �ʿ��� �κ��� �ڵ� �߰��� ##�� ǥ���صξ���.

# dash�κ� ���� �ʿ�

			
			���� �׼�
			������
			������(�̹���)
			HPUI
			�ذ��̹��� ����

			���ϸ� ��Ż�� (��ȭ ��/�� �ֱ�)
			

 - �÷��̾� 1Ÿ�� ������ 2Ÿ�� �ȳ����� ���� �����ϱ�
 - effect ���
 - �߻�ȭ(������!)

 # ��Ƽ��Ʈ ��� ������ų������

 on collision�Լ� �ߵ���
 head�� OnCollision�Լ��� �����ͼ� �����Ų��.

bool canWalk, canDash, canJump, canSkillA, B, canAttack����� ���� ����
update���� �ش� ���� on off �Լ����� �����ϴ� ��� ����غ���
�� �۾����� ��
1/4
�ؾ��� �� : Hit����Ʈ �̹��� �߽ɸ��߱�
			�±� �׼� �����
			�Ӹ��� ������ ���� �÷��̾�� �̰�
			���� ��ġ��
			�浹 ��ġ��

1/3
������ �����Ƚ�....
A, S��ų ���� ��
����Ʈ �־���
�浹�Լ�����

1/2
basic skul A, S�����

A ����ü �غ� ��ġ��
S ��ǥ�̵� ����

1/1
			jump�����
			����, ��� ����Ʈ �����

12/31
	�����浹�α���

12/30
...

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