#pragma once
#include "Component.h"

class Nervousness : public Component
{
private:
public:
	void Init();
	void Update();
	void Render();
	void Release();

	Nervousness() {}
	~Nervousness() {}
};