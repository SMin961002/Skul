#pragma once
class MenuUI
{
private:
	int m_keyState;
public:
	CImage* img;
	MenuUI();
	~MenuUI();
	void Init();
	void Update();
	void Render();
	void Release();
	bool isResetScene;
};

