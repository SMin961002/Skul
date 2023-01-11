#include "stdafx.h"
#include "Hporb.h"
#include "CollisionComponent.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include"Player.h"

void Hporb::Init()
{
	m_rotation = 0;
	m_uphightimer = 0;
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Hporb");
	m_vimage[eIdle]->Setting(0.1f, true);
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(7);
	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_obj->GetCollisionComponent().push_back(m_collision);
	m_obj->AddCollisionComponent(m_collision);
}

void Hporb::Update()
{
	m_collision->Setting(12, m_obj->x + 5, m_obj->y, "Hpup");
	m_uphightimer += DELTA_TIME;


	if (m_uphightimer >= 1.48f)
	{
		m_obj->y += sinf(m_rotation) * 0.2f;
		m_rotation += 0.01;
		m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(1);
		m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(false);

	}
}

void Hporb::Render()
{
	m_vimage[eIdle]->CenterRender(m_obj->x, m_obj->y - 4, 2, 2, 0, 1);
}

void Hporb::Release()
{
}

void Hporb::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			other->GetComponent<Player>()->Heal();
			//other->GetComponent<Player>()-플레이어 상태쉉
			//other->GetComponent<Player>()->
			m_obj->ObjectDestroyed();
		}
	}
}
