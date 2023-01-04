#include "stdafx.h"
#include "BossObject.h"
#include "Nervousness.h"
#include "Consecration.h"

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
}

void BossObject::Render()
{
	IMAGEMANAGER->CenterRender(_imgBossChair, WINSIZE_X / 2, WINSIZE_Y / 2 + 80, 1.8, 1.8, 0);

	// ���� ���
	if (_isIdleOn == true)
	{
		// Idle on
		_imgBossIdle->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	}

	// ����� On
	if (_isNervousnessOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_isNervousnessLoopOn == false) _imgPhase1BossNervousReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-32, 1.8, 1.8, 0, false);

		if (_imgPhase1BossNervousReady->GetIsImageEnded() == true)
		{
			_isNervousnessLoopOn = true;
		}
	}
	// �����_���� ���
	if (_isNervousnessLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_nervousnessMotionDeltaTime <= 1) _imgPhase1BossNervousReadyLoop->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-32, 1.8, 1.8, 0, false);

		_nervousnessMotionDeltaTime += DELTA_TIME;
	}
	// �����_���ݴ�� 1�� ��
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
	// �����_����� �߻� ��
	if (_isNervousnessAttackLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		_nervousnessEffectDeltaTime += DELTA_TIME;

		if (_nervousnessEffectDeltaTime > 2)
		{
			_imgPhase1BossNervousEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
		}
	}
	// �����_���ۿϷ�
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
	
	// ���̽� On
	if (_isChoiceOn == true)
	{
		if(_isChoiceReadyLoopOn == false) _imgPhase1BossChoiceReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	}
	// ���̽�_�յ��
	if (_imgPhase1BossChoiceReady->GetIsImageEnded() == true && _imgPhase1BossChoiceEnd->GetIsImageEnded() == false)
	{
		if(_choiceMotionDeltaTime < 0.5) _imgPhase1BossChoiceReadyLoop->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);

		_isChoiceReadyLoopOn = true;
	}
	// ���̽�_���
	if (_isChoiceReadyLoopOn == true)
	{
		_choiceMotionDeltaTime += DELTA_TIME;
	}
	// ���̽�_�հ���ƨ���
	if (_choiceMotionDeltaTime > 0.5)
	{
		if (_isChoiceAttackEnd == false)
		{
			_imgPhase1BossChoiceAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
			_imgPhase1BossChoiceSpark->CenterRender(WINSIZE_X / 2 - 150, WINSIZE_Y / 2 - 50, 1.8, 1.8, 0, false);
		}
	}
	// ���̽�_���ۿϷ�
	if (_imgPhase1BossChoiceSpark->GetIsImageEnded() == true)
	{
		_isChoiceAttackEnd = true;
		if(_isChoiceOn == true)_imgPhase1BossChoiceEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	}
	// ���̽�_�ʱ�ȭ
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

	// ĳ���� On
	if (_isCastingOn == true)
	{
		 _imgPhase1BossCastingReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-25, 1.8, 1.8, 0, false);
	}
	if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
	{
		_imgPhase1BossCastingAttack->CenterRender(WINSIZE_X / 2, WINSIZE_Y / 2-26, 1.8, 1.8, 0, false);
		
		_isCastingAttackOn = true;
		_castingMotionDeltaTime += DELTA_TIME;
	}
	if (_castingMotionDeltaTime > 0.5)
	{
		if (_isConsecrationLoopOn == false)_imgPhase1BossConsecrationStart->CenterRender(WINSIZE_X / 2 + 200, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
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
		_imgPhase1BossCastingEnd->CenterRender(WINSIZE_X / 2, WINSIZE_Y/2, 1.8, 1.8, 0, false);
		_imgPhase1BossConsecrationEnd->CenterRender(WINSIZE_X / 2 + 200, WINSIZE_Y / 2, 1.8, 1.8, 0, false);
	}
}

void BossObject::Release()
{
}

