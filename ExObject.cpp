#include "stdafx.h"
#include "ExObject.h"

void ExObject::Init()
{
	img = IMAGEMANAGER->FindImageVector("Ex_Idle");
	img->Setting(3, true);
	
	
}

void ExObject::Update()
{
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_obj->x -= 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_obj->x += 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_UP))
	{
		m_obj->y -= 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_obj->y += 3;
	}
}

void ExObject::Render()
{
	img->Render(m_obj->x, m_obj->y, 1, 1, 0);
}

void ExObject::Release()
{
}
