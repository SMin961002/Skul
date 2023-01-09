#include "stdafx.h"
#include "PlayerEffect.h"

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
	m_img = IMAGEMANAGER->AddImageVectorCopy("DeadEffect");
	m_img->Setting(0.05, false);
}

void GamblerAttack_1::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Gambler_Attack1Effect");
	m_img->Setting(0.07, false);//
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

