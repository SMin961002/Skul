#include "stdafx.h"
#include"CSound.h"
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
	case eNormal2:
		img = IMAGEMANAGER->FindImage("NormalRoom");
		vimg = IMAGEMANAGER->FindImageVector("NormalRoom");
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
	if (GAMEMANAGER->enemyCount == 0)
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
		if (m_kind != eSpdir)
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
	//BackgroundMusic->Stop();
	//SAFE_DELETE(BackgroundMusic);
}

void DoorObject::UIRender()
{
	if (m_isChange == true)
	{
		switch (m_kind)
		{
		case eNormal:
			SCENEMANAGER->FadeOut(0.02, []() {
				FILEMANAGER->SetNowStageFile("map_2");
				SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		case eSkul:

			SCENEMANAGER->FadeOut(0.02, []() {
				FILEMANAGER->SetNowStageFile("map_3");
				SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		case eShop:

			SCENEMANAGER->FadeOut(0.02, []() {
				FILEMANAGER->SetNowStageFile("Shop");
				SCENEMANAGER->ChangeScene("ShopScene"); }, 2);
			break;
		case eSpdir:

			SCENEMANAGER->FadeOut(0.02, []() {
				FILEMANAGER->SetNowStageFile("map_4");
				SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		case eBoss:
			SCENEMANAGER->FadeOut(0.02, []() {
				FILEMANAGER->SetNowStageFile("map_1");
				SCENEMANAGER->ChangeScene("BossScene"); }, 2);
		case eNormal2:
			SCENEMANAGER->FadeOut(0.02, []() {
				FILEMANAGER->SetNowStageFile("map_6");
			SCENEMANAGER->ChangeScene("Stage"); }, 2);
			break;
		}

	}
}

void DoorObject::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName() == m_coll->GetName())
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
