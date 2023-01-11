#include "stdafx.h"
#include "Thunder.h"
#include "Enemy.h"

void Thunder::Init()
{
	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(10, m_obj->x + 50, m_obj->y +5, "GamblerThunder");
}

void Thunder::Update()
{
	if (m_thunder->GetIsEnded())
		m_obj->ObjectDestroyed();
	CollisionUpdate();
}

void Thunder::Release()
{
}

void Thunder::Render()
{
}

void Thunder::CollisionUpdate()
{
	if (m_isBigHit)
	{

	}
	else
	{
		m_coll->Setting(110, m_obj->x + 55, m_obj->y + 55);
	}
}

void Thunder::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	bool hited = false;
	for (auto iter : m_CollObjList)
	{
		if (other == iter)
		{
			hited = true;
			break;
		}
	}
	if (!hited)
	{
		Enemy* e = other->GetComponent<Enemy>();
		if (e != nullptr)
		{
			e->HitEnemy(15, 0);
			m_CollObjList.push_back(other);
		}
	}
}
