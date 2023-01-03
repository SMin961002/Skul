#include "stdafx.h"
#include "NpcObject.h"

NpcObject::NpcObject()
{
}

NpcObject::~NpcObject()
{
}

void NpcObject::Setting(string name)
{
	m_name = name;
	m_shopImage = IMAGEMANAGER->FindImageVector(name);
	m_shopImage->Setting(0.15f,true);
}

void NpcObject::Init()
{
}

void NpcObject::Update()
{
}

void NpcObject::Render()
{
	m_shopImage->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
}

void NpcObject::Release()
{
}
