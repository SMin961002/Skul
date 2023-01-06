#include "stdafx.h"
#include "BossObject.h"
#include "Nervousness.h"
#include "Consecration.h"
#include "Baptism.h"
#include "Worship.h"

void BossObject::Init()
{
	_imgBossChair = IMAGEMANAGER->FindImage("Boss_Chair");

	_imgBossIdle = IMAGEMANAGER->FindImageVector("Boss_Idle");
	_imgBossIdle->Setting(0.1, true);

	_imgPhase1BossNervousReady = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Ready");
	_imgPhase1BossNervousReady->Setting(0.1, false);
	_imgPhase1BossNervousReadyLoop = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Ready_Loop");
	_imgPhase1BossNervousReadyLoop->Setting(0.1, true);
	_imgPhase1BossNervousAttack = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Attack");
	_imgPhase1BossNervousAttack->Setting(0.1, false);
	_imgPhase1NervousEffectShine = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Attack");
	_imgPhase1NervousEffectShine->Setting(0.1, false);
	_imgPhase1BossNervousEnd = IMAGEMANAGER->FindImageVector("Boss_Nervousness_End");
	_imgPhase1BossNervousEnd->Setting(0.1, false);

	_imgPhase1BossChoiceReady = IMAGEMANAGER->FindImageVector("Boss_Choice_Ready");
	_imgPhase1BossChoiceReady->Setting(0.1, false);
	_imgPhase1BossChoiceReadyLoop = IMAGEMANAGER->FindImageVector("Boss_Choice_Ready_Loop");
	_imgPhase1BossChoiceReadyLoop->Setting(0.1, true);
	_imgPhase1BossChoiceAttack = IMAGEMANAGER->FindImageVector("Boss_Choice_Attack");
	_imgPhase1BossChoiceAttack->Setting(0.1, false);
	_imgPhase1BossChoiceSpark = IMAGEMANAGER->FindImageVector("Boss_Choice_Spark");
	_imgPhase1BossChoiceSpark->Setting(0.1, false);
	_imgPhase1BossChoiceEnd = IMAGEMANAGER->FindImageVector("Boss_Choice_End");
	_imgPhase1BossChoiceEnd->Setting(0.1, false);

	_imgPhase1BossCastingReady = IMAGEMANAGER->FindImageVector("Boss_Casting_Ready");
	_imgPhase1BossCastingReady->Setting(0.1, false);
	_imgPhase1BossCastingAttack = IMAGEMANAGER->FindImageVector("Boss_Casting_Attack");
	_imgPhase1BossCastingAttack->Setting(0.1, true);
	_imgPhase1BossCastingEnd = IMAGEMANAGER->FindImageVector("Boss_Casting_End");
	_imgPhase1BossCastingEnd->Setting(0.1, false);
	
	_imgPhase1BossConsecrationStart = IMAGEMANAGER->FindImageVector("Boss_Consecration_Start");
	_imgPhase1BossConsecrationStart->Setting(0.1, false);
	_imgPhase1BossConsecrationLoop = IMAGEMANAGER->FindImageVector("Boss_Consecration_Loop");
	_imgPhase1BossConsecrationLoop->Setting(0.1, true);
	_imgPhase1BossConsecrationEnd = IMAGEMANAGER->FindImageVector("Boss_Consecration_End");
	_imgPhase1BossConsecrationLoop->Setting(0.1, false);
	
	_imgPhase1BossBaptismAttack = IMAGEMANAGER->FindImageVector("Boss_Baptism_Attack");
	_imgPhase1BossBaptismAttack->Setting(0.1, false);

	_isIdleOn = true;

	_isNervousnessOn = false;
	_isNervousnessLoopOn = false;
	_isNervousnessAttackLoopOn = false;
	_isNervousnessMotionEnd = false;
	_nervousnessMotionDeltaTime = 0;
	_nervousnessEffectDeltaTime = 0;

	_isChoiceOn = false;
	_isChoiceReadyLoopOn == false;
	_isChoiceAttackEnd = false;
	_choiceMotionDeltaTime = 0;

	_isCastingOn = false;
	_isCastingAttackOn = false;
	_isConsecrationLoopOn = false;

	_castingMotionDeltaTime = 0;
	_consecrationDeltaTime = 0;

	for (int i = 0; i < 30; i++)
	{
		//OBJECTMANAGER->AddObject("Baptism", WINSIZE_X / 2 + 200, 100, eEnemy)->AddComponent<Baptism>();
		Baptism* tmp = OBJECTMANAGER->AddObject("Baptism", WINSIZE_X / 2 + 200, 100, eEnemy)->AddComponent<Baptism>();
		tmp->SetIsActive(false);
		
		_vBaptism.push_back(tmp);
	}

	for (int i = 0; i < 50; i++)
	{
		int j = MY_UTILITY::getFromIntTo(0, 3);
		int k = 0;
		switch (j)
		{
		case 0:
			k = 0;
			break;
		case 1:
			k = 150;
			break;
		case 2:
			k = 300;
			break;
		case 3:
			k = 450;
			break;
		}
		WorshipLeft* tmp = OBJECTMANAGER->AddObject("Worship", 0, k, eEnemy)->AddComponent<WorshipLeft>();
		tmp->SetIsActive(false);

		_vWorshipLeft.push_back(tmp);
	}
	for (int i = 0; i < 50; i++)
	{
		int j = MY_UTILITY::getFromIntTo(0, 3);
		int k = 0;
		switch (j)
		{
		case 0:
			k = 0;
			break;
		case 1:
			k = 150;
			break;
		case 2:
			k = 300;
			break;
		case 3:
			k = 450;
			break;
		}
		WorshipRight* tmp = OBJECTMANAGER->AddObject("Worship", WINSIZE_X, k, eEnemy)->AddComponent<WorshipRight>();
		tmp->SetIsActive(false);

		_vWorshipRight.push_back(tmp);
	}
}

