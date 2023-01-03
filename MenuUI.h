#pragma once
class MenuUI
{
public:
	CImage* img;
	MenuUI();
	~MenuUI();
	void Init();
	void Update();
	void Render();
	void Release();
};

