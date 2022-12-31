#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"

void Player::Init()
{
	m_life = 100;
	m_headList[0] = new Head_Basic;
	m_headList[0]->SetObject(m_obj);
	m_headList[0]->Init();

	m_headSlot[0] = m_headList[0];
	m_headSlot[1] = m_headList[0];
	OBJECTMANAGER->m_player = this;
	m_nowHead = m_headSlot[0];

	m_artifactCoolD = 0;
	m_haveArtifact = false;

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };

	//m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->GetCollisionComponent().push_back(coll);

	m_obj->AddCollisionComponent(coll);
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddComponent<RigidBodyComponent>();	
}

void Player::Update()
{
	Vector2 v;
	//m_obj->GetCollisionComponent()->Setting(20, m_obj->x, m_obj->y);
	MY_UTILITY::GetLerpVec2(&v, { m_obj->x - WINSIZE_X / 2,m_obj->y - 400 }, { IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y }, 0.5);
	IMAGEMANAGER->SetCameraPosition(v.x, v.y);

	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
	}

	m_nowHead->Update();
	InputArtifactKey();
	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Render()
{
	m_nowHead->Render();
}

void Player::InputArtifactKey()
{
	if (KEYMANAGER->GetOnceKeyDown('D'))
	{

	}
}

void Player::Release()
{
	SAFE_DELETE(*m_headList);
}

void Player::OnCollision(string collisionName, Object* other)
{
	if (collisionName == coll->GetName())
	{
		if (other->GetName() == "Enemy")
		{

		}
	}
}
