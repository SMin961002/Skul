#include "stdafx.h"
#include "ImageManager.h"

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
	for (auto iter : m_vectorImageList)
	{
		for (auto _iter : iter.second->GetImages())
		{
			SAFE_DELETE(_iter);
		}
		SAFE_DELETE(iter.second);
	}
	m_vectorImageList.clear();

	for (auto iter : m_tileImages)
	{
		SAFE_DELETE(iter);
	}
	m_tileImages.clear();

	for (auto iter : m_imageList)
	{
		SAFE_DELETE(iter.second);
	}
	m_imageList.clear();

	for (auto iter : m_structureImages)
	{
		SAFE_DELETE(iter.second);
	}
	m_structureImages.clear();

	m_brush->Release();
	tf->Release();

	for (auto iter : m_gimages)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_gimages.clear();

	for (auto iter : m_vImages)
	{
		SAFE_DELETE(iter);
	}
	m_vImages.clear();
}

void ImageManager::Init()
{
	factory = nullptr;
	RECT rc;
	GetClientRect(_hWnd, &rc);

	camera.x = 0;
	camera.y = 0;

	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
	pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(_hWnd, D2D1::SizeU(WINSIZE_X, WINSIZE_Y)), &pRT);

	CoInitialize(0);
	CoCreateInstance(CLSID_WICImagingFactory, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));

	IDWriteFactory* m_pDWriteFactory = nullptr;

	DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_pDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
	);

	m_pDWriteFactory->CreateTextFormat(
		L"맑음 고딕",                  // 폰트 패밀리 이름의 문자열
		NULL,                        // 폰트 컬렉션 객체, NULL=시스템 폰트 컬렉션
		DWRITE_FONT_WEIGHT_NORMAL,   // 폰트 굵기. LIGHT, NORMAL, BOLD 등.
		DWRITE_FONT_STYLE_NORMAL,    // 폰트 스타일. NORMAL, OBLIQUE, ITALIC.
		DWRITE_FONT_STRETCH_NORMAL,  // 폰트 간격. CONDENSED, NORMAL, MEDIUM, EXTEXDED 등.
		30,                          // 폰트 크기.
		L"ko",                         // 로케일을 문자열로 명시.  영어-미국=L"en-us", 한국어-한국=L"ko-kr"
		&tf
	);

	D2D1_COLOR_F color;
	color.a = 1;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pRT->CreateSolidColorBrush(color, &m_brush);

	m_pDWriteFactory->Release();
}

