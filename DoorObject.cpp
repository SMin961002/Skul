#include "stdafx.h"
#include "DoorObject.h"
#include "CollisionComponent.h"
DoorObject::DoorObject()
{
}

DoorObject::~DoorObject()
{
}

void DoorObject::Setting(int state)
{
	m_kind = state;
	m_isClear = false;
	switch (m_kind)
	{
	case eNormal:
		img = IMAGEMANAGER->FindImage("NormalRoom");
		vimg = IMAGEMANAGER->FindImageVector("NormalRoom");
		break;
	case eSkul:
		img = IMAGEMANAGER->FindImage("SkulRoom");
		vimg = IMAGEMANAGER->FindImageVector("SkulRoom");
		break;
	case eShop:
		img = IMAGEMANAGER->FindImage("ShopRoom");
		vimg = IMAGEMANAGER->FindImageVector("ShopRoom");
		break;
	case eSpdir:
		img = IMAGEMANAGER->FindImage("SpirderRoom");
		vimg = IMAGEMANAGER->FindImageVector("SpirderRoom");
		break;
	case eBoss:
		img = IMAGEMANAGER->FindImage("BossRoom");
		vimg = IMAGEMANAGER->FindImageVector("BossRoom");
		break;
	}
	vimg->Setting(0.1, true);
}

void DoorObject::Init()
{
	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
}

void DoorObject::Update()
{
	m_coll->Setting(50, m_obj->x + 20, m_obj->y + 100, "enter");
	if (OBJECTMANAGER->GetEnemyCount() == 0)
	{
		m_isClear = true;
	}
	else
	{
		m_isClear = false;
	}
}

void DoorObject::Render()
{
	if (m_isClear == false)
	{
		if(m_kind != eSpdir)
		IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, 2, 2);
		else
		{
			IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, 1, 1);

		}
	}
	else
	{
		if (m_kind != eSpdir)
		vimg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
		else
			vimg->CenterRender(m_obj->x, m_obj->y, 1.75, 1.75, 0, 0);

	}

}

void DoorObject::Release()
{

}

void DoorObject::UIRender()
{
	if (m_isChange == true)
	{
		switch (m_kind)
		{
		case eNormal:
			FILEMANAGER->SetNowStageFile("map_2");
			SCENEMANAGER->FadeOut(0.02, []() {SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		case eSkul:
			FILEMANAGER->SetNowStageFile("map_3");
			SCENEMANAGER->FadeOut(0.02, []() {SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		case eShop:
			FILEMANAGER->SetNowStageFile("Shop");
			SCENEMANAGER->FadeOut(0.02, []() {SCENEMANAGER->ChangeScene("ShopScene"); }, 2);
			break;
		case eSpdir:
			FILEMANAGER->SetNowStageFile("map_4");
			SCENEMANAGER->FadeOut(0.02, []() {SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		case eBoss:
			FILEMANAGER->SetNowStageFile("map_1");
			SCENEMANAGER->FadeOut(0.02, []() {SCENEMANAGER->ChangeScene("BossScene"); }, 2);
			break;
		}

	}
}

void DoorObject::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_coll->GetName())
	{
		if (m_isClear == true)
		{
			if (other->GetName() == "player")
			{
				if (KEYMANAGER->GetOnceKeyDown(VK_UP))
				{
					m_isChange = true;
				}
			}
		}
	}
}
