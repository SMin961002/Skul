#include "stdafx.h"
#include "ImageManager.h"

void ImageManager::LoadImages()
{
	AddImage("CaerleonSword", L"./Resources/Item/CaerleonSword.png");
	AddImage("Caerleonarmor", L"./Resources/Item/Caerleonarmor.png");
	AddImage("BoneOfMana", L"./Resources/Item/BoneOfMana.png");
	AddImage("Pause_Frame", L"./Resources/UI/Pause_Frame.png");

	// 맵툴 UI 이미지
	AddImage("newFile", L"./MapFile/newFile.png");

	// 예시 이미지
	AddImage("Frame_1SKill", L"./Resources/Frame_1SKill.png");

	//캐릭터 이펙트
	AddImageVector("DashSmoke", L"./Resources/Png/Skul/Effect/DashSmoke/", 1, 13);
	AddImageVector("JumpSmoke", L"./Resources/Png/Skul/Effect/DoubleJumpSmoke/", 1, 10);
	AddImageVector("PlayerHit", L"./Resources/Png/Skul/Effect/Hit/", 1, 12);

	AddImageVector("GodRay_Loop", L"./Resources/GodRay_Loop/GodRay_Loop_", 1, 48);
	AddImageVector("GodRay_Start", L"./Resources/GodRay_Start/GodRay_Start_", 1, 47);

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
	AddImage("Background2", L"./MapFile/BackGround/background2.png");
	AddImage("Background3", L"./MapFile/BackGround/background3.png");
	AddImage("Background4", L"./MapFile/BackGround/background4.png");
	AddImage("Background5", L"./MapFile/BackGround/background5.png");
	AddImage("Background6", L"./MapFile/BackGround/background6.png");
	AddImage("Background7", L"./MapFile/BackGround/background7.png");
	AddImage("Background8", L"./MapFile/BackGround/background8.png");


	AddImage("Castle", L"./MapFile/BackGround/castle.png");
	AddImage("Castle2", L"./MapFile/BackGround/castle2.png");
	AddImage("Castle3", L"./MapFile/BackGround/castle3.png");
	AddImage("Moon2", L"./MapFile/BackGround/Moon2.png");
	AddImage("Cloud", L"./MapFile/BackGround/cloud.png");
	AddImage("Cloud2", L"./MapFile/BackGround/cloud2.png");
	AddImage("Cloud3", L"./MapFile/BackGround/cloud3.png");
	AddImage("Cloud4", L"./MapFile/BackGround/cloud4.png");
	AddImage("ChandelierBack", L"./MapFile/BackGround/ChandelierBack.png");
	AddImage("ChandelierBack2", L"./MapFile/BackGround/ChandelierBack2.png");
	AddImage("Demoncastle", L"./MapFile/BackGround/Demoncastle.png");


	//약탈자 모션 이미지

	//디스트로이어 모션 이미지

	//갬블러스컬 모션 이미지
	AddImageVector("Gambler_Idle", L"./Resources/Png/Skul/Gambler/Motion/Idle/", 1, 7);
	AddImageVector("Gambler_Walk", L"./Resources/Png/Skul/Gambler/Motion/Walk/", 1, 6);
	AddImageVector("Gambler_Dash", L"./Resources/Png/Skul/Gambler/Motion/Dash/", 1, 5);
	AddImageVector("Gambler_AttackA1", L"./Resources/Png/Skul/Gambler/Motion/AttackA1/", 1, 11);
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
	AddImageVector("Gambler_SlotMachineBigHitEffect", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/BigHitPlayerEffect/", 1, 21);
	//갬블러스킬
	AddImageVector("Gambler_BlackJackSpark", L"./Resources/Png/Skul/Gambler/Effect/BlackJackSpark/", 1, 11);
	AddImageVector("Gambler_BlackJackJokerExplosion", L"./Resources/Png/Skul/Gambler/Effect/BlackJack_BigHit_Explosion/", 1, 15);
	AddImageVector("Gambler_RouletteEmerge", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Emerge/", 1, 24);
	AddImageVector("Gambler_Roulette", L"./Resources/Png/Skul/Gambler/Effect/Roulette/", 1, 18);
	AddImageVector("Gambler_RouletteBroken", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Effect/", 1, 15);
	AddImageVector("Gambler_RouletteCircle", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Circle/", 1, 14);
	AddImageVector("Gambler_Roulette_Black", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Black/", 1, 32);
	AddImageVector("Gambler_Roulette_Red", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Red/", 1, 23);
	AddImageVector("Gambler_RouletteFail", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Failed/", 1, 51);
	AddImageVector("Gambler_RouletteCircle", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Circle/", 1, 14);
	AddImageVector("Gambler_RouletteBigShot", L"./Resources/Png/Skul/Gambler/Effect/Roulette/BigShot/", 1, 8);
	AddImageVector("Gambler_RouletteBigShotBroken", L"./Resources/Png/Skul/Gambler/Effect/Roulette/BigShotEffect/", 1, 23);
	AddImageVector("Gambler_RouletteBigShotCircle", L"./Resources/Png/Skul/Gambler/Effect/Roulette/BigShotCircle/", 1, 8);
	AddImageVector("Gambler_Roulette_BlackBig", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Black_BigHit/", 1, 91);
	AddImageVector("Gambler_Roulette_RedBig", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Red_BigHit/", 1, 49);
	AddImageVector("Gambler_SlotMachine", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/", 1, 4);
	AddImageVector("Gambler_SlotMachine_Explosion", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/Explosion/", 1, 17);
	AddImageVector("Gambler_SlotMachine_ExplosionBigHit", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/BigHitExplosion/", 1, 17);
	AddImageVector("Gambler_SlotMachine_Thunder", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/Thunder/", 1, 16);
	AddImageVector("Gambler_SlotMachine_ThunderBigHit", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/BigHitThunder/", 1, 20);
	AddImage("GamblerCardNormal", L"./Resources/Png/Skul/Gambler/Effect/Gambler_Card_Normal.png");
	AddImage("GamblerCardJoker", L"./Resources/Png/Skul/Gambler/Effect/Gambler_Card_Joker.png");
	AddImage("GamblerRouletteBlack", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Stop_Black.png");
	AddImage("GamblerRouletteRed", L"./Resources/Png/Skul/Gambler/Effect/Roulette/Stop_Red.png");
	AddImage("GamblerSlotMachineExplosion_Thunder", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/Explosion.png");
	AddImage("GamblerSlotMachineThunder_Laiser", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/Thunder.png");
	AddImage("GamblerSlotMachineExplosion_BigHit", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/ExplosionBigHit.png");
	AddImage("GamblerSlotMachineThunder_BigHit", L"./Resources/Png/Skul/Gambler/Effect/SlotMachine/ThunderBigHit.png");

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
	// 1페이즈_체력바
	AddImage("Boss_HPBar", L"./Resources/Saint_Joanna/Phase_1/HPBar/Phase1_HPBar.png");
	AddImage("Boss_HP", L"./Resources/Saint_Joanna/Phase_1/HPBar/Phase1_HP.png");
	AddImage("Boss_HPDamage", L"./Resources/Saint_Joanna/Phase_1/HPBar/Phase1_Damage.png");

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
	AddImageVector("Boss_HolyFountain_End_Left", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/End/Phase1_HolyBarrier_Orb_End_", 1, 24);
	AddImageVector("Boss_HolyFountain_End_Right", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/End/Phase1_HolyBarrier_Orb_End_", 1, 24);
	// 1페이즈_분수
	AddImage("Fountain_Deactivate", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/Fountain/Deactive/Deactivate_01.png");
	AddImageVector("Boss_HolyFountain_Activate", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/Fountain/Active/Activate_", 1, 8);
	AddImageVector("TeleportEffect", L"./Resources/Saint_Joanna/Phase_2/Teleport/in/", 1, 38);
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
	AddImageVector("Boss_Baptism_Projectile_Despawn", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Baptism/Projectile_Despawn/Phase1_Baptism_Projectile_Despawn_", 1, 24);
	// 1페이즈_레이저z
	AddImageVector("Boss_Consecration_Start", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/Start/Phase1_Consecration_Start_", 1, 27);
	AddImageVector("Boss_Consecration_Sign", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/Sign/Phase1_Consecration_Sign_", 1, 23);
	AddImageVector("Boss_Consecration_Loop", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/Loop/Phase1_Consecration_Loop_", 1, 33);
	AddImageVector("Boss_Consecration_End", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Consecration/End/Phase1_Consecration_End_", 1, 21);
	// 1페이즈_좌우 구슬
	AddImageVector("Boss_Worship", L"./Resources/Saint_Joanna/Phase_1/Casting/Effect/Worship/Phase1_Worship_Projectile_", 1, 60);

	// 2페이즈_대기
	AddImageVector("Phase2_Ball_CreateBall_Start", L"./Resources/Saint_Joanna/Phase_2/CreateBall/HolyBarrierOrb/Start/", 1, 21);
	AddImageVector("Phase2_Ball_CreateBall_Idle", L"./Resources/Saint_Joanna/Phase_2/CreateBall/HolyBarrierOrb/Orb/Phase1_HolyBarrier_Orb_", 1, 48);

	AddImageVector("Phase2_Ball_SoulChase_Attack", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Boss/Attack/", 1, 7);
	AddImageVector("Phase2_Ball_SoulChase_Ready", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Boss/Ready/", 1, 7);
	AddImageVector("Phase2_Ball_SoulChase_End", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Boss/End/", 1, 7);
	AddImageVector("Trail", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Effect/Trail/", 1, 51);

	AddImageVector("Phase2_Ball_DivineLight_AttackLoop", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Boss/AttackLoop/", 15, 21);
	AddImageVector("Phase2_Ball_DivineLight_AttackReady", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Boss/AttackReady/", 8, 14);
	AddImageVector("Phase2_Ball_DivineLight_End", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Boss/End/", 24, 28);
	AddImageVector("Phase2_Ball_DivineLight_Ready", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Boss/Ready/", 1, 7);

	AddImageVector("DivineLight_ef1", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Effect/ef/", 2, 38);
	AddImageVector("DivineLight_ef2", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Effect/ef2/", 2, 40);
	AddImageVector("MuzzleFlash", L"./Resources/Saint_Joanna/Phase_2/DivineLight/Effect/MuzzleFlash/", 1, 24);


	AddImageVector("Circle", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Boss/Circle/", 1, 40);
	AddImageVector("CircleIdle", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Boss/CircleIdle/", 1, 39);
	AddImageVector("CircleDis", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Boss/CircleDis/", 1, 8);

	AddImageVector("MagicCircle", L"./Resources/Saint_Joanna/Phase_2/SoulChase/Effect/MagicCircle/", 1, 42);

	AddImageVector("MagicCircle", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Effect/MagicCircle/", 1, 42);
	AddImageVector("MagicCircle", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Effect/Phase2_DivineImpact_", 1, 27);
	AddImageVector("Phase2_DivineImpact_Effect", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Effect/Phase2_DivineImpact_", 1, 27);

	AddImageVector("Phase2_DivineImpact_Attack_Loop", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Boss/Attack/DivineImpact_Attack_Loop_", 1, 7);
	AddImageVector("Phase2_DivineImpact_End", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Boss/End/DivineImpact_End_", 1, 7);
	AddImageVector("Phase2_DivineImpact_Ready", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Boss/Ready/DivineImpact_Ready_", 1, 7);
	AddImageVector("Phase2_DivineImpact_Ready_Loop", L"./Resources/Saint_Joanna/Phase_2/DivineImpact/Boss/ReadyLoop/DivineImpact_Ready_Loop_", 1, 7);

	AddImageVector("Phase2_Phase_3_Loop", L"./Resources/Saint_Joanna/Phase_3/Attack/Sacrament_Attack_Loop_", 1, 7);
	AddImageVector("Phase2_Phase_3_End", L"./Resources/Saint_Joanna/Phase_3/End/Sacrament_End_", 1, 7);
	AddImageVector("Phase2_Phase_3_Ready", L"./Resources/Saint_Joanna/Phase_3/Ready/Sacrament_Ready_", 1, 7);

	AddImageVector("Phase2_Phase_3_Effect", L"./Resources/Saint_Joanna/Phase_3/Effect/Phase3_Sacrament_", 1, 66);

	AddImageVector("Phase2_Death_Ready", L"./Resources/Saint_Joanna/Phase2_Intro_7/", 1, 7);
	AddImageVector("Phase2_DeathLoop", L"./Resources/Saint_Joanna/Phase2_Intro_8/", 1, 14);
	AddImageVector("Phase2_Death_Effect", L"./Resources/Saint_Joanna/deathEffect/", 1, 11);

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

	AddImageVector("LootGear_Legendary_Behind_Loop_", L"./Resources/HeadUI/Behind/Loop/LootGear_Legendary_Behind_Loop_", 1, 36);
	AddImageVector("LootGear_Lengedary_Behind_Start_", L"./Resources/HeadUI/Behind/Start/LootGear_Lengedary_Behind_Start_", 1, 66);
	AddImageVector("LootGear_Legendaryr_Front_Loop_", L"./Resources/HeadUI/Front/Loop/LootGear_Legendaryr_Front_Loop_", 1, 36);
	AddImageVector("LootGear_Legendary_Front_Start_", L"./Resources/HeadUI/Front/Start/LootGear_Legendary_Front_Start_",2, 66);

	// 2페이즈_상단 텔포, 직선 레이저

	AddImage("FireKnife", L"./Resources/Saint_Joanna/Phase_1/Normal_Monster/Monster/FireKnife.png");
	AddImage("hpBar", L"./Resources/hpBar.png");
	AddImage("deathUI", L"./Resources/deathUI.png");
	AddImage("goldUI", L"./Resources/goldUI.png");
	AddImage("enemyUI", L"./Resources/enemyUI.png");
	AddImage("bossHp", L"./Resources/bossHp.png");
	AddImage("GamblerHead", L"./Resources/HeadUI/Gambler #54692.png");

	AddImage("GamblerHeadUI", L"./Resources/HeadUI/Gambler #57092.png");
	AddImage("LittleHeadUI", L"./Resources/3.png");

	AddImage("gamA", L"./Resources/gamA.png");
	AddImage("gamS", L"./Resources/gamS.png");
	AddImage("littleA", L"./Resources/littleA.png");
	AddImage("littleS", L"./Resources/littleS.png");
	AddImage("skillBlank", L"./Resources/skillBlank.png");
	AddImage("colltime", L"./Resources/colltime.png");
	AddImage("switchColl", L"./Resources/switchColl.png");


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
	AddStructureImage("Box2", L"./Resources/Tile/4Stage/Structure/box2.png");
	AddStructureImage("Box3", L"./Resources/Tile/4Stage/Structure/box3.png");
	AddStructureImage("Box4", L"./Resources/Tile/4Stage/Structure/box4.png");
	AddStructureImage("Guillotine", L"./Resources/Tile/4Stage/Structure/Guillotine.png");
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
	AddStructureImage("BrokenHouse", L"./Resources/Tile/4Stage/Structure/BrokenHouse.png");
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
	AddImageVector("MapReward_Spawn", L"Resources/MapRe/MapReward_Spawn_", 1, 40);


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
	AddImageVector("NormalRoom2", L"Resources/Door/NormalRoom/", 1, 8);
	AddImageVector("SkulRoom", L"Resources/Door/SkulRoom/", 1, 7);
	AddImageVector("BossRoom", L"Resources/Door/BossRoom/", 1, 7);
	AddImageVector("ShopRoom", L"Resources/Door/ShopRoom/", 1, 8);
	AddImageVector("SpirderRoom", L"Resources/Door/SpirderRoom/", 1, 8);

	AddImageVector("Fountain", L"Resources/Tile/4Stage/Structure/fountain/", 1, 6);
	AddImageVector("Spider", L"Resources/Tile/4Stage/Structure/spider/", 1, 11);
	AddImageVector("LobbyNpc", L"Resources/Tile/4Stage/Structure/Npc1/", 1, 7);
	AddImageVector("LobbyNpc2", L"Resources/Tile/4Stage/Structure/Npc2/", 1, 24);
	AddImageVector("LobbyNpc3", L"Resources/Tile/4Stage/Structure/Npc3/", 1, 8);
	AddImageVector("LobbyNpc4", L"Resources/Tile/4Stage/Structure/Npc4/", 1, 8);
	AddImageVector("LobbyNpc5", L"Resources/Tile/4Stage/Structure/Npc5/", 1, 8);
	AddImageVector("CatIdle", L"Resources/Tile/4Stage/Structure/Cat/Idle/", 1, 6);
	AddImageVector("CatWalk", L"Resources/Tile/4Stage/Structure/Cat/Walk/", 1, 6);
	AddImageVector("SpaerSkul", L"Resources/Tile/4Stage/Structure/Spearskul/", 1, 35);
	AddImageVector("Elevator", L"Resources/Tile/4Stage/Structure/Elevator/", 1, 6);

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
	AddObjectImage("NormalRoom2", L"Resources/Door/NormalRoom/Deactivate_0.png");
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
	AddObjectImage("Trigger4", L"./Resources/Trigger4.png");
	AddObjectImage("Trigger5", L"./Resources/Trigger5.png");
	AddObjectImage("Trigger6", L"./Resources/Trigger6.png");
	AddObjectImage("Trigger7", L"./Resources/Trigger7.png");
	AddObjectImage("Trigger8", L"./Resources/Trigger8.png");
	AddObjectImage("Trigger9", L"./Resources/Trigger9.png");
	AddObjectImage("Trigger10", L"./Resources/Trigger10.png");

	AddObjectImage("Fountain", L"./Resources/Tile/4Stage/Structure/fountain/01.png");
	AddObjectImage("Spider", L"./Resources/Tile/4Stage/Structure/spider/01.png");
	AddObjectImage("LobbyNpc", L"./Resources/Tile/4Stage/Structure/Npc1/01.png");
	AddObjectImage("LobbyNpc2", L"./Resources/Tile/4Stage/Structure/Npc2/01.png");
	AddObjectImage("LobbyNpc3", L"./Resources/Tile/4Stage/Structure/Npc3/01.png");
	AddObjectImage("LobbyNpc4", L"./Resources/Tile/4Stage/Structure/Npc4/01.png");
	AddObjectImage("LobbyNpc5", L"./Resources/Tile/4Stage/Structure/Npc5/01.png");
	AddObjectImage("CatIdle", L"./Resources/Tile/4Stage/Structure/Cat/Idle/01.png");
	AddObjectImage("CatWalk", L"./Resources/Tile/4Stage/Structure/Cat/Walk/01.png");
	AddObjectImage("SpaerSkul", L"./Resources/Tile/4Stage/Structure/Spearskul/01.png");
	AddObjectImage("Elevator", L"./Resources/Tile/4Stage/Structure/Elevator/01.png");

	// 인게임 UI이미지
	AddImage("Inventory_Frame", L"./Resources/UI/Inventory_Frame.png");
	AddImage("PlayerStatusUI", L"./Resources/UI/PlayerStatusUI.png");
	AddImage("ItemUI", L"./Resources/UI/itemUI.png");

	AddImage("IntroTitle", L"./Resources/IntroTitle.png");
	AddImage("IntroClick", L"./Resources/IntroClick.png");
	AddImage("IntroBg", L"./Resources/IntroBg.png");

	// 엔딩신 이미지
	AddImage("Ending_BG_SmallMountain", L"./Resources/EndingScene/BG/SmallMountain.png");
	AddImage("Ending_BG_BigMountain", L"./Resources/EndingScene/BG/BigMountain.png");
	AddImage("Ending_BG_SmallCloud", L"./Resources/EndingScene/BG/SmallCloud.png");
	AddImage("Ending_BG_MediumCloud", L"./Resources/EndingScene/BG/MediumCloud.png");
	AddImage("Ending_BG_BigCloud", L"./Resources/EndingScene/BG/BigCloud.png");
	AddImage("Ending_BG_Sunset", L"./Resources/EndingScene/BG/Sunset.png");

	AddImage("Ending_Castle_Front", L"./Resources/EndingScene/Castle/EndingCastle_Front.png");
	AddImage("Ending_Castle_Back", L"./Resources/EndingScene/Castle/EndingCastle_Back.png");

	AddImageVector("Ending_Cat_Walk", L"./Resources/EndingScene/Cat/Walk/Cat_Walk_", 1, 6);
	AddImageVector("Ending_Cat_Polymorph", L"./Resources/EndingScene/Cat/Polymorph/Cat_Polymorph_", 1, 21);

	AddImage("Ending_Duo_Talk_Loop", L"./Resources/EndingScene/Duo/TalkLoop/Duo_Talk.png");
	AddImageVector("Ending_Duo_SeeWitch", L"./Resources/EndingScene/Duo/SeeWitch/Duo_SeeWitch_", 1, 3);
	AddImageVector("Ending_Duo_ReturnKing", L"./Resources/EndingScene/Duo/ReturnKing/Duo_ReturnKing_", 1, 3);
	AddImageVector("Ending_Duo_ReturnSkul", L"./Resources/EndingScene/Duo/ReturnSkul/Duo_ReTurnSkul_", 1, 3);
	AddImageVector("Ending_Duo_DuoThanks", L"./Resources/EndingScene/Duo/DuoThanks/Duo_Thanks_", 1, 3);

	AddImageVector("food", L"./Resources/food/", 1, 15);

	AddImage("Ending_Duo_DuoThanks_Loop", L"./Resources/EndingScene/Duo/DuoThanksLoop/Duo_Thanks_Loop.png");

	SOUNDMANAGER->AddSound("Intro", "./Resources/Sound/Intro.wav");
	SOUNDMANAGER->FindSound("Intro")->SetVolume(60);
	SOUNDMANAGER->AddSound("Lobby", "./Resources/Sound/Lobby.wav");
	SOUNDMANAGER->FindSound("Lobby")->SetVolume(60);
	SOUNDMANAGER->AddSound("Chapter4", "./Resources/Sound/Chapter4.wav");
	SOUNDMANAGER->FindSound("Chapter4")->SetVolume(60);
	SOUNDMANAGER->AddSound("Shop", "./Resources/Sound/Shop.wav");
	SOUNDMANAGER->FindSound("Shop")->SetVolume(60);
	SOUNDMANAGER->AddSound("Middle", "./Resources/Sound/Middle.wav");
	SOUNDMANAGER->AddSound("Dash", "./Resources/Sound/Dash.wav");
	SOUNDMANAGER->FindSound("Middle")->SetVolume(60);
	SOUNDMANAGER->AddSound("Bossphase1", "./Resources/Sound/Bossphase1.wav");
	SOUNDMANAGER->FindSound("Bossphase1")->SetVolume(60);
	SOUNDMANAGER->AddSound("Jump", "./Resources/Sound/Jump.wav");
	SOUNDMANAGER->AddSound("SkulAttack1", "./Resources/Sound/Skul_Atk 1.wav");
	SOUNDMANAGER->FindSound("SkulAttack1")->SetVolume(50);
	SOUNDMANAGER->AddSound("SkulAttack2", "./Resources/Sound/Skul_Atk 2.wav");
	SOUNDMANAGER->FindSound("SkulAttack2")->SetVolume(50);
	SOUNDMANAGER->AddSound("SkulSkill1", "./Resources/Sound/SkulSkill.wav");
	SOUNDMANAGER->FindSound("SkulSkill1")->SetVolume(50);
	SOUNDMANAGER->AddSound("Switch", "./Resources/Sound/Switch.wav");
	SOUNDMANAGER->FindSound("Switch")->SetVolume(50);
	SOUNDMANAGER->AddSound("SkulSwitch", "./Resources/Sound/SkulSwitch.wav");
	SOUNDMANAGER->FindSound("SkulSwitch")->SetVolume(50);
	SOUNDMANAGER->AddSound("SkulAttackSword", "./Resources/Sound/Hit_Sword_Small.wav");
	SOUNDMANAGER->FindSound("SkulAttackSword")->SetVolume(100);
	SOUNDMANAGER->AddSound("SkulAttack", "./Resources/Sound/Hit_Sword_Small02.wav");
	SOUNDMANAGER->FindSound("SkulAttack")->SetVolume(100);
	SOUNDMANAGER->AddSound("SkulAttackBluntLarge", "./Resources/Sound/Hit_Blunt_Large.wav");
	SOUNDMANAGER->FindSound("SkulAttackBluntLarge")->SetVolume(100);
	SOUNDMANAGER->AddSound("SkulAttackBluntSmall", "./Resources/Sound/Hit_Blunt_Small.wav");
	SOUNDMANAGER->FindSound("SkulAttackBluntSmall")->SetVolume(100);
	SOUNDMANAGER->AddSound("SkulAttackExplosion", "./Resources/Sound/Legacy_Hit [Unused].wav");
	SOUNDMANAGER->FindSound("SkulAttackExplosion")->SetVolume(100);
	SOUNDMANAGER->AddSound("FanaticAttackReady", "./Resources/Sound/FanaticAttack_Ready.wav");
	SOUNDMANAGER->FindSound("FanaticAttackReady")->SetVolume(30);
	SOUNDMANAGER->AddSound("FanaticAttack", "./Resources/Sound/FanaricAttack.wav");
	SOUNDMANAGER->FindSound("FanaticAttack")->SetVolume(50);
	SOUNDMANAGER->AddSound("CandleFanaticAttack", "./Resources/Sound/CandleFanaticAttack.wav");
	SOUNDMANAGER->FindSound("CandleFanaticAttack")->SetVolume(50);
	SOUNDMANAGER->AddSound("CandleFanaticAttackHit", "./Resources/Sound/CandleFanaticAttackHit.wav");
	SOUNDMANAGER->FindSound("CandleFanaticAttackHit")->SetVolume(50);
	SOUNDMANAGER->AddSound("CandleFanaticFire", "./Resources/Sound/CandleFanaticFire.wav");
	SOUNDMANAGER->FindSound("CandleFanaticFire")->SetVolume(50);
	SOUNDMANAGER->AddSound("Sacrifice", "./Resources/Sound/Sacrifice.wav");
	SOUNDMANAGER->FindSound("Sacrifice")->SetVolume(60);
	SOUNDMANAGER->AddSound("AngleStatueAttackReady", "./Resources/Sound/AngleStatueAttackReady.wav");
	SOUNDMANAGER->FindSound("AngleStatueAttackReady")->SetVolume(100);
	SOUNDMANAGER->AddSound("AngleStatueAttack", "./Resources/Sound/AngleStatueAttack.wav");
	SOUNDMANAGER->FindSound("AngleStatueAttack")->SetVolume(100);
	SOUNDMANAGER->AddSound("TentacleAttack", "./Resources/Sound/TentacleAttack.wav");
	SOUNDMANAGER->FindSound("TentacleAttack")->SetVolume(100);
	SOUNDMANAGER->AddSound("LeoniaSolderAttack", "./Resources/Sound/LeoniaSolderAttack.wav");
	SOUNDMANAGER->FindSound("LeoniaSolderAttack")->SetVolume(100);
	SOUNDMANAGER->AddSound("LeonialSolderAttackHit", "./Resources/Sound/LeonialSolderAttackHit.wav");
	SOUNDMANAGER->FindSound("LeonialSolderAttackHit")->SetVolume(100);

	SOUNDMANAGER->AddSound("GamblerBigHit", "./Resources/Sound/Gambler_BigHit.wav")->SetVolume(100);
	SOUNDMANAGER->AddSound("GamblerSwitch", "./Resources/Sound/GamblerSwitch.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("GamblerAtk1", "./Resources/Sound/Gambler_AtkA.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("GamblerAtk2", "./Resources/Sound/Gambler_AtkB.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("GamblerAtk3", "./Resources/Sound/Gambler_AtkC.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("GamblerBigHit", "./Resources/Sound/Gambler_BigHit.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("GamblerBlackJackReady", "./Resources/Sound/Gambler_BlackJack_Ready.wav")->SetVolume(30);
	SOUNDMANAGER->AddSound("GamblerBlackJack1", "./Resources/Sound/Gambler_BlackJack1.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("GamblerBlackJack2", "./Resources/Sound/Gambler_BlackJack2.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("GamblerBlackJack3", "./Resources/Sound/Gambler_BlackJack3.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("GamblerBlackJackBigHit", "./Resources/Sound/Gambler_BlackJack_BigHit.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineStart", "./Resources/Sound/Gambler_SlotMachine_Start.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineRunning", "./Resources/Sound/Gambler_SlotMachine.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineJackpot", "./Resources/Sound/Gambler_SlotMachine_Jackpot.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineFinish", "./Resources/Sound/Gambler_SlotMachine_Finish.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineExplosion", "./Resources/Sound/Gambler_SlotMachine_Explosion.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("SlotMachineExplosion3", "./Resources/Sound/Gambler_SlotMachine_Explosion3.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("SlotMachineThunder", "./Resources/Sound/Gambler_SlotMachine_Lightning.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("SlotMachineThunder3", "./Resources/Sound/Gambler_SlotMachine_Lightning3.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("SlotMachineThunder3ImpactA", "./Resources/Sound/Gambler_SlotMachine_Lightning3A.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("SlotMachineThunder3ImpactB", "./Resources/Sound/Gambler_SlotMachine_Lightning3B.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("SlotMachineThunder3ImpactC", "./Resources/Sound/Gambler_SlotMachine_Lightning3C.wav")->SetVolume(60);
	SOUNDMANAGER->AddSound("RouletteSummon", "./Resources/Sound/Gambler_Roulette_Summon.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteSpin", "./Resources/Sound/Gambler_Roulette.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteSpike", "./Resources/Sound/Gambler_Roulette_Spike.wav")->SetVolume(10);
	SOUNDMANAGER->AddSound("RouletteFail", "./Resources/Sound/Gambler_Roulette_Fail.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteResultBlack", "./Resources/Sound/Gambler_Roulette_Black.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteResultRed", "./Resources/Sound/Gambler_Roulette_Red.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteHitBlack", "./Resources/Sound/Gambler_DestinyRoulette_Success_Black.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteHitRed", "./Resources/Sound/Gambler_DestinyRoulette_Success_Red.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteBigHitBlackCast", "./Resources/Sound/Gambler_DestinyRoulette_BigHit_BlackCast.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteBigHitBlack", "./Resources/Sound/Gambler_DestinyRoulette_BigHit_BlackAtk.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("RouletteBigHitRed", "./Resources/Sound/Gambler_DestinyRoulette_BigHit_Red.wav")->SetVolume(50);

	SOUNDMANAGER->AddSound("033_Archbishop_Teleport_In_a_v1", "./Resources/Sound/보스 오디오/2페이즈/Teleport/033_Archbishop_Teleport_In_a_v1.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("034_Archbishop_Teleport_Out_a_v1", "./Resources/Sound/보스 오디오/2페이즈/Teleport/034_Archbishop_Teleport_Out_a_v1.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("022_Archbishop_Voice_5_b_v1", "./Resources/Sound/022_Archbishop_Voice_5_b_v1.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("Archbishop_DvineLight_Fire", "./Resources/Sound/보스 오디오/2페이즈/DivineLight/Archbishop_DvineLight_Fire.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("036_Archbishop_DivineImpact_Explosion_a_v1", "./Resources/Sound/보스 오디오/2페이즈/DivineImpact/036_Archbishop_DivineImpact_Explosion_a_v1.wav")->SetVolume(50);

	SOUNDMANAGER->AddSound("052_Archbishop_Sacrament_Voice_a_v1", "./Resources/Sound/보스 오디오/2페이즈/Sacrament/052_Archbishop_Sacrament_Voice_a_v1.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("053_Archbishop_Sacrament_Ready_a_v1", "./Resources/Sound/보스 오디오/2페이즈/Sacrament/053_Archbishop_Sacrament_Ready_a_v1.wav")->SetVolume(50);

	SOUNDMANAGER->AddSound("SkulRise", "./Resources/Sound/SkulRise.wav");
	SOUNDMANAGER->FindSound("SkulRise")->SetVolume(70);
	SOUNDMANAGER->AddSound("SkulCape", "./Resources/Sound/SkulCape.wav");
	SOUNDMANAGER->FindSound("SkulCape")->SetVolume(70);
	SOUNDMANAGER->AddSound("Barrier", "./Resources/Sound/보스 오디오/1페이즈/Barrier/Barrier.wav");
	SOUNDMANAGER->FindSound("Barrier")->SetVolume(70);
	SOUNDMANAGER->AddSound("Nervousnessvoice", "./Resources/Sound/보스 오디오/1페이즈/Nervousness/Nervousnessvoice.wav");
	SOUNDMANAGER->FindSound("Nervousnessvoice")->SetVolume(70);
	SOUNDMANAGER->AddSound("Nervousness", "./Resources/Sound/보스 오디오/1페이즈/Nervousness/Nervousness.wav");
	SOUNDMANAGER->FindSound("Nervousness")->SetVolume(70);
	SOUNDMANAGER->AddSound("Worshipvoice", "./Resources/Sound/보스 오디오/1페이즈/Worship/Worshipvoice.wav");
	SOUNDMANAGER->FindSound("Worshipvoice")->SetVolume(70);
	SOUNDMANAGER->AddSound("Wosrship", "./Resources/Sound/보스 오디오/1페이즈/Worship/Wosrship.wav");
	SOUNDMANAGER->FindSound("Wosrship")->SetVolume(70);
	SOUNDMANAGER->AddSound("Consecration", "./Resources/Sound/보스 오디오/1페이즈/Consecration/Consecration.wav");
	SOUNDMANAGER->FindSound("Consecration")->SetVolume(70);
}
