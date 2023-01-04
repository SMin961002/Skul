#include "stdafx.h"
#include "GoldResult.h"

void GoldResult::Init()
{
	img = IMAGEMANAGER->FindImageVector("GoldResoult");
	img->Setting(0.1, true);
}

void GoldResult::Update()
{
}

void GoldResult::Render()
{
	img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
}

void GoldResult::Release()
{
}
