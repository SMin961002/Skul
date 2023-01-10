#include "stdafx.h"
#include "HitDamageEffect.h"

void HitDamageEffect::Init()
{
}

void HitDamageEffect::Update()
{
}

void HitDamageEffect::Render()
{
	rot += 0.1;

	m_obj->y -= cos(rot)*2;
	if (rot > 3.141592)
	{
		m_obj->ObjectDestroyed();
	}
	IMAGEMANAGER->D2dTextOut(to_wstring((int)Dmg), m_obj->x - IMAGEMANAGER->GetCameraPosition().x, m_obj->y - IMAGEMANAGER->GetCameraPosition().y, { 255,255,255, 1 }, 0.7f);
}

void HitDamageEffect::Release()
{
}

void HitDamageEffect::Setting(float dmg)
{
	Dmg = dmg;
}
