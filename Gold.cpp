#include "stdafx.h"
#include "Gold.h"
#include "CollisionComponent.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include "Player.h"
void Gold::Init()
{
	m_goldx = 0;
	m_goldy = 0;
	state = 0;
	m_goldy2 = 0;
	m_updown = 0;
	m_drop = false;
	m_vimage[eGlod] = IMAGEMANAGER->AddImageVectorCopy("Gold");
	m_vimage[eGlod]->Setting(0.1f, true);

	m_vimage[eGetgold] = IMAGEMANAGER->AddImageVectorCopy("GetGold");
	m_vimage[eGetgold]->Setting(0.05f, false);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->GetComponent<PixelCollisionComponent>()->m_isGold = true;

	//m_obj->AddComponent<CollisionComponent>();
	//m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	//m_obj->GetCollisionComponent().push_back();
	//m_obj->GetCollisionComponent().push_back(m_hitpointcollision);

	m_obj->AddComponent<RigidBodyComponent>();
	m_goldy = MY_UTILITY::getFromFloatTo(2, 5);
	m_goldx = MY_UTILITY::getFromFloatTo(-200, 300) / 100.f;
	m_goldy2 = MY_UTILITY::getFromFloatTo(15, 25);
	m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(m_goldy);
	//m_obj->GetComponent<RigidBodyComponent>()->SetGravityOngetFromIntToOff(true);

}

void Gold::Update()
{
	if (m_vimage[eGetgold]->GetIsImageEnded())
	{
		m_obj->ObjectDestroyed();
	}

	if (m_drop == true)
	{
		m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(false);
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);

		state = eGetgold;
	}
	if (m_drop == false)
	{
		state = eGlod;
	}

	if (m_updown == 2)
	{
		m_drop = true;
	}
	else
	{
		m_obj->x = m_obj->x + m_goldx;
	}

	if (m_obj->GetComponent<RigidBodyComponent>()->GetCollisionY() == true && m_updown < 2)
	{
		m_obj->y = m_obj->y - m_goldy2;
		m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(2);
		m_updown++;
	}
	else
	{
	}
}

void Gold::Render()
{
	m_vimage[state]->CenterRender(m_obj->x, m_obj->y - 4, 2, 2, 0, 1);
}

void Gold::Release()
{
	OBJECTMANAGER->m_player->goldValue += 10;
}
