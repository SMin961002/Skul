#include"stdafx.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"

void PixelCollisionComponent::Init()

{
	m_isCheck = false;
	m_image = IMAGEMANAGER->FindPixelImage("CollisionBox");
	m_checkY = 0;
	m_checkX = 0;

	m_isLeftCheck = false;
	m_isRightCheck = false;
	m_isBottomCheck = false;
	m_isTopCheck = false;
}

void PixelCollisionComponent::Update()
{
	m_isCheck = false;
	m_isLeftCheck = false;
	m_isRightCheck = false;
	m_isBottomCheck = false;
	m_isTopCheck = false;

	LeftCollision();
	RightCollision();
	TopCollision();
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

	int y1 = 0;
	for (int i = *y + rtB.top; i < *y + rtB.bottom; i++)
	{
		if (m_isBottomCheck == true)
		{
			break;
		}
		int h = i / (m_image->GetHight() - 1);
		if (h < m_tiles.size())
		{
			for (int j = *x + rtB.left; j < *x + rtB.right; j++)
			{
				int w = j / (m_image->GetWidth() - 1);
				if (w < m_tiles[0].size())
				{
					if (m_tiles[h][w] == 0 || m_tiles[h][w] == 1 || m_tiles[h][w] == 2 || m_tiles[h][w] == 3 || m_tiles[h][w] == 4 || m_tiles[h][w] == 7 || m_tiles[h][w] == 8 || m_tiles[h][w] == 9 || m_tiles[h][w] == 10 || m_tiles[h][w] == 11 || m_tiles[h][w] == 12 || m_tiles[h][w] == 13 || m_tiles[h][w] == 14 || m_tiles[h][w] == 36 || m_tiles[h][w] == 37)
					{
						float _x = int(*x) % int(m_image->GetWidth() - 1);
						float _y = int(*y) % int(m_image->GetHight() - 1);
						if (_x >= 0 && _x <= m_image->GetWidth() - 1 && _y >= 0 && _y <= m_image->GetHight() - 1)
						{
							COLORREF color = GetPixel(m_image->GetMemDC(), _x, _y);
							int r = GetRValue(color);
							int g = GetGValue(color);
							int b = GetBValue(color);
							if (r == 255 && g == 0 && b == 255)
							{
								m_checkY = i; // 높은곳에서 떨어졌을때 땅파고들어가는것 방지
								m_isBottomCheck = true;
								break;
							}
						}
					}
				}
			}
		}
	}
}

void PixelCollisionComponent::TopCollision()
{

	int y1 = 0;
	for (int i = *y + rtT.bottom; i > *y + rtT.top; i--)
	{
		if (m_isTopCheck == true)
		{
			break;
		}
		int h = i / (m_image->GetHight() - 1);
		if (h < m_tiles.size())
		{
			for (int j = *x + rtT.left; j < *x + rtT.right; j++)
			{
				int w = j / (m_image->GetWidth() - 1);
				if (w < m_tiles[0].size())
				{
					if (m_tiles[h][w] == 0 || m_tiles[h][w] == 1 || m_tiles[h][w] == 2 || m_tiles[h][w] == 3 || m_tiles[h][w] == 4 || m_tiles[h][w] == 7 || m_tiles[h][w] == 8 || m_tiles[h][w] == 9 || m_tiles[h][w] == 10 || m_tiles[h][w] == 11 || m_tiles[h][w] == 12 || m_tiles[h][w] == 13 || m_tiles[h][w] == 14 || m_tiles[h][w] == 36 || m_tiles[h][w] == 37)
					{
						float _x = int(*x) % int(m_image->GetWidth() - 1);
						float _y = int(*y) % int(m_image->GetHight() - 1);
						if (_x >= 0 && _x <= m_image->GetWidth() - 1 && _y >= 0 && _y <= m_image->GetHight() - 1)
						{
							COLORREF color = GetPixel(m_image->GetMemDC(), _x, _y);
							int r = GetRValue(color);
							int g = GetGValue(color);
							int b = GetBValue(color);
							if (r == 255 && g == 0 && b == 255)
							{
								m_checkY = i; // 높은곳에서 떨어졌을때 땅파고들어가는것 방지
								m_isTopCheck = true;
								break;
							}
						}
					}
				}
			}
		}
	}
}

