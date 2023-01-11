#include "stdafx.h"
#include "Phase3B.h"
#include "Player.h"
void Phase3B::Init()
{
	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(coll);
	img = IMAGEMANAGER->AddImageVectorCopy("Phase2_Phase_3_Effect");
	img->Setting(0.05f, false);
	coll->SetIsActive(false);
}

void Phase3B::Update()
{
	if (img->GetFrame() > 20 && img->GetFrame() < 25)
	{
		coll->SetIsActive(true);
		coll->Setting(30, m_obj->x + 10, m_obj->y + 10, "coll");
	}
	else
	{
		coll->SetIsActive(false);
	}
	if (img->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
	}
}

void Phase3B::Render()
{
	img->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0, 0);
}

void Phase3B::Release()
{
}

void Phase3B::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		Player* ply = other->GetComponent<Player>();
		if (coll2->GetName() == "PlayerHitRange")
		{
			ply->HitPlayerMagicAttack(10);
			if (other->x > m_obj->x)
			{
				other->GetComponent<Player>()->HitPlayerKnockBack(25, -25);
			}
			else
			{
				other->GetComponent<Player>()->HitPlayerKnockBack(-25, -25);
			}
		}
	}
}
