#pragma once
#include "LittleBorn.h"
#include "Gambler.h"
//!!!!벡터가 터져요!!!!//
//↓/↓/Comment at End of Page/↓/↓/
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

	//=============이동에 필요한 변수===========
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

	int m_knockBackY;
	bool m_knockBack;
	//============이동에 필요한 변수end==========
	
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

	//물리공격 데미지를 입력해주세요
	void HitPlayerPhysicAttack(float dmg);
	//마법공격 데미지를 입력해주세요
	void HitPlayerMagicAttack(float dmg);
	//플레이어 피격시 밀림(플레이어가 x+moveX, y+moveY포인트로 옮겨집니다)
	void HitPlayerKnockBack(float moveX, float moveY);

	//플레이어 피격시 이펙트(일반타)
	void HitPlayerEffect();
	//플레이어 피격시 이펙트(크리티컬)(내용 안채워서 지금은 안뜹니다)
	void CritialHitPlayerEffect();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;
	virtual void UIRender() override;

	virtual void OnCollision(string collisionName, Object* other) override;
	void InputArtifactKey();

	//↓====PlayerMove.cpp에 있습니다====↓//
	void Move();
	//	in move
	void InputJumpKey();
	void InputDashKey();
	void InputArrowKey();
	//↑====PlayerMove.cpp에 있습니다====↑//
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

# 추가작업 필요한 부분은 코드 중간에 ##로 표시해두었음.

# dash부분 보강 필요

			
			갬블러 액션
			샤샤샥
			데미지(이미지)
			HPUI
			해골이미지 슬롯

			다하면 약탈자 (진화 전/후 넣기)
			

 - 플레이어 1타중 맞으면 2타가 안나가는 문제 수정하기
 - effect 출력
 - 추상화(진행중!)

 # 아티펙트 어떻게 소지시킬것인지

 on collision함수 발동시
 head의 OnCollision함수를 가져와서 실행시킨다.

bool canWalk, canDash, canJump, canSkillA, B, canAttack등등의 변수 만들어서
update에서 해당 변수 on off 함수실행 조절하는 방식 고려해보기
※ 작업일지 ※
1/4
해야할 일 : Hit이펙트 이미지 중심맞추기
			태그 액션 만들기
			머리통 움직임 동작 플레이어로 이관
			점프 고치기
			충돌 고치기

1/3
자잘한 버그픽스....
A, S스킬 구현 완
이펙트 넣었고
충돌함수넣음

1/2
basic skul A, S만들기

A 투사체 붕붕 고치기
S 좌표이동 구현

1/1
			jump만들기
			점프, 대시 이펙트 만들기

12/31
	공격충돌부구현

12/30
...

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