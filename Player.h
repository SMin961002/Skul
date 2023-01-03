#pragma once
#include "Head_Basic.h"

//↓/↓/Comment at End of Page/↓/↓/
//head가 컴포넌트를 갖고, 머리교체할 때 init에서 m_obj연결?
class Player : public Component
{
	/*
	점프2회, 대시2회 섞기가능
	점프중 대시 쿨 돌아오면 새 대시 세트 가능,
	1점프->2단대시->2점프->2단대시->땅에닿기직전 2단대시 가능
	(추락고도가 높으면 추가대시 더 가능)
	
	1회차 대시 직후 일정시간 이내에 대시키 눌러야 2회차 대시 가능
	(안그러면 쿨 돌아감. 쿨 끝날때까지 대시 불가)
	대시 쿨탐분석필
	점프어택이 몇회까지 되는지 분석 필요

	행동제어 이미지 delay
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

	//물리공격 데미지를 입력해주세요
	void HitPlayerPhysicAttack(float dmg)
	{
		m_life -= dmg;
	}
	//마법공격 데미지를 입력해주세요
	void HitPlayerMagicAttack(float dmg)
	{
		m_life -= dmg;
	}
	//피격시 플레이어 밀림(플레이어가 x+moveX, y+moveY포인트로 옮겨집니다)
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

# 추가작업 필요한 부분은 코드 중간에 ##로 표시해두었음.

# jump, dash부분 보강 필요
 - jump 전체 구현해야함
 - 공격모션 출력 
 - 스킬 출력

 - effect 출력
 - 추상화(진행중!)

 # 아티펙트 어떻게 소지시킬것인지



※ 작업일지 ※
1/2
오늘할거 : basic skul A, S만들기
bool canWalk, canDash, canJump, canSkillA, B, canAttack등등의 변수 만들어서
update에서 해당 변수 on off 함수실행 조절하는 방식 고려해보기

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