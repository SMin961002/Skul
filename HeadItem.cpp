#include "stdafx.h"
#include "HeadItem.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "Player.h"
void HeadItem::Init()
{
	imgBegin[0] = IMAGEMANAGER->AddImageVectorCopy("LootGear_Lengedary_Behind_Start_");
	imgBegin[1] = IMAGEMANAGER->AddImageVectorCopy("LootGear_Legendary_Behind_Loop_");
	imgBack[0] = IMAGEMANAGER->AddImageVectorCopy("LootGear_Legendary_Front_Start_");
	imgBack[1] = IMAGEMANAGER->AddImageVectorCopy("LootGear_Legendaryr_Front_Loop_");
	imgBegin[0]->Setting(0.1, false);
	imgBegin[1]->Setting(0.1, true);
	imgBack[0]->Setting(0.1, false);
	imgBack[1]->Setting(0.1, true);
	/*
	",
	"
	",
	",
	*/
	img = IMAGEMANAGER->FindImage("GamblerHead");

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityPower(10);

	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(coll);
}

void HeadItem::Update()
{
	coll->Setting(10, m_obj->x, m_obj->y, "name");
	m_obj->y += 1;
}

void HeadItem::Render()
{
	if (m_obj->GetComponent<RigidBodyComponent>()->GetCollisionY() == true)
	{

		if (imgBack[0]->GetIsImageEnded() == false)
		{
			imgBack[0]->CenterRender(m_obj->x, m_obj->y - 290, 2, 2, 0, 0);
		}
		else
		{
			imgBack[1]->CenterRender(m_obj->x, m_obj->y - 250, 2, 2, 0, 0);
		}
	}

	IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y - 50, 2, 2, 0, 0);
	if (m_obj->GetComponent<RigidBodyComponent>()->GetCollisionY() == true)
	{
		if (imgBegin[0]->GetIsImageEnded() == false)
		{
			imgBegin[0]->CenterRender(m_obj->x, m_obj->y - 290, 2, 2, 0, 0);
		}
		else
		{
			imgBegin[1]->CenterRender(m_obj->x, m_obj->y - 290, 2, 2, 0, 0);
		}
	}
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
