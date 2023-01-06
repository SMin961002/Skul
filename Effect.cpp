#include "stdafx.h"
#include "Effect.h"

void Effect::Init()
{

}

void Effect::Update()
{
	Move();
}

void Effect::Render()
{
	m_img->CenterRender(x, y, m_scale, m_scale, 0, m_isReversed);
}

void Effect::Release()
{

}