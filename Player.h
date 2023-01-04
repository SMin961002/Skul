#pragma once
#include "Head_Basic.h"

//↓/↓/Comment at End of Page/↓/↓/
//head가 컴포넌트를 갖고, 머리교체할 때 init에서 m_obj연결?
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
	//============이동에 필요한 변수end==========
	
	//=============이동에 필요한 변수===========
	float m_supperArmarTime;
	float m_supperArmarNowTime;
	//============이동에 필요한 변수end==========

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

	//물리공격 데미지를 입력해주세요
	void HitPlayerPhysicAttack(float dmg)
	{
		m_supperArmarNowTime = m_supperArmarTime;
		m_playerHitBox->SetIsActive(false);
		m_life -= dmg;
		EFFECTMANAGER->AddEffect<PlayerHit>((m_obj->GetComponent<CollisionComponent>()->GetCollisionPosX())
			, m_obj->GetComponent<CollisionComponent>()->GetCollisionPosY(), m_isLeft);
	}
	//마법공격 데미지를 입력해주세요
	void HitPlayerMagicAttack(float dmg)
	{
		m_supperArmarNowTime = m_supperArmarTime;
		m_playerHitBox->SetIsActive(false);
		m_life -= dmg;
		EFFECTMANAGER->AddEffect<PlayerHit>((m_obj->GetComponent<CollisionComponent>()->GetCollisionPosX())
			, m_obj->GetComponent<CollisionComponent>()->GetCollisionPosY(), m_isLeft);
	}
	//피격시 플레이어 밀림(플레이어가 x+moveX, y+moveY포인트로 옮겨집니다)
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

# 추가작업 필요한 부분은 코드 중간에 ##로 표시해두었음.

# jump, dash부분 보강 필요
 - jump 전체 구현해야함
 - 공격모션 출력
 - 스킬 출력

 - effect 출력
 - 추상화(진행중!)

 # 아티펙트 어떻게 소지시킬것인지



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