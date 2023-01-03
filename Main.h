#pragma once
#include "MenuUI.h"

class Main
{
private:
	MenuUI* menu = nullptr;
public:
	Main() {}
	~Main() {}
public:
	void Init();
	void Update();
	void Render();
	void Release();
	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

