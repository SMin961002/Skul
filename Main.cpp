#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	SetTimer(_hWnd, 1, 1, NULL);
	TIMERMANAGER->Init();
	IMAGEMANAGER->Init();
	SCENEMANAGER->Init();
	KEYMANAGER->Init();
	

	IMAGEMANAGER->LoadImages();
}

void Main::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_F6))
	{
		SCENEMANAGER->ChangeScene("EnemyTestScene");
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F7))
	{
		SCENEMANAGER->ChangeScene("MapToolMapSelectScene");
	}
	if (KEYMANAGER->GetToggleKey(VK_F12))
	{
		IMAGEMANAGER->SetViewCollision(true);
	}
	else
	{
		IMAGEMANAGER->SetViewCollision(false);
	}
	SCENEMANAGER->Update();
	OBJECTMANAGER->Update();
	EFFECTMANAGER->Update();
}

void Main::Render()
{
	IMAGEMANAGER->Begin();
	SCENEMANAGER->Render();
	OBJECTMANAGER->Render();
	TIMERMANAGER->Render();
	EFFECTMANAGER->Render();
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
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
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
