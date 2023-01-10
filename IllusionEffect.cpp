#include "stdafx.h"
#include "IllusionEffect.h"

void IllusionEffect::Init()
{
	alpha = 1;
}

void IllusionEffect::Update()
{
	if (alpha <= 0)
	{
		m_obj->ObjectDestroyed();
	}
}

void IllusionEffect::Render()
{
	alpha -= DELTA_TIME * 2;
	IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, { 0,0,0,alpha }, 2, 2, 0, isLeft);
}

void IllusionEffect::Release()
{
}
