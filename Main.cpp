#include "stdafx.h"
#include "Main.h"
void Main::Init()
{
	srand(time(NULL));

	SetTimer(_hWnd, 1, 1, NULL);
	TIMERMANAGER->Init();
	IMAGEMANAGER->Init();
	SCENEMANAGER->Init();
	KEYMANAGER->Init();

	IMAGEMANAGER->LoadImages();
	TIMERMANAGER->Init();

	srand(GetTickCount64());

	//SCENEMANAGER->ChangeScene("EnemyTestScene");
	inven = new Inventory;
	inven->Init();
	menu = new MenuUI;
	menu->Init();

	SCENEMANAGER->ChangeScene("IntroTitleScene");
}

void Main::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_ESCAPE) && SCENEMANAGER->GetInvenActive() == false)
	{
		SCENEMANAGER->SetMenuActive(!SCENEMANAGER->GetMenuActive());
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_TAB) && SCENEMANAGER->GetMenuActive() == false)
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
