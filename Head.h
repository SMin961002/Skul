#pragma once
#include "PlayerEffect.h"

enum class eSkulSpecies
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler
};

//머리들이 계승받는 상위클래스
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
		//=↑=↑=여기까진 앵간하면 고정행동=↑=↑=//
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
		eAutoAttack,

		eCollisionArrTagNumCount
	};

protected:
	eSkulSpecies m_species;

	vImage* img[eActionTagNumber];
	vImage* img_reborn;
	vImage* nowImg;

	//이미지, 시간으로 제어
	ActionTag m_action;

	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_isDown;

	float m_dashSpeed;		//대시 속도 (가속->감속 계산필요)
	float m_dashCool;		//대시 끝나고 다음 대시세트 시작까지 걸리는 쿨타임
	float m_dashNowCool;	//현재 대시 쿨타임 (0 되면 다음 대시 가능)
	float m_dashTime;		//대시 발동되는 시간 (이 안에 입력해야 2단대시 가능)
	float m_dashNowTime;	//대시 후 지나간 시간
	short m_dashCount;		//현재 몇회차 대시인지
	short m_dashMax;		//최대 대시 가능 횟수
	bool  m_dashing;

	float m_jumpSpeed;		//점프 시작속도
	short m_jumpCount;		//현재 점프 몇회인지
	short m_jumpMax;		//최대 점프 가능 횟수		
	bool  m_jumpping;

	short m_attackCount;
	short m_attackMax;
	bool  m_attackCast;		//1타중 아무때나 공격키 1회 누르면 액션 끝나고 2타가 이어서 발동된다.

	float m_skillCoolA;
	float m_skillNowCoolA;
	float m_skillCoolS;
	float m_skillNowCoolS;
	bool  m_skillUsing;

	bool  m_imageChange;	//무언가 동작을 입력하면 true가 된다.
	bool m_canAction[eActionTagNumber];

public:
	void Init();
	void Update();
	void Render();
	void Release();

	inline bool GetIsDashing() { return m_dashing; }

	virtual void ImageSetting() {};
	virtual void ParameterSetting() {};
	virtual void CollisionSetting() {};

	//Update 안에 들어가는 함수
	virtual void Move();
	virtual void Act();

	virtual void CoolDown() {};
	virtual void ActionArrangement() {};
	virtual void CollisionUpdate() {};
	//	in move
	virtual void InputJumpKey();
	virtual void InputDashKey();
	virtual void InputArrowKey();
	//	in act
	virtual void InputSkillKey() {};
	virtual void InputAttackKey() {};


	//Render 안에 들어가는 함수
	virtual void DrawCharactor();

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

	virtual void OnCollision(string collisionName, Object* other) override 
	{
		cout << "" << endl;
	};
};