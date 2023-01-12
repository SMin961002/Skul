#include "stdafx.h"
#include "Main.h"
#include"CSound.h"
void Main::Init()
{
	srand(time(NULL));

	
	SetTimer(_hWnd, 1, 1, NULL);
	TIMERMANAGER->Init();
	IMAGEMANAGER->Init();
	SCENEMANAGER->Init();
	KEYMANAGER->Init();
	SOUNDMANAGER->init(_hWnd);
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
	SOUNDMANAGER->AddSound("CandleFanaticAttack","./Resources/Sound/CandleFanaticAttack.wav");
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
	SOUNDMANAGER->AddSound("EndingScene", "./Resources/Sound/EndingScene.wav")->SetVolume(50);


	IMAGEMANAGER->LoadImages();
	TIMERMANAGER->Init();

	srand(GetTickCount64());

	//SCENEMANAGER->ChangeScene("EnemyTestScene");
	inven = new Inventory;
	inven->Init();
	menu = new MenuUI;
	menu->Init();
	SOUNDMANAGER->AddSound("Dash", "./Resources/Sound/Dash.wav");
	SOUNDMANAGER->AddSound("Jump", "./Resources/Sound/Jump.wav");

	FILEMANAGER->SetNowStageFile("map_0");

	SCENEMANAGER->ChangeScene("IntroTitleScene");
}

void Main::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_ESCAPE) && SCENEMANAGER->GetInvenActive() == false && menu->isResetScene == false)
	{
		SCENEMANAGER->SetMenuActive(!SCENEMANAGER->GetMenuActive());
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_TAB) && SCENEMANAGER->GetMenuActive() == false && menu->isResetScene == false)
	{
		SCENEMANAGER->SetInvenActive(!SCENEMANAGER->GetInvenActive());
	}
	if (SCENEMANAGER->GetInvenActive() == true)
	{
		if (inven)
			inven->Update();
		g_TimeScale = 0;
	}
	else if (SCENEMANAGER->GetMenuActive() == true)
	{
		if (menu)
			menu->Update();
		g_TimeScale = 0;
	}
	else
	{
		g_TimeScale = 1;
		OBJECTMANAGER->Update();
		EFFECTMANAGER->Update();
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->ChangeScene("EndingScene");
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F5))
	{
		SCENEMANAGER->ChangeScene("ShopScene");
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F7))
	{
		SCENEMANAGER->ChangeScene("MapToolMapSelectScene");
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F8))
	{
		SCENEMANAGER->ChangeScene("BossScene");
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_F12))
	{
		IMAGEMANAGER->SetViewCollision(!IMAGEMANAGER->GetViewCollision());
	}
	SCENEMANAGER->Update();

	if (KEYMANAGER->GetOnceKeyDown(VK_TAB))
	{

	}
}

void Main::Render()
{
	IMAGEMANAGER->Begin();
	SCENEMANAGER->Render();
	OBJECTMANAGER->Render();
	//TIMERMANAGER->Render();
	EFFECTMANAGER->Render();
	OBJECTMANAGER->UIRender();
	SCENEMANAGER->UIRender();
	if (SCENEMANAGER->GetMenuActive() == true)
	{
		IMAGEMANAGER->UIRender(SCENEMANAGER->GetPadeImage(), 0, 0, 2, 2, 0, 0.5f);
		if (menu)
			menu->Render();
	}
	else if (SCENEMANAGER->GetInvenActive() == true)
	{
		IMAGEMANAGER->UIRender(SCENEMANAGER->GetPadeImage(), 0, 0, 2, 2, 0, 0.5f);
		if (inven)
			inven->Render();
	}

	if (menu->isResetScene == true)
	{
		SCENEMANAGER->FadeOut(0.03, [&]() {
			FILEMANAGER->SetNowStageFile("map_5");
			SCENEMANAGER->ChangeScene("Stage");
			menu->isResetScene = false;
			}, 51);
	}
	IMAGEMANAGER->End();
}

void Main::Release()
{
	SceneManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	TIMERMANAGER->Release();
	EffectManager::ReleaseInstance();
	TimerManager::ReleaseInstance();
	KeyManager::ReleaseInstance();
	IOFillManager::ReleaseInstance();
	CSoundMgr::ReleaseInstance();
}

LRESULT Main::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_TIMER:
		Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		this->Render();
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
