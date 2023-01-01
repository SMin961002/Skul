#include "stdafx.h"
#include "BossObject.h"

void BossObject::Init()
{
	_imgBoss = IMAGEMANAGER->FindImageVector("Boss_Idle");
	_imgBoss->Setting(0.1, true);







	_imgBossReady = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Ready");
	_imgBossReady->Setting(0.1, true);
	_imgBossReadyLoop = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Ready_Loop");
	_imgBossReadyLoop->Setting(0.1, true);
	_imgBossAttack = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Attack");
	_imgBossAttack->Setting(0.1, true);
	_imgBossAttackLoop = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Attack_Loop");
	_imgBossAttackLoop->Setting(0.1, true);
	_imgBossEnd = IMAGEMANAGER->FindImageVector("Boss_Nervousness_End");
	_imgBossEnd->Setting(0.1, true);
	_imgEffectShine = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Attack");
	_imgEffectShine->Setting(0.1, true);
	_imgEffectImpact = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Projectile");
	_imgEffectImpact->Setting(0.1, true);

}

void BossObject::Update()
{
}

void BossObject::Render()
{
	_imgBoss->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 91.5 * 2, 2, 2, 0, false);








	//_imgBossReady->CenterRender(WINSIZE_X / 2, WINSIZE_Y - 91.5 * 2, 1, 1, 0, false);			센터점 위치
	_imgBossReady->CenterRender(100, 100, 1, 1, 0, false);
	_imgBossReadyLoop->CenterRender(300, 100, 1, 1, 0, false);
	_imgBossAttack->CenterRender(500, 100, 1, 1, 0, false);
	_imgBossAttackLoop->CenterRender(700, 100, 1, 1, 0, false);
	_imgBossEnd->CenterRender(100, 300, 1, 1, 0, false);
	_imgEffectShine->CenterRender(300, 300, 1, 1, 0, false);
	_imgEffectImpact->CenterRender(500, 300, 1, 1, 0, true);
	_imgEffectImpact->CenterRender(700, 300, 1, 1, 0, false);

}

void BossObject::Release()
{
}

