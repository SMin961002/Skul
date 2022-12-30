#pragma once
#include "Component.h"

//↓/↓/Comment at End of Page/↓/↓/

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

	행동제어 이미지 delay
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
//=↑=↑=여기까진 앵간하면 고정행동=↑=↑=//
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

	//이미지, 시간으로 제어
	ActionTag m_action;

	float m_moveSpeed;
	bool  m_isLeft;
	bool  m_down;
		  
	float m_dashSpeed;		//대시 속도 (가속->감속 계산필요)
	float m_dashCool;		//대시 끝나고 다음 대시세트 시작까지 걸리는 쿨타임
	float m_dashNowCool;	//현재 대시 쿨타임 (0 되면 다음 대시 가능)
//↓↓현재는 이용 없음↓↓ 대시타임동간 틱당 이동거리 계산할 때 필요할 수도 있을 것 같아서 남겨둠
	float m_dashTime;		//대시 발동되는 시간 (이 안에 입력해야 2단대시 가능)
	float m_dashNowTime;	//대시 후 지나간 시간
//↑↑현재는 이용 없음↑↑
	short m_dashCount;		//현재 몇회차 대시인지
	short m_dashMax;		//최대 대시 가능 횟수
	bool  m_dashing;

	float m_jumpSpeed;		//점프 시작속도
	float m_jumpNowSpeed;	//점프 속도 (가속->감속, 속도 -되면 jumpDown 2차식 계산필요)
	short m_jumpCount;		//현재 점프 몇회인지
	short m_jumpMax;		//최대 점프 가능 횟수		
	bool  m_jumpping;
		  
	short m_attackCount;
	bool  m_attackCast;		//1타중 아무때나 공격키 1회 누르면 액션 끝나고 2타가 이어서 발동된다.

	float m_skillCoolA;
	float m_skillNowCoolA;
	float m_skillCoolS;
	float m_skillNowCoolS;
	bool  m_skillUsing;
	float m_artifactCoolD;
	float m_artifactNowCoolD;
	bool  m_haveArtifact;

	bool  m_commandInput;	//무언가 동작을 입력하면 true가 된다.
		  
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
	virtual void OnCollision(Object* other) override;
	float GetplayerX(void) { return m_obj->x; }

	virtual void Move();
	virtual void Act();

	//Update 안에 들어가는 함수
	virtual void InputArtifactKey();
	//	in move
	virtual void InputJumpKey();
	virtual void InputDashKey();
	virtual void InputArrowKey();
	//	in act
	virtual void InputAttackKey();
	virtual void InputSkillKey();

	//Render 안에 들어가는 함수
	virtual void DrawCharactor();
	virtual void DrawEffect();	//이펙트는 오브젝트라고 생각하고 생성소멸시키기.

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

# 추가작업 필요한 부분은 코드 중간에 ##로 표시해두었음.

# jump, dash부분 보강 필요
 - jump 전체 구현해야함
 - 공격모션 출력
 - 스킬 출력
 
 - effect 출력
 - 추상화





※ 작업일지 ※
12/30

12/29
1. 전체적으로 모션 작동 방식 수정하였습니다.
	- 커멘드 입력시 동작별 tick 넣고, update시에 -DELTA_TIME 한 뒤 0이 되면 Idle로 돌리는 방식에서
	  Image delay를 이용해 동작 제어하는 방식으로 변경
	  | 부자연스러운 걷기모션 개선됨
	  | 
	- 키입력시 action에 동작을 넣는다
	  : 더 높은 우선순위를 가진 동작의 입력을 뒤에서 받아온다 (최종적으로 뒤에 입력한 동작이 출력됨)
	    대시, 점프의 경우 이미지는 캔슬돼도 가로, 세로 동작은 남아있는 경우가 다수라 각각 bool값을 주었음
2. 이미지에 프레임별 체류시간을 넣었습니다. (태웅씨 컨펌 완료)
*/