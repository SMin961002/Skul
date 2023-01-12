#include "stdafx.h"
#include "BossObject.h"
#include "Nervousness.h"
#include "Consecration.h"
#include "Baptism.h"
#include "Worship.h"
#include "Player.h"
#include "HolyFountain.h"
#include "BossCircle.h"
#include "Gold.h"
#include "Lazer.h"
#include "DivineImpact.h"
#include "Phase3B.h"
#include"CSound.h"
void BossObject::Init()
{
	bossHpbar = IMAGEMANAGER->FindImage("bossHp");
	hpImg = IMAGEMANAGER->FindImage("hpBar");
	isMove = false;
	lazerCount = 0;
	isPhase3 = false;
	SOUNDMANAGER->FindSound("Middle")->Stop();
	SOUNDMANAGER->FindSound("Bossphase1")->Play(true);
	divineLightEf1 = IMAGEMANAGER->FindImageVector("DivineLight_ef1");
	divineLightEf2 = IMAGEMANAGER->FindImageVector("DivineLight_ef2");
	divineLightEf1->Setting(0.1, false);
	divineLightEf2->Setting(0.1, false);
	lazerImg = IMAGEMANAGER->AddImageVectorCopy("MuzzleFlash");
	trailImg = IMAGEMANAGER->AddImageVectorCopy("Trail");
	m_isMagicCircleImage = false;
	magicCircleImage = IMAGEMANAGER->FindImageVector("MagicCircle");
	magicCircleImage->Setting(0.1, false);
	trailImg->Setting(0.1, false);
	m_bossState = eIntro1;
	m_talkCount = 0;
	bossBall[0] = nullptr;
	bossBall[1] = nullptr;
	teleprotTimer = 0;
	bossBall[2] = nullptr;
	isLazer = false;
	OBJECTMANAGER->m_boss = this;
	m_teleportEffect = IMAGEMANAGER->FindImageVector("TeleportEffect");
	m_teleportEffect->Setting(0.07f, false);

	m_patterTimer = 0;
	m_currenthp = 3000;
	chairY = m_obj->y;
	chairX = m_obj->x;
	m_isAttack = false;
	m_phase2Patter = 0;

	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(coll);
	coll->SetIsActive(false);

	/*
Vector("",
Vector(""
Vector("Boss_Barrier_Loop_Front",
Vector("Boss_Barrier_Loop_Behind",
Vector("Boss_Barrier_Impact", L"./
Vector("Boss_Barrier_Spark", L"./R
("Boss_Barrier_Crack", L"./Resourc
Vector("Boss_Barrier_Crack_Impact"
Phase2_Death_Ready
Phase2_DeathLoop",
	*/
	

	deathImg = IMAGEMANAGER->AddImageVectorCopy("Phase2_Death_Effect");
	deathImg->Setting(0.1, false);
	_imgPhase1BossBarrierIntroFront = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Intro_Front");
	_imgPhase1BossBarrierIntroFront->Setting(0.1, false);
	_imgPhase1BossBarrierIntroBehind = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Intro_Behind");
	_imgPhase1BossBarrierIntroBehind->Setting(0.1, false);
	_imgPhase1BossBarrierLoopFront = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Loop_Front");
	_imgPhase1BossBarrierLoopFront->Setting(0.1, true);
	_imgPhase1BossBarrierLoopBehind = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Loop_Behind");
	_imgPhase1BossBarrierLoopBehind->Setting(0.1, true);

	_imgPhase1BossBarrierImpact = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Impact");
	_imgPhase1BossBarrierImpact->Setting(0.1, false);
	_imgPhase1BossBarrierSpark = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Spark");
	_imgPhase1BossBarrierSpark->Setting(0.1, false);
	_imgPhase1BossBarrierCrack = IMAGEMANAGER->FindImage("Boss_Barrier_Crack");
	_imgPhase1BossBarrierCrackImpact = IMAGEMANAGER->AddImageVectorCopy("Boss_Barrier_Crack_Impact");
	_imgPhase1BossBarrierCrackImpact->Setting(0.1, false);
	_left = OBJECTMANAGER->AddObject("Enemy", 100, 590, 0)->AddComponent<HolyFountainLeft>();
	_right = OBJECTMANAGER->AddObject("Enemy", 1500, 590, 0)->AddComponent<HolyFountainRight>();

	m_phase2Img[ePhase_3A] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Phase_3_Loop");
	m_phase2Img[ePhase_3A]->Setting(0.1, false);
	m_phase2Img[ePhase_3E] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Phase_3_End");
	m_phase2Img[ePhase_3E]->Setting(0.15, false);
	m_phase2Img[ePhase_3R] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Phase_3_Ready");
	m_phase2Img[ePhase_3R]->Setting(0.15, false);

	m_phase2Img[eIntro1] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Boss_Intro_1");
	m_phase2Img[eIntro1]->Setting(0.1, false);
	m_phase2Img[eIntro2] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Boss_Intro_2");
	m_phase2Img[eIntro2]->Setting(0.15, false);
	m_phase2Img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Boss_Idle");
	m_phase2Img[eIdle]->Setting(0.15, true);

	m_phase2Img[eDeathR] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Death_Ready");
	m_phase2Img[eDeathR]->Setting(0.3, false);
	m_phase2Img[eDeathL] = IMAGEMANAGER->AddImageVectorCopy("Phase2_DeathLoop");
	m_phase2Img[eDeathL]->Setting(0.3f, false);

	m_phase2Img[eDivineImpactA] = IMAGEMANAGER->AddImageVectorCopy("Phase2_DivineImpact_Attack_Loop");
	m_phase2Img[eDivineImpactA]->Setting(0.1, false);
	m_phase2Img[eDivineImpactE] = IMAGEMANAGER->AddImageVectorCopy("Phase2_DivineImpact_End");
	m_phase2Img[eDivineImpactE]->Setting(0.15, false);
	m_phase2Img[eDivineImpactR] = IMAGEMANAGER->AddImageVectorCopy("Phase2_DivineImpact_Ready");
	m_phase2Img[eDivineImpactR]->Setting(0.15, false);
	m_phase2Img[eDivineImpactRL] = IMAGEMANAGER->AddImageVectorCopy("Phase2_DivineImpact_Ready_Loop");
	m_phase2Img[eDivineImpactRL]->Setting(0.15, false);
	nowPattern = false;
	m_phase2Img[eDivineLightA] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_DivineLight_AttackLoop");
	m_phase2Img[eDivineLightA]->Setting(0.1, false);
	m_phase2Img[eDivineLightAR] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_DivineLight_AttackReady");
	m_phase2Img[eDivineLightAR]->Setting(0.15, false);
	m_phase2Img[eDivineLightR] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_DivineLight_Ready");
	m_phase2Img[eDivineLightR]->Setting(0.15, false);
	m_phase2Img[eDivineLightE] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_DivineLight_End");
	m_phase2Img[eDivineLightE]->Setting(0.15, false);

	m_phase2Img[eCreateBallA] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Boss_CreateBall_Attack");
	m_phase2Img[eCreateBallA]->Setting(0.1, false);
	m_phase2Img[eCreateBallR] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Boss_CreateBall_Ready");
	m_phase2Img[eCreateBallR]->Setting(0.15, false);
	m_phase2Img[eCreateBallE] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Boss_CreateBall_End");
	m_phase2Img[eCreateBallE]->Setting(0.15, false);

	m_page = 0;
	m_phase2Img[eSoulChaseR] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_SoulChase_Ready");
	m_phase2Img[eSoulChaseR]->Setting(0.1, false);
	m_phase2Img[eSoulChaseA] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_SoulChase_Attack");
	m_phase2Img[eSoulChaseA]->Setting(0.1, false);
	m_phase2Img[eSoulChaseE] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_SoulChase_End");
	m_phase2Img[eSoulChaseE]->Setting(0.1, false);

	_imgBossChair = IMAGEMANAGER->FindImage("Boss_Chair");

	_imgBossTalk = IMAGEMANAGER->FindImageVector("Boss_Intro_Talk");
	_imgBossTalk->Setting(0.1, true);

	_imgBossIdle = IMAGEMANAGER->FindImageVector("Boss_Idle");
	_imgBossIdle->Setting(0.1, true);
	_imgBossHPBar = IMAGEMANAGER->FindImage("Boss_HPBar");
	_imgBossHP = IMAGEMANAGER->FindImage("Boss_HP");
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

	hitAlpha = 0;
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
	_imgPhase1BossConsecrationEnd->Setting(0.1, false);

	_imgPhase1BossBaptismAttack = IMAGEMANAGER->FindImageVector("Boss_Baptism_Attack");
	_imgPhase1BossBaptismAttack->Setting(0.1, false);

	_isIntroOn = true;

	_isIdleOn = false;

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

	isActive = false;
	_isCastingOn = false;
	_isCastingAttackOn = false;
	_isConsecrationLoopOn = false;
	_bossHPBarLocate = -30;
	_castingMotionDeltaTime = 0;
	_consecrationDeltaTime = 0;

	m_currenthp = maxHp;

}

