#include "stdafx.h"
#include "Player.h"

void Player::Move()
{
	{
		if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
		{
			m_obj->x -= MOVE_SPEED;
		}
		if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
		{
			m_obj->x += MOVE_SPEED;
		}
		if (KEYMANAGER->GetStayKeyDown(VK_UP))
		{
			m_obj->y -= MOVE_SPEED;
		}
		if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
		{
			m_obj->y += MOVE_SPEED;
		}
	}
	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Init()
{
	img = IMAGEMANAGER->FindImageVector("Ex_Idle");
	img->Setting(3, true);
	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Update()
{
	Move();
}

void Player::Render()
{
	Draw();
}

void Player::Release()
{
}

void Player::Draw()
{//프레임 순환이 끝나면 현재 action을 idle로 바꾸고 
	img->Render(m_obj->x, m_obj->y, 1, 1, 0);
}
