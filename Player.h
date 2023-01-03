#pragma once
#include "Head_Basic.h"

//��/��/Comment at End of Page/��/��/
//head�� ������Ʈ�� ����, �Ӹ���ü�� �� init���� m_obj����?
class Player : public Component
{
	/*
	����2ȸ, ���2ȸ ���Ⱑ��
	������ ��� �� ���ƿ��� �� ��� ��Ʈ ����,
	1����->2�ܴ��->2����->2�ܴ��->����������� 2�ܴ�� ����
	(�߶����� ������ �߰���� �� ����)
	
	1ȸ�� ��� ���� �����ð� �̳��� ���Ű ������ 2ȸ�� ��� ����
	(�ȱ׷��� �� ���ư�. �� ���������� ��� �Ұ�)
	��� ��Ž�м���
	���������� ��ȸ���� �Ǵ��� �м� �ʿ�

	�ൿ���� �̹��� delay
	*/

private:
	enum UITag
	{
		ePlayerStatus,
		eEnd
	};
	CImage* m_UIImage[UITag::eEnd];

	Head* m_headList[1];
	Head* m_headSlot[2];
	Head* m_nowHead;
	RECT m_hitBox;

	int m_life;
	float m_attack;
	float m_deffendence;

	float m_artifactCoolD;
	float m_artifactNowCoolD;

public:
	CollisionComponent* coll;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;
	virtual void UIRender() override;

	//�������� �������� �Է����ּ���
	void HitPlayerPhysicAttack(float dmg)
	{
		m_life -= dmg;
	}
	//�������� �������� �Է����ּ���
	void HitPlayerMagicAttack(float dmg)
	{
		m_life -= dmg;
	}
	//�ǰݽ� �÷��̾� �и�(�÷��̾ x+moveX, y+moveY����Ʈ�� �Ű����ϴ�)
	void HitPlayerKnockBack(float moveX, float moveY)
	{
		m_obj->x += moveX;
		m_obj->y += moveY;
	}

	void InputArtifactKey();	
	bool  m_haveArtifact;

	void OnCollision(string collisionName, Object* other);
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



�� �۾����� ��
1/2
�����Ұ� : basic skul A, S�����
bool canWalk, canDash, canJump, canSkillA, B, canAttack����� ���� ����
update���� �ش� ���� on off �Լ����� �����ϴ� ��� ����غ���

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