#include "stdafx.h"
#include "HeadItem.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "Player.h"
void HeadItem::Init()
{
	img = IMAGEMANAGER->FindImage("GamblerHead");

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityPower(10);

	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(coll);
}

void HeadItem::Update()
{
	coll->Setting(10, m_obj->x, m_obj->y, "name");
}

void HeadItem::Render()
{
	IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, 2, 2, 0, 0);
}

void HeadItem::Release()
{
}

void HeadItem::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		if (KEYMANAGER->GetOnceKeyDown('F'))
		{
			other->GetComponent<Player>()->isHeadCheck = true;
			m_obj->ObjectDestroyed();
		}
	}
}
