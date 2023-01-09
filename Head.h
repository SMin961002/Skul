#pragma once
#include "PlayerEffect.h"

class Enemy;
//�Ӹ����� ��¹޴� ����Ŭ����
class Head
{
public:
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
		eAutoAttack_1 = eBasicActionTagNumberCount,
		eAutoAttack_2,
		eAutoAttack_3,
		eJumpAttack,
		eSkill_1,
		eSkill_2,
		eTagAction,

		eReborn,

		eActionTagNumber
	};

	typedef list<Object*> listObj;
protected:
	eSkulSpecies m_species;
	Object* m_obj;
	vImage* img[20];
	vImage* img_reborn;
	vImage* nowImg;
	listObj m_CollObjList;
	CollisionComponent* m_collAutoAttack;	//##���� �ߵ��ϸ� ���⿡ ����collision�� �����Ѵ�.
	CollisionComponent* m_collSkillA;	//##��ų �ߵ��ϸ� ���⿡ ��ų collision�� �����Ѵ�.
	CollisionComponent* m_collSkillS = nullptr;	//##��ų �ߵ��ϸ� ���⿡ ��ų collision�� �����Ѵ�.
	CollisionComponent* m_collSkillTag;	//##��ų �ߵ��ϸ� ���⿡ ��ų collision�� �����Ѵ�.
	float m_tagCoolTime;

	//�̹���, �ð����� ����
	int m_action;

	float* m_x = nullptr, * m_y = nullptr;
	bool* m_isLeft = nullptr;
	bool* m_isDown = nullptr;
	bool*  m_dashing;
	bool*  m_jumpping;

	//=============�̵��� �ʿ��� ����===========
	float m_moveSpeed;

	float m_dashSpeed;		//��� �ӵ� (����->���� ����ʿ�)
	float m_dashCool;		//��� ������ ���� ��ü�Ʈ ���۱��� �ɸ��� ��Ÿ��
	float m_dashNowCool;	//���� ��� ��Ÿ�� (0 �Ǹ� ���� ��� ����)
	float m_dashTime;		//��� �ߵ��Ǵ� �ð� (�� �ȿ� �Է��ؾ� 2�ܴ�� ����)
	float m_dashNowTime;	//��� �� ������ �ð�
	short m_dashCount;		//���� ��ȸ�� �������
	short m_dashMax;		//�ִ� ��� ���� Ƚ��

	float m_jumpSpeed;		//���� ���ۼӵ�
	short m_jumpCount;		//���� ���� ��ȸ����
	short m_jumpMax;		//�ִ� ���� ���� Ƚ��		
	//============�̵��� �ʿ��� ����end==========

	short m_attackCount;
	short m_attackMax;
	bool  m_attackCast[2];		//1Ÿ�� �ƹ����� ����Ű 1ȸ ������ �׼� ������ 2Ÿ�� �̾ �ߵ��ȴ�.

	float m_skillCoolA;
	float m_skillNowCoolA;
	float m_skillCoolS;
	float m_skillNowCoolS;
	bool  m_skillUsing;

	bool  m_imageChange;	//���� ������ �Է��ϸ� true�� �ȴ�.
	bool m_canAction[eActionTagNumber];

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	void SetObject(Object* obj) { m_obj = obj; }
	inline void SetPlayerXY(float* x, float* y, bool* left, bool* down) { m_x = x, m_y = y, m_isLeft = left; }
	inline void SetImageChange(bool tf) { m_imageChange = tf; }
	inline void SetImage(int image, bool isImageEqualAction = true, int action = eIdle)
	{
		nowImg->Reset();
		img[image]->Reset();
		nowImg = img[image];
		m_action = isImageEqualAction ? image : action;
	}
	inline void SetAction(int action, bool doWantToChangeImage=true, bool actionImageReset = false)
	{
		m_action = action;
		if (doWantToChangeImage) { m_imageChange = true; }
		if (actionImageReset) { img[action]->Reset(); }
	}
	inline eSkulSpecies GetSpecies() { return m_species; }
	virtual bool GetIsAttack() PURE;
	inline int GetAction() { return m_action; }
	inline float GetTagCoolTime() { return m_tagCoolTime; }
	inline float GetActionTime(int action) { return img[action]->GetTotalDelay(); }
	inline float GetNowActionTime() { return img[m_action]->GetTotalDelay(); }
	inline CollisionComponent* GetCollAutoAttack() { return m_collAutoAttack; }
	inline CollisionComponent* GetCollSkill() { return m_collSkillA; }
	
	virtual void ImageSetting() {};
	virtual void ParameterSetting() {};
	virtual void CollisionSetting() {};
	virtual void CollisionResetting(Object* obj, CollisionComponent* autoAttack, CollisionComponent* skill1,CollisionComponent* skill2, CollisionComponent* tag)
	{
		m_collAutoAttack = autoAttack;
		m_collSkillA = skill1;
		m_collSkillS = skill2;
		m_collSkillTag = tag;
		
		CollisionSetting();
	};

	//Update �ȿ� ���� �Լ�
	virtual void Act();

	virtual void CoolDown() {};
	virtual void ActionArrangement() {};
	virtual void CollisionUpdate() {};
	//	in act
	virtual void InputSkillKey() {};
	virtual void InputAttackKey() {};

	virtual void TagAction() {};

	//Render �ȿ� ���� �Լ�
	virtual void DrawCharactor();
	virtual void OnCollisionAutoAttack(Component* enemy, Object* obj, float dmg, float delay)
	{
		bool isEnemyHit = false;
		for (auto iter : m_CollObjList)
		{
			if (iter == obj) isEnemyHit = true;
		}
		if (!isEnemyHit)
		{
			enemy->HitEnemy(dmg, delay);
			m_CollObjList.push_back(obj);
		}
	};

	void SetPlayerMoveParameter(float* moveSpeed, float* dashSpeed, float* dashtime, short* dashMax, bool* dashing,float* jumpSpeed, short* jumpMax, bool* jumpping)
	{
		*moveSpeed = m_moveSpeed;
		*dashSpeed = m_dashSpeed;
		*dashtime = m_dashTime;
		*dashMax = m_dashMax;
		m_dashing = dashing;
		*jumpSpeed = m_jumpSpeed;
		*jumpMax = m_jumpMax;
		m_jumpping = jumpping;
	}

	virtual void ResetAll()
	{
		ResetAttack();
		ResetSkill();
		m_imageChange = false;
		m_action = eIdle;
	}
	void ResetAttack() {
		m_attackCast[0] = false;
		m_attackCast[1] = false;
		m_attackCount = 0;
	}
	void ResetSkill() {
		m_skillNowCoolA = 0;
		m_skillNowCoolS = 0;
		m_skillUsing = false;
	}
};