void BossObject::Update()
{
	if (KEYMANAGER->GetToggleKey('Q'))
	{
		_isNervousnessOn = true;
		_isIdleOn = false;
	}
	
	if (KEYMANAGER->GetToggleKey('W'))
	{
		_isChoiceOn = true;
		_isIdleOn = false;
	}

	if (KEYMANAGER->GetToggleKey('E'))
	{
		_isCastingOn = true;
		_isIdleOn = false;
	}

	if (_isNervousnessLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		_nervousnessMotionDeltaTime += DELTA_TIME;
	}
	if (_isNervousnessAttackLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		_nervousnessEffectDeltaTime += DELTA_TIME;
	}

	// 초이스_대기
	if (_isChoiceReadyLoopOn == true)
	{
		_choiceMotionDeltaTime += DELTA_TIME;
	}
	// 캐스팅_공격모션
	if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
	{
		_castingMotionDeltaTime += DELTA_TIME;
	}
	if (_patternSelect == 2)
	{
		_isWorshipCheck = true;
		_worshipDeltaTime += DELTA_TIME;
	}
}

void BossObject::Render()
{
	IMAGEMANAGER->CenterRender(_imgBossChair, WINSIZE_X / 2, WINSIZE_Y / 2 + 80, 1.8, 1.8, 0);

	// 보스 대기
	if (_isIdleOn == true)
	{
		// Idle on
		_imgBossIdle->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	}

	// 땅찍기 On
	if (_isNervousnessOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_isNervousnessLoopOn == false) _imgPhase1BossNervousReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-32, 1.8, 1.8, 0, false);

		if (_imgPhase1BossNervousReady->GetIsImageEnded() == true)
		{
			_isNervousnessLoopOn = true;
		}
	}
	// 땅찍기_공격 대기
	if (_isNervousnessLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_nervousnessMotionDeltaTime <= 1) _imgPhase1BossNervousReadyLoop->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-32, 1.8, 1.8, 0, false);
	}
	// 땅찍기_공격대기 1초 후
	if (_nervousnessMotionDeltaTime > 1)
	{
		if(_nervousnessEffectDeltaTime < 2) _imgPhase1BossNervousAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-6, 1.8, 1.8, 0, false);
		_imgPhase1NervousEffectShine->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-40, 1.5, 1.5, 0, false);

		if (_isNervousnessAttackLoopOn == false)
		{

			OBJECTMANAGER->AddObject("NervousImpactLeft", WINSIZE_X / 2, WINSIZE_Y , 1)->AddComponent<LeftImpact>();
			OBJECTMANAGER->AddObject("NervousImpactRight", WINSIZE_X / 2, WINSIZE_Y , 1)->AddComponent<RightImpact>();
		}
		_isNervousnessAttackLoopOn = true;
	}
	// 땅찍기_충격파 발사 후
	if (_isNervousnessAttackLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_nervousnessEffectDeltaTime > 2)
		{
			_imgPhase1BossNervousEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
		}
	}
	// 땅찍기_동작완료
	if (_imgPhase1BossNervousEnd->GetIsImageEnded() == true)
	{
		_nervousnessMotionDeltaTime = 0;
		_nervousnessEffectDeltaTime = 0;
		_isIdleOn = true;
		_isNervousnessLoopOn = false;
		_isNervousnessOn = false;
		_isNervousnessAttackLoopOn = false;
		_isNervousnessMotionEnd = false;

		_imgPhase1BossNervousReady->Reset();
		_imgPhase1BossNervousAttack->Reset();
		_imgPhase1NervousEffectShine->Reset();
		_imgPhase1BossNervousEnd->Reset();
	}
	
	// 초이스 On
	if (_isChoiceOn == true)
	{
		if (_isChoiceReadyLoopOn == false)
		{
			_imgPhase1BossChoiceReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
		}
	}
	// 초이스_손들기
	if (_imgPhase1BossChoiceReady->GetIsImageEnded() == true && _imgPhase1BossChoiceEnd->GetIsImageEnded() == false)
	{
		if (_choiceMotionDeltaTime < 0.5)
		{
			_imgPhase1BossChoiceReadyLoop->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
		}
		_isChoiceReadyLoopOn = true;
	}
	// 초이스_손가락튕기기
	if (_choiceMotionDeltaTime > 0.5)
	{
		if (_isChoiceAttackEnd == false)
		{
			_imgPhase1BossChoiceAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
			_imgPhase1BossChoiceSpark->CenterRender(WINSIZE_X / 2 - 150, WINSIZE_Y / 2 - 50, 1.8, 1.8, 0, false);
		}
	}
	// 초이스_동작완료
	if (_imgPhase1BossChoiceSpark->GetIsImageEnded() == true)
	{
		_isChoiceAttackEnd = true;
		if(_isChoiceOn == true)_imgPhase1BossChoiceEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	}
	// 초이스_초기화
	if (_imgPhase1BossChoiceEnd->GetIsImageEnded() == true)
	{
		_isChoiceAttackEnd = false;
		_isChoiceReadyLoopOn = false;
		_isChoiceOn = false;
		_isIdleOn = true;
		_choiceMotionDeltaTime = 0;

		_imgPhase1BossChoiceReady->Reset();
		_imgPhase1BossChoiceAttack->Reset();
		_imgPhase1BossChoiceSpark->Reset();
		_imgPhase1BossChoiceEnd->Reset();
	}

	// 캐스팅 On
	if (_isCastingOn == true)
	{
		if (_imgPhase1BossCastingReady->GetIsImageEnded() == false)
		{
			_imgPhase1BossCastingReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2 - 25, 1.8, 1.8, 0, false);
		}
	}
	// 캐스팅_공격모션
	if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
	{
		if (_consecrationDeltaTime < 2)
		{
			if (_imgPhase1BossCastingAttack->GetIsImageEnded() == false)
			{
				_imgPhase1BossCastingAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2 - 26, 1.8, 1.8, 0, false);
			}
		}

		_isCastingAttackOn = true;
	}
	// 캐스팅_패턴 선택
	if (_castingMotionDeltaTime > 0.5)
	{
		if (_patternLock == false)
		{
			_patternSelect = MY_UTILITY::getFromIntTo(0, 2);
		}

		switch (_patternSelect)
		{
		case 0:
			_patternLock = true;
			if (_isConsecrationLoopOn == false)
			{
				_imgPhase1BossConsecrationStart->CenterRender(WINSIZE_X / 2 + 200, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
			}
			if (_imgPhase1BossConsecrationStart->GetIsImageEnded() == true)
			{
				if (_isConsecrationLoopOn == false)
				{
					OBJECTMANAGER->AddObject("Consecration", WINSIZE_X / 2 + 200, WINSIZE_Y, 1)->AddComponent<Consecration>();
				}

				_consecrationDeltaTime += DELTA_TIME;
				_isConsecrationLoopOn = true;
			}
			if (_consecrationDeltaTime > 2)
			{
				_imgPhase1BossCastingEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2 - 26, 1.8, 1.8, 0, false);
				_imgPhase1BossConsecrationEnd->CenterRender(m_obj->x, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
			}
			if (_imgPhase1BossConsecrationEnd->GetIsImageEnded() == true)
			{
				_isCastingOn = false;
				_isCastingAttackOn = false;
				_isConsecrationLoopOn = false;

				_castingMotionDeltaTime = 0;
				_consecrationDeltaTime = 0;

				_imgPhase1BossCastingReady->Reset();
				_imgPhase1BossCastingEnd->Reset();
				_imgPhase1BossConsecrationStart->Reset();
				_imgPhase1BossConsecrationEnd->Reset();
				_patternDelay = 0;
				_patternLock = false;
			}
			break;
		case 1:
			// 맵 생기고 제작
			//_patternLock = true;
			//_imgPhase1BossBaptismAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
			//
			//_viBaptism = _vBaptism.begin();
			//for (; _viBaptism != _vBaptism.end(); ++_viBaptism)
			//{
			//	(*_viBaptism)->SetIsActive(true);
			//}
			break;
		case 2:
			_patternLock = true;
			if (_worshipDeltaTime > 1 && _isWorshipFirstWaveOn == false)
			{
				for (int i = 0; i <= 2; i++)
				{
					_vWorshipLeft[MY_UTILITY::getFromIntTo(0, 10)]->SetIsActive(true);
					_vWorshipRight[MY_UTILITY::getFromIntTo(0, 10)]->SetIsActive(true);
				}
				_isWorshipFirstWaveOn = true;
			}
			if (_worshipDeltaTime > 4 && _isWorshipSecondWaveOn == false)
			{
				for (int i = 0; i <= 2; i++)
				{
					_vWorshipLeft[MY_UTILITY::getFromIntTo(0, 10)]->SetIsActive(true);
					_vWorshipRight[MY_UTILITY::getFromIntTo(0, 10)]->SetIsActive(true);
				}
				_isWorshipSecondWaveOn = true;
			}
			if (_worshipDeltaTime > 7)
			{
				_imgPhase1BossCastingEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2 - 26, 1.8, 1.8, 0, false);
			}
			if (_imgPhase1BossCastingEnd->GetIsImageEnded() == true)
			{
				_isCastingOn = false;
				_isCastingAttackOn = false;

				_worshipDeltaTime = 0;
			}
			cout << _worshipDeltaTime << endl;
			break;
		}
	}
}

void BossObject::Release()
{
}

