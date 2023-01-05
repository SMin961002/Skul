#include"stdafx.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"

void PixelCollisionComponent::Init()
{
	m_isCheck = false;
	m_image = IMAGEMANAGER->FindPixelImage("CollisionBox");
	m_imagePlatform = IMAGEMANAGER->FindPixelImage("CollisionPlatform");
	m_checkY = 0;
	m_checkX = 0;
	m_isLeftCheck = false;
	m_isRightCheck = false;
	m_isBottomCheck = false;
	m_isTopCheck = false;
	m_isGold = false;
	m_platformCheck = false;
}

void PixelCollisionComponent::Update()
{
	m_platformCheck = false;
	m_isCheck = false;
	m_isLeftCheck = false;
	m_isRightCheck = false;
	m_isBottomCheck = false;
	m_isTopCheck = false;

	if (m_isGold == false)
	{
		LeftCollision();
		RightCollision();
		TopCollision();
	}

	BottomCollision();
}

void PixelCollisionComponent::Render()
{
	if (IMAGEMANAGER->GetViewCollision())
	{
		IMAGEMANAGER->DrawRect({ (int)*x + rtL.left,(int)*y + rtL.top,(int)*x + rtL.right,(int)*y + rtL.bottom });
		IMAGEMANAGER->DrawRect({ (int)*x + rtR.left,(int)*y + rtR.top,(int)*x + rtR.right,(int)*y + rtR.bottom });
		IMAGEMANAGER->DrawRect({ (int)*x + rtB.left,(int)*y + rtB.top,(int)*x + rtB.right,(int)*y + rtB.bottom });
		IMAGEMANAGER->DrawRect({ (int)*x + rtT.left,(int)*y + rtT.top,(int)*x + rtT.right,(int)*y + rtT.bottom });
	}
}

void PixelCollisionComponent::Release()
{
	for (auto iter : m_tiles)
	{
		iter.clear();
	}
	m_tiles.clear();
}

void PixelCollisionComponent::setting(vector<vector<int>> tiles, float* x, float* y)
{
	m_tiles = tiles;
	this->x = x;
	this->y = y;
	for (auto iter : tiles)
	{
		iter.clear();
	}
	tiles.clear();
}

void PixelCollisionComponent::BottomCollision()
{
	PixcelCollision((*x + rtB.left) / (m_image->GetWidth() - 1), (*y + rtB.bottom) / (m_image->GetHight() - 1), true, "B");
	if (m_isBottomCheck == false)
		PixcelCollision((*x + rtB.right) / (m_image->GetWidth() - 1), (*y + rtB.bottom) / (m_image->GetHight() - 1), true, "B");
	if (m_isBottomCheck == false)
		PixcelCollision((*x + rtB.left) / (m_image->GetWidth() - 1), (*y + rtB.top) / (m_image->GetHight() - 1), false, "B");
	if (m_isBottomCheck == false)
		PixcelCollision((*x + rtB.right) / (m_image->GetWidth() - 1), (*y + rtB.top) / (m_image->GetHight() - 1), false, "B");
}

void PixelCollisionComponent::TopCollision()
{
	PixcelCollision((*x + rtT.left) / (m_image->GetWidth() - 1), (*y + rtT.top) / (m_image->GetHight() - 1), &m_isBottomCheck, "T");
	if (m_isBottomCheck == false)
		PixcelCollision((*x + rtT.right) / (m_image->GetWidth() - 1), (*y + rtT.top) / (m_image->GetHight() - 1), &m_isBottomCheck, "T");
	if (m_isBottomCheck == false)
		PixcelCollision((*x + rtT.left) / (m_image->GetWidth() - 1), (*y + rtT.bottom) / (m_image->GetHight() - 1), &m_isBottomCheck, "T");
	if (m_isBottomCheck == false)
		PixcelCollision((*x + rtT.right) / (m_image->GetWidth() - 1), (*y + rtT.bottom) / (m_image->GetHight() - 1), &m_isBottomCheck, "T");
}

