#include "stdafx.h"
#include "Player.h"
#include "PixelCollisionComponent.h"

void Player::Init()
{
	m_life = 100;
	m_headList[0] = new Head_Basic;
	m_headList[0]->SetObject(m_obj);
	m_headList[0]->Init();

	m_headSlot[0] = m_headList[0];
	m_headSlot[1] = m_headList[0];

	m_nowHead = m_headSlot[0];

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };

	m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());

	m_obj->AddComponent<PixelCollisionComponent>();
	m_obj->GetComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles,&m_obj->x, &m_obj->y);
}

void Player::Update()
{
	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
	}
	IMAGEMANAGER->SetCameraPosition(m_obj->x - WINSIZE_X / 2, m_obj->y - 150);
	m_obj->GetCollisionComponent()->Setting(20, m_obj->x, m_obj->y);

	m_nowHead->Update();
	InputAttackKey();

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Render()
{
	m_nowHead->Render();
}

void Player::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('D'))
	{

	}
}

void Player::Release()
{
}

void Player::OnCollision(Object* other)
{
	if (other->GetName() == "Enemy")
	{
		m_life -= 5;
	}
}
