#include "stdafx.h"
#include "Phase3B.h"

void Phase3B::Init()
{
	img = IMAGEMANAGER->AddImageVectorCopy("Phase2_Phase_3_Effect");
	img->Setting(0.05f, false);
}

void Phase3B::Update()
{
	if (img->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
	}
}

void Phase3B::Render()
{
	img->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0, 0);
}

void Phase3B::Release()
{
}
