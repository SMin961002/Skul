#include "stdafx.h"
#include "ResultValue.h"
#include "CollisionComponent.h"
#include "Gold.h"

void ResultValue::Init()
{
	m_isCheck = false;
	CollisionComponent* coll = m_obj->AddComponent<CollisionComponent>();
	com = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(com);
	com->Setting(100, m_obj->x + 10, m_obj->y + 50, "sapwn");
	coll->Setting(50, m_obj->x + 10, m_obj->y + 50, "Reword");
	m_obj->AddCollisionComponent(coll);
	spanwImage = IMAGEMANAGER->AddImageVectorCopy("MapReward_Spawn");
	spanwImage->Setting(0.03, false);
	Setting();
	isTr = false;
}

void ResultValue::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_F3))
	{
		OBJECTMANAGER->AddObject("Gold", m_obj->x, m_obj->y, eItem)->AddComponent<Gold>()->Setting(10);
	}
}

void ResultValue::Render()
{
	if (GAMEMANAGER->allEnemycount <= 0 && isTr == true)
	{
		if (m_isCheck == false)
		{
			m_idleImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
			if (spanwImage->GetIsImageEnded() == false)
			{
				spanwImage->CenterRender(m_obj->x, m_obj->y - 20, 1, 0.5, 0, 0);
			}
		}
		else
		{
			if (m_activeImg->GetIsImageEnded() == false)
			{
				m_activeImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
			}
			else
			{
				Reword();
			}
		}
	}
}

void ResultValue::Release()
{
}

void ResultValue::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName() == "sapwn")
	{
		if (other->GetName() == "player")
		{
			if (GAMEMANAGER->allEnemycount <= 0)
				isTr = true;
		}
	}
	if (coll1->GetName() == "Reword")
	{
		if (KEYMANAGER->GetOnceKeyDown('F'))
		{
			if (other->GetName() == "player")
			{
				m_isCheck = true;
			}
		}
	}
}
