#pragma once
#include "Head_Basic.h"

//��/��/Comment at End of Page/��/��/
//head�� ������Ʈ�� ����, �Ӹ���ü�� �� init���� m_obj����?
class Player : public Component
{
private:
	enum UITag
	{
		ePlayerStatus,
		eEnd
	};
	CImage* m_UIImage[UITag::eEnd];

	Head* m_headList[1];
	eSkulSpecies m_headSlot;
	Head* m_nowHead;

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
	//============�̵��� �ʿ��� ����end==========
	
	//=============�̵��� �ʿ��� ����===========
	float m_supperArmarTime;
	float m_supperArmarNowTime;
	//============�̵��� �ʿ��� ����end==========

public:
	CollisionComponent* m_playerHitBox;
	CollisionComponent* m_collAutoAttack;
	CollisionComponent* m_collSkill;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;
	virtual void UIRender() override;

	void Move();
	//	in move
	void InputJumpKey();
	void InputDashKey();
	void InputArrowKey();

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
	Head* GetNowHead() { return m_nowHead; }

	//�������� �������� �Է����ּ���
	void HitPlayerPhysicAttack(float dmg)
	{
		m_supperArmarNowTime = m_supperArmarTime;
		m_playerHitBox->SetIsActive(false);
		m_life -= dmg;
		EFFECTMANAGER->AddEffect<PlayerHit>((m_obj->GetComponent<CollisionComponent>()->GetCollisionPosX())
			, m_obj->GetComponent<CollisionComponent>()->GetCollisionPosY(), m_isLeft);
	}
	//�������� �������� �Է����ּ���
	void HitPlayerMagicAttack(float dmg)
	{
		m_supperArmarNowTime = m_supperArmarTime;
		m_playerHitBox->SetIsActive(false);
		m_life -= dmg;
		EFFECTMANAGER->AddEffect<PlayerHit>((m_obj->GetComponent<CollisionComponent>()->GetCollisionPosX())
			, m_obj->GetComponent<CollisionComponent>()->GetCollisionPosY(), m_isLeft);
	}
	//�ǰݽ� �÷��̾� �и�(�÷��̾ x+moveX, y+moveY����Ʈ�� �Ű����ϴ�)
	void HitPlayerKnockBack(float moveX, float moveY)
	{
		m_obj->x += (m_isLeft ? moveX : -moveX);
		m_obj->y += moveY;
	}

	void InputArtifactKey();
	bool  m_haveArtifact;

	virtual void OnCollision(string collisionName, Object* other) override;
	float GetplayerX(void) { return m_obj->x; }
	float GetplayerY(void) { return m_obj->y; }

	Player() : m_life(100) {};
};


/*
	/ C / O / M / M / E / N / T /

# �߰��۾� �ʿ��� �κ��� �ڵ� �߰��� ##�� ǥ���صξ���.

# jump, dash�κ� ���� �ʿ�
 - jump ��ü �����ؾ���
 - ���ݸ�� ���
 - ��ų ���

 - effect ���
 - �߻�ȭ(������!)

 # ��Ƽ��Ʈ ��� ������ų������



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