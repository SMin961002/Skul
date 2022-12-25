#include "stdafx.h"
#include "Player.h"

void Player::move()
{
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_obj->x -= 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_obj->x += 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_UP))
	{
		m_obj->y -= 3;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_obj->y += 3;
	}

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Init()
{
	m_isReverse = false;
	img = IMAGEMANAGER->FindImageVector("Ex_Idle");
	img->Setting(3, true);
	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };

}

void Player::Update()
{
	if (KEYMANAGER->GetOnceKeyDown(VK_F1))
	{
		m_isReverse = !m_isReverse;
	}

	move();
}

void Player::Render()
{
	draw();
}

void Player::Release()
{
}

void Player::draw()
{
	img->Render(m_obj->x, m_obj->y, 1, 1, 0);
	img->CenterRender(m_obj->x, m_obj->y, 1, 1, 0,m_isReverse);
}
