#include "stdafx.h"
#include "ProjectileHeadSkull.h"
#include "CollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"
#include "Head_Basic.h"
#include "Player.h"
void ProjectileHeadSkull::SetSkullThrow(float x, float y, bool reversed)
{
	m_hit = false;
	m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
	m_colHeadSkull->SetIsActive(true);
	m_isReverse = reversed;
	m_obj->x = m_startX = reversed ? x - 54 : x + 54;
	m_obj->y = m_startY = y - 50;

	m_rot = 0;
}

void ProjectileHeadSkull::Init()
{
	m_img = IMAGEMANAGER->FindImage("Basic_Skull");
	m_isReverse = false;
	m_hit = false;
	m_speed = 10;
	m_rot = 0;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
	m_colHeadSkull = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_colHeadSkull);
	m_colHeadSkull->Setting(15, m_obj->x+2, m_obj->y-10, "ThrowHeadSkull");
	m_colHeadSkull->SetIsActive(false);
}

void ProjectileHeadSkull::Update()
{
	if (!m_hit)
	{
		if (m_isReverse)
		{
			m_obj->x -= 600 * DELTA_TIME;
			m_rot += 20;

			if (m_startX - m_obj->x > 400 || m_obj->GetComponent<PixelCollisionComponent>()->GetIsLeftCollision())
			{
				m_hit = true;
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			}
		}
		else
		{
			m_obj->x += 600 * DELTA_TIME;
			m_rot -= 20;

			if (m_obj->x - m_startX > 400 || m_obj->GetComponent<PixelCollisionComponent>()->GetIsRightCollision())
			{
				m_hit = true;
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			}
		}
	}//end nonhit
	m_colHeadSkull->Setting(m_obj->x + 8, m_obj->y);
}//end update

void ProjectileHeadSkull::Render()
{
	IMAGEMANAGER->CenterRender(m_img, m_obj->x, m_obj->y - 10, 2, 2, m_rot, m_isReverse);
}

void ProjectileHeadSkull::Off()
{
	m_obj->GetComponent<CollisionComponent>()->SetIsActive(false);
	m_obj->GetComponent<ProjectileHeadSkull>()->SetIsActive(false);
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(false);
}

void ProjectileHeadSkull::On()
{
	m_obj->GetComponent<CollisionComponent>()->SetIsActive(true);
	m_obj->GetComponent<ProjectileHeadSkull>()->SetIsActive(true);
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);
}

void ProjectileHeadSkull::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_colHeadSkull->GetName())
	{
		if (!m_hit)
		{
			if (other->GetName() == "Enemy")
			{
				m_hit = true;
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
				other->GetComponent<Enemy>()->HitEnemy(20);
			}
		}//end nonhit
		if (other->GetName() == "player")
		{
			//if (other->GetName() == "player")
			// {
			Head_Basic* head;
			head = dynamic_cast<Head_Basic*>(other->GetComponent<Player>()->GetNowHead());
			head->PutOnHead();
			Off();
			//m_colHeadSkull->SetIsActive(false);
		}
	}
}