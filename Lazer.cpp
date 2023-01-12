#include "stdafx.h"
#include "Lazer.h"

void Lazer::Init()
{
	img[eStart] = IMAGEMANAGER->AddImageVectorCopy("Boss_Consecration_Start");
	img[eLoop] = IMAGEMANAGER->AddImageVectorCopy("Boss_Consecration_Loop");
	img[eLast] = IMAGEMANAGER->AddImageVectorCopy("Boss_Consecration_End");
	img[eStart]->Setting(DELTA_TIME, false);
	img[eLoop]->Setting(0.06, false);
	img[eLast]->Setting(0.07, false);
	/*
	Boss_Consecration_Start
	Boss_Consecration_Sign"
	Boss_Consecration_Loop"
	Boss_Consecration_End",
	*/
	collll1 = m_obj->AddComponent<CollisionComponent>();
	collll2 = m_obj->AddComponent<CollisionComponent>();
	collll3 = m_obj->AddComponent<CollisionComponent>();
	collll4 = m_obj->AddComponent<CollisionComponent>();

	collll1->SetIsActive(false);
	collll2->SetIsActive(false);
	collll3->SetIsActive(false);
	collll4->SetIsActive(false);

	m_obj->AddCollisionComponent(collll1);
	m_obj->AddCollisionComponent(collll2);
	m_obj->AddCollisionComponent(collll3);
	m_obj->AddCollisionComponent(collll4);
	m_obj->AddCollisionComponent(collll4);
	m_obj->AddCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	m_obj->AddCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	m_obj->AddCollisionComponent(m_obj->AddComponent<CollisionComponent>());

	m_state = eStart;
	for (auto iter : m_obj->GetCollisionComponent())
	{
		iter->SetIsActive(false);
	}
}

void Lazer::Update()
{
	float xx = -400;
	for (auto iter : m_obj->GetCollisionComponent())
	{
		xx += 100;
		iter->Setting(60, m_obj->x + xx, m_obj->y, "gse");
	}
}

void Lazer::Render()
{
	if (img[eStart]->GetIsImageEnded() == true)
	{
		m_state = eLoop;
		for (auto iter : m_obj->GetCollisionComponent())
		{
			iter->SetIsActive(true);
		}
	}
	if (img[eLoop]->GetIsImageEnded() == true)
	{
		m_state = eLast;
		for (auto iter : m_obj->GetCollisionComponent())
		{
			iter->SetIsActive(false);
		}
	}
	if (img[eLast]->GetIsImageEnded() == true)
	{

		m_obj->ObjectDestroyed();
	}
	if (m_state == eLoop)
	{
		img[m_state]->CenterRender(m_obj->x + 250, m_obj->y, 1.5, 3, 90);
	}
	else if (m_state == eStart)
	{
		img[m_state]->CenterRender(m_obj->x + 250, m_obj->y, 1.5, 3, 90);
	}
	else
	{
		img[m_state]->CenterRender(m_obj->x + 250, m_obj->y, 1.5, 3, 90);
	}
}

void Lazer::Release()
{
}

#include "Player.h"
void Lazer::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		if (coll2->GetName() == "PlayerHitRange")
		{
			if (other->GetName() == "player")
			{
				Player* ply = other->GetComponent<Player>();

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
}
