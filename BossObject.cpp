#include "stdafx.h"
#include "BossObject.h"
#include "HollyFountain.h"

void BossObject::Init()
{
	// 보스 1페이즈 대화
	_imgBossTalk = IMAGEMANAGER->FindImageVector("Boss_Intro_Talk");
	_imgBossTalk->Setting(0.1, false);
	// 보스 1페이즈 대기 상태
	_imgBossIdle = IMAGEMANAGER->FindImageVector("Boss_Idle");
	_imgBossIdle->Setting(0.1, true);
	
	// 보스 1페이즈 캐스팅
	_imgPhase1BossCastingReady = IMAGEMANAGER->FindImageVector("Boss_Casting_Ready");
	_imgPhase1BossCastingReady->Setting(0.1, false);
	_imgPhase1BossCastingAttack = IMAGEMANAGER->FindImageVector("Boss_Casting_Attack");
	_imgPhase1BossCastingAttack->Setting(0.1, true);
	_imgPhase1BossCastingEnd = IMAGEMANAGER->FindImageVector("Boss_Casting_End");
	_imgPhase1BossCastingEnd->Setting(0.1, false);
	// 보스 1페이즈 캐스팅 선택지
	// 비산되는 구슬
	_imgPhase1BossBaptismAttack = IMAGEMANAGER->FindImageVector("Boss_Baptism_Attack");
	_imgPhase1BossBaptismAttack->Setting(0.1, true);
	// 레이저
	_imgPhase1BossConsecrationSign = IMAGEMANAGER->FindImageVector("Boss_Consecration_Sign");
	_imgPhase1BossConsecrationSign->Setting(0.1, false);
	_imgPhase1BossConsercrationStart = IMAGEMANAGER->FindImageVector("Boss_Consecration_Start");
	_imgPhase1BossConsercrationStart->Setting(0.1, false);
	_imgPhase1BossConsercrationLoop = IMAGEMANAGER->FindImageVector("Boss_Consecration_Loop");
	_imgPhase1BossConsercrationLoop->Setting(0.1, true);
	_imgPhase1BossConsercrationEnd = IMAGEMANAGER->FindImageVector("Boss_Consecration_End");
	_imgPhase1BossConsercrationEnd->Setting(0.1, false);
	// 좌우로 오는 구슬
	_imgPhase1BossWorship = IMAGEMANAGER->FindImageVector("Boss_Worship");
	_imgPhase1BossWorship->Setting(0.1, true);
	
	// 보스 1페이즈 땅찍기
	_imgPhase1BossNervousReady = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Ready");
	_imgPhase1BossNervousReady->Setting(0.1, false);
	_imgPhase1BossNervousReadyLoop = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Ready_Loop");
	_imgPhase1BossNervousReadyLoop->Setting(0.1, true);
	_imgPhase1BossNervousAttack = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Attack");
	_imgPhase1BossNervousAttack->Setting(0.1, false);
	_imgPhase1BossNervousAttackLoop = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Attack_Loop");
	_imgPhase1BossNervousAttackLoop->Setting(0.1, true);
	_imgPhase1BossNervousEnd = IMAGEMANAGER->FindImageVector("Boss_Nervousness_End");
	_imgPhase1BossNervousEnd->Setting(0.1, false);
	_imgPhase1NervousEffectShine = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Attack");
	_imgPhase1NervousEffectShine->Setting(0.1, false);
	_imgPhase1NervousEffectImpact = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Projectile");
	_imgPhase1NervousEffectImpact->Setting(0.1, true);
	
	// 보스 1페이즈 초이스
	_imgPhase1ChoiceReady = IMAGEMANAGER->FindImageVector("Boss_Choice_Ready");
	_imgPhase1ChoiceReady->Setting(0.1, false);
	_imgPhase1ChoiceReadyLoop = IMAGEMANAGER->FindImageVector("Boss_Choice_Ready_Loop");
	_imgPhase1ChoiceReadyLoop->Setting(0.1, true);
	_imgPhase1ChoiceAttack = IMAGEMANAGER->FindImageVector("Boss_Choice_Attack");
	_imgPhase1ChoiceAttack->Setting(0.1, false);
	_imgPhase1ChoiceEnd = IMAGEMANAGER->FindImageVector("Boss_Choice_End");
	_imgPhase1ChoiceEnd->Setting(0.1, false);
	_imgPhase1ChoiceSpark = IMAGEMANAGER->FindImageVector("Boss_Choice_Spark");
	_imgPhase1ChoiceSpark->Setting(0.1, false);
	
	// 보스 1페이즈 배리어
	_imgPhase1BarrierIntroFront = IMAGEMANAGER->FindImageVector("Boss_Barrier_Intro_Front");
	_imgPhase1BarrierIntroFront->Setting(0.1, false);
	_imgPhase1BarrierIntroBehind = IMAGEMANAGER->FindImageVector("Boss_Barrier_Intro_Behind");
	_imgPhase1BarrierIntroBehind->Setting(0.1, false);
	_imgPhase1BarrierLoopFront = IMAGEMANAGER->FindImageVector("Boss_Barrier_Loop_Front");
	_imgPhase1BarrierLoopFront->Setting(0.1, true);
	_imgPhase1BarrierLoopBehind = IMAGEMANAGER->FindImageVector("Boss_Barrier_Loop_Behind");
	_imgPhase1BarrierLoopBehind->Setting(0.1, true);
	_imgPhase1BarrierImpact = IMAGEMANAGER->FindImageVector("Boss_Barrier_Impact");
	_imgPhase1BarrierImpact->Setting(0.1, false);
	_imgPhase1BarrierSpark = IMAGEMANAGER->FindImageVector("Boss_Barrier_Spark");
	_imgPhase1BarrierSpark->Setting(0.1, false);
	_imgPhase1BarrierCrackImpact = IMAGEMANAGER->FindImageVector("Boss_Barrier_Crack_Impact");
	_imgPhase1BarrierCrackImpact->Setting(0.1, false);
	_imgPhase1BarrierCrack = IMAGEMANAGER->FindImage("Boss_Barrier_Crack");

	_isIntro = true;
	_isIdle = false;
	_isCasting = false;
	_isNervousness = false;
	_isChoice = false;

	_leftFountainHP = 500;
	_rightFountainHP = 500;

	_castingTime = 0;

	for (int i = 0; i < 15; i++)
	{
		tagBaptism baptism;
		baptism._imgPhase1BossBaptismProjectile = IMAGEMANAGER->AddImageVectorCopy("Boss_Baptism_Projectile");
		baptism._imgPhase1BossBaptismProjectile->Setting(0.1, true);
		baptism._imgPhase1BossBaptismProjectileDespawn = IMAGEMANAGER->AddImageVectorCopy("Boss_Baptism_Projectile_Dewspawn");
		baptism._imgPhase1BossBaptismProjectileDespawn->Setting(0.1, true);
		baptism.speed = 3;

		baptism.fire = false;

		_vBaptism.push_back(baptism);
	}
}

