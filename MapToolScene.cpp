#include "stdafx.h"
#include "MapToolScene.h"

MapToolScene::MapToolScene()
{
}

MapToolScene::~MapToolScene()
{
}

void MapToolScene::Init()
{
	m_page = 0;
	IMAGEMANAGER->AddImage("exBg", L"./Resources/exBg.png");

	m_tileImages = IMAGEMANAGER->GetTileImages();

	m_width = m_tileImages[0]->GetWidth();
	m_kind = -1;
	HRESULT hr = FILEMANAGER->TileFileRead(&m_tiles);
	if (hr != S_OK)
	{
		m_tiles.resize(30, vector<int>(100));
		for (auto iter : m_tiles)
		{
			iter.resize(100, -1);
		}
	}
}

void MapToolScene::Update()
{
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x - 1, IMAGEMANAGER->GetCameraPosition().y);
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x + 1, IMAGEMANAGER->GetCameraPosition().y);
	}
	if (KEYMANAGER->GetStayKeyDown(VK_UP))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y - 1);
	}
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y + 1);
	}
}

void MapToolScene::Render()
{
	IMAGEMANAGER->Render(IMAGEMANAGER->FindImage("exBg"), IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 1);

	int y1 = 0;
	for (auto iter : m_tiles)
	{
		int x = 0;
		for (auto _iter : iter)
		{
			if (_iter != -1)
				if (x * m_width - IMAGEMANAGER->GetCameraPosition().x < 800)
					IMAGEMANAGER->Render(m_tileImages[_iter], x * m_width, y1 * m_width);
			x++;
		}
		y1++;
	}

	int y = 0;
	int idx = 0;
	for (char i = '0'; i <= '9'; i++)
	{
		if (KEYMANAGER->GetOnceKeyDown(i))
		{
			m_page = i - 48 - 1;
		}
	}

	for (auto iter : m_tileImages)
	{
		idx++;
		if (idx >= m_maxIndex * m_page)
		{
			if (y == m_maxIndex)
			{
				break;
			}
			RECT rt = { 900 + (y / 6) * 100 + (y / 6) * 100,
				y * (2 * m_tileImages[0]->GetHeight() + 10) * (1 + y % 6) ,
				900 + iter->GetWidth() * 2 + (y / 6) * 100 + (y / 6) * 100 ,
				y * (2 * m_tileImages[0]->GetHeight() + 10) + iter->GetHeight() * 2 * (1 + y % 6) };

			IMAGEMANAGER->UIRender(iter, 900 + (y / 6) * 100, (1 + y % 6) * (2 * m_width + 10), 2, 2);
			y++;
		}
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_LBUTTON))
	{
		y = 0;
		idx = 0;
		for (auto iter : m_tileImages)
		{
			idx++;
			if (idx >= m_maxIndex * m_page)
			{
				RECT rt = { 900 + (y / 6) * 100 ,
				(2 * m_tileImages[0]->GetHeight() + 10) * (1 + y % 6) ,
				900 + iter->GetWidth() * 2 + (y / 6) * 100,
				 (2 * m_tileImages[0]->GetHeight() + 10) + iter->GetHeight() * 2 * (1 + y % 6) };

				if (rt.left < _ptMouse.x && rt.right > _ptMouse.x && rt.top < _ptMouse.y && rt.bottom>_ptMouse.y)
				{
					m_kind = idx - 1;
				}
				if (y == m_maxIndex * (m_page + 1))
				{
					break;
				}
				y++;
			}
		}
	}

	if (m_kind != -1)
	{
		if (KEYMANAGER->GetStayKeyDown(VK_LBUTTON))
		{
			int y2 = 0;
			for (auto& iter : m_tiles)
			{
				int x2 = 0;
				for (auto& _iter = iter.begin(); _iter != iter.end(); _iter++)
				{
					RECT rt = { x2 * m_width, y2 * m_width , x2 * m_width + m_width , y2 * m_width + m_width };
					if (x2 * m_width - IMAGEMANAGER->GetCameraPosition().x < 800)
					{
						if (rt.left < _ptMouse.x + IMAGEMANAGER->GetCameraPosition().x && rt.right > _ptMouse.x + IMAGEMANAGER->GetCameraPosition().x && rt.top < _ptMouse.y + IMAGEMANAGER->GetCameraPosition().y && rt.bottom>_ptMouse.y + IMAGEMANAGER->GetCameraPosition().y)
						{
							(*_iter) = m_kind;
						}
						x2++;
					}
				}
				y2++;
			}
		}
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RBUTTON))
	{
		int y2 = 0;
		for (auto& iter : m_tiles)
		{
			int x2 = 0;
			for (auto& _iter = iter.begin(); _iter != iter.end(); _iter++)
			{
				RECT rt = { x2 * m_width, y2 * m_width , x2 * m_width + m_width , y2 * m_width + m_width };
				if (x2 * m_width - IMAGEMANAGER->GetCameraPosition().x < 800)
				{
					if (rt.left < _ptMouse.x + IMAGEMANAGER->GetCameraPosition().x && rt.right > _ptMouse.x + IMAGEMANAGER->GetCameraPosition().x && rt.top < _ptMouse.y + IMAGEMANAGER->GetCameraPosition().y && rt.bottom>_ptMouse.y + IMAGEMANAGER->GetCameraPosition().y)
					{
						(*_iter) = -1;
					}
					x2++;
				}
			}
			y2++;
		}
	}
	if (m_kind != -1)
	{
		IMAGEMANAGER->UIRender(m_tileImages[m_kind], _ptMouse.x, _ptMouse.y, 0.5f, 0.5f);
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_BACK))
	{
		FILEMANAGER->TileFileWrite("Test1", "TileMap", m_tiles);
		cout << "ÀúÀå";
		SCENEMANAGER->ChangeScene("MapToolMapSelectScene");
	}
}

void MapToolScene::Release()
{
	m_tiles.clear();
	m_tileImages.clear();
}