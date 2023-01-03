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
}

void MenuUI::Update()
{
}

void MenuUI::Render()
{
	IMAGEMANAGER->UICenterRender(img, WINSIZE_X / 2, WINSIZE_Y / 2-100,2,2);
}

void MenuUI::Release()
{
}
