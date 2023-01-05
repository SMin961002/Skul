#include "stdafx.h"
#include "BlackRock.h"
#include "CollisionComponent.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"

void BlackRock::Init()
{
	m_rockx = 0;
	m_rocky = 0;
	state = 0;
	m_rocky2 = 0;
	m_updown = 0;
	m_drop = false;
	m_vimage[eBlackRock] = IMAGEMANAGER->AddImageVectorCopy("BlackRock");
	m_vimage[eBlackRock]->Setting(0.1f, true);

	m_vimage[eGetBlackRock] = IMAGEMANAGER->AddImageVectorCopy("GetBlackRock");
	m_vimage[eGetBlackRock]->Setting(0.05f, false);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->GetComponent<PixelCollisionComponent>()->m_isGold = true;

	//m_obj->AddComponent<CollisionComponent>();
	//m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	//m_obj->GetCollisionComponent().push_back();
	//m_obj->GetCollisionComponent().push_back(m_hitpointcollision);

	m_obj->AddComponent<RigidBodyComponent>();
	m_rocky = MY_UTILITY::getFromFloatTo(3, 6);
	m_rockx = MY_UTILITY::getFromFloatTo(-200, 300) / 100.f;
	m_rocky2 = MY_UTILITY::getFromFloatTo(15, 25);
	m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(m_rocky);
	//m_obj->GetComponent<RigidBodyComponent>()->SetGravityOngetFromIntToOff(true);
}

void BlackRock::Update()
{
	if (m_vimage[eBlackRock]->GetIsImageEnded())
	{
		m_obj->ObjectDestroyed();
	}

	if (m_drop == true)
	{
		m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(false);
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);

		state = eGetBlackRock;
	}
	if (m_drop == false)
	{
		state = eBlackRock;
	}

	if (m_updown == 2)
	{
		m_drop = true;
	}
	else
	{
		m_obj->x = m_obj->x + m_rockx;
	}

	if (m_obj->GetComponent<RigidBodyComponent>()->GetCollisionY() == true && m_updown < 2)
	{
		m_obj->y = m_obj->y - m_rocky2;
		m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(2);
		m_updown++;
	}
	else
	{
	}
}

void BlackRock::Render()
{
	m_vimage[state]->CenterRender(m_obj->x, m_obj->y - 4, 2, 2, 0, 1);
}

void BlackRock::Release()
{
}
