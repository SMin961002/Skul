#include "stdafx.h"
#include "Fountain.h"

void Fountain::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("Fountain");
	_img->Setting(0.1f, true);
}

void Fountain::Update()
{
}

void Fountain::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void Fountain::Release()
{
}
