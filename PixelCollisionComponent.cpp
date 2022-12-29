#include "stdafx.h"
#include "PixelCollisionComponent.h"

void PixelCollisionComponent::Init()
{
	m_image = IMAGEMANAGER->FindPixelImage("CollisionBox");

}

void PixelCollisionComponent::Update()
{
	int j;
	int y1 = 0;
	for (auto iter : m_tiles)
	{
		int x1 = 0;
		for (auto _iter : iter)
		{
			if (_iter == 0 || _iter == 1 || _iter == 2 || _iter == 3 || _iter == 4 || _iter == 7 || _iter == 8 || _iter == 9 || _iter == 10 || _iter == 11 || _iter == 12 || _iter == 13 || _iter == 14 || _iter == 36 || _iter == 37)
			{
				float _x= *x - x1 * m_image->GetWidth();
				float _y = *y - y1 * m_image->GetHight();
				COLORREF color = GetPixel(m_image->GetMemDC(),_x ,_y );
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);
				if ((r == 255 && g == 0 && b == 255))
				{
					cout << "üũ" << endl;
				}
			}
			else if (_iter == 19 || _iter == 18 || _iter == 17 || _iter == 16)
			{

			}
			x1++;
		}
		y1++;
	}

}

void PixelCollisionComponent::Render()
{
}

void PixelCollisionComponent::Release()
{
}

void PixelCollisionComponent::setting(vector<vector<int>> tiles, float* x, float* y)
{
	m_tiles = tiles;
	this->x = x;
	this->y = y;
}