void BossObject::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_F1))
	{
		m_currenthp -= 10000;
	}
	if (hitAlpha >= 0)
	{
		hitAlpha -= 0.05;
	}
	if (_left != nullptr)
	{
		if (_left->getLeftCurrentHP() <= 0)
		{
			_left->GetObject_()->ObjectDestroyed();
			_left = nullptr;
		}
	}
	if (_right != nullptr)
	{
		if (_right->getRightCurrentHP() <= 0)
		{
			_right->GetObject_()->ObjectDestroyed();
			_right = nullptr;
		}
	}
	if (_left == nullptr && _right == nullptr)
	{
		m_page = 1;

	}
	if (isTeleport)
		Teleport();
	if (isMove)
	{
		MovePos();
	}
	if (m_page == 0)
	{
		if (_isIntroOn == false && _bossHPBarLocate <= 50 && _left != nullptr && _right != nullptr)
		{
			_bossHPBarLocate += DELTA_TIME * 50;
		}
		else if (_left == nullptr && _right == nullptr)
		{
			_bossHPBarLocate -= DELTA_TIME * 50;
		}

		if (_isIntroOn == false && nowPattern == false)
		{
			nowPattern = true;
			switch (MY_UTILITY::getFromIntTo(0, 2))
			{
			case 0:
				_isNervousnessOn = true;
				_isIdleOn = false;
				break;
			case 1:
				_isChoiceOn = true;
				_isIdleOn = false;
				break;
			case 2:
				_isCastingOn = true;
				_isIdleOn = false;
				break;
			}
		}
		else if (nowPattern == true)
		{
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
			if (_isCastingAttackOn == true && _imgPhase1BossCastingReady->GetIsImageEnded() == true)
			{
				_castingMotionDeltaTime += DELTA_TIME;
			}
			if (_patternCheck == 1 && _imgPhase1BossCastingReady->GetIsImageEnded() == true)
			{
				_isBaptismCheck = true;
				_baptismDeltaTime += DELTA_TIME;
			}
			if (_patternCheck == 2)
			{
				_isWorshipCheck = true;
				_worshipDeltaTime += DELTA_TIME;
			}
		}
	}
	else if (m_page == 1)
	{
		Page_2();
	}
}

