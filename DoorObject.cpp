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
	if (KEYMANAGER->GetToggleKey(VK_F11))
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
		IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, 2, 2);
	}
	else
	{
		vimg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
	}

}

void DoorObject::Release()
{
}

void DoorObject::UIRender()
{
	if (m_isChange == true)
	{
		SCENEMANAGER->FadeOut(0.02, []() {SCENEMANAGER->ChangeScene("EnemyTestScene"); }, 2);
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
