#include "stdafx.h"
#include "Nervousness.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "CSound.h"

void LeftImpact::Init()
{
	_imgPhase1NervousEffectImpactRight = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Projectile");
	_imgPhase1NervousEffectImpactRight->Setting(0.1, true);
	SOUNDMANAGER->FindSound("Nervousnessvoice")->Play(false);
	SOUNDMANAGER->FindSound("Nervousness")->Play(false);

	_collisionLeft = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collisionLeft);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);

}

void LeftImpact::Update()
{
	m_obj->x += 3;

	if (m_obj->x > WINSIZE_X + WINSIZE_X/2 - 50)
	{
		m_obj->ObjectDestroyed();
	}
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);

	_collisionLeft->Setting(80, m_obj->x+40, m_obj->y+60, "Attack");
}

void LeftImpact::Render()
{
	_imgPhase1NervousEffectImpactRight->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, false);
}

void LeftImpact::Release()
{
	m_obj->ObjectDestroyed();
}

void LeftImpact::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		Player* player = other->GetComponent<Player>();
		player->HitPlayerMagicAttack(10);
		player->HitPlayerEffect();
		if (OBJECTMANAGER->m_player->GetplayerX() < m_obj->x)
		{
			player->HitPlayerKnockBack(-15, -5);
		}
		else if (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x)
		{
			player->HitPlayerKnockBack(-15, -5);
		}
	}
}

void RightImpact::Init()
{
	_imgPhase1NervousEffectImpactLeft = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Projectile");
	_imgPhase1NervousEffectImpactLeft->Setting(0.1, true);

	_collisionRight = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collisionRight);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);

}

void RightImpact::Update()
{
	m_obj->x -= 3;

	if (m_obj->x < -50)
	{
		m_obj->ObjectDestroyed();
	}

	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);

	_collisionRight->Setting(80, m_obj->x + 40, m_obj->y + 60, "Attack");
}

void RightImpact::Render()
{
	_imgPhase1NervousEffectImpactLeft->CenterRender(m_obj->x, m_obj->y, 1.8, 1.8, 0, true);
}

void RightImpact::Release()
{
	m_obj->ObjectDestroyed();
}

void RightImpact::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		Player* player = other->GetComponent<Player>();
		player->HitPlayerMagicAttack(10);
		player->HitPlayerEffect();
		if (OBJECTMANAGER->m_player->GetplayerX() < m_obj->x)
		{
			player->HitPlayerKnockBack(-15, -5);
		}
		else if (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x)
		{
			player->HitPlayerKnockBack(-15, -5);
		}
	}
}

void ImpactShine::Init()
{
	_imgPhase1NervousEffectShine = IMAGEMANAGER->FindImageVector("Boss_Nervousness_Effect_Attack");
	_imgPhase1NervousEffectShine->Setting(0.1, false);
}

void ImpactShine::Update()
{
	if (_imgPhase1NervousEffectShine->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
		_imgPhase1NervousEffectShine->Reset();
	}
}

void ImpactShine::Render()
{
	_imgPhase1NervousEffectShine->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0, false);
}

void ImpactShine::Release()
{
	m_obj->ObjectDestroyed();
}

