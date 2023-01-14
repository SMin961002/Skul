#include "stdafx.h"
#include "PlayerEffect.h"
#include "Player.h"
#include"CSound.h"

void DoubleJumpSmoke::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("JumpSmoke");
	m_img->Setting(0.1, false);
}

void DashSmoke::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("DashSmoke");
	m_img->Setting(0.1, false);
}
 
void PlayerHit::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("PlayerHit");
	m_img->Setting(0.05, false);
}

void TeleportationToHead::Init()
{
	Effect::Init();
	SOUNDMANAGER->FindSound("SkulSkill1")->Play(false);
	m_img = IMAGEMANAGER->AddImageVectorCopy("DeadEffect");
	m_img->Setting(0.05, false);
}

void GamblerAttack_1::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_Attack1Effect");
	m_img->Setting(0.07, false);
}

void GamblerAttack_2::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_Attack2Effect");
	m_img->Setting(0.07, false);							
}

void GamblerJumpAttack::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_JumpAttackEffect");
	m_img->Setting(0.07, false);
}

void JokerExplosion::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_JockerExplosion");
	m_img->Setting(0.04, false);
}

void BlackJackJokerExplosion::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_BlackJackJokerExplosion");
	m_img->Setting(0.04, false);
}

void BlackJackSpark::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_BlackJackSpark");
	m_img->Setting(0.1, false);
}

void BlackJackSpark::Move()
{
	x = m_isReversed ? x - 500 * DELTA_TIME : x + 500 * DELTA_TIME;
}

void RouletteReady::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_RouletteEmerge");
	SOUNDMANAGER->FindSound("RouletteSummon")->Play(false);
}

void RouletteReady::Release()
{
}

void RouletteShot::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_RouletteCircle");
}

void RouletteBigShot::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_RouletteBigShotCircle");
	SOUNDMANAGER->FindSound("RouletteSpike")->Play(false);
}
void RouletteBrokenEffect::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_RouletteBroken");
	m_img->Setting(0.05, false);
}
void RouletteBrokenEffectBigShot::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_RouletteBigShotBroken");
	m_img->Setting(0.03, false);
}

void SlotMachineBigHit::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_SlotMachineBigHitEffect");
	m_img->Setting(0.03, false);
}

void SlotMachineBigHit::Move()
{
	x = OBJECTMANAGER->m_player->GetplayerX();
	y = OBJECTMANAGER->m_player->GetplayerY()-46;
}

void SlotMachineThunder::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_SlotMachine_Thunder");
	m_img->Setting(0.03, false);
	//for (int i = 0; i < 8; i++)
	//{
	//	m_img->Setting(i, 0.03);
	//}
	SOUNDMANAGER->FindSound("SlotMachineThunder")->Play(false);
}