void PixelCollisionComponent::LeftCollision()
{
	int y1 = 0;
	for (int i = *y + rtL.top; i < *y + rtL.bottom; i++)
	{
		if (m_isLeftCheck == true)
		{
			break;
		}
		int h = i / (m_image->GetHight() - 1);
		if (h < m_tiles.size())
		{
			for (int j = *x + rtL.right; j > *x + rtL.left; j--)
			{
				int w = j / (m_image->GetWidth() - 1);
				if (w < m_tiles[0].size())
				{
					if (m_tiles[h][w] == 0 || m_tiles[h][w] == 1 || m_tiles[h][w] == 2 || m_tiles[h][w] == 3 || m_tiles[h][w] == 4 || m_tiles[h][w] == 7 || m_tiles[h][w] == 8 || m_tiles[h][w] == 9 || m_tiles[h][w] == 10 || m_tiles[h][w] == 11 || m_tiles[h][w] == 12 || m_tiles[h][w] == 13 || m_tiles[h][w] == 14 || m_tiles[h][w] == 36 || m_tiles[h][w] == 37)
					{
						float _x = int(*x) % int(m_image->GetWidth() - 1);
						float _y = int(*y) % int(m_image->GetHight() - 1);
						if (_x >= 0 && _x <= m_image->GetWidth() - 1 && _y >= 0 && _y <= m_image->GetHight() - 1)
						{
							COLORREF color = GetPixel(m_image->GetMemDC(), _x, _y);
							int r = GetRValue(color);
							int g = GetGValue(color);
							int b = GetBValue(color);
							if (r == 255 && g == 0 && b == 255)
							{
								m_checkX = j; // 높은곳에서 떨어졌을때 땅파고들어가는것 방지
								m_isLeftCheck = true;
								break;
							}
						}
					}
				}
			}
		}
	}
}

void PixelCollisionComponent::RightCollision()
{

	int y1 = 0;
	for (int i = *y + rtR.top; i < *y + rtR.bottom; i++)
	{
		if (m_isRightCheck == true)
		{
			break;
		}
		int h = i / (m_image->GetHight() - 1);
		if (h < m_tiles.size())
		{
			for (int j = *x + rtR.left; j < *x + rtR.right; j++)
			{
				int w = j / (m_image->GetWidth() - 1);
				if (w < m_tiles[0].size())
				{
					if (m_tiles[h][w] == 0 || m_tiles[h][w] == 1 || m_tiles[h][w] == 2 || m_tiles[h][w] == 3 || m_tiles[h][w] == 4 || m_tiles[h][w] == 7 || m_tiles[h][w] == 8 || m_tiles[h][w] == 9 || m_tiles[h][w] == 10 || m_tiles[h][w] == 11 || m_tiles[h][w] == 12 || m_tiles[h][w] == 13 || m_tiles[h][w] == 14 || m_tiles[h][w] == 36 || m_tiles[h][w] == 37)
					{
						float _x = int(*x) % int(m_image->GetWidth() - 1);
						float _y = int(*y) % int(m_image->GetHight() - 1);
						if (_x >= 0 && _x <= m_image->GetWidth() - 1 && _y >= 0 && _y <= m_image->GetHight() - 1)
						{
							COLORREF color = GetPixel(m_image->GetMemDC(), _x, _y);
							int r = GetRValue(color);
							int g = GetGValue(color);
							int b = GetBValue(color);
							if (r == 255 && g == 0 && b == 255)
							{
								m_checkX = j; // 높은곳에서 떨어졌을때 땅파고들어가는것 방지
								m_isRightCheck = true;
								break;
							}
						}
					}
				}
			}
		}
	}
}
