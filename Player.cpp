#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"
void Player::Init()
{
	m_UIImage[ePlayerStatus] = IMAGEMANAGER->FindImage("PlayerStatusUI");

	m_life = 100;
	m_headList[0] = new Head_Basic;
	m_headList[0]->SetObject(m_obj);
	m_headList[0]->Init();

	m_headSlot[0] = m_headList[0];
	m_headSlot[1] = m_headList[0];
	m_nowHead = m_headSlot[0];
	
	m_artifactCoolD = 0;
	m_haveArtifact = false;

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
	
	OBJECTMANAGER->m_player = this;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	coll = m_obj->AddComponent<CollisionComponent>();
	coll->Setting(25, m_obj->x + 14, m_obj->y - 15, "PlayerHitRange");
	m_obj->AddCollisionComponent(coll);
	m_obj->AddComponent<RigidBodyComponent>();
}

void Player::Update()
{
	Vector2 v;
	//m_obj->GetCollisionComponent()->Setting(20, m_obj->x, m_obj->y);

	coll->Setting(m_obj->x+14,m_obj->y-15);
	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
	}

	InputArtifactKey();
	m_nowHead->Update();
	
	coll->SetIsActive(!m_nowHead->GetIsDashing());

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Render()
{
	m_nowHead->Render();
}

void Player::UIRender()
{
	IMAGEMANAGER->UIRender(m_UIImage[ePlayerStatus],0,430,2,2,0);
}

void Player::InputArtifactKey()
{
	if (KEYMANAGER->GetOnceKeyDown('D'))
	{

	}
}

void Player::Release()
{
	//SAFE_DELETE(*m_headList);
}

void Player::OnCollision(string collisionName, Object* other)
{
	if (collisionName == coll->GetName())
	{
		if (other->GetName() == "Enemy")
		{
			//##데미지 받기
			m_life -= 10;
			if (m_life < 0) m_life = 0;
		}
	}
}
