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
		//OBJECTMANAGER->AddObject("Baptism", m_obj->x + 200, 100, eEnemy)->AddComponent<Baptism>();
		Baptism* tmp = OBJECTMANAGER->AddObject("Baptism", m_obj->x + 200, 100, eEnemy)->AddComponent<Baptism>();
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

	// ���̽�_���
	if (_isChoiceReadyLoopOn == true)
	{
		_choiceMotionDeltaTime += DELTA_TIME;
	}
	// ĳ����_���ݸ��
	if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
	{
		_castingMotionDeltaTime += DELTA_TIME;
	}
}

void BossObject::Render()
{
	IMAGEMANAGER->CenterRender(_imgBossChair, m_obj->x, m_obj->y + 80, 1.8, 1.8, 0);

	// ���� ���
	if (_isIdleOn == true)
	{
		// Idle on
		_imgBossIdle->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
	}

	// ����� On
	if (_isNervousnessOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_isNervousnessLoopOn == false) _imgPhase1BossNervousReady->CenterRender(m_obj->x, m_obj->y-32, 1.8, 1.8, 0, false);

		if (_imgPhase1BossNervousReady->GetIsImageEnded() == true)
		{
			_isNervousnessLoopOn = true;
		}
	}
	// �����_���� ���
	if (_isNervousnessLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_nervousnessMotionDeltaTime <= 1) _imgPhase1BossNervousReadyLoop->CenterRender(m_obj->x, m_obj->y-32, 1.8, 1.8, 0, false);
	}
	// �����_���ݴ�� 1�� ��
	if (_nervousnessMotionDeltaTime > 1)
	{
		if(_nervousnessEffectDeltaTime < 2) _imgPhase1BossNervousAttack->CenterRender(m_obj->x, m_obj->y-6, 1.8, 1.8, 0, false);
		_imgPhase1NervousEffectShine->CenterRender(m_obj->x, m_obj->y-40, 1.5, 1.5, 0, false);

		if (_isNervousnessAttackLoopOn == false)
		{

			OBJECTMANAGER->AddObject("NervousImpactLeft", m_obj->x, WINSIZE_Y , 1)->AddComponent<LeftImpact>();
			OBJECTMANAGER->AddObject("NervousImpactRight", m_obj->x, WINSIZE_Y , 1)->AddComponent<RightImpact>();
		}
		_isNervousnessAttackLoopOn = true;
	}
	// �����_����� �߻� ��
	if (_isNervousnessAttackLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
	{
		if (_nervousnessEffectDeltaTime > 2)
		{
			_imgPhase1BossNervousEnd->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
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
		if (_isChoiceReadyLoopOn == false)
		{
			_imgPhase1BossChoiceReady->CenterRender(m_obj->x,m_obj->y, 1.8, 1.8, 0, false);
		}
	}
	// ���̽�_�յ��
	if (_imgPhase1BossChoiceReady->GetIsImageEnded() == true && _imgPhase1BossChoiceEnd->GetIsImageEnded() == false)
	{
		if (_choiceMotionDeltaTime < 0.5)
		{
			_imgPhase1BossChoiceReadyLoop->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
		}
		_isChoiceReadyLoopOn = true;
	}
	// ���̽�_�հ���ƨ���
	if (_choiceMotionDeltaTime > 0.5)
	{
		if (_isChoiceAttackEnd == false)
		{
			_imgPhase1BossChoiceAttack->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			_imgPhase1BossChoiceSpark->CenterRender(m_obj->x - 150, m_obj->y - 50, 1.8, 1.8, 0, false);
		}
	}
	// ���̽�_���ۿϷ�
	if (_imgPhase1BossChoiceSpark->GetIsImageEnded() == true)
	{
		_isChoiceAttackEnd = true;
		if(_isChoiceOn == true)_imgPhase1BossChoiceEnd->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
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
		if (_isConsecrationLoopOn == false) _imgPhase1BossCastingReady->CenterRender(m_obj->x, m_obj->y - 25, 1.8, 1.8, 0, false);
	}
	// ĳ����_���ݸ��
	if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
	{
		if (_consecrationDeltaTime < 2)
		{
			_imgPhase1BossCastingAttack->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
		}

		_isCastingAttackOn = true;
	}
	// ĳ����_���� ����
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
				_imgPhase1BossConsecrationStart->CenterRender(m_obj->x + 200, m_obj->y, 1.8, 1.8, 0, false);
			}
			if (_imgPhase1BossConsecrationStart->GetIsImageEnded() == true)
			{
				if (_isConsecrationLoopOn == false)
				{
					OBJECTMANAGER->AddObject("Consecration", m_obj->x + 200, WINSIZE_Y, 1)->AddComponent<Consecration>();
				}

				_consecrationDeltaTime += DELTA_TIME;
				_isConsecrationLoopOn = true;
			}
			if (_consecrationDeltaTime > 2)
			{
				_imgPhase1BossCastingEnd->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
				_imgPhase1BossConsecrationEnd->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
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
			// �� ����� ����
			//_patternLock = true;
			//_imgPhase1BossBaptismAttack->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			//
			//_viBaptism = _vBaptism.begin();
			//for (; _viBaptism != _vBaptism.end(); ++_viBaptism)
			//{
			//	(*_viBaptism)->SetIsActive(true);
			//}
			break;
		case 2:
			for (int i = 0; i < 2; i++)
			{
				_vWorshipLeft[i]->SetIsActive(true);
				_vWorshipRight[i]->SetIsActive(true);
			}
			break;
		}
	}

}

void BossObject::Release()
{
}

