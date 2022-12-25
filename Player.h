#pragma once
#include "Component.h"

//#define MOVE_SPEED				3
//#define JUMP_SPEED				3
//#define JUMP_MULTIPLE			2	//점프 기본 최대 횟수
//#define DASH_MULTIPLE			2	//대시 기본 최대 횟수
//#define JUMP_DELAY				2000	//단위 밀리초
//#define DASH_DELAY				2000	//단위 밀리초
//#define COMMAND_WATINGTIME		1000	//기본공격, 대시, 이단점프 두번째커멘드 들어오기까지 기다려주는시간. 단위 밀리초

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
		eAutoAttack_1,
		eAutoAttack_2,
		eJump,
		eJumpDown,
		eDash,
		eSkill_1,
		eSkill_2
	};

protected:
	RECT m_hitBox;
	ActionTag m_action;
	ActionTag m_action_prev;

	float m_physicalDamage;
	float m_masicalDamage;
	float m_physicalDeffence;
	float m_masicalDeffence;

	float m_level;

	//이동관련
	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_down;
	//대시
	float m_dashDelay;
	float m_dashWaitingTime;
	short m_dashCount;
	//점프
	float m_jumpSpeed;
	float m_jumpDelay;
	float m_jumpWaitingTime;
	short m_jumpCount;

	//공격
	float m_attackWaitingTime;
	float m_attackCount;
	//스킬
	float m_skillCoolA;
	float m_skillCoolS;
	float m_skillCoolD;


	//이미지로 행동
//z대시 x공격 c점프
//a s 스킬 d
//공격스킬 2가지
//일반공격
//점프
//점프공격
//대시
//이동

public:
	vImage* img;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void Move();
	virtual void Action();
	virtual void Draw();
};