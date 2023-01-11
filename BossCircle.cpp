#include "stdafx.h"
#include "BossCircle.h"
#include "Player.h"

void BossCircle::Init()
{
	cicle = 0;
	img[eCreate] = IMAGEMANAGER->AddImageVectorCopy("Circle");
	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("CircleIdle");
	img[eDis] = IMAGEMANAGER->AddImageVectorCopy("CircleDis");

	img[eCreate]->Setting(0.1, false);
	img[eIdle]->Setting(0.1, false);
	img[eDis]->Setting(0.1f, false);
	m_state = eCreate;
	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(coll);
	hitcoll = 0;
}

void BossCircle::Update()
{
	hitcoll += DELTA_TIME;
	coll->Setting(50, m_obj->x, m_obj->y);
	if (img[eCreate]->GetIsImageEnded() == true)
	{
		m_state = eIdle;

	}
	if (m_state == eIdle)
	{
		float rot = atan2(OBJECTMANAGER->m_player->GetplayerY() - m_obj->y, OBJECTMANAGER->m_player->GetplayerX() - m_obj->x);
		m_obj->x += cos(rot) * 50 * DELTA_TIME;
		m_obj->y += sin(rot) * 50 * DELTA_TIME;
	}
	if (cicle > 2)
	{
		m_state = eDis;
		if (img[eDis]->GetIsImageEnded() == true)
		{
			m_obj->ObjectDestroyed();
		}
	}
	else if (img[eIdle]->GetIsImageEnded() == true)
	{
		cicle++;
		img[eIdle]->Reset();

	}
}

void BossCircle::Render()
{
	img[m_state]->CenterRender(m_obj->x, m_obj->y, 1.5f, 1.5f, 0, 0);
}

void BossCircle::Release()
{
}

void BossCircle::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
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