void PixelCollisionComponent::LeftCollision()
{
	PixcelCollision((*x + rtL.left) / (m_image->GetWidth() - 1), (*y + rtL.bottom) / (m_image->GetHight() - 1), &m_isBottomCheck, "L");
	if (m_isLeftCheck == false)
		PixcelCollision((*x + rtL.left) / (m_image->GetWidth() - 1), (*y + rtL.top) / (m_image->GetHight() - 1), &m_isBottomCheck, "L");
	if (m_isLeftCheck == false)
		PixcelCollision((*x + rtL.right) / (m_image->GetWidth() - 1), (*y + rtL.bottom) / (m_image->GetHight() - 1), &m_isBottomCheck, "L");
	if (m_isLeftCheck == false)
		PixcelCollision((*x + rtL.right) / (m_image->GetWidth() - 1), (*y + rtL.top) / (m_image->GetHight() - 1), &m_isBottomCheck, "L");
}

void PixelCollisionComponent::RightCollision()
{
	PixcelCollision((*x + rtR.right) / (m_image->GetWidth() - 1), (*y + rtR.bottom) / (m_image->GetHight() - 1), &m_isBottomCheck, "R");
	if (m_isRightCheck == false)
		PixcelCollision((*x + rtR.right) / (m_image->GetWidth() - 1), (*y + rtR.top) / (m_image->GetHight() - 1), &m_isBottomCheck, "R");
	if (m_isRightCheck == false)
		PixcelCollision((*x + rtR.left) / (m_image->GetWidth() - 1), (*y + rtR.top) / (m_image->GetHight() - 1), &m_isBottomCheck, "R");
	if (m_isRightCheck == false)
		PixcelCollision((*x + rtR.left) / (m_image->GetWidth() - 1), (*y + rtR.bottom) / (m_image->GetHight() - 1), &m_isBottomCheck, "R");
}

void PixelCollisionComponent::PixcelCollision(float w, float h, bool isCheck, string dir)
{
	if (w < 0 || w >= m_tiles[0].size())
	{
		return;
	}
	if (h < 0 || h >= m_tiles.size())
	{
		return;
	}
	if (m_tiles[h][w] == 0 || m_tiles[h][w] == 1 || m_tiles[h][w] == 2 || m_tiles[h][w] == 3 || m_tiles[h][w] == 4 || m_tiles[h][w] == 7 || m_tiles[h][w] == 8 || m_tiles[h][w] == 9 || m_tiles[h][w] == 10 || m_tiles[h][w] == 11 || m_tiles[h][w] == 12 || m_tiles[h][w] == 13 || m_tiles[h][w] == 14 || m_tiles[h][w] == 36 || m_tiles[h][w] == 37 || m_tiles[h][w] == 38 || m_tiles[h][w] == 39 || m_tiles[h][w] == 40 || m_tiles[h][w] == 41 || m_tiles[h][w] == 42 || m_tiles[h][w] == 43)
	{
		float _x = int(*x) % int(m_image->GetWidth() - 1);
		float _y = int(*y) % int(m_image->GetHight() - 1);
		if (_x >= 0 && _x <= m_image->GetWidth() - 1 && _y >= 0 && _y <= m_image->GetHight() - 1)
		{
			COLORREF color = m_image->pixel[(int)_x][(int)_y];
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);
			if (r == 255 && g == 0 && b == 255)
			{
				if (dir == "B")
				{
					m_checkY = *y - _y;
					m_isBottomCheck = true;
				}
				else if (dir == "T")
				{
					m_checkY = *y + (m_image->GetHight() - _y);
					m_isTopCheck = true;
				}
				else if (dir == "R")
				{
					m_checkX = *x - _x;
					m_isRightCheck = true;
				}
				else if (dir == "L")
				{
					m_checkX = *x + (m_image->GetWidth() - _x);
					m_isLeftCheck = true;
				}
			}
		}
	}
	if (dir == "B")
	{
		if (isCheck == true && m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() <= 0)
		{
			if (m_tiles[h][w] == 17 || m_tiles[h][w] == 18 || m_tiles[h][w] == 19 || m_tiles[h][w] == 20)
			{
				float _x = int(*x) % int(m_image->GetWidth() - 1);
				float _y = int(*y) % int(m_image->GetHight() - 1);
				if (_x >= 0 && _x <= m_imagePlatform->GetWidth() - 1 && _y >= 0 && _y <= m_imagePlatform->GetHight() - 1)
				{
					COLORREF color = m_imagePlatform->pixel[(int)_x][(int)_y];
					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);
					if (r == 255 && g == 0 && b == 254)
					{
						m_checkY = *y - _y + 2;
						m_isBottomCheck = true;
						return;
					}
				}
			}
		}
	}
}
