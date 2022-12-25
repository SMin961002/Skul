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
	점프2회, 대시2회 섞기가능
	점프중 대시 쿨 돌아오면 새 대시 세트 가능,
	1점프->2단대시->2점프->2단대시->땅에닿기직전 2단대시 가능
	(추락고도가 높으면 추가대시 더 가능)
	첫 대시 이하의 고도에서만 2회차 대시 가능
	
	1회차 대시 직후 일정시간 이내에 대시키 눌러야 2회차 대시 가능
	(안그러면 쿨 돌아감. 쿨 끝날때까지 대시 불가)
	대시 쿨탐분석필
	점프어택이 몇회까지 되는지 분석 필요
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

	//이미지, 시간으로 제어
	ActionTag m_action;
	ActionTag m_action_prev;
	float m_actionTick;		//행동지속시간

	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_down;
	bool  m_commandInput;
		  
	float m_dashSpeed;		//대시 속도 (가속->감속 계산필요)
	float m_dashDelay;		//대시 끝나고 다음 대시세트 시작까지 걸리는 쿨타임
	float m_dashTime;		//대시 발동되는 시간 (이 안에 입력해야 2단대시 가능)
	short m_dashCount;		//현재 몇회차 대시인지
	short m_dashMax;		//최대 대시 가능 횟수
		  
	float m_jumpSpeed;		//점프 시작속도
	float m_jumpGravity;	//점프 속도 (가속->감속, 속도 -되면 jumpDown 2차식 계산필요)
	short m_jumpCount;		//현재 점프 몇회인지
	short m_jumpMax;		//최대 점프 가능 횟수		  
		  
	float m_attackWaitingTime;
	short m_attackCount;
		  
	float m_skillCoolA;
	float m_skillCoolS;
	float m_skillCoolD;

//공격스킬 2가지
//일반공격
//점프
//점프공격
//대시
//이동

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void Move();
	//virtual void Action();
	virtual void Draw();
};