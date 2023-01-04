#include "stdafx.h"
#include "RigidBodyComponent.h"

void RigidBodyComponent::Init()
{
	m_speed = 0;
	m_gravity = 9.8 * DELTA_TIME;
	cout << DELTA_TIME;
	m_isGravity = true;
	pixelCollisionComponent = m_obj->GetComponent<PixelCollisionComponent>();

	pixelCollisionComponent->RSettingRect({ 25 , -30, 30 , -15 });
	pixelCollisionComponent->LSettingRect({ -30 , -30, -25 , -15 });
	pixelCollisionComponent->TSettingRect({ -10 , -60, 10 , -55 });
	pixelCollisionComponent->BSettingRect({ -10 , -10, 10 , 1 });
}

void RigidBodyComponent::Update()
{

	if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision() == false&&
		m_obj->GetComponent<PixelCollisionComponent>()->GetIsPlatformCollision() == false)
	{
		if (m_isGravity == true)
		{
			m_speed -= m_gravity ;
			m_obj->y -= m_speed ;
		}
	}
	else
	{
		m_obj->y = m_obj->GetComponent<PixelCollisionComponent>()->GetCheckY();
		m_speed = 0;
	}

	if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsLeftCollision() == true)
	{
		m_obj->x = m_obj->GetComponent<PixelCollisionComponent>()->GetCheckX();
	}
	if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsRightCollision() == true)
	{
		m_obj->x = m_obj->GetComponent<PixelCollisionComponent>()->GetCheckX();
	}
	if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsTopCollision() == true)
	{
		m_obj->y = m_obj->GetComponent<PixelCollisionComponent>()->GetCheckY();
	}
}

void RigidBodyComponent::Render()
{
}

void RigidBodyComponent::Release()
{
}

void RigidBodyComponent::AddForce()
{

}

RigidBodyComponent::RigidBodyComponent()
{
}

RigidBodyComponent::~RigidBodyComponent()
{
}

bool RigidBodyComponent::GetCollisionY()
{
	return m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision();
}
