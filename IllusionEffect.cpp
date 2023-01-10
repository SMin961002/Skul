#include "stdafx.h"
#include "IllusionEffect.h"

void IllusionEffect::Init()
{
	alpha = 1;
	alphaGo = false;
	preAlphaTime = 0.2;
}

void IllusionEffect::Update()
{
	if (alphaGo == false)
	{
		if((preAlphaTime -= DELTA_TIME)<0)
		{
			alphaGo = true;
		}
	}
	if (alphaGo)
	{
		alpha -= DELTA_TIME * 2;
	}
	if (alpha <= 0)
	{
		m_obj->ObjectDestroyed();
	}
}

void IllusionEffect::Render()
{
	IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, { 0,0,0,alpha }, 2, 2, 0, isLeft);
}

void IllusionEffect::Release()
{
}
