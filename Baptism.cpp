#include "stdafx.h"
#include "Baptism.h"
#include "RigidBodyComponent.h"
#include "CollisionComponent.h"

void Baptism::Init()
{
	_imgPhase1BossBaptismProjectile = IMAGEMANAGER->FindImageVector("Boss_Baptism_Projectile");
	_imgPhase1BossBaptismProjectile->Setting(0.1, true);
	_imgPhase1BossBaptismProjectileDespawn = IMAGEMANAGER->FindImageVector("Boss_Baptism_Projectile_Dewspawn");
	_imgPhase1BossBaptismProjectileDespawn->Setting(0.1, false);

	_angle = MY_UTILITY::getFromIntTo(PI,PI*2);

	//_collision = m_obj->AddComponent<CollisionComponent>();
	//m_obj->AddCollisionComponent(_collision);
	//m_obj->AddComponent<PixelCollisionComponent>();
	//m_obj->AddComponent<RigidBodyComponent>();
	//
	//_collision->Setting(20, m_obj->x, m_obj->y, "BaptismCollision");
	//_collision->SetIsActive(false);
}

void Baptism::Update()
{
	//m_obj->x = MY_UTILITY::getFromIntTo(0, 1000);
	//m_obj->x -= cosf((m_obj->x - 90) * PI / 180.f) * 200;
}

void Baptism::Render()
{
	_imgPhase1BossBaptismProjectile->CenterRender(m_obj->x, m_obj->y, 1, 1, 0, false);
}

void Baptism::Release()
{
	if (m_obj->y > 1000)
	{
		m_obj->ObjectDestroyed();
	}
}
