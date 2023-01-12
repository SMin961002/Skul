// Project9.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Main.h"

Main mg;
int countS = 0;


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

#if defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(7053);
#endif

	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	WNDCLASS wcex;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = WIN_NAME;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wcex);
	_hWnd = CreateWindow(WIN_NAME, WIN_NAME, WS_OVERLAPPEDWINDOW, 0, 0, WINSIZE_X, WINSIZE_Y, GetDesktopWindow(), (HMENU)NULL, hInstance, NULL);

	mg.Init();

	MSG msg;

	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(_hWnd, nCmdShow);
	UpdateWindow(_hWnd);

	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			TIMERMANAGER->Update(60.f);
			mg.Update();
			mg.Render();
		}
	}
	mg.Release();
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return mg.WndProc(hWnd, message, wParam, lParam);
}

//미사일 충돌처리
//내가발사한 미사일로 적제거