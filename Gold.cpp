#include "stdafx.h"
#include "Gold.h"
#include "CollisionComponent.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"

void Gold::Init()
{
	m_goldx = 0;
	m_goldy = 0;
	m_goldy2 = 0;
	m_updown = 0;
	m_drop = false;
	m_vimage[eGlod] = IMAGEMANAGER->AddImageVectorCopy("Gold");
	m_vimage[eGlod]->Setting(0.1f, true);

	m_vimage[eGetgold] = IMAGEMANAGER->AddImageVectorCopy("GetGold");
	m_vimage[eGetgold]->Setting(0.05f, false);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	//m_obj->AddComponent<CollisionComponent>();
	//m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	//m_obj->GetCollisionComponent().push_back();
	//m_obj->GetCollisionComponent().push_back(m_hitpointcollision);
	
	m_obj->AddComponent<RigidBodyComponent>();
	m_goldy =MY_UTILITY::getFromFloatTo(2, 5);
	m_goldx = MY_UTILITY::getFromFloatTo(-2, 3);
	m_goldy2 = MY_UTILITY::getFromFloatTo(15, 25);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityPower(m_goldy);
	//m_obj->GetComponent<RigidBodyComponent>()->SetGravityOngetFromIntToOff(true);

}

void Gold::Update()
{
	if (m_vimage[eGetgold]->GetIsImageEnded())
	{
		m_obj->ObjectDestroyed();
	}
		if (m_drop == false)
		{
			state = eGlod;
		}
		if (m_drop == true)
		{
			state = eGetgold;
		}
		if (m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() < 0)
		{

			m_obj->x = m_obj->x + m_goldx;
		}
		else if (m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() == 0 && m_updown < 2)
		{
			m_obj->y = m_obj->y - m_goldy2;
			m_updown++;
		}
		else
		{
			m_drop = true;
		}
	
}

void Gold::Render()
{	
	m_vimage[state]->CenterRender(m_obj->x, m_obj->y-4, 2, 2, 0, 1);
}

void Gold::Release()
{
}