void BossObject::Render()
{
	if (isTeleport == true)
	{
		m_teleportEffect->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
	}

	IMAGEMANAGER->CenterRender(_imgBossChair, chairX, chairY + 80, 1.8, 1.8, 0);

	// 보스 대기
	if (m_page == 0)
	{
		if (_isIntroOn == true)
		{
			if (_isIdleOn == false)
			{
				_imgBossTalk->CenterRender(m_obj->x + 28, m_obj->y, 1.8, 1.8, 0, false);
			}

			_introTimeCheck += DELTA_TIME;
			if (_introTimeCheck > 2)
			{
				_isIdleOn = true;
			}
		}
		if (m_page == 0 && _isIntroOn == false)
		{
			IMAGEMANAGER->UICenterRender(_imgBossHPBar, WINSIZE_X / 2, _bossHPBarLocate, 2, 2, 0);
		}

		if (_isIdleOn == true)
		{
			// Idle on
			_imgBossIdle->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			_isIntroOn = false;
			_introTimeCheck = 0;
		}

		// 땅찍기 On
		if (_isNervousnessOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
		{
			if (_isNervousnessLoopOn == false) _imgPhase1BossNervousReady->CenterRender(m_obj->x, m_obj->y - 32, 1.8, 1.8, 0, false);

			if (_imgPhase1BossNervousReady->GetIsImageEnded() == true)
			{
				_isNervousnessLoopOn = true;
			}
		}
		// 땅찍기_공격 대기
		if (_isNervousnessLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
		{
			if (_nervousnessMotionDeltaTime <= 1) _imgPhase1BossNervousReadyLoop->CenterRender(m_obj->x, m_obj->y - 32, 1.8, 1.8, 0, false);
		}
		// 땅찍기_공격대기 1초 후
		if (_nervousnessMotionDeltaTime > 1)
		{
			if (_nervousnessMotionDeltaTime < 3 && _isNervousnessMotionEnd == false)
			{
				_imgPhase1BossNervousAttack->CenterRender(m_obj->x, m_obj->y - 6, 1.8, 1.8, 0, false);
			}

			if (_isNervousnessAttackLoopOn == false)
			{
				OBJECTMANAGER->AddObject("NervousImpactShine", m_obj->x, m_obj->y - 20, eBossObject)->AddComponent<ImpactShine>();
				OBJECTMANAGER->AddObject("NervousImpactLeft", m_obj->x, m_obj->y + 120, eBossObject)->AddComponent<LeftImpact>();
				OBJECTMANAGER->AddObject("NervousImpactRight", m_obj->x, m_obj->y + 120, eBossObject)->AddComponent<RightImpact>();
			}
			_isNervousnessAttackLoopOn = true;

			if (_imgPhase1BossNervousAttack->GetIsImageEnded() == true && _isNervousnessMotionEnd == false)
			{
				_imgPhase1BossNervousAttackLoop->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			}

		}
		// 땅찍기_충격파 발사 후
		if (_isNervousnessAttackLoopOn == true && _imgPhase1BossNervousEnd->GetIsImageEnded() == false)
		{
			if (_nervousnessEffectDeltaTime > 3)
			{
				_isNervousnessMotionEnd = true;
				_imgPhase1BossNervousEnd->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			}
		}
		// 땅찍기_동작완료
		if (_imgPhase1BossNervousEnd->GetIsImageEnded() == true)
		{
			_nervousnessMotionDeltaTime = 0;
			_nervousnessEffectDeltaTime = 0;

			_isIdleOn = true;
			nowPattern = false;
			_isNervousnessLoopOn = false;
			_isNervousnessOn = false;
			_isNervousnessAttackLoopOn = false;
			_isNervousnessMotionEnd = false;

			_imgPhase1BossNervousReady->Reset();
			_imgPhase1BossNervousAttack->Reset();
			_imgPhase1BossNervousEnd->Reset();
		}

		// 초이스 On
		if (_isChoiceOn == true)
		{
			if (_isChoiceReadyLoopOn == false)
			{
				_imgPhase1BossChoiceReady->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			}
		}
		// 초이스_손들기
		if (_imgPhase1BossChoiceReady->GetIsImageEnded() == true && _imgPhase1BossChoiceEnd->GetIsImageEnded() == false)
		{
			if (_choiceMotionDeltaTime < 0.5)
			{
				_imgPhase1BossChoiceReadyLoop->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
			}
			_isChoiceReadyLoopOn = true;
		}
		// 초이스_손가락튕기기
		if (_choiceMotionDeltaTime > 0.5)
		{
			if (_isChoiceAttackEnd == false)
			{
				_imgPhase1BossChoiceAttack->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
				_imgPhase1BossChoiceSpark->CenterRender(m_obj->x - 150, m_obj->y - 50, 1.8, 1.8, 0, false);
			}
		}
		// 초이스_동작완료
		if (_imgPhase1BossChoiceSpark->GetIsImageEnded() == true)
		{
			_isChoiceAttackEnd = true;

		}
		if (_isChoiceAttackEnd == true)
		{
			_imgPhase1BossChoiceEnd->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
		}
		// 초이스_초기화
		if (_imgPhase1BossChoiceEnd->GetIsImageEnded() == true)
		{
			_isChoiceAttackEnd = false;
			_isChoiceReadyLoopOn = false;
			_isChoiceOn = false;
			_isIdleOn = true;
			_choiceMotionDeltaTime = 0;
			nowPattern = false;
			_isChoiceOn = false;
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
				_imgPhase1BossCastingReady->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
			}
		}
		// 캐스팅_공격모션
		if (_imgPhase1BossCastingReady->GetIsImageEnded() == true)
		{
			if (_consecrationDeltaTime < 2 && _worshipDeltaTime < 5 && _imgPhase1BossBaptismAttack->GetIsImageEnded() == false)
			{
				if (_imgPhase1BossCastingAttack->GetIsImageEnded() == false)
				{
					_imgPhase1BossCastingAttack->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
				}
			}

			_isCastingAttackOn = true;
		}
		// 캐스팅_패턴 선택
		if (_castingMotionDeltaTime > 0.5 && _isCastingAttackOn == true)
		{
			if (_patternLock == false)
			{
				_patternCheck = MY_UTILITY::getFromIntTo(0, 2);

				_consecrationDeltaTime = 0;
				_castingMotionDeltaTime = 0;
				_consecrationDeltaTime = 0;
				_locate = OBJECTMANAGER->m_player->GetplayerX();
			}

			switch (_patternCheck)
			{
			case 0:
				// 레이저
				_patternLock = true;
				if (_isConsecrationLoopOn == false)
				{
					_imgPhase1BossConsecrationStart->CenterRender(_locate, m_obj->y - 130, 1.8, 1.8, 0, false);
				}
				if (_imgPhase1BossConsecrationStart->GetIsImageEnded() == true)
				{
					if (_isConsecrationLoopOn == false)
					{
						OBJECTMANAGER->AddObject("Consecration", _locate, m_obj->y - 130, eBossObject)->AddComponent<Consecration>();
					}

					_consecrationDeltaTime += DELTA_TIME;
					_isConsecrationLoopOn = true;
				}
				if (_consecrationDeltaTime > 2)
				{
					_imgPhase1BossCastingEnd->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
					//_imgPhase1BossConsecrationEnd->CenterRender(_locate, m_obj->y, 1.8, 1.8, 0, false);
				}
				if (_imgPhase1BossCastingEnd->GetIsImageEnded() == true)
				{
					_isCastingOn = false;
					_isCastingAttackOn = false;
					_isConsecrationLoopOn = false;
					_consecrationDeltaTime = 0;
					_castingMotionDeltaTime = 0;
					_consecrationDeltaTime = 0;
					nowPattern = false;
					_imgPhase1BossCastingReady->Reset();
					_imgPhase1BossCastingEnd->Reset();
					_imgPhase1BossConsecrationStart->Reset();
					_imgPhase1BossConsecrationEnd->Reset();

					_patternLock = false;
				}
				break;
			case 1:
				// 밥티즘
				_patternLock = true;


				if (_imgPhase1BossBaptismAttack->GetIsImageEnded() == false)
					_imgPhase1BossBaptismAttack->CenterRender(m_obj->x + 130, m_obj->y - 120, 1.8, 1.8, 0, false);
				else
				{
					if (_imgPhase1BossCastingEnd->GetIsImageEnded() == false)
					{
						_imgPhase1BossCastingEnd->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
					}
					if (_imgPhase1BossCastingEnd->GetIsImageEnded() == true)
					{
						_isCastingOn = false;
						_isCastingAttackOn = false;
						_isConsecrationLoopOn = false;
						_baptismDeltaTime = 0;
						_imgPhase1BossCastingReady->Reset();
						_imgPhase1BossCastingEnd->Reset();
						_imgPhase1BossBaptismAttack->Reset();
						nowPattern = false;
						_patternLock = false;
					}
				}

				break;
			case 2:
				// 워쉽
				if (_patternLock == false)
				{
					random_device rd;
					shuffle(suf, &suf[4], rd);
					OBJECTMANAGER->AddObject("Worship", 0, 50 + suf[0] * 150, eBossObject)->AddComponent<WorshipLeft>();
					OBJECTMANAGER->AddObject("Worship", 0, 50 + suf[1] * 150, eBossObject)->AddComponent<WorshipLeft>();
					OBJECTMANAGER->AddObject("Worship", 0, 50 + suf[2] * 150, eBossObject)->AddComponent<WorshipLeft>();
					shuffle(suf, &suf[4], rd);
					OBJECTMANAGER->AddObject("Worship", 1600, 50 + suf[0] * 150, eBossObject)->AddComponent<WorshipRight>();
					OBJECTMANAGER->AddObject("Worship", 1600, 50 + suf[1] * 150, eBossObject)->AddComponent<WorshipRight>();
					OBJECTMANAGER->AddObject("Worship", 1600, 50 + suf[2] * 150, eBossObject)->AddComponent<WorshipRight>();
				}

				_patternLock = true;

				cout << _worshipDeltaTime << endl;
				if (_worshipDeltaTime > 5)
				{
					_imgPhase1BossCastingEnd->CenterRender(m_obj->x, m_obj->y - 26, 1.8, 1.8, 0, false);
				}
				if (_imgPhase1BossCastingEnd->GetIsImageEnded() == true)
				{
					_isCastingOn = false;
					_isCastingAttackOn = false;
					_isConsecrationLoopOn = false;
					_worshipDeltaTime = 0;
					_imgPhase1BossCastingReady->Reset();
					_imgPhase1BossCastingEnd->Reset();
					nowPattern = false;
					_patternLock = false;
				}

				break;
			}
		}
	}
	else if (m_page == 1)
	{
		if (m_isAttack == true)
		{
			if (m_bossState == eCreateBallR)
			{
				if (m_phase2Img[eCreateBallR]->GetIsImageEnded() == true)
				{
					m_bossState = eCreateBallA;
					if (m_phase2Patter == 3)
					{
						bossBall[0] = OBJECTMANAGER->AddObject("Enemy2", m_obj->x, m_obj->y, eBossObject)->AddComponent<BossBall>();
						bossBall[1] = OBJECTMANAGER->AddObject("Enemy2", m_obj->x, m_obj->y, eBossObject)->AddComponent<BossBall>();
						bossBall[2] = OBJECTMANAGER->AddObject("Enemy2", m_obj->x, m_obj->y, eBossObject)->AddComponent<BossBall>();
						bossBall[0]->Setting((2 * 3.141592) / 3 * 1);
						bossBall[1]->Setting((2 * 3.141592) / 3 * 2);
						bossBall[2]->Setting((2 * 3.141592) / 3 * 3);
					}
					else
					{
						bossBall[0]->ldist = !bossBall[0]->ldist;
						bossBall[1]->ldist = !bossBall[1]->ldist;
						bossBall[2]->ldist = !bossBall[2]->ldist;
					}
				}
			}
			else if (m_bossState == eCreateBallA)
			{
				if (m_phase2Img[eCreateBallA]->GetIsImageEnded() == true)
				{
					m_bossState = eCreateBallE;
				}
			}
			else if (m_bossState == eCreateBallE)
			{
				if (m_phase2Img[eCreateBallE]->GetIsImageEnded() == true)
				{
					m_bossState = eIdle;
					m_phase2Patter++;
					m_isAttack = false;
				}
			}
		}
		else if (m_bossState == eIntro1)
		{
			if (m_talkCount > 3)
			{
				m_bossState = eIntro2;
			}
			else if (m_phase2Img[eIntro1]->GetIsImageEnded() == true)
			{
				m_talkCount++;
				m_phase2Img[eIntro1]->Reset();
			}
		}
		else if (m_bossState == eIntro2)
		{
			if (m_phase2Img[eIntro2]->GetIsImageEnded() == true)
			{
				m_bossState = eIdle;
				m_phase2Patter++;
			}
		}
		if (m_bossState == eIntro1 || m_bossState == eIntro2)
		{
			m_phase2Img[m_bossState]->CenterRender(m_obj->x + 20, m_obj->y - 20, 1.8, 1.8, 0, 0, alpha);
			IMAGEMANAGER->CenterRender(m_phase2Img[m_bossState]->GetNowImage(), m_obj->x + 20, m_obj->y - 20, { 255,255,255,hitAlpha }, 1.8, 1.8);
			_bossHPBarLocate = -60;

		}
		else
		{
			if (_bossHPBarLocate <= 50)
			{
				_bossHPBarLocate += DELTA_TIME * 50;
			}
			if (m_bossState != -1)
			{
				m_phase2Img[m_bossState]->CenterRender(m_obj->x - 3, m_obj->y + 25, 1.8, 1.8, 0, 0, alpha);
				IMAGEMANAGER->CenterRender(m_phase2Img[m_bossState]->GetNowImage(), m_obj->x - 3, m_obj->y + 25, { 255,255,255,hitAlpha }, 1.8, 1.8);
			}
		}
	}
	if (m_isMagicCircleImage == true)
	{
		if (magicCircleImage->GetFrame() == 15 && circleCount == 0)
		{
			circleCount++;
			OBJECTMANAGER->AddObject("Enemy2", m_obj->x, m_obj->y + 80, eBossObject)->AddComponent<BossCircle>();
		}
		if (magicCircleImage->GetIsImageEnded() == true)
		{
			m_bossState = eSoulChaseE;
		}
		magicCircleImage->CenterRender(m_obj->x - 15, m_obj->y + 80, 1.5, 1.5, 0, 0);
		trailImg->CenterRender(m_obj->x, m_obj->y + 80, 1.5, 1.5, 0, 0);
	}
	if (isLazer == true)
	{
		divineLightEf1->CenterRender(m_obj->x + 100, m_obj->y, 1.5, 1.5, 0, 0, 1);
		divineLightEf2->CenterRender(m_obj->x + 190, m_obj->y, 1.5, 1.5, 0, 0, 1);
	}
	if (_left != nullptr)
		IMAGEMANAGER->UIRender(hpImg, 250, _bossHPBarLocate, 245.f / 300 * _left->getLeftCurrentHP(), 2.7);
	if (_right != nullptr)
		IMAGEMANAGER->UIRender(hpImg, 603, _bossHPBarLocate, 245.f / 300 * _right->getRightCurrentHP(), 2.7);

	if (_imgPhase1BossBarrierIntroFront->GetIsImageEnded() == false)
	{
		_imgPhase1BossBarrierIntroBehind->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
		_imgPhase1BossBarrierIntroFront->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
	}
	else
	{
		if (_left != nullptr || _right != nullptr)
		{
			if (_left != nullptr)
			{
				_imgPhase1BossBarrierLoopFront->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
			}
			else
			{
				if (_imgPhase1BossBarrierCrackImpact->GetIsImageEnded() == false)
				{
					_imgPhase1BossBarrierCrackImpact->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
					_imgPhase1BossBarrierSpark->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
				}
				else
				{
					IMAGEMANAGER->CenterRender(_imgPhase1BossBarrierCrack, m_obj->x, m_obj->y, 2, 2);
				}
			}
			if (_right != nullptr)
			{
				_imgPhase1BossBarrierLoopBehind->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
			}
			else
			{
				if (_imgPhase1BossBarrierCrackImpact->GetIsImageEnded() == false)
				{
					_imgPhase1BossBarrierCrackImpact->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
					_imgPhase1BossBarrierSpark->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
				}
				else
				{
					IMAGEMANAGER->CenterRender(_imgPhase1BossBarrierCrack, m_obj->x, m_obj->y, 2, 2);
				}
			}
		}
		else
		{
			if (_imgPhase1BossBarrierSpark->GetIsImageEnded() == false)
			{
				IMAGEMANAGER->CenterRender(_imgPhase1BossBarrierCrack, m_obj->x, m_obj->y, 2, 2);
				_imgPhase1BossBarrierImpact->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
				_imgPhase1BossBarrierSpark->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
			}
		}
	}

	if (m_page == 1)
	{
		if (m_currenthp <= 0)
		{
			m_currenthp = 0;
			m_page = 2;
			m_bossState = eDeathR;
		}
		IMAGEMANAGER->UICenterRender(bossHpbar, WINSIZE_X / 2, _bossHPBarLocate, 2, 2, 0);
		IMAGEMANAGER->UIRender(hpImg, 277, _bossHPBarLocate, 547.f / maxHp * m_currenthp, 2.6);
	}

	if (m_page == 2)
	{
		_bossHPBarLocate -= DELTA_TIME * 50;
		if (m_bossState != -1)
			m_phase2Img[m_bossState]->CenterRender(m_obj->x - 3, m_obj->y + 25, 1.8, 1.8, 0, 0, alpha);
		IMAGEMANAGER->UICenterRender(bossHpbar, WINSIZE_X / 2, _bossHPBarLocate, 2, 2, 0);
		IMAGEMANAGER->UIRender(hpImg, 277, _bossHPBarLocate, 547.f / maxHp * m_currenthp, 2.6);
		if (m_bossState == eDeathR)
		{
			if (m_phase2Img[m_bossState]->GetIsImageEnded() == true)
			{
				m_bossState = eDeathL;
			}
		}
		if (m_bossState == eDeathL)
		{

		}
	}
	if (isEnd == false)
	{
		if (m_phase2Img[eDeathL]->GetIsImageEnded() == true)
		{
			if (m_bossState != -1)
			{
				for (int i = 0; i < 100; i++)
				{
					OBJECTMANAGER->AddObject("gold", m_obj->x, m_obj->y, eBossObject)->AddComponent<Gold>();
				}
			}
			m_bossState = -1;
			SCENEMANAGER->FadeInColor(0.005, [&]() {isEnd = true; }, 5611);
			deathImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);

			if (isEnd == true)
			{

			}
		}
	}


	//_imgPhase1BossBarrierIntroBehind;
	//_imgPhase1BossBarrierLoopFront;
	//_imgPhase1BossBarrierLoopBehind;
	//_imgPhase1BossBarrierImpact;
	//_imgPhase1BossBarrierCrack;
	//_imgPhase1BossBarrierCrackImpact;
}

