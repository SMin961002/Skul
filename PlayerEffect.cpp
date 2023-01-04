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
