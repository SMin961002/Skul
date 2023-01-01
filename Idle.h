#pragma once

class Idle
{
	vImage* _imgBoss;
	RECT _rcBoss;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	Idle() {}
	~Idle() {}
};

