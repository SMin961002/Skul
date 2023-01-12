#include "stdafx.h"
#include "DivineImpact.h"
#include "Player.h"
void DivineImpact::Init()
{
	img = IMAGEMANAGER->AddImageVectorCopy("Phase2_DivineImpact_Effect");
	img->Setting(0.06, false);
	m_obj->x = OBJECTMANAGER->m_player->GetplayerX();
	m_obj->y = OBJECTMANAGER->m_player->GetplayerY();
	coll = m_obj->AddComponent<CollisionComponent>();
	coll->SetIsActive(false);
	m_obj->AddCollisionComponent(coll);
	count = 0;
}

void DivineImpact::Update()
{
	coll->Setting(30, m_obj->x, m_obj->y, "hit");
	if (img->GetFrame() == 10)
	{
		if (count == 0)
		{
			count++;
			SOUNDMANAGER->FindSound("036_Archbishop_DivineImpact_Explosion_a_v1")->Play(false);
		}
		coll->SetIsActive(true);
	}
	if (img->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
	}
}

void DivineImpact::Render()
{
	img->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0, 0);
}

void DivineImpact::Release()
{
}

void DivineImpact::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
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
