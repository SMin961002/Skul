#include "stdafx.h"
#include "MenuUI.h"

MenuUI::MenuUI()
{
}

MenuUI::~MenuUI()
{
}

void MenuUI::Init()
{
	img = IMAGEMANAGER->FindImage("Pause_Frame");
	m_keyState = 0;
}

void MenuUI::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_DOWN))
	{
		if (m_keyState == 5)
			m_keyState = 0;
		else
			m_keyState++;
	}
	else if (KEYMANAGER->GetOnceKeyDown(VK_UP))
	{
		if (m_keyState == 0)
			m_keyState = 5;
		else
			m_keyState--;

	}

	if (KEYMANAGER->GetOnceKeyDown(VK_RETURN))
	{
		switch (m_keyState)
		{
		case 0:
			SCENEMANAGER->SetMenuActive(false);
			m_keyState = 0;
			break;
		case 5:
			PostMessage(_hWnd, WM_DESTROY, 0, 0);
			break;
		}
	}
}

void MenuUI::Render()
{
	IMAGEMANAGER->UICenterRender(img, WINSIZE_X / 2, WINSIZE_Y / 2 - 80, 2, 2);
	IMAGEMANAGER->D2dTextOut(L"일시정지", WINSIZE_X / 2 - 57, 110, { 176,153,137,1 });
	if (m_keyState == 0)
		IMAGEMANAGER->D2dTextOut(L"돌아가기", WINSIZE_X / 2 - 47, 173, { 176,153,137,1 }, 0.8f);
	else
		IMAGEMANAGER->D2dTextOut(L"돌아가기", WINSIZE_X / 2 - 47, 173, { 97,75,59,1 }, 0.8f);
	if (m_keyState == 1)
		IMAGEMANAGER->D2dTextOut(L"새 게임", WINSIZE_X / 2 - 38, 216, { 176,153,137,1 }, 0.8f);
	else
		IMAGEMANAGER->D2dTextOut(L"새 게임", WINSIZE_X / 2 - 38, 216, { 97,75,59,1 }, 0.8f);

	if (m_keyState == 2)
		IMAGEMANAGER->D2dTextOut(L"메인화면", WINSIZE_X / 2 - 45, 259, { 176,153,137,1 }, 0.8f);
	else
		IMAGEMANAGER->D2dTextOut(L"메인화면", WINSIZE_X / 2 - 45, 259, { 97,75,59,1 }, 0.8f);

	if (m_keyState == 3)
		IMAGEMANAGER->D2dTextOut(L"컨트롤", WINSIZE_X / 2 - 35, 302, { 176,153,137,1 }, 0.8f);
	else
		IMAGEMANAGER->D2dTextOut(L"컨트롤", WINSIZE_X / 2 - 35, 302, { 97,75,59,1 }, 0.8f);

	if (m_keyState == 4)
		IMAGEMANAGER->D2dTextOut(L"설정", WINSIZE_X / 2 - 25, 345, { 176,153,137,1 }, 0.8f);
	else
		IMAGEMANAGER->D2dTextOut(L"설정", WINSIZE_X / 2 - 25, 345, { 97,75,59,1 }, 0.8f);

	if (m_keyState == 5)
		IMAGEMANAGER->D2dTextOut(L"게임종료", WINSIZE_X / 2 - 47, 388, { 176,153,137,1 }, 0.8f);
	else
		IMAGEMANAGER->D2dTextOut(L"게임종료", WINSIZE_X / 2 - 47, 388, { 97,75,59,1 }, 0.8f);

}

void MenuUI::Release()
{
}
