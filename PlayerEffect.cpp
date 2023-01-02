#include "stdafx.h"
#include "PlayerEffect.h"

void DoubleJumpSmoke::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->FindImageVector("JumpSmoke");
	m_img->Setting(0.1, false);
}

void DashSmoke::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->FindImageVector("DashSmoke");
	m_img->Setting(0.1, false);
}