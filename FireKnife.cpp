#include "stdafx.h"
#include "FireKnife.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
void FireKnife::Init()
{
	collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(collision);
	img = IMAGEMANAGER->FindImage("FireKnife");
	rot = atan2(OBJECTMANAGER->m_player->GetplayerY() - 30 - m_obj->y, OBJECTMANAGER->m_player->GetplayerX() - m_obj->x);
	x = 0;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);
}

void FireKnife::Update()
{
	PixelCollisionComponent* pc = m_obj->GetComponent<PixelCollisionComponent>();
	if (pc != nullptr)
	{
		if (pc->GetIsBottomCollision() == true || pc->GetIsLeftCollision() == true || pc->GetIsRightCollision() == true || pc->GetIsTopCollision() == true)
		{
			m_obj->ObjectDestroyed();
		}
	}

	x += DELTA_TIME;
	if (x > 5)
		m_obj->ObjectDestroyed();
	collision->Setting(10, m_obj->x, m_obj->y, "fire");
	m_obj->x += cos(rot) * speed * DELTA_TIME;
	m_obj->y += sin(rot) * speed * DELTA_TIME;
}

void FireKnife::Render()
{
	IMAGEMANAGER->CenterRender(img, m_obj->x, m_obj->y, 2, 2, rot * (180 / 3.141592));
}

void FireKnife::Release()
{
}

void FireKnife::OnCollision(string collisionName, Object* other)
{
	if (other->GetName() == "player")
	{
		Player* ply = other->GetComponent<Player>();
		ply->HitPlayerMagicAttack(10);
		ply->HitPlayerEffect();
		if (OBJECTMANAGER->m_player->GetplayerX() < m_obj->x)
		{
			ply->HitPlayerKnockBack(-15, -5);
		}
		else if (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x)
		{

			ply->HitPlayerKnockBack(15, -5);

		}
		m_obj->ObjectDestroyed();
	}
}
