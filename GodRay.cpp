#include "stdafx.h"
#include "Player.h"
#include "GodRay.h"

GodRay::GodRay()
{
}

GodRay::~GodRay()
{
}

void GodRay::Init()
{
	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(coll);

	isEnd = false;
	img[0] = IMAGEMANAGER->AddImageVectorCopy("GodRay_Start");
	img[0]->Setting(0.1, false);
	img[1] = IMAGEMANAGER->AddImageVectorCopy("GodRay_Loop");
	img[1]->Setting(0.1, true);
	m_state = 0;
}
#include "RigidBodyComponent.h"
void GodRay::Update()
{
	coll->Setting(100, m_obj->x + 50, m_obj->y + 100, "fasd");
	if (img[0]->GetIsImageEnded() == true)
	{
		m_state = 1;
	}
	if (isEnd == true)
	{
		OBJECTMANAGER->m_player->GetObject_()->y -= 2.5;
	}
}

void GodRay::Render()
{
	if (m_state == 0)
		img[m_state]->CenterRender(m_obj->x, m_obj->y, 1.4, 1.4, 0, 0, 1);
	else
	{
		img[m_state]->CenterRender(m_obj->x - 10, m_obj->y + 50, 1.4, 1.4, 0, 0, 1);
	}
}

void GodRay::UIRender()
{
	if (isEnd == true)
	{
		if (OBJECTMANAGER->m_player->GetplayerY() < 0)
		{
			SCENEMANAGER->FadeOutColor(0.004, []() {		SCENEMANAGER->ChangeScene("EndingScene"); }, 52193);
		}
	}
}

void GodRay::Release()
{
}

void GodRay::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		if (KEYMANAGER->GetOnceKeyDown('F'))
		{
			isEnd = true;

			other->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
		}
	}
}
