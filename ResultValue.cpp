#include "stdafx.h"
#include "ResultValue.h"
#include "CollisionComponent.h"
void ResultValue::Init()
{
	m_isCheck = false;
	CollisionComponent* coll = m_obj->AddComponent<CollisionComponent>();
	coll->Setting(50, m_obj->x + 10, m_obj->y + 50, "Reword");
	m_obj->AddCollisionComponent(coll);
	Setting();
}

void ResultValue::Update()
{
}

void ResultValue::Render()
{
	if (m_isCheck == false)
	{
		m_idleImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
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

void ResultValue::Release()
{
}

void ResultValue::OnCollision(string collisionName, Object* other)
{
	if (collisionName == "Reword")
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
