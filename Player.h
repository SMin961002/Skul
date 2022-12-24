#pragma once
#include "Component.h"

#define MOVE_SPEED	3
#define JUMP_SPEED	3
#define DASH_MULTIPLE	2
#define DASH_COLLTIME	
#define COMMAND_ReENTRY_TIME

enum SkulTag
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler
};
class Player : public Component
{
	//공격스킬 2가지
	//일반공격
	//점프
	//점프공격
	//대시
	//이동
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

private:
	RECT m_hitBox;

public:
	virtual enum ActionTag
	{
		eAutoAttack_1,
		eAutoAttack_2,
		eJump,
		eDash,
		eSkill_1,
		eSkill_2,
		eIdle
	};

	vImage* img;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void move();
	virtual void draw();
};