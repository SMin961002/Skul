#pragma once
#include "Component.h"

class Baptism;
class WorshipLeft;
class WorshipRight;

class BossObject : public Component
{
private:
	CImage* _imgBossChair;
	// 보스 1페이즈 대화
	vImage* _imgBossTalk;

	// 보스 1페이즈 대기 상태
	vImage* _imgBossIdle;

	// 보스 1페이즈 땅찍기
	vImage* _imgPhase1BossNervousReady;
	vImage* _imgPhase1BossNervousReadyLoop;
	vImage* _imgPhase1BossNervousAttack;
	vImage* _imgPhase1BossNervousAttackLoop;
	vImage* _imgPhase1BossNervousEnd;

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

protected:
	bool _isIdleOn;
	bool _patternLock;

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

	vector<Baptism*> _vBaptism;
	vector<Baptism*>::iterator _viBaptism;
	
protected:
	bool _isWorshipCheck;
	bool _isWorshipFirstWaveOn;
	bool _isWorshipSecondWaveOn;
	bool _updateCheck;

	float _worshipDeltaTime;

	vector<WorshipLeft*> _vWorshipLeft;
	vector<WorshipLeft*>::iterator _viWorshipLeft;

	vector<WorshipRight*> _vWorshipRight;
	vector<WorshipRight*>::iterator _viWorshipRight;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	BossObject() {}
	~BossObject() {}
};

