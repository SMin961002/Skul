#pragma once
class Inventory
{
public:
	CImage* image;

	Inventory();
	~Inventory();
public:
	void Init();
	void Update();
	void Render();
	void Release();
};

