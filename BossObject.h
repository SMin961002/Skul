#pragma once
#include "Component.h"

class HollyFountain;

class BossObject : public Component
{
private:
	// ���� 1������ ��� ����
	vImage* _imgBoss;
	RECT _rcBossIdle;

	// ���� 1������ �����
	vImage* _imgPhase1BossNervousReady;
	vImage* _imgPhase1BossNervousReadyLoop;
	vImage* _imgPhase1BossNervousAttack;
	vImage* _imgPhase1BossNervousAttackLoop;
	vImage* _imgPhase1BossNervousEnd;
	vImage* _imgPhase1NervousEffectShine;
	vImage* _imgPhase1NervousEffectImpact;
	RECT _rcPhase1NervousEffectLeft;
	RECT _rcPhase1NervousEffectRight;

	// ���� 1������ ĳ����
	vImage* _imgPhase1BossCastingReady;
	vImage* _imgPhase1BossCastingAttack;
	vImage* _imgPhase1BossCastingEnd;
	// ���� 1������ ĳ���� ������
	// ���Ǵ� ����
	vImage* _imgPhase1BossBaptismAttack;
	vImage* _imgPhase1BossBaptismProjectile;
	vImage* _imgPhase1BossBaptismProjectileDespawn;
	// ������
	vImage* _imgPhase1BossConsecrationSign;
	vImage* _imgPhase1BossConsercrationStart;
	vImage* _imgPhase1BossConsercrationLoop;
	vImage* _imgPhase1BossConsercrationEnd;
	// �¿�� ���� ����
	vImage* _imgPhase1BossWorship;

	// ���� 1������ ���̽�
	vImage* _imgPhase1ChoiceReady;
	vImage* _imgPhase1ChoiceReadyLoop;
	vImage* _imgPhase1ChoiceAttack;
	vImage* _imgPhase1ChoiceEnd;
	vImage* _imgPhase1ChoiceSpark;

	// ���� 1������ �踮��
	vImage* _imgPhase1BarrierIntroFront;
	vImage* _imgPhase1BarrierIntroBehind;
	vImage* _imgPhase1BarrierLoopFront;
	vImage* _imgPhase1BarrierLoopBehind;
	vImage* _imgPhase1BarrierImpact;
	vImage* _imgPhase1BarrierSpark;
	CImage* _imgPhase1BarrierCrack;
	vImage* _imgPhase1BarrierCrackImpact;

private:
	bool _isIdle;
	bool _isIntro;
	bool _isBarrierLoop;
	bool _isBarrierCrack;
	bool _isCasting;
	bool _isNervousness;
	bool _isChoice;

	int _leftFountainHP;
	int _rightFountainHP;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;


	BossObject() {}
	~BossObject() {}
};

