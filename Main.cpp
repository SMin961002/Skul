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
	SOUNDMANAGER->FindSound("Middle")->SetVolume(60);
	SOUNDMANAGER->AddSound("Bossphase1", "./Resources/Sound/Bossphase1.wav");
	SOUNDMANAGER->FindSound("Bossphase1")->SetVolume(60);
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

	SOUNDMANAGER->AddSound("GamblerBigHit", "./Resources/Sound/Gambler_BigHit.wav")->SetVolume(100);
	SOUNDMANAGER->AddSound("SlotMachineStart", "./Resources/Sound/Gambler_SlotMachine_Start.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineRunning", "./Resources/Sound/Gambler_SlotMachine.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineJackpot", "./Resources/Sound/Gambler_SlotMachine_Jackpot.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineFinish", "./Resources/Sound/Gambler_SlotMachine_Finish.wav")->SetVolume(50);
	SOUNDMANAGER->AddSound("SlotMachineExplosion", "./Resources/Sound/Gambler_SlotMachine_Explosion.wav")->SetVolume(80);
	SOUNDMANAGER->AddSound("SlotMachineExplosion3", "./Resources/Sound/Gambler_SlotMachine_Explosion3.wav")->SetVolume(80);


	IMAGEMANAGER->LoadImages();
	TIMERMANAGER->Init();

	srand(GetTickCount64());

	//SCENEMANAGER->ChangeScene("EnemyTestScene");
	inven = new Inventory;
	inven->Init();
	menu = new MenuUI;
	menu->Init();
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
	if (KEYMANAGER->GetOnceKeyDown(VK_F9))
	{
		SCENEMANAGER->ChangeScene("Stage");
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