void BossObject::Release()
{
}

void BossObject::HitEnemy(float dmg, float time)
{
	m_currenthp -= dmg;
	hitAlpha = 1;
	if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 0, 1.5);
	}
	else
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 1, 1.5);
	}
}

void BossObject::Page_2()
{
	coll->Setting(100, m_obj->x + 50, m_obj->y + 80, "hitBox");
	if (m_phase2Patter == 1)
	{
		if (m_obj->y < 200)
		{
			m_phase2Patter = 2;
		}
		chairY += DELTA_TIME * 80;
		m_obj->y -= 40 * DELTA_TIME;
	}
	else if (m_phase2Patter == 2)
	{
		m_patterTimer += DELTA_TIME;
		coll->SetIsActive(true);

		if (m_patterTimer > 1)
		{
			m_phase2Patter = 3;
			m_patterTimer = 0;
		}

	}
	else if (m_phase2Patter == 3)
	{
		if (m_isAttack == false)
		{
			m_bossState = eCreateBallR;
			m_isAttack = true;
		}
		else
		{
			if (m_phase2Img[eCreateBallE]->GetIsImageEnded() == true)
			{
				m_phase2Patter = 4;
				m_isAttack = false;
			}
		}
	}
	else if (m_phase2Patter == 4)
	{
		m_patterTimer++;
		if (m_patterTimer > 1)
		{
			m_phase2Img[eCreateBallA]->Reset();
			m_phase2Img[eCreateBallR]->Reset();
			m_phase2Img[eCreateBallE]->Reset();
			m_phase2Patter = 5;
			m_isAttack = false;
			m_patterTimer = 0;
		}
	}
	else if (m_phase2Patter == 5)
	{
		if (m_isAttack == false)
		{
			m_bossState = eCreateBallR;
			m_isAttack = true;
		}
		else
		{
			if (m_phase2Img[eCreateBallE]->GetIsImageEnded() == true)
			{
				m_phase2Patter = 6;
				m_isAttack = false;
				m_bossState = eIdle;
			}
		}
	}
	else if (m_phase2Patter == 6)
	{
		tpX = (float)MY_UTILITY::getFromFloatTo(200, 1400);
		tpY = (int)MY_UTILITY::getFromFloatTo(100, 500);
		isTeleport = true;
	}
	else if (m_phase2Patter == 7)
	{
		if (isLazer == false)
		{
			divineLightEf1->Reset();
			divineLightEf2->Reset();
			m_phase2Img[eDivineLightE]->Reset();
			m_phase2Img[eDivineLightA]->Reset();
			m_phase2Img[eDivineLightAR]->Reset();
			m_phase2Img[eDivineLightR]->Reset();
			lazerCount = 0;
			tpX = 200;
			tpY = (int)MY_UTILITY::getFromFloatTo(100, 500);
			isTeleport = true;
		}
	}
	else if (m_phase2Patter == 8)
	{
		if (m_phase2Img[eDivineLightE]->GetIsImageEnded() == true)
		{
			m_phase2Patter++;
			isLazer = false;
			m_bossState = eIdle;
		}
		else if (m_phase2Img[eDivineLightA]->GetIsImageEnded() == true)
		{
			lazerCount++;
			if (lazerCount > 3)
			{
				m_bossState = eDivineLightE;
			}
			else
				m_phase2Img[eDivineLightA]->Reset();
		}
		else if (m_phase2Img[eDivineLightAR]->GetIsImageEnded() == true)
		{
			if (isLazer == false)
			{
				OBJECTMANAGER->AddObject("Enemy2", m_obj->x + 400, m_obj->y, eEnemy)->AddComponent<Lazer>();
			}
			isLazer = true;
			m_bossState = eDivineLightA;
		}
		else if (m_phase2Img[eDivineLightR]->GetIsImageEnded() == true)
		{
			m_bossState = eDivineLightAR;
		}
		else
		{
			m_bossState = eDivineLightR;
		}
	}
	else if (m_phase2Patter == 9)
	{
		if (isTeleport == false)
		{
			tpX = (float)MY_UTILITY::getFromFloatTo(200, 1400);
			tpY = (int)MY_UTILITY::getFromFloatTo(100, 500);
			isTeleport = true;
		}
	}
	else if (m_phase2Patter == 10)
	{
		if (m_isMagicCircleImage == false)
		{
			trailImg->Reset();
			magicCircleImage->Reset();
			circleCount = 0;
			m_phase2Img[eSoulChaseR]->Reset();
			m_phase2Img[eSoulChaseA]->Reset();
			m_phase2Img[eSoulChaseE]->Reset();
			m_isMagicCircleImage = true;
			m_bossState = eSoulChaseR;
		}
		if (m_phase2Img[eSoulChaseE]->GetIsImageEnded() == true)
		{
			m_phase2Patter++;
			m_phase2Img[eIdle]->Reset();
			m_isMagicCircleImage = false;
			m_bossState = eIdle;
		}
	}
	else if (m_phase2Patter == 11)
	{
		if (isMove == false)
		{
			m_bossState = eIdle;
			tpX = (int)MY_UTILITY::getFromFloatTo(200, 1400);
			tpY = (int)MY_UTILITY::getFromFloatTo(100, 600);
			isMove = true;
		}
	}
	else if (m_phase2Patter == 12)
	{
		if (isDivine == false)
		{
			m_phase2Img[eDivineImpactR]->Reset();
			m_phase2Img[eDivineImpactA]->Reset();
			m_phase2Img[eDivineImpactRL]->Reset();
			m_phase2Img[eDivineImpactE]->Reset();
			devineCount = 0;
			m_bossState = eDivineImpactR;
			isDivine = true;
		}
		if (m_bossState == eDivineImpactR)
		{
			if (m_phase2Img[eDivineImpactR]->GetIsImageEnded() == true)
			{
				m_bossState = eDivineImpactRL;
			}
		}
		if (m_bossState == eDivineImpactRL)
		{
			if (m_phase2Img[eDivineImpactRL]->GetIsImageEnded() == true)
			{
				m_bossState = eDivineImpactA;
			}
		}
		if (m_bossState == eDivineImpactA)
		{
			if (m_phase2Img[eDivineImpactA]->GetIsImageEnded() == true)
			{
				if (devineCount < 10)
				{
					m_phase2Img[eDivineImpactA]->Reset();
					devineCount++;
					OBJECTMANAGER->AddObject("Enemy2", m_obj->x, m_obj->y, eBossObject)->AddComponent<DivineImpact>();
				}
				else
				{
					m_bossState = eDivineImpactE;
				}
			}
		}
		if (m_bossState == eDivineImpactE)
		{
			if (m_phase2Img[eDivineImpactE]->GetIsImageEnded() == true)
			{
				m_phase2Patter++;
				isDivine = false;
				devineCount = 0;
				m_bossState = eIdle;
			}
		}
	}
	else if (m_phase2Patter == 13)
	{
		if (isPhase3 == false)
		{
			m_bossState = ePhase_3R;
			isPhase3 = true;
		}
		if (m_bossState == ePhase_3R)
		{
			if (m_phase2Img[ePhase_3R]->GetIsImageEnded() == true)
			{
				m_bossState = ePhase_3A;
				for (int i = 0; i < 50; i++)
					OBJECTMANAGER->AddObject("Enemy2", MY_UTILITY::getFromFloatTo(50, 1550), MY_UTILITY::getFromFloatTo(30, 650), eEnemy)->AddComponent<Phase3B>();
			}
		}
		if (m_bossState == ePhase_3A)
		{
			if (m_phase2Img[ePhase_3A]->GetIsImageEnded() == true)
			{
				m_bossState = ePhase_3E;
			}
		}
		if (m_bossState == ePhase_3E)
		{
			if (m_phase2Img[ePhase_3E]->GetIsImageEnded() == true)
			{
				isPhase3 = false;
				m_phase2Patter = 6;
			}
		}
	}
}

