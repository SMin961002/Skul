#include "stdafx.h"
#include "ImageManager.h"

void ImageManager::LoadImages()
{
	AddImage("CaerleonSword", L"./Resources/Item/CaerleonSword.png");

	AddImage("Pause_Frame", L"./Resources/UI/Pause_Frame.png");

	// 맵툴 UI 이미지
	AddImage("newFile", L"./MapFile/newFile.png");

	// 예시 이미지
	AddImage("Frame_1SKill", L"./Resources/Frame_1SKill.png");

	//캐릭터 이펙트
	AddImageVector("DashSmoke", L"./Resources/Png/Skul/Effect/DashSmoke/", 1, 13);
	AddImageVector("JumpSmoke", L"./Resources/Png/Skul/Effect/DoubleJumpSmoke/", 1, 10);
	AddImageVector("PlayerHit", L"./Resources/Png/Skul/Effect/Hit/", 1, 12);
	//AddImageVector("PlayerCHit", L"./Resources/Png/Skul/Effect/Hit/", 1, 8);
	//AddImageVector("PlayerCPublicHit", L"./Resources/Png/Skul/Effect/CriticalHit/", 1, 11);

	//일반스컬 모션 이미지
	AddImageVector("Basic_Idle", L"./Resources/Png/Skul/Basic/Motion/Idle/", 1, 4);
	AddImageVector("Basic_Walk", L"./Resources/Png/Skul/Basic/Motion/Walk/", 1, 8);
	AddImageVector("Basic_Dash", L"./Resources/Png/Skul/Basic/Motion/Dash/", 1, 1);
	AddImageVector("Basic_Attack1", L"./Resources/Png/Skul/Basic/Motion/Attack1/", 1, 5);
	AddImageVector("Basic_Attack2", L"./Resources/Png/Skul/Basic/Motion/Attack2/", 1, 4);
	AddImageVector("Basic_JumpStart", L"./Resources/Png/Skul/Basic/Motion/JumpStart/", 1, 2);
	AddImageVector("Basic_JumpRepeat", L"./Resources/Png/Skul/Basic/Motion/JumpRepeat/", 1, 3);
	AddImageVector("Basic_JumpFall", L"./Resources/Png/Skul/Basic/Motion/JumpFall/", 1, 2);
	AddImageVector("Basic_JumpAttack", L"./Resources/Png/Skul/Basic/Motion/JumpAttack/", 1, 4);
	AddImageVector("Basic_Reborn", L"./Resources/Png/Skul/Basic/Motion/Reborn/", 1, 27);
	AddImageVector("Basic_Skill", L"./Resources/Png/Skul/Basic/Motion/Skill/", 1, 4);
	AddImageVector("Basic_TagAction", L"./Resources/Png/Skul/Basic/Motion/TagAction/", 1, 14);

	//일반스컬 - 머리 없는 모션 이미지
	AddImageVector("Basic_Headless_Idle", L"./Resources/Png/Skul/Basic/Headless/HeadlessIdle/", 1, 4);
	AddImageVector("Basic_Headless_Walk", L"./Resources/Png/Skul/Basic/Headless/HeadlessWalk/", 1, 8);
	AddImageVector("Basic_Headless_Dash", L"./Resources/Png/Skul/Basic/Headless/HeadlessDash/", 1, 1);
	AddImageVector("Basic_Headless_Attack1", L"./Resources/Png/Skul/Basic/Headless/HeadlessAttack1/", 1, 5);
	AddImageVector("Basic_Headless_Attack2", L"./Resources/Png/Skul/Basic/Headless/HeadlessAttack2/", 1, 4);
	AddImageVector("Basic_Headless_JumpStart", L"./Resources/Png/Skul/Basic/Headless/HeadlessJumpStart/", 1, 2);
	AddImageVector("Basic_Headless_JumpRepeat", L"./Resources/Png/Skul/Basic/Headless/HeadlessJumpRepeat/", 1, 3);
	AddImageVector("Basic_Headless_JumpFall", L"./Resources/Png/Skul/Basic/Headless/HeadlessJumpFall/", 1, 2);
	AddImageVector("Basic_Headless_JumpAttack", L"./Resources/Png/Skul/Basic/Headless/HeadlessJumpAttack/", 1, 4);
	AddImage("Basic_Skull", L"./Resources/Png/Skul/Basic/Effect/Skul.png");

	AddImage("exBg", L"./Resources/exBg.png");
	AddImage("Background", L"./MapFile/BackGround/background.png");
	AddImage("Castle", L"./MapFile/BackGround/castle.png");
	AddImage("Castle2", L"./MapFile/BackGround/castle2.png");
	AddImage("Moon2", L"./MapFile/BackGround/Moon2.png");
	AddImage("Cloud", L"./MapFile/BackGround/cloud.png");
	AddImage("Cloud2", L"./MapFile/BackGround/cloud2.png");
	//약탈자 모션 이미지

	//디스트로이어 모션 이미지

	//갬블러스컬 모션 이미지
	AddImageVector("Gambler_Idle", L"./Resources/Png/Skul/Gambler/Motion/Idle/", 1, 7);
	AddImageVector("Gambler_Walk", L"./Resources/Png/Skul/Gambler/Motion/Walk/", 1, 6);
	AddImageVector("Gambler_Dash", L"./Resources/Png/Skul/Gambler/Motion/Dash/", 1, 5);
	AddImageVector("Gambler_AttackA1", L"./Resources/Png/Skul/Gambler/Motion/AttackA1/", 1, 5);
	AddImageVector("Gambler_AttackA2", L"./Resources/Png/Skul/Gambler/Motion/AttackA2/", 1, 6);
	AddImageVector("Gambler_Attack1", L"./Resources/Png/Skul/Gambler/Motion/AttackB1/", 1, 6);
	AddImageVector("Gambler_Attack2", L"./Resources/Png/Skul/Gambler/Motion/AttackB2/", 1, 6);
	AddImageVector("Gambler_Attack3", L"./Resources/Png/Skul/Gambler/Motion/AttackB3/", 1, 8);
	AddImageVector("Gambler_JumpStart", L"./Resources/Png/Skul/Gambler/Motion/JumpStart/", 1, 3);
	AddImageVector("Gambler_JumpRepeat", L"./Resources/Png/Skul/Gambler/Motion/JumpRepeat/", 1, 2);
	AddImageVector("Gambler_JumpFall", L"./Resources/Png/Skul/Gambler/Motion/JumpFall/", 1, 3);
	AddImageVector("Gambler_JumpAttack", L"./Resources/Png/Skul/Gambler/Motion/JumpAttack/", 1, 5);
	AddImageVector("Gambler_RussianRoulette", L"./Resources/Png/Skul/Gambler/Motion/RussianRoulette/", 1, 8);
	AddImageVector("Gambler_TagAction", L"./Resources/Png/Skul/Gambler/Motion/AttackA1/", 1, 11);
	//갬블러이펙트
	AddImageVector("Gambler_Attack1Effect", L"./Resources/Png/Skul/Gambler/Effect/AutoAttack_1/", 1, 21);
	AddImageVector("Gambler_Attack2Effect", L"./Resources/Png/Skul/Gambler/Effect/AutoAttack_2/", 1, 22);
	AddImageVector("Gambler_JumpAttackEffect", L"./Resources/Png/Skul/Gambler/Effect/JumpAttack/", 1, 24);
	AddImageVector("Gambler_JockerExplosion", L"./Resources/Png/Skul/Gambler/Effect/BasicAttack_Joker_Explosion/", 1, 17);
	AddImageVector("Gambler_BlackJackSpark", L"./Resources/Png/Skul/Gambler/Effect/BlackJackSpark/", 1, 11);
	AddImageVector("Gambler_BlackJackJokerExplosion", L"./Resources/Png/Skul/Gambler/Effect/BlackJack_BigHit_Explosion/", 1, 15);
	AddImageVector("Gambler_Roullet", L"./Resources/Png/Skul/Gambler/Effect/Roulette/", 1, 18);
	AddImage("GamblerCardNormal", L"./Resources/Png/Skul/Gambler/Effect/Gambler_Card_Normal.png");
	AddImage("GamblerCardJoker", L"./Resources/Png/Skul/Gambler/Effect/Gambler_Card_Joker.png");
	AddImage("GamblerRoulletBlack", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Stop_Black.png");
	AddImage("GamblerRoulletRed", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Stop_Red.png");

	// 타일 이미지
	AddTileImage(L"./Resources/Tile/4Stage/01.png"); // 0
	AddTileImage(L"./Resources/Tile/4Stage/02.png");
	AddTileImage(L"./Resources/Tile/4Stage/03.png");
	AddTileImage(L"./Resources/Tile/4Stage/04.png");
	AddTileImage(L"./Resources/Tile/4Stage/05.png");
	AddTileImage(L"./Resources/Tile/4Stage/06.png");
	AddTileImage(L"./Resources/Tile/4Stage/07.png");
	AddTileImage(L"./Resources/Tile/4Stage/08.png");
	AddTileImage(L"./Resources/Tile/4Stage/09.png");
	AddTileImage(L"./Resources/Tile/4Stage/10.png");
	AddTileImage(L"./Resources/Tile/4Stage/11.png");// 10
	AddTileImage(L"./Resources/Tile/4Stage/12.png");
	AddTileImage(L"./Resources/Tile/4Stage/13.png");
	AddTileImage(L"./Resources/Tile/4Stage/14.png");
	AddTileImage(L"./Resources/Tile/4Stage/15.png");
	AddTileImage(L"./Resources/Tile/4Stage/16.png");
	AddTileImage(L"./Resources/Tile/4Stage/17.png");
	AddTileImage(L"./Resources/Tile/4Stage/18.png");
	AddTileImage(L"./Resources/Tile/4Stage/19.png");
	AddTileImage(L"./Resources/Tile/4Stage/20.png");
	AddTileImage(L"./Resources/Tile/4Stage/21.png");// 20
	AddTileImage(L"./Resources/Tile/4Stage/22.png");
	AddTileImage(L"./Resources/Tile/4Stage/23.png");
	AddTileImage(L"./Resources/Tile/4Stage/24.png");
	AddTileImage(L"./Resources/Tile/4Stage/25.png");
	AddTileImage(L"./Resources/Tile/4Stage/26.png");
	AddTileImage(L"./Resources/Tile/4Stage/27.png");
	AddTileImage(L"./Resources/Tile/4Stage/28.png");
	AddTileImage(L"./Resources/Tile/4Stage/29.png");
	AddTileImage(L"./Resources/Tile/4Stage/30.png");
	AddTileImage(L"./Resources/Tile/4Stage/31.png");// 30
	AddTileImage(L"./Resources/Tile/4Stage/32.png");
	AddTileImage(L"./Resources/Tile/4Stage/33.png");
	AddTileImage(L"./Resources/Tile/4Stage/34.png");
	AddTileImage(L"./Resources/Tile/4Stage/35.png");
	AddTileImage(L"./Resources/Tile/4Stage/36.png");
	AddTileImage(L"./Resources/Tile/4Stage/37.png");
	AddTileImage(L"./Resources/Tile/4Stage/38.png");
	AddTileImage(L"./Resources/Tile/4Stage/39.png");
	AddTileImage(L"./Resources/Tile/4Stage/40.png");
	AddTileImage(L"./Resources/Tile/4Stage/41.png");// 40
	AddTileImage(L"./Resources/Tile/4Stage/42.png");
	AddTileImage(L"./Resources/Tile/4Stage/43.png");
	AddTileImage(L"./Resources/Tile/4Stage/44.png");
	AddTileImage(L"./Resources/Tile/4Stage/45.png");
	AddTileImage(L"./Resources/Tile/4Stage/46.png");
	AddTileImage(L"./Resources/Tile/4Stage/47.png");
	AddTileImage(L"./Resources/Tile/4Stage/48.png");
	AddTileImage(L"./Resources/Tile/4Stage/49.png");
	AddTileImage(L"./Resources/Tile/4Stage/50.png");
	AddTileImage(L"./Resources/Tile/4Stage/51.png");// 50
	AddTileImage(L"./Resources/Tile/4Stage/52.png");
	AddTileImage(L"./Resources/Tile/4Stage/53.png");
	AddTileImage(L"./Resources/Tile/4Stage/54.png");
	AddTileImage(L"./Resources/Tile/4Stage/55.png");
	AddTileImage(L"./Resources/Tile/4Stage/56.png");
	AddTileImage(L"./Resources/Tile/4Stage/57.png");
	AddTileImage(L"./Resources/Tile/4Stage/58.png");
	AddTileImage(L"./Resources/Tile/4Stage/59.png");
	AddTileImage(L"./Resources/Tile/4Stage/60.png");
	AddTileImage(L"./Resources/Tile/4Stage/61.png");// 60
	AddTileImage(L"./Resources/Tile/4Stage/62.png");
	AddTileImage(L"./Resources/Tile/4Stage/63.png");
	AddTileImage(L"./Resources/Tile/4Stage/64.png");
	AddTileImage(L"./Resources/Tile/4Stage/65.png");
	AddTileImage(L"./Resources/Tile/4Stage/66.png");
	AddTileImage(L"./Resources/Tile/4Stage/67.png");
	AddTileImage(L"./Resources/Tile/4Stage/68.png");
	AddTileImage(L"./Resources/Tile/4Stage/69.png");
	AddTileImage(L"./Resources/Tile/4Stage/70.png");
	AddTileImage(L"./Resources/Tile/4Stage/71.png");// 70
	AddTileImage(L"./Resources/Tile/4Stage/72.png");
	AddTileImage(L"./Resources/Tile/4Stage/73.png");
	AddTileImage(L"./Resources/Tile/4Stage/74.png");
	AddTileImage(L"./Resources/Tile/4Stage/75.png");
	AddTileImage(L"./Resources/Tile/4Stage/76.png");
	AddTileImage(L"./Resources/Tile/4Stage/77.png");
	AddTileImage(L"./Resources/Tile/4Stage/78.png");
	AddTileImage(L"./Resources/Tile/4Stage/79.png");
	AddTileImage(L"./Resources/Tile/4Stage/80.png");
	AddTileImage(L"./Resources/Tile/4Stage/81.png"); // 80
	AddTileImage(L"./Resources/Tile/4Stage/82.png");
	AddTileImage(L"./Resources/Tile/4Stage/83.png");
	AddTileImage(L"./Resources/Tile/4Stage/84.png");
	AddTileImage(L"./Resources/Tile/4Stage/85.png");
	AddTileImage(L"./Resources/Tile/4Stage/86.png");
	AddTileImage(L"./Resources/Tile/4Stage/87.png");
	AddTileImage(L"./Resources/Tile/4Stage/88.png");
	AddTileImage(L"./Resources/Tile/4Stage/89.png");
	AddTileImage(L"./Resources/Tile/4Stage/90.png");// 90
	AddTileImage(L"./Resources/Tile/4Stage/91.png");
	AddTileImage(L"./Resources/Tile/4Stage/92.png");
	AddTileImage(L"./Resources/Tile/4Stage/93.png");
	AddTileImage(L"./Resources/Tile/4Stage/94.png");
	AddTileImage(L"./Resources/Tile/4Stage/95.png");
	AddTileImage(L"./Resources/Tile/4Stage/96.png");
	AddTileImage(L"./Resources/Tile/4Stage/97.png");
	AddTileImage(L"./Resources/Tile/4Stage/98.png");
	AddTileImage(L"./Resources/Tile/4Stage/99.png");
	AddTileImage(L"./Resources/Tile/4Stage/100.png");
	AddTileImage(L"./Resources/Tile/4Stage/101.png");// 100
	AddTileImage(L"./Resources/Tile/4Stage/102.png");
	AddTileImage(L"./Resources/Tile/4Stage/103.png");
	AddTileImage(L"./Resources/Tile/4Stage/104.png");
	AddTileImage(L"./Resources/Tile/Lobby/49.png"); // 104
	AddTileImage(L"./Resources/Tile/Lobby/50.png");
	AddTileImage(L"./Resources/Tile/Lobby/51.png");
	AddTileImage(L"./Resources/Tile/Lobby/52.png");
	AddTileImage(L"./Resources/Tile/Lobby/53.png");
	AddTileImage(L"./Resources/Tile/Lobby/54.png");
	AddTileImage(L"./Resources/Tile/Lobby/55.png");// 10
	AddTileImage(L"./Resources/Tile/Lobby/56.png");
	AddTileImage(L"./Resources/Tile/Lobby/57.png");
	AddTileImage(L"./Resources/Tile/Lobby/58.png");
	AddTileImage(L"./Resources/Tile/Lobby/59.png");
	AddTileImage(L"./Resources/Tile/Lobby/60.png");
	AddTileImage(L"./Resources/Tile/Lobby/61.png");
	AddTileImage(L"./Resources/Tile/Lobby/62.png");
	AddTileImage(L"./Resources/Tile/Lobby/63.png");
	AddTileImage(L"./Resources/Tile/Lobby/64.png");
	AddTileImage(L"./Resources/Tile/Lobby/65.png");
	AddTileImage(L"./Resources/Tile/Lobby/66.png");
	AddTileImage(L"./Resources/Tile/Lobby/67.png");
	AddTileImage(L"./Resources/Tile/Lobby/68.png");
	AddTileImage(L"./Resources/Tile/Lobby/69.png");
	AddTileImage(L"./Resources/Tile/Lobby/70.png");
	AddTileImage(L"./Resources/Tile/Lobby/71.png");
	AddTileImage(L"./Resources/Tile/Lobby/72.png");
	AddTileImage(L"./Resources/Tile/Lobby/73.png");
	AddTileImage(L"./Resources/Tile/Lobby/74.png");
	AddTileImage(L"./Resources/Tile/Lobby/75.png");
	AddTileImage(L"./Resources/Tile/Lobby/76.png");
	AddTileImage(L"./Resources/Tile/Lobby/77.png");
	AddTileImage(L"./Resources/Tile/Lobby/78.png");
	AddTileImage(L"./Resources/Tile/Lobby/79.png");

	// 배경 이미지
	AddImage("Moon", L"./Resources/BackGround/Boss_Stage_Moon.png");
	AddImage("Building", L"./Resources/BackGround/Boss_Stage_Building.png");
	AddImage("Lion", L"./Resources/BackGround/Boss_Stage_Lion.png");
	AddImage("Fence", L"./Resources/BackGround/Boss_Stage_Fence.png");

	AddImage("CollisionPlatform", L"./Resources/Tile/4Stage/CollisionPlatform.png");
	AddImage("CollisionBox", L"./Resources/Tile/4Stage/CollisionBox.png");
	AddImage("Light", L"./Resources/Light.png");
	AddImage("Rather", L"./Resources/Saint_Joanna/Phase_1/Normal_Monster/Rather/05.png");

	AddPixelmage("CollisionBox", "./Resources/Tile/4Stage/CollisionBox.bmp", 32, 32);
	AddPixelmage("CollisionPlatform", "./Resources/Tile/4Stage/CollisionPlatform.bmp", 32, 32);

	// 보스 ====================================================================================
	// 1페이즈_대화
	AddImageVector("Boss_Intro_Talk", L"./Resources/Saint_Joanna/Phase1_Intro_2/Idle_Talk_Loop_", 1, 7);

	AddImage("Boss_Chair", L"./Resources/Saint_Joanna/Phase_1/Chair/Boss_Chair.png");
	// 1페이즈_대기
	AddImageVector("Boss_Idle", L"./Resources/Saint_Joanna/Phase1_Intro_1/Idle_", 1, 7);
	// 1페이즈_지팡이 들기
	AddImageVector("Boss_Casting_Ready", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/Ready/Casting_Ready_", 1, 7);
	AddImageVector("Boss_Casting_Attack", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/Attack/Casting_Attack_Loop_", 1, 7);
	AddImageVector("Boss_Casting_End", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/End/Casting_End_", 1, 7);
	// 1페이즈_초이스
	AddImageVector("Boss_Choice_Ready", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/Ready/Ready/Choice_Ready_", 1, 7);
	AddImageVector("Boss_Choice_Ready_Loop", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/Ready/Loop/Choice_Ready_Loop_", 1, 7);
	AddImageVector("Boss_Choice_Attack", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/Attack/Choice_Attack_Loop_", 1, 7);
	AddImageVector("Boss_Choice_End", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/End/Choice_End_", 1, 7);
	AddImageVector("Boss_Choice_Spark", L"./Resources/Saint_Joanna/Phase_1/Choice/Effect/Phase1_Choice_Spark_", 1, 12);
	// 1페이즈_땅찍기
	AddImageVector("Boss_Nervousness_Ready", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Boss/Ready/Ready/Nervousness_Ready_", 1, 14);
	AddImageVector("Boss_Nervousness_Ready_Loop", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Boss/Ready/Loop/Nervousness_Ready_Loop_", 1, 7);
	AddImageVector("Boss_Nervousness_Attack", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Boss/Attack/Attack/Nervousness_Attack_", 1, 7);
	AddImageVector("Boss_Nervousness_Attack_Loop", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Boss/Attack/Loop/Nervousness_Attack_Loop_", 1, 7);
	AddImageVector("Boss_Nervousness_End", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Boss/End/Nervousness_End_", 1, 7);
	// 1페이즈_땅찍기 이펙트
	AddImageVector("Boss_Nervousness_Effect_Attack", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Effect/Attack/Phase1_Nervousness_Attack_", 1, 33);
	AddImageVector("Boss_Nervousness_Effect_Projectile", L"./Resources/Saint_Joanna/Phase_1/Nervousness/Effect/Projectile/Phase1_Nervousness_Projectile_", 1, 12);
	// 1페이즈_분수 구슬
	AddImageVector("Boss_HolyFountain_Start_Left", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/Start/Phase1_HolyBarrier_Orb_Start_", 1, 22);
	AddImageVector("Boss_HolyFountain_Start_Right", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/Start/Phase1_HolyBarrier_Orb_Start_", 1, 22);
	AddImageVector("Boss_HolyFountain_Orb", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/Orb/Phase1_HolyBarrier_Orb_", 1, 47);
	AddImageVector("Boss_HolyFountain_End", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/End/Phase1_HolyBarrier_Orb_End_", 1, 24);
	// 1페이즈_분수
	AddImage("Fountain_Deactivate", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/Fountain/Deactive/Deactivate_01.png");
	AddImageVector("Boss_HolyFountain_Activate", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/Fountain/Active/Activate_", 1, 8);
	// 1페이즈_방어막
	AddImageVector("Boss_Barrier_Intro_Front", L"./Resources/Saint_Joanna/Phase_1/Barrier/Intro_Front/Phase1_Barrier_Intro_Front_", 1, 30);
	AddImageVector("Boss_Barrier_Intro_Behind", L"./Resources/Saint_Joanna/Phase_1/Barrier/Intro_Behind/Phase1_Barrier_Intro_Behind_", 1, 30);
	AddImageVector("Boss_Barrier_Loop_Front", L"./Resources/Saint_Joanna/Phase_1/Barrier/Loop_Front/Phase1_Barrier_Loop_Front_", 1, 24);
	AddImageVector("Boss_Barrier_Loop_Behind", L"./Resources/Saint_Joanna/Phase_1/Barrier/Loop_Behind/Phase1_Barrier_Loop_Behind_", 1, 24);
	AddImageVector("Boss_Barrier_Impact", L"./Resources/Saint_Joanna/Phase_1/Barrier/Impact/Phase1_Barrier_Impact_", 1, 12);
	AddImageVector("Boss_Barrier_Spark", L"./Resources/Saint_Joanna/Phase_1/Barrier/Spark/Phase1_Barrier_Impact_Spark_", 1, 26);
	AddImage("Boss_Barrier_Crack", L"./Resources/Saint_Joanna/Phase_1/Barrier/Crack/Crack/Phase1_Barrier_Crack_01.png");
	AddImageVector("Boss_Barrier_Crack_Impact", L"./Resources/Saint_Joanna/Phase_1/Barrier/Crack/Crack_Impact/Phase1_Barrier_Crack_Impact_", 1, 12);
	// 1페이즈_떨어지는 구슬
	AddImageVector("Boss_Baptism_Attack", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Baptism/Attack/Phase1_Baptism_Attack_", 1, 36);
	AddImageVector("Boss_Baptism_Projectile", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Baptism/Projectile/Phase1_Batism_Projectile_", 1, 21);
	AddImageVector("Boss_Baptism_Projectile_Dewspawn", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Baptism/Projectile_Despawn/Phase1_Baptism_Projectile_Despawn_", 1, 24);
	// 1페이즈_레이저
	AddImageVector("Boss_Consecration_Start", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/Start/Phase1_Consecration_Start_", 1, 27);
	AddImageVector("Boss_Consecration_Sign", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/Sign/Phase1_Consecration_Sign_", 1, 23);
	AddImageVector("Boss_Consecration_Loop", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/Loop/Phase1_Consecration_Loop_", 1, 33);
	AddImageVector("Boss_Consecration_End", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/End/Phase1_Consecration_End_", 1, 21);
	// 1페이즈_좌우 구슬
	AddImageVector("Boss_Worship", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Worship/Phase1_Worship_Projectile_", 1, 60);

	// 2페이즈_대기
	AddImageVector("Phase2_Ball_CreateBall_Start", L"./Resources/Saint_Joanna/Phase_2/CreateBall/HolyBarrierOrb/Start/", 1, 21);
	AddImageVector("Phase2_Ball_CreateBall_Idle", L"./Resources/Saint_Joanna/Phase_2/CreateBall/HolyBarrierOrb/Orb/Phase1_HolyBarrier_Orb_", 1, 48);



	// 2페이즈_인트로
	AddImageVector("Phase2_Boss_Idle", L"./Resources/Saint_Joanna/Phase_2/Idle/Phase2_Idle_", 1, 6);
	AddImageVector("Phase2_Boss_Intro_1", L"./Resources/Saint_Joanna/Phase2_Intro_3/", 29, 35);
	AddImageVector("Phase2_Boss_Intro_2", L"./Resources/Saint_Joanna/Phase2_Intro_4/", 1, 28);

	AddImageVector("Phase2_Boss_CreateBall_Attack", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/Attack/Sacrament_Attack_Loop_", 1, 7);
	AddImageVector("Phase2_Boss_CreateBall_End", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/End/Sacrament_End_", 1, 7);
	AddImageVector("Phase2_Boss_CreateBall_Ready", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/Ready/Sacrament_Ready_", 1, 6);

	// 2페이즈_구체 생성
	AddImageVector("Phase2_Boss_CreateBall_Ready", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/Ready/Sacrament_Ready_", 1, 6);
	AddImageVector("Phase2_Boss_CreateBall_Attack", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/Attack/Sacrament_Attack_Loop_", 1, 7);
	AddImageVector("Phase2_Boss_CreateBall_End", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/End/Sacrament_End_", 1, 7);
	// 2페이즈_상단 텔포, 직선 레이저

	AddImage("FireKnife", L"./Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/FireKnife.png");


	//==========================================================================================================
	// 맵 구조물 이미지
	AddStructureImage("statue", L"./Resources/Tile/4Stage/Structure/statue.png");
	AddStructureImage("arch1", L"./Resources/Tile/4Stage/Structure/arch1.png");
	AddStructureImage("arch2", L"./Resources/Tile/4Stage/Structure/arch2.png");
	AddStructureImage("arch3", L"./Resources/Tile/4Stage/Structure/arch3.png");
	AddStructureImage("arch4", L"./Resources/Tile/4Stage/Structure/arch4.png");
	AddStructureImage("arch5", L"./Resources/Tile/4Stage/Structure/arch5.png");
	AddStructureImage("arch6", L"./Resources/Tile/4Stage/Structure/arch6.png");
	AddStructureImage("arch7", L"./Resources/Tile/4Stage/Structure/arch7.png");
	AddStructureImage("arch8", L"./Resources/Tile/4Stage/Structure/arch8.png");
	AddStructureImage("Elevator", L"./Resources/Tile/4Stage/Structure/elevator.png");
	AddStructureImage("DoorBack", L"Resources/Door/DoorBack.png");
	AddStructureImage("Reword", L"Resources/Door/Reword.png");
	AddStructureImage("_01", L"./Resources/Tile/4Stage/Structure/_01.png");
	AddStructureImage("01", L"./Resources/Tile/4Stage/Structure/01.png");
	AddStructureImage("banch", L"./Resources/Tile/4Stage/Structure/banch.png");
	AddStructureImage("shop", L"./Resources/Tile/4Stage/Structure/shop.png");
	AddStructureImage("factory", L"./Resources/Tile/4Stage/Structure/factory.png");
	AddStructureImage("bossPlatFormL", L"./Resources/Tile/4Stage/Structure/bossPlatFormL.png");
	AddStructureImage("bossPlatFormS", L"./Resources/Tile/4Stage/Structure/bossPlatFormS.png");
	AddStructureImage("Terrain", L"./Resources/Tile/4Stage/Structure/Terrain.png");
	AddStructureImage("Table1", L"./Resources/Tile/4Stage/Structure/table1.png");
	AddStructureImage("Table2", L"./Resources/Tile/4Stage/Structure/table2.png");
	AddStructureImage("Table3", L"./Resources/Tile/4Stage/Structure/table3.png");
	AddStructureImage("Lamp1", L"./Resources/Tile/4Stage/Structure/lamp1.png");
	AddStructureImage("Lamp2", L"./Resources/Tile/4Stage/Structure/lamp2.png");
	AddStructureImage("Lamp3", L"./Resources/Tile/4Stage/Structure/HangingLamp1.png");
	AddStructureImage("Lamp4", L"./Resources/Tile/4Stage/Structure/HangingLamp2.png");
	AddStructureImage("Box1", L"./Resources/Tile/4Stage/Structure/box1.png");
	AddStructureImage("Brokenbox1", L"./Resources/Tile/4Stage/Structure/Brokenbox1.png");
	AddStructureImage("Chair1", L"./Resources/Tile/4Stage/Structure/chair1.png");
	AddStructureImage("Fence1", L"./Resources/Tile/4Stage/Structure/Fence1.png");
	AddStructureImage("Throne", L"./Resources/Tile/4Stage/Structure/Throne.png");
	AddStructureImage("Flag", L"./Resources/Tile/4Stage/Structure/Flag.png");
	AddStructureImage("Flag2", L"./Resources/Tile/4Stage/Structure/Flag2.png");
	AddStructureImage("ThroneWall", L"./Resources/Tile/4Stage/Structure/ThroneCurtain1.png");
	AddStructureImage("Thronecurtain", L"./Resources/Tile/4Stage/Structure/ThroneCurtain2.png");
	AddStructureImage("Thronetain2", L"./Resources/Tile/4Stage/Structure/ThroneWall.png");
	AddStructureImage("Demoncurtain", L"./Resources/Tile/4Stage/Structure/demoncurtain.png");
	AddStructureImage("Demoncurtain2", L"./Resources/Tile/4Stage/Structure/demoncurtain2.png");
	AddStructureImage("Demoncurtain3", L"./Resources/Tile/4Stage/Structure/demoncurtain3.png");
	AddStructureImage("Demonwall", L"./Resources/Tile/4Stage/Structure/demonwall.png");
	AddStructureImage("Demonwall2", L"./Resources/Tile/4Stage/Structure/demonwall2.png");
	AddStructureImage("Demonwall3", L"./Resources/Tile/4Stage/Structure/demonwall3.png");
	AddStructureImage("Demonwall4", L"./Resources/Tile/4Stage/Structure/demonwall4.png");
	AddStructureImage("robbymap", L"./Resources/Tile/4Stage/Structure/robbymap.png");
	AddStructureImage("Picture", L"./Resources/Tile/4Stage/Structure/picture.png");
	AddStructureImage("Picture2", L"./Resources/Tile/4Stage/Structure/picture2.png");
	AddStructureImage("Chandelier", L"./Resources/Tile/4Stage/Structure/Chandelier.png");

	// 저장은 백스페이스 숫자키와 번호키로 오브젝트교체 ,f7 <- 신규씬 , 좌클릭은 뒤에 그려지고 우클릭은 앞에
	// 타일 지우는거 컨트롤 <- 맨마지막에 그린것만 지워짐, 맵크기는 영상 참조

	// 몬스터 체력바 이미지
	AddImageVector("Hpbar_Empty", L"./Resources/Monster/Hpbar/Empty/", 1, 1);
	AddImageVector("Hpbar_Down", L"./Resources/Monster/Hpbar/Down/", 1, 1);
	AddImageVector("Hpbar_Up", L"./Resources/Monster/Hpbar/Up/", 1, 1);

	// 몬스터 이미지
	AddImageVector("Leon_Idle", L"Resources/Monster/Leonia Soldier/Idle/", 1, 5);
	AddImageVector("Leon_Attack", L"Resources/Monster/Leonia Soldier/Attack/", 1, 4);
	AddImageVector("Leon_Run", L"Resources/Monster/Leonia Soldier/Run/", 1, 8);
	AddImageVector("Leon_Hit", L"Resources/Monster/Leonia Soldier/Hit/", 1, 1);

	AddImageVector("Fanatic_Idle", L"Resources/Monster/Fanatic/Idle/", 1, 6);
	AddImageVector("Fanatic_AttackIdle", L"Resources/Monster/Fanatic/Attack Idle/", 1, 5);
	AddImageVector("Fanatic_Attack", L"Resources/Monster/Fanatic/Attack/", 1, 13);
	AddImageVector("Fanatic_Runattack", L"Resources/Monster/Fanatic/Walk Attack/", 1, 8);
	AddImageVector("Fanatic_Run", L"Resources/Monster/Fanatic/Walk Idle/", 1, 6);
	AddImageVector("Fanatic_Setcrifice", L"Resources/Monster/Fanatic/Setcrifice/", 1, 9);
	AddImageVector("Fanatic_Setcrificeloop", L"Resources/Monster/Fanatic/Setcrifice Loop/", 1, 1);
	AddImageVector("Fanatic_Setcrificeready", L"Resources/Monster/Fanatic/Setcrifice Ready/", 1, 6);
	AddImageVector("Fanatic_Hit", L"Resources/Monster/Fanatic/Hit/", 1, 1);

	AddImageVector("Bfanatic_Idle", L"Resources/Monster/Black Fanatic/Idle/", 1, 6);
	AddImageVector("Bfanatic_AttackIdle", L"Resources/Monster/Black Fanatic/Attack Idle/", 1, 5);
	AddImageVector("BFanatic_Runattack", L"Resources/Monster/Black Fanatic/Walk Attack/", 1, 8);
	AddImageVector("BFanatic_Run", L"Resources/Monster/Black Fanatic/Walk/", 1, 6);

	AddImageVector("Cfanatic_Idle", L"Resources/Monster/Candle_Fanatic/Idle/", 1, 6);
	AddImageVector("Cfanatic_AttackReady", L"Resources/Monster/Candle_Fanatic/Attack_Ready/", 1, 17);
	AddImageVector("Cfanatic_Attack", L"Resources/Monster/Candle_Fanatic/Attack/", 1, 10);
	AddImageVector("Cfanatic_Run", L"Resources/Monster/Candle_Fanatic/Run/", 1, 8);
	AddImageVector("Cfanatic_Hit", L"Resources/Monster/Candle_Fanatic/Hit/", 1, 1);
	AddImageVector("Cfanatic_Satcrifice", L"Resources/Monster/Candle_Fanatic/Setcrifice/", 1, 15);
	AddImageVector("Cfanatic_SatcrificeReady", L"Resources/Monster/Candle_Fanatic/Setcrifice_Ready/", 1, 6);
	AddImageVector("Cfanatic_SatcrificeLoop", L"Resources/Monster/Candle_Fanatic/Setcrifice_Loop/", 1, 5);

	AddImageVector("Tentacles_Idle", L"Resources/Monster/Tentacles_Of_Light/Idle/", 1, 10);
	AddImageVector("Tentacles_Attack", L"Resources/Monster/Tentacles_Of_Light/Attack/", 1, 8);
	AddImageVector("Tntackles_Recovery", L"Resources/Monster/Tentacles_Of_Light/Recovery/", 1, 12);
	AddImageVector("Tentacles_Emerge", L"Resources/Monster/Tentacles_Of_Light/Emerge/", 1, 5);

	AddImageVector("Lfanatic_Idle", L"Resources/Monster/Lamp_Fanatic/Idle/", 1, 8);
	AddImageVector("Lfanatic_Mass", L"Resources/Monster/Lamp_Fanatic/Mass/", 1, 3);
	AddImageVector("Lfanatic_MassLoop", L"Resources/Monster/Lamp_Fanatic/Mass_Loop/", 1, 3);
	AddImageVector("Lfanatic_MassReady", L"Resources/Monster/Lamp_Fanatic/Mass_Ready/", 1, 3);
	AddImageVector("Lfanatic_MassReadyLoop", L"Resources/Monster/Lamp_Fanatic/Mass_Ready_Loop/", 1, 3);
	AddImageVector("Lfanatic_Run", L"Resources/Monster/Lamp_Fanatic/Run/", 1, 8);
	AddImageVector("Lfanatic_SummonReady", L"Resources/Monster/Lamp_Fanatic/Summon_Ready/", 1, 5);
	AddImageVector("Lfanatic_Summons", L"Resources/Monster/Lamp_Fanatic/Summons/", 1, 8);

	AddImageVector("Befanatic_Idle", L"Resources/Monster/Bell_Fanatic/Idle/", 1, 7);
	AddImageVector("Befanatic_Sacrifice", L"Resources/Monster/Bell_Fanatic/Sacrifice/", 1, 6);
	AddImageVector("Befanatic_SacrificeLoop", L"Resources/Monster/Bell_Fanatic/Sacrifice_Loop/", 1, 1);
	AddImageVector("Befanatic_SummonLoop", L"Resources/Monster/Bell_Fanatic/Summon_Loop/", 1, 12);
	AddImageVector("Befanatic_SummonReady", L"Resources/Monster/Bell_Fanatic/Summon_Ready/", 1, 4);

	AddImageVector("AStatue_Attack", L"Resources/Monster/Angel_Statue/Attack/", 1, 40);
	AddImageVector("AStatue_End", L"Resources/Monster/Angel_Statue/End/", 1, 10);
	AddImageVector("AStatue_Idle", L"Resources/Monster/Angel_Statue/Idle/", 1, 1);
	AddImageVector("AStatue_AttackRedadyEffect", L"Resources/Monster/Angel_Statue/AttackEffectReady/", 1, 18);
	AddImageVector("AStatue_AttackEffect", L"Resources/Monster/Angel_Statue/AttackEffect/", 1, 22);
	AddImageVector("GoldResoult", L"Resources/GoldResult/Idle/", 1, 19);
	AddImageVector("GoldResoultActive", L"Resources/GoldResult/Idle/", 1, 1);


	// 몬스터 이펙트
	AddImageVector("Secrifice", L"Resources/Monster/Effect/Secrifice/", 1, 11);
	AddImageVector("SkulAttack", L"Resources/Monster/Effect/SkulAttack/", 1, 10);
	AddImageVector("DeadEffect", L"Resources/Monster/Effect/Dead/", 1, 6);
	AddImageVector("AppearEffect", L"Resources/Monster/Effect/Appear/", 1, 11);

	// 상점 오브젝트 
	AddImageVector("Atifact", L"Resources/Shop/Atifact/", 1, 24);
	AddImageVector("Blacksmith", L"Resources/Shop/Blacksmith/", 1, 8);
	AddImageVector("FoodShop", L"Resources/Shop/FoodShop/", 1, 8);
	AddImageVector("Head", L"Resources/Shop/Head/", 1, 7);
	AddImageVector("ItemView", L"Resources/Shop/ItemView/", 1, 5);
	//아이템
	AddImageVector("Gold", L"Resources/Item/Gold/GoldUnit/", 1, 9);
	AddImageVector("GetGold", L"Resources/Item/Gold/GetGold/", 1, 29);
	AddImageVector("HeadResult", L"./Resources/HeadResult/Idle/", 1, 1);
	AddImageVector("HeadResultActive", L"./Resources/HeadResult/Active/", 1, 7);
	AddImageVector("Hporb", L"Resources/Item/Hporb/", 1, 72);
	AddImageVector("BlackRock", L"Resources/Item/BlackRock/Rock/", 1, 1);
	AddImageVector("GetBlackRock", L"Resources/Item/BlackRock/GetRock/", 1, 28);


	// 보스 1페이지 잡몹

	AddImageVector("Normal_Monster2_Attack", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster2/Attack/", 15, 26);
	AddImageVector("Normal_Monster2_Idle", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster2/Idle/", 2, 6);
	AddImageVector("Normal_Monster2_Move", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster2/Move/", 8, 14);
	AddImageVector("Normal_Monster2_Up", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster2/Up/", 27, 83);

	AddImageVector("Normal_Monster1_Up", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/Up/", 9, 58);
	AddImageVector("Normal_Monster1_Idle", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/Idle/", 87, 91);
	AddImageVector("Normal_Monster1_Move", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/Move/", 92, 99);
	AddImageVector("Normal_Monster1_FireReady", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/FireReady/", 69, 85);
	AddImageVector("Normal_Monster1_Fire", L"Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/Fire/", 59, 68);

	//맵 오브젝트
	AddImage("NormalRoom", L"Resources/Door/NormalRoom/Deactivate_0.png");
	AddImage("SkulRoom", L"Resources/Door/SkulRoom/Deactivate_0.png");

	AddImage("BossRoom", L"Resources/Door/BossRoom/08.png");
	AddImage("SpirderRoom", L"Resources/Door/SpirderRoom/Deactivate_0 #80165.png");
	AddImage("ShopRoom", L"Resources/Door/ShopRoom/Deactivate_0 #80139.png");

	AddImage("ShopBackGround", L"Resources/Shop/backGround.png");
	AddImage("ShopCloud", L"Resources/Shop/Cloud.png");
	AddImage("ShopStruecture", L"Resources/Shop/Struecture.png");


	//맵 오브젝트 애니메이션
	AddImageVector("NormalRoom", L"Resources/Door/NormalRoom/", 1, 8);
	AddImageVector("SkulRoom", L"Resources/Door/SkulRoom/", 1, 7);
	AddImageVector("BossRoom", L"Resources/Door/BossRoom/", 1, 7);
	AddImageVector("ShopRoom", L"Resources/Door/ShopRoom/", 1, 8);
	AddImageVector("SpirderRoom", L"Resources/Door/SpirderRoom/", 1, 8);

	AddImageVector("Fountain", L"Resources/Tile/4Stage/Structure/fountain/", 1, 6);

	//맵툴 오브젝트 이미지 저장
	AddObjectImage("Leon", L"Resources/Monster/Leonia Soldier/Idle/01.png");
	AddObjectImage("Fanatic", L"Resources/Monster/Fanatic/Idle/01.png");
	AddObjectImage("Bfanatic", L"Resources/Monster/Black Fanatic/Idle/01.png");
	AddObjectImage("Cfanatic", L"Resources/Monster/Candle_Fanatic/Idle/01.png");
	AddObjectImage("Tentacles", L"Resources/Monster/Tentacles_Of_Light/Idle/01.png");
	AddObjectImage("Lfanatic", L"Resources/Monster/Lamp_Fanatic/Idle/01.png");
	AddObjectImage("Befanatic", L"Resources/Monster/Bell_Fanatic/Idle/01.png");
	AddObjectImage("AStatue", L"Resources/Monster/Angel_Statue/Idle/01.png");
	AddObjectImage("NormalRoom", L"Resources/Door/NormalRoom/Deactivate_0.png");
	AddObjectImage("SkulRoom", L"Resources/Door/SkulRoom/Deactivate_0.png");
	AddObjectImage("BossRoom", L"Resources/Door/BossRoom/08.png");
	AddObjectImage("ShopRoom", L"Resources/Door/ShopRoom/Deactivate_0 #80139.png");
	AddObjectImage("SpirderRoom", L"Resources/Door/SpirderRoom/Deactivate_0 #80165.png");

	AddObjectImage("Basic", L"./Resources/Png/Skul/Basic/Motion/Idle/01.png");
	AddObjectImage("Atifact", L"./Resources/Shop/Atifact/Deactivate_0 #80153.png");
	AddObjectImage("FoodShop", L"./Resources/Shop/FoodShop/Deactivate_0 #80158.png");
	AddObjectImage("Blacksmith", L"./Resources/Shop/Blacksmith/Deactivate_0 #80166.png");
	AddObjectImage("ItemView", L"./Resources/Shop/ItemView/01.png");
	AddObjectImage("Head", L"./Resources/Shop/Head/01.png");
	AddObjectImage("GoldResoult", L"./Resources/GoldResult/Idle/01.png");
	AddObjectImage("HeadResult", L"./Resources/HeadResult/Idle/01.png");
	AddObjectImage("Trigger1", L"./Resources/Trigger1.png");
	AddObjectImage("Trigger2", L"./Resources/Trigger2.png");
	AddObjectImage("Trigger3", L"./Resources/Trigger3.png");
	AddObjectImage("Fountain", L"./Resources/Tile/4Stage/Structure/fountain/01.png");

	// 인게임 UI이미지
	AddImage("Inventory_Frame", L"./Resources/UI/Inventory_Frame.png");
	AddImage("PlayerStatusUI", L"./Resources/UI/PlayerStatusUI.png");
	AddImage("ItemUI", L"./Resources/UI/itemUI.png");

	AddImage("IntroTitle", L"./Resources/IntroTitle.png");
	AddImage("IntroClick", L"./Resources/IntroClick.png");
	AddImage("IntroBg", L"./Resources/IntroBg.png");
}
