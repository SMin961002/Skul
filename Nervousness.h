#pragma once
#include "Component.h"

class Nervousness : public Component
{
private:
	vImage* _imgBossReady;
	vImage* _imgBossReadyLoop;
	vImage* _imgBossAttack;
	vImage* _imgBossAttackLoop;
	vImage* _imgBossEnd;
	vImage* _imgEffectShine;
	vImage* _imgEffectImpact;

	RECT _rcBoss;
	RECT _rcEffectLeft;
	RECT _rcEffectRight;
public:
	void Init();
	void Update();
	void Render();
	void Release();

	Nervousness() {}
	~Nervousness() {}
};