void BossObject::Teleport()
{
	if (m_teleportEffect->GetFrame() > 10)
	{
		if (isActive == false)
		{
			if (alpha > 0)
			{
				alpha -= DELTA_TIME * 0.5f;
			}
		}
		else
		{
			if (alpha < 1)
			{
				alpha += DELTA_TIME * 0.5f;
			}
		}
	}
	if (m_teleportEffect->GetIsImageEnded() == true)
	{
		if (isActive == true)
		{
			m_teleportEffect->Reset();
			isTeleport = false;
			isActive = false;
			m_phase2Patter++;
		}
		else
		{
			teleprotTimer += DELTA_TIME;
		}
		if (teleprotTimer > 0.5f)
		{
			m_obj->x = tpX;
			m_obj->y = tpY;

			m_teleportEffect->Reset();
			teleprotTimer = 0;
			isActive = true;
		}
	}
}

void BossObject::MovePos()
{
	Vector2 v;
	MY_UTILITY::GetLerpVec2(&v, { m_obj->x,m_obj->y }, { tpX,tpY }, 0.01);
	m_obj->x = v.x;
	m_obj->y = v.y;

	if (abs(m_obj->x - tpX) < 1 && abs(m_obj->y - tpY) < 100)
	{
		m_phase2Patter++;
		isMove = false;
	}
}
