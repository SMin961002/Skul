#include "stdafx.h"
#include "Item.h"
#include"RigidBodyComponent.h"

void Item::Init()
{
	OBJECTMANAGER->m_item = this;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
}

void Item::Update()
{
}

void Item::Render()
{
}

void Item::Release()
{
}