void BossObject::Update()
{
	if (KEYMANAGER->GetToggleKey('Q'))
	{
		_isIdle = true;
	}
	if (KEYMANAGER->GetToggleKey('W'))
	{
		_isNervousness = true;
	}
	if (KEYMANAGER->GetToggleKey('E'))
	{
		_isChoice = true;
	}
	if (KEYMANAGER->GetToggleKey('R'))
	{
		_isCasting = true;
	}
	if (KEYMANAGER->GetOnceKeyDown('1'))
	{
		_leftFountainHP = 0;
	}
	if (KEYMANAGER->GetOnceKeyDown('2'))
	{
		_rightFountainHP = 0;
	}
	if (KEYMANAGER->GetToggleKey('0'))
	{
		_isIntro = true;
	}
	if (KEYMANAGER->GetOnceKeyDown('P'))
	{
		_isIdle = false;
		_isNervousness = false;
		_isChoice = false;
		_isCasting = false;

		_isIntro = false;
		_isBarrierLoop = false;
		_isBarrierCrack = false;
		_leftFountainHP = 500;
		_rightFountainHP = 500;
	}
}

void BossObject::Render()
{
	// Boss 1 Phase Intro
	if (_isIntro == true && _isIdle == false)
	{
		_imgBossTalk->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

		if (_imgBossTalk->GetIsImageEnded() == true)
		{
			_isIdle = true;
		}
	}
	// Boss 1 Phase Idle
	if (_isIdle == true)
	{
		_imgBossIdle->CenterRender(WINSIZE_X / 2 - 30, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

		_isIntro = false;
	}

	// Boss 1 Phase Barrier
	if (_isIdle == true)
	{
		_imgPhase1BarrierIntroFront->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
		_imgPhase1BarrierIntroBehind->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

		if (_imgPhase1BarrierIntroFront->GetIsImageEnded() == true &&
			_imgPhase1BarrierIntroBehind->GetIsImageEnded() == true)
		{
			_isBarrierLoop = true;
		}
	}
	if (_isBarrierLoop == true && _leftFountainHP > 0)
	{
		_imgPhase1BarrierLoopFront->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
	}
	if (_isBarrierLoop == true && _rightFountainHP > 0)
	{
		_imgPhase1BarrierLoopBehind->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
	}
	if ((_leftFountainHP <= 0 || _rightFountainHP <= 0) && _isBarrierCrack == false)
	{
		_imgPhase1BarrierCrackImpact->CenterRender(WINSIZE_X / 2 - 21, WINSIZE_Y - 157, 1.7, 1.7, 0, false);
	}
	if (_imgPhase1BarrierCrackImpact->GetIsImageEnded() == true)
	{
		_isBarrierCrack = true;
	}
	if (_isBarrierCrack == true)
	{
		IMAGEMANAGER->CenterRender(_imgPhase1BarrierCrack, WINSIZE_X / 2 - 21, WINSIZE_Y - 160, 1.7, 1.7, 0, false);
	}
	if (_leftFountainHP <= 0 && _rightFountainHP <= 0 && _isBarrierCrack == true)
	{
		_imgPhase1BarrierSpark->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
		_imgPhase1BarrierImpact->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
	}

	// Boss 1 Phase Casting
	if (_isCasting == true)
	{
		_imgPhase1BossCastingReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

		if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
		{
			_isCastingReady = true;
		}
	}
	if (_isCastingReady == true)
	{
		_imgPhase1BossCastingAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
		
		
		if(_castingTime == 0) _rndCasting = MY_UTILITY::getFromIntTo(0, 2);

		_castingTime += DELTA_TIME;
	}





	if (_isCastingReady == true && _rndCasting == 0)
	{
		// 비산하는 구슬
		for (_viBaptism = _vBaptism.begin(); _viBaptism != _vBaptism.end(); ++_viBaptism)
		{
				_viBaptism->_imgPhase1BossBaptismProjectile->CenterRender(0,
					100, 1.8, 1.8, 0, false);
				_viBaptism->_imgPhase1BossBaptismProjectileDespawn->CenterRender(MY_UTILITY::getFromFloatTo(0, 1000),
					100, 1.8, 1.8, 0, false);
		}
		_imgPhase1BossBaptismAttack->CenterRender(WINSIZE_X/2+100, 100, 1, 1, 0, false);
	}







	if (_isCastingReady == true && _rndCasting == 1)
	{
		// 레이저
		_imgPhase1BossConsecrationSign->CenterRender(100, 100, 1.8, 1.8, 0, false);

		if (_imgPhase1BossConsecrationSign->GetIsImageEnded() == true)
		{
			_imgPhase1BossConsercrationStart->CenterRender(300, 100, 1.8, 1.8, 0, false);
			if (_imgPhase1BossConsercrationStart->GetIsImageEnded() == true)
			{
				_imgPhase1BossConsercrationLoop->CenterRender(500, 100, 1.8, 1.8, 0, false);
			}
		}
		_imgPhase1BossConsercrationEnd->CenterRender(700, 100, 1.8, 1.8, 0, false);
	}

	if (_isCastingReady == true && _rndCasting == 2)
	{
		// 좌우 이동 구슬
		_imgPhase1BossWorship->CenterRender(100, 100, 1.8, 1.8, 0, false);
	}
	
_imgPhase1BossCastingEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
	

	// 보스 1페이즈 땅찍기
	if (_isNervousness == true)
	{
		_imgPhase1BossNervousReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
		if (_imgPhase1BossNervousReady->GetIsImageEnded() == true)
		{
			_imgPhase1BossNervousReadyLoop->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

			if (_imgPhase1BossNervousReadyLoop->GetIsImageEnded() == true)
			{
				_imgPhase1BossNervousAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

				if (_imgPhase1BossNervousReadyLoop->GetIsImageEnded() == true)

					_imgPhase1BossNervousAttackLoop->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
				_imgPhase1NervousEffectShine->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);

				_isNervousnessEffectOn = true;
			}
		}
	}

	if (_isNervousnessEffectOn == true)
	{
		_imgPhase1NervousEffectImpact->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, true);
		_imgPhase1NervousEffectImpact->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
		
		//if(_imgPhase1NervousEffectImpact->) -> X좌표가 맵을 넘어갔을 시
		_imgPhase1BossNervousEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 160, 1.8, 1.8, 0, false);
	}



	// 보스 1페이즈 초이스
	if (_isChoice == true)
	{
		_imgPhase1ChoiceReady->CenterRender(100, 100, 1.8, 1.8, 0, false);
		_imgPhase1ChoiceReadyLoop->CenterRender(300, 100, 1.8, 1.8, 0, false);
		_imgPhase1ChoiceAttack->CenterRender(500, 100, 1.8, 1.8, 0, false);
		_imgPhase1ChoiceEnd->CenterRender(700, 100, 1.8, 1.8, 0, false);
		_imgPhase1ChoiceSpark->CenterRender(1000, 100, 1.8, 1.8, 0, false);
	}
}

void BossObject::Release()
{
}

void BossObject::Baptism()
{
}

void BossObject::Consercration()
{
}

void BossObject::Worship()
{
}

void BossObject::Casting()
{
}

void BossObject::Nervousness()
{
}

void BossObject::Barrier()
{
}

void BossObject::Choice()
{
}

