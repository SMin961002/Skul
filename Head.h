#pragma once
#include "PlayerEffect.h"

class Enemy;
//머리들이 계승받는 상위클래스
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
		//=↑=↑=여기까진 앵간하면 고정행동=↑=↑=//
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
	CollisionComponent* m_collAutoAttack;	//##공격 발동하면 여기에 어택collision을 대입한다.
	CollisionComponent* m_collSkillA;	//##스킬 발동하면 여기에 스킬 collision을 대입한다.
	CollisionComponent* m_collSkillS = nullptr;	//##스킬 발동하면 여기에 스킬 collision을 대입한다.
	CollisionComponent* m_collSkillTag;	//##스킬 발동하면 여기에 스킬 collision을 대입한다.
	float m_tagCoolTime;

	//이미지, 시간으로 제어
	int m_action;

	float* m_x = nullptr, * m_y = nullptr;
	bool* m_isLeft = nullptr;
	bool* m_isDown = nullptr;
	bool*  m_dashing;
	bool*  m_jumpping;

	//=============이동에 필요한 변수===========
	float m_moveSpeed;

	float m_dashSpeed;		//대시 속도 (가속->감속 계산필요)
	float m_dashCool;		//대시 끝나고 다음 대시세트 시작까지 걸리는 쿨타임
	float m_dashNowCool;	//현재 대시 쿨타임 (0 되면 다음 대시 가능)
	float m_dashTime;		//대시 발동되는 시간 (이 안에 입력해야 2단대시 가능)
	float m_dashNowTime;	//대시 후 지나간 시간
	short m_dashCount;		//현재 몇회차 대시인지
	short m_dashMax;		//최대 대시 가능 횟수

	float m_jumpSpeed;		//점프 시작속도
	short m_jumpCount;		//현재 점프 몇회인지
	short m_jumpMax;		//최대 점프 가능 횟수		
	//============이동에 필요한 변수end==========

	short m_attackCount;
	short m_attackMax;
	bool  m_attackCast[2];		//1타중 아무때나 공격키 1회 누르면 액션 끝나고 2타가 이어서 발동된다.

	float m_skillCoolA;
	float m_skillNowCoolA;
	float m_skillCoolS;
	float m_skillNowCoolS;
	bool  m_skillUsing;

	bool  m_imageChange;	//무언가 동작을 입력하면 true가 된다.
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

	//Update 안에 들어가는 함수
	virtual void Act();

	virtual void CoolDown() {};
	virtual void ActionArrangement() {};
	virtual void CollisionUpdate() {};
	//	in act
	virtual void InputSkillKey() {};
	virtual void InputAttackKey() {};

	virtual void TagAction() {};

	//Render 안에 들어가는 함수
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