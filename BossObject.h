#pragma once
#include "Component.h"
#include "BossBall.h"
#include "Enemy.h"
class Baptism;
class WorshipLeft;
class WorshipRight;
class HolyFountainLeft;
class HolyFountainRight;

class BossObject : public Enemy
{
private:
	const float maxHp = 600;
	int circleCount = 0;
	bool m_isMagicCircleImage;
	int m_talkCount;
	int m_page;
	float chairY = 0;
	bool isActive;
	float alpha = 1;
	float hitAlpha = 0;
	float teleprotTimer;
	bool isDivine = false;
	bool isPhase3 = false;
	bool isTeleport = false;
	bool soundon = false;
	bool soundon2 = false;
	float chairX = 0;
	bool isLazer;
	float tpX;
	float tpY;
	CImage* bossHpbar;
	CImage* hpImg;
	CollisionComponent* coll;
private:

	CImage* _imgBossChair;
	CImage* _imgBossHPBar;
	CImage* _imgBossHP;
	CImage* _imgBossHPDamage;
	// 보스 1페이즈 대화
	vImage* divineLightEf1;
	vImage* divineLightEf2;
	vImage* lazerImg;

	vImage* _imgBossTalk;

	// 보스 1페이즈 대기 상태
	vImage* magicCircleImage;
	vImage* _imgBossIdle;
	BossBall* bossBall[3];
	// 보스 1페이즈 땅찍기
	vImage* trailImg;
	vImage* _imgPhase1BossNervousReady;
	vImage* _imgPhase1BossNervousReadyLoop;
	vImage* _imgPhase1BossNervousAttack;
	vImage* _imgPhase1BossNervousAttackLoop;
	vImage* _imgPhase1BossNervousEnd;

	int castCount;
	// 보스 1페이즈 캐스팅
	vImage* _imgPhase1BossCastingReady;
	vImage* _imgPhase1BossCastingAttack;
	vImage* _imgPhase1BossCastingEnd;
	// 보스 1페이즈 캐스팅 선택지
	// 비산되는 구슬
	vImage* _imgPhase1BossBaptismAttack;
	// 레이저
	vImage* _imgPhase1BossConsecrationSign;
	vImage* _imgPhase1BossConsecrationStart;
	vImage* _imgPhase1BossConsecrationLoop;
	vImage* _imgPhase1BossConsecrationEnd;
	// 좌우로 오는 구슬

	// 보스 1페이즈 초이스
	vImage* _imgPhase1BossChoiceReady;
	vImage* _imgPhase1BossChoiceReadyLoop;
	vImage* _imgPhase1BossChoiceAttack;
	vImage* _imgPhase1BossChoiceEnd;
	vImage* _imgPhase1BossChoiceSpark;

	// 보스 1페이즈 배리어
	vImage* _imgPhase1BossBarrierIntroFront;
	vImage* _imgPhase1BossBarrierIntroBehind;
	vImage* _imgPhase1BossBarrierLoopFront;
	vImage* _imgPhase1BossBarrierLoopBehind;
	vImage* _imgPhase1BossBarrierImpact;
	vImage* _imgPhase1BossBarrierSpark;
	CImage* _imgPhase1BossBarrierCrack;
	vImage* _imgPhase1BossBarrierCrackImpact;

	bool m_isAttack;
	int m_bossState;
	float m_patterTimer;
	int lazerCount = 0;

	enum BossPhase2State
	{
		eIntro1,
		eIntro2,
		eIdle,
		eCreateBallR,
		eCreateBallA,
		eCreateBallE,
		eDivineLightR,
		eDivineLightAR,
		eDivineLightA,
		eDivineLightE,
		eDivineImpactA,
		eDivineImpactE,
		eDivineImpactR,
		eDivineImpactRL,
		ePhase_3A,
		ePhase_3E,
		ePhase_3R,
		eSoulChaseA,
		eSoulChaseR,
		eSoulChaseE,
		eDeathR,
		eDeathL,
		eEnd
	};
	bool isEnd;
	vImage* m_phase2Img[eEnd];
	vImage* m_teleportEffect;
	int m_phase2Patter;
protected:
	bool _isIntroOn;
	float _introTimeCheck;
	bool isMove;
	bool _isIdleOn;
	bool _patternLock;
	int suf[4] = { 1,2,3,4 };
	int devineCount = 0;
	int _patternSelect;
	float _patternDelay;
protected:
	bool _isNervousnessOn;
	bool _isNervousnessLoopOn;
	bool _isNervousnessAttackLoopOn;
	bool _isNervousnessMotionEnd;

	float _nervousnessMotionDeltaTime;
	float _nervousnessEffectDeltaTime;

protected:
	bool _isChoiceOn;
	bool _isChoiceReadyLoopOn;
	bool _isChoiceAttackEnd;

	float _choiceMotionDeltaTime;

protected:
	bool _isCastingOn;
	bool _isCastingAttackOn;
	bool _isConsecrationLoopOn;

	float _castingMotionDeltaTime;
	float _consecrationDeltaTime;
	float _locate;
	bool nowPattern;

	bool _isBaptismCheck;
	float _baptismDeltaTime;

protected:
	bool _isWorshipCheck;
	bool _isWorshipFirstWaveOn;
	bool _isWorshipSecondWaveOn;
	bool _updateCheck;

	float _worshipDeltaTime;



	int rand;

	float _bossHPBarLocate;

public:
	int _patternCheck;
	vImage* deathImg;
	bool getIdleOn() { return _isIdleOn; }

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void HitEnemy(float dmg, float time) override;


	BossObject() {}
	~BossObject() {}

	void Page_2();
	void Teleport();
	void MovePos();

	HolyFountainLeft* _left;
	HolyFountainRight* _right;
};

