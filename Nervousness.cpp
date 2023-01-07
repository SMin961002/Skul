#include "stdafx.h"
#include "Nervousness.h"

void LeftImpact::Init()
{
	_imgPhase1NervousEffectImpactRight = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Projectile");
	_imgPhase1NervousEffectImpactRight->Setting(0.1, true);
}

void LeftImpact::Update()
{
	m_obj->x += 3;

	if (m_obj->x > WINSIZE_X + WINSIZE_X/2 - 50)
	{
		m_obj->ObjectDestroyed();
	}
}

void LeftImpact::Render()
{
	_imgPhase1NervousEffectImpactRight->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
}

void LeftImpact::Release()
{
	m_obj->ObjectDestroyed();
}

void RightImpact::Init()
{
	_imgPhase1NervousEffectImpactLeft = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Projectile");
	_imgPhase1NervousEffectImpactLeft->Setting(0.1, true);
}

void RightImpact::Update()
{
	m_obj->x -= 3;

	if (m_obj->x < -50)
	{
		m_obj->ObjectDestroyed();
	}
}

void RightImpact::Render()
{
	_imgPhase1NervousEffectImpactLeft->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, true);
}

void RightImpact::Release()
{
	m_obj->ObjectDestroyed();
}

void ImpactShine::Init()
{
	_imgPhase1NervousEffectShine = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Attack");
	_imgPhase1NervousEffectShine->Setting(0.1, false);
}

void ImpactShine::Update()
{
	if (_imgPhase1NervousEffectShine->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
		_imgPhase1NervousEffectShine->Reset();
	}
}

void ImpactShine::Render()
{
	_imgPhase1NervousEffectShine->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0, false);
}

void ImpactShine::Release()
{
	m_obj->ObjectDestroyed();
}
