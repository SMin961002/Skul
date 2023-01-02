#pragma once
#include "Component.h"

class BossObject : public Component
{
private:
	vImage* _imgBoss;
	RECT _rcBossIdle;

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
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;


	BossObject() {}
	~BossObject() {}
};