void ImageManager::LoadImages()
{
	// 맵툴 UI 이미지
	AddImage("newFile", L"./MapFile/newFile.png");

	// 예시 이미지
	AddImage("Frame_1SKill", L"./Resources/Frame_1SKill.png");
	AddImageVector("Ex_Idle", L"./Resources/Png/Idle/", 1, 6);

	//캐릭터 대시, 점프 이펙트
	AddImageVector("Jump_Smoke", L"./Resources/Png/Skul/Effect_DashSmoke/", 1, 13);
	AddImageVector("Jump_Smoke", L"./Resources/Png/Skul/Effect_DoubleJumpSmoke/", 1, 10);

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

	AddImage("exBg", L"./Resources/exBg.png");
	AddImage("Background", L"./MapFile/BackGround/background.png");
	AddImage("Castle", L"./MapFile/BackGround/castle.png");
	AddImage("Cloud", L"./MapFile/BackGround/cloud.png");
	//약탈자 모션 이미지

	//디스트로이어 모션 이미지

	//갬블러스컬 모션 이미지 경로수정중
	AddImageVector("Gambler_Idle", L"./Resources/Png/Skul/Gambler/Motion/Idle/", 1, 7);
	AddImageVector("Gambler_Walk", L"./Resources/Png/Skul/Gambler/Motion/Walk/", 1, 6);
	//AddImageVector("Gambler_Dash", L"./Resources/Png/Skul/Gambler/Motion/Dash/", 1, 5);
	//AddImageVector("Gambler_AttackA1", L"./Resources/Png/Skul/Gambler/Motion/AttackA1/", 1, 5);
	//AddImageVector("Gambler_AttackA2", L"./Resources/Png/Skul/Gambler/Motion/AttackA2/", 1, 6);
	//AddImageVector("Gambler_AttackB1", L"./Resources/Png/Skul/Gambler/Motion/AttackB1/", 1, 6);
	//AddImageVector("Gambler_AttackB2", L"./Resources/Png/Skul/Gambler/Motion/AttackB2/", 1, 6);
	//AddImageVector("Gambler_AttackB3", L"./Resources/Png/Skul/Gambler/Motion/AttackB3/", 1, 8);
	//AddImageVector("Gambler_JumpStart", L"./Resources/Png/Skul/Gambler/Motion/JumpStart/", 1, 3);
	//AddImageVector("Gambler_JumpRepeat", L"./Resources/Png/Skul/Gambler/Motion/JumpRepeat/", 1, 2);
	//AddImageVector("Gambler_JumpFall", L"./Resources/Png/Skul/Gambler/Motion/JumpFall/", 1, 3);
	//AddImageVector("Gambler_JumpAttack", L"./Resources/Png/Skul/Gambler/Motion/JumpAttack/", 1, 5);
	//AddImageVector("Gambler_RussianRoulette", L"./Resources/Png/Skul/Gambler/Motion/RussianRoulette/", 1, 8);

	// 타일 이미지
	AddTileImage(L"./Resources/Tile/4Stage/01.png");
	AddTileImage(L"./Resources/Tile/4Stage/02.png");
	AddTileImage(L"./Resources/Tile/4Stage/03.png");
	AddTileImage(L"./Resources/Tile/4Stage/04.png");
	AddTileImage(L"./Resources/Tile/4Stage/05.png");
	AddTileImage(L"./Resources/Tile/4Stage/06.png");
	AddTileImage(L"./Resources/Tile/4Stage/07.png");
	AddTileImage(L"./Resources/Tile/4Stage/08.png");
	AddTileImage(L"./Resources/Tile/4Stage/09.png");
	AddTileImage(L"./Resources/Tile/4Stage/10.png");
	AddTileImage(L"./Resources/Tile/4Stage/11.png");
	AddTileImage(L"./Resources/Tile/4Stage/12.png");
	AddTileImage(L"./Resources/Tile/4Stage/13.png");
	AddTileImage(L"./Resources/Tile/4Stage/14.png");
	AddTileImage(L"./Resources/Tile/4Stage/15.png");
	AddTileImage(L"./Resources/Tile/4Stage/16.png");
	AddTileImage(L"./Resources/Tile/4Stage/17.png");
	AddTileImage(L"./Resources/Tile/4Stage/18.png");
	AddTileImage(L"./Resources/Tile/4Stage/19.png");
	AddTileImage(L"./Resources/Tile/4Stage/20.png");
	AddTileImage(L"./Resources/Tile/4Stage/21.png");
	AddTileImage(L"./Resources/Tile/4Stage/22.png");
	AddTileImage(L"./Resources/Tile/4Stage/23.png");
	AddTileImage(L"./Resources/Tile/4Stage/24.png");
	AddTileImage(L"./Resources/Tile/4Stage/25.png");
	AddTileImage(L"./Resources/Tile/4Stage/26.png");
	AddTileImage(L"./Resources/Tile/4Stage/27.png");
	AddTileImage(L"./Resources/Tile/4Stage/28.png");
	AddTileImage(L"./Resources/Tile/4Stage/29.png");
	AddTileImage(L"./Resources/Tile/4Stage/30.png");
	AddTileImage(L"./Resources/Tile/4Stage/31.png");
	AddTileImage(L"./Resources/Tile/4Stage/32.png");
	AddTileImage(L"./Resources/Tile/4Stage/33.png");
	AddTileImage(L"./Resources/Tile/4Stage/34.png");
	AddTileImage(L"./Resources/Tile/4Stage/35.png");
	AddTileImage(L"./Resources/Tile/4Stage/36.png");
	AddTileImage(L"./Resources/Tile/4Stage/37.png");
	AddTileImage(L"./Resources/Tile/4Stage/38.png");

	// 배경 이미지
	AddImage("Moon", L"./Resources/BackGround/Boss_Stage_Moon.png");
	AddImage("Building", L"./Resources/BackGround/Boss_Stage_Building.png");
	AddImage("Lion", L"./Resources/BackGround/Boss_Stage_Lion.png");

	AddImage("CollisionPlatform", L"./Resources/Tile/4Stage/CollisionPlatform.png");
	AddImage("CollisionBox", L"./Resources/Tile/4Stage/CollisionBox.png");

	AddPixelmage("CollisionBox", "./Resources/Tile/4Stage/CollisionBox.bmp", 32, 32);

	// 보스 ====================================================================================
	// 1페이즈_대기
	AddImageVector("Boss_Idle", L"./Resources/Saint_Joanna/Phase1_Intro_1/Idle_", 1, 7);
	// 1페이즈_지팡이 들기
	AddImageVector("Boss_Casting_Ready", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/Ready/Casting_Ready_", 1, 7);
	AddImageVector("Boss_Casting_Attack", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/Attack/Casting_Attack_Loop_", 1, 7);
	AddImageVector("Boss_Casting_End", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/Attack/Casting_Attack_Loop_", 1, 7);
	// 1페이즈_초이스
	AddImageVector("Boss_Choice_Ready", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/Ready/Ready/Choice_Ready_", 1, 7);
	AddImageVector("Boss_Choice_Ready_Loop", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/Ready/Loop/Choice_Ready_Loop_", 1, 7);
	AddImageVector("Boss_Choice_Attack", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/Attack/Choice_Attack_Loop_", 1, 7);
	AddImageVector("Boss_Choice_End", L"./Resources/Saint_Joanna/Phase_1/Choice/Boss/End/Choice_End_", 1, 7);
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
	AddImageVector("Boss_HolyFountain_Start", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/Start/Phase1_HolyBarrier_Orb_Start_", 1, 22);
	AddImageVector("Boss_HolyFountain_Orb", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/Orb/Phase1_HolyBarrier_Orb_", 1, 47);
	AddImageVector("Boss_HolyFountain_End", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/HolyBarrierOrb/End/Phase1_HolyBarrier_Orb_End_", 1, 24);
	// 1페이즈_분수
	AddImage("Fountain_Deactivate", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/Fountain/Deactive/Deactivate_01.png");
	AddImageVector("Boss_HolyFountain_Activate", L"./Resources/Saint_Joanna/Phase_1/HollyFountain/Fountain/Active/Activate_", 1, 8);
	// 1페이즈_방어막
	AddImageVector("Boss_Barrier_Intro", L"./Resources/Saint_Joanna/Phase_1/Barrier/Intro/Phase1_Barrier_Intro_", 1, 30);
	AddImageVector("Boss_Barrier_Loop", L"./Resources/Saint_Joanna/Phase_1/Barrier/Loop/Phase1_Barrier_Loop_", 1, 24);
	AddImageVector("Boss_Barrier_Crack_Impact", L"./Resources/Saint_Joanna/Phase_1/Barrier/Crack/Crack_Impact/Phase1_Barrier_Crack_Impact_", 1, 12);
	AddImageVector("Boss_Barrier_Crack_Spark", L"./Resources/Saint_Joanna/Phase_1/Barrier/Spark/Phase1_Barrier_Impact_Spark_", 1, 26);
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
	AddImageVector("Phase2_Boss_Idle", L"./Resources/Saint_Joanna/Phase_2/Idle/Phase2_Idle_", 1, 6);
	// 구체 생성
	AddImageVector("Phase2_Boss_CreateBall_Ready", L"./Resources/Saint_Joanna/Phase_2/CreateBall/Boss/Ready/Sacrament_Ready_", 1, 6);

	//==========================================================================================================
	// 맵 구조물 이미지
	AddStructureImage("statue", L"./Resources/Tile/4Stage/Structure/statue.png");
	AddStructureImage("arch1", L"./Resources/Tile/4Stage/Structure/arch1.png");
	AddStructureImage("arch2", L"./Resources/Tile/4Stage/Structure/arch2.png");
	AddStructureImage("Elevator", L"./Resources/Tile/4Stage/Structure/elevator.png");

	// 몬스터 체력바 이미지
	AddImageVector("Hpbar_Empty", L"./Resources/Monster/Hpbar/Empty/", 1, 1);
	AddImageVector("Hpbar_Down", L"./Resources/Monster/Hpbar/Down/", 1, 1);
	AddImageVector("Hpbar_Up", L"./Resources/Monster/Hpbar/Up/",1,1);

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

	//맵툴 오브젝트 이미지 저장
	AddObjectImage("Leon", L"Resources/Monster/Leonia Soldier/Idle/01.png");
	AddObjectImage("Fanatic", L"Resources/Monster/Fanatic/Idle/01.png");
	AddObjectImage("Bfanatic", L"Resources/Monster/Black Fanatic/Idle/01.png");
	AddObjectImage("Cfanatic", L"Resources/Monster/Candle_Fanatic/Idle/01.png");
	AddObjectImage("Tentacles", L"Resources/Monster/Tentacles_Of_Light/Idle/01.png");
	AddObjectImage("Lfanatic", L"Resources/Monster/Lamp_Fanatic/Idle/01.png");
	AddObjectImage("Befanatic", L"Resources/Monster/Bell_Fanatic/Idle/01.png");
	AddObjectImage("AStatue", L"Resources/Monster/Angel_Statue/Idle/01.png");
}

ID2D1Bitmap* ImageManager::AddBitmap(std::wstring path, UINT* Width, UINT* Height)
{
	ID2D1Bitmap* bitmap;
	IWICBitmapDecoder* decoder = nullptr;
	factory->CreateDecoderFromFilename(path.c_str(), 0, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoder);

	IWICBitmapFrameDecode* frameDecode = nullptr;
	decoder->GetFrame(0, &frameDecode);

	IWICFormatConverter* converter = nullptr;
	factory->CreateFormatConverter(&converter);

	converter->Initialize(frameDecode, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, 0, 0.0, WICBitmapPaletteTypeCustom);
	pRT->CreateBitmapFromWicBitmap(converter, 0, &bitmap);
	converter->GetSize(Width, Height);
	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return bitmap;
}

CImage* ImageManager::AddImage(const std::string key, std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_imageList.insert(std::make_pair(key, img));
	return img;
}

CImage* ImageManager::AddTileImage(std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_tileImages.push_back(img);
	return img;
}

CImage* ImageManager::AddStructureImage(std::string key, std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_structureImages.insert(make_pair(key, img));
	return nullptr;
}

CImage* ImageManager::AddObjectImage(std::string key, std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_objectImages.insert(make_pair(key, img));
	return nullptr;
}

CImage* ImageManager::FindImage(const std::string key)
{
	auto find = m_imageList.find(key);
	if (find != m_imageList.end())
	{
		return find->second;
	}
	cout << "이미지 key 없음 : " << key << "\n";
	return nullptr;
}

vImage* ImageManager::AddImageVector(const std::string key, std::wstring path, int startIndex, int endIndex)
{
	auto find = m_vectorImageList.find(key);

	if (find == m_vectorImageList.end())
	{
		vImage* imgs = new vImage();
		for (int i = startIndex; i <= endIndex; i++)
		{
			UINT _width = 0, _height = 0;
			std::wstring _path;
			if (i < 10)
			{
				_path = path + L"0" + std::to_wstring(i).c_str() + L".png";
			}
			else
			{
				_path = path + std::to_wstring(i).c_str() + L".png";
			}

			CImage* cImage = new CImage(AddBitmap(_path, &_width, &_height), _width, _height);
			imgs->AddImage(cImage);
		}
		m_vectorImageList.insert(std::make_pair(key, imgs));
		return imgs;
	}
	return nullptr;
}

vImage* ImageManager::FindImageVector(const std::string key)
{
	auto find = m_vectorImageList.find(key);
	if (find != m_vectorImageList.end())
	{
		return find->second;
	}
	cout << "애니메이션 key 없음 : " << key << "\n";
	return nullptr;
}

vImage* ImageManager::AddImageVectorCopy(const std::string key)
{
	auto find = m_vectorImageList.find(key);
	if (find != m_vectorImageList.end())
	{
		vImage* vimg = new vImage();
		for (auto iter : find->second->GetImages())
		{
			vimg->AddImage(iter);
		}
		return vimg;
	}
	return nullptr;
}

GImage* ImageManager::AddPixelmage(string strKey, const char* fileName, int width, int height)
{
	GImage* img;
	img = new GImage;
	img->init(fileName, width, height);
	m_gimages.insert(make_pair(strKey, img));
	return img;
}

GImage* ImageManager::FindPixelImage(string strKey)
{
	auto find = m_gimages.find(strKey);
	if (find == m_gimages.end())
	{
		return nullptr;
	}
	return find->second;
}

void ImageManager::DrawCircle(float x, float y, float width)
{
	D2D1_ELLIPSE ellipse;
	ellipse.radiusX = width;
	ellipse.radiusY = width;
	ellipse.point.x = 0;
	ellipse.point.y = 0;
	D2D1_COLOR_F color;
	color.b = 255;
	color.a = 0.5f;
	color.r = 255;
	color.g = 255;

	D2D1_MATRIX_3X2_F mat;
	mat = D2D1::Matrix3x2F::Translation(x - width / 2 - camera.x, y - width / 2 - camera.y);
	pRT->SetTransform(&mat);
	pRT->CreateSolidColorBrush(color, &m_brush);

	pRT->FillEllipse(ellipse, (m_brush));
}

void ImageManager::DrawRect(RECT rt)
{
	D2D1_COLOR_F color;
	color.b = 255;
	color.a = 255;
	color.r = 255;
	color.g = 255;

	D2D1_MATRIX_3X2_F mat;
	mat = D2D1::Matrix3x2F::Translation(-camera.x, -camera.y);
	pRT->SetTransform(&mat);
	pRT->CreateSolidColorBrush(color, &m_brush);

	pRT->FillRectangle(D2D1_RECT_F{ (float)rt.left ,(float)rt.top,(float)rt.right,(float)rt.bottom }, (m_brush));
}

void ImageManager::DrawMapTile(vector<vector<int>> vec)
{
	int y1 = 0;
	int m_width = m_tileImages[0]->GetWidth();
	for (auto iter : vec)
	{
		int x = 0;
		for (auto _iter : iter)
		{
			if (_iter != -1)
				IMAGEMANAGER->Render(m_tileImages[_iter], x * (m_width - 1), y1 * (m_width - 1));
			x++;
		}
		y1++;
	}
}

void ImageManager::DrawMapStructureBack(vector<StructureData*> vec)
{
	for (auto iter : vec)
	{
		if (iter->isBack == true)
			IMAGEMANAGER->Render(m_structureImages[iter->key], iter->x, iter->y, 2, 2);
	}
}

void ImageManager::DrawMapStructureFoward(vector<StructureData*> vec)
{
	for (auto iter : vec)
	{
		if (iter->isBack == false)
			IMAGEMANAGER->Render(m_structureImages[iter->key], iter->x, iter->y, 2, 2);
	}
}

void ImageManager::DrawRectCenter(RECT rt, CImage* img)
{
	D2D1_COLOR_F color;
	color.b = 255;
	color.a = 255;
	color.r = 255;
	color.g = 255;

	D2D1_MATRIX_3X2_F mat;
	mat = D2D1::Matrix3x2F::Translation(0, 0);
	pRT->SetTransform(&mat);
	pRT->CreateSolidColorBrush(color, &m_brush);
	pRT->FillRectangle(D2D1_RECT_F{ (float)rt.left + img->GetWidth() / 2,(float)rt.top + img->GetHeight() / 2,(float)rt.right + img->GetWidth() / 2,(float)rt.bottom + img->GetHeight() / 2 }, m_brush);


}

void ImageManager::DrawMapTilePixel(vector<vector<int>> vec)
{
	int y1 = 0;
	int m_width = m_tileImages[0]->GetWidth() - 1;
	for (auto iter : vec)
	{
		int x = 0;
		for (auto _iter : iter)
		{
			if (_iter == 0 || _iter == 1 || _iter == 2 || _iter == 3 || _iter == 4 || _iter == 7 || _iter == 8 || _iter == 9 || _iter == 10 || _iter == 11 || _iter == 12 || _iter == 13 || _iter == 14 || _iter == 36 || _iter == 37)
			{
				IMAGEMANAGER->Render(FindImage("CollisionBox"), x * m_width, y1 * m_width);
			}
			else if (_iter == 19 || _iter == 18 || _iter == 17 || _iter == 16)
			{
				IMAGEMANAGER->Render(FindImage("CollisionPlatform"), x * m_width, y1 * m_width);
			}
			x++;
		}
		y1++;
	}
}

void ImageManager::DrawColorRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot, bool isReverse, D2D1_COLOR_F colr)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;

	if (isReverse == false)
	{
		matT = D2D1::Matrix3x2F::Translation((x - img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	}
	else
	{
		matT = D2D1::Matrix3x2F::Translation((x + img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(-sizeX, sizeY);
	}
	pRT->SetTransform((matS * matT * matR));
	ID2D1SolidColorBrush* color;
	pRT->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	pRT->CreateSolidColorBrush(colr, &color);

	pRT->FillOpacityMask(img->GetBitMap(), color, D2D1_OPACITY_MASK_CONTENT_GRAPHICS, D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()));

}

void ImageManager::D2dTextOut(wstring str, float x, float y)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x, y);

	pRT->SetTransform((matT));
	D2D1_RECT_F fRect;
	fRect.left = x;
	fRect.top = y;
	fRect.right = x + 1080;
	fRect.bottom = y + 1920;
	pRT->DrawTextA(str.c_str(), str.size(), tf, fRect, m_brush);
}

void ImageManager::Render(CImage* img, float x, float y, float sizeX, float sizeY, float rot) // 카메라 O
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x - camera.x, y - camera.y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x + img->GetWidth() / 2,y + img->GetHeight() / 2 });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

void ImageManager::CenterRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot, bool isReverse)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;

	if (isReverse == false)
	{
		matT = D2D1::Matrix3x2F::Translation((x - img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	}
	else
	{
		matT = D2D1::Matrix3x2F::Translation((x + img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(-sizeX, sizeY);
	}
	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

void ImageManager::UIRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot) // 카메라 X
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x, y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x ,y });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

HRESULT GImage::init(const char* fileName, float width, float height)
{
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(hInst, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	return S_OK;
}
