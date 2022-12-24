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
	m_streuctureKey = "";
	m_state = eTileBatch;
	IMAGEMANAGER->AddImage("exBg", L"./Resources/exBg.png");

	m_tileImages = IMAGEMANAGER->GetTileImages();
	m_structureImages = IMAGEMANAGER->GetStructureImages();

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
	if (KEYMANAGER->GetOnceKeyDown(VK_F1))
	{
		m_state = eTileBatch;
		m_streuctureKey = "";
		m_page = 0;
		m_kind = -1;
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F2))
	{
		m_kind = -1;
		m_page = 0;
		m_state = eStructureBatch;
		m_streuctureKey = "";

	}
	if (KEYMANAGER->GetOnceKeyDown(VK_F3))
	{
		m_page = 0;
		m_kind = -1;
		m_state = eCollisionBatch;
		m_streuctureKey = "";

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

	for (auto iter : m_sturctDatas)
	{
		IMAGEMANAGER->Render(m_structureImages[iter->key], iter->x, iter->y,1.5,1.5);
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
	if (m_state == eTileBatch)
	{
		for (auto iter : m_tileImages)
		{
			idx++;
			if (idx >= m_maxIndex * m_page)
			{
				if (y == m_maxIndex)
				{
					break;
				}
				IMAGEMANAGER->UIRender(iter, 900 + (y / 6) * 100, (1 + y % 6) * (2 * m_width + 10), 2, 2);
				y++;
			}
		}
	}
	else if (m_state == eStructureBatch)
	{
		for (auto iter : m_structureImages)
		{
			idx++;
			if (idx >= m_maxIndex * m_page)
			{
				if (y == m_maxIndex)
				{
					break;
				}
				IMAGEMANAGER->UIRender(iter.second, 900 + (y / 6) * 100, (1 + y % 6) * (2 * m_width + 10),
					1.f / iter.second->GetWidth() * (iter.second->GetWidth() - (iter.second->GetWidth() - m_tileImages[0]->GetWidth() * 2)),
					1.f / iter.second->GetHeight() * (iter.second->GetHeight() - (iter.second->GetHeight() - m_tileImages[0]->GetHeight() * 2)));
				y++;
			}
		}
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_LBUTTON))
	{
		y = 0;
		idx = 0;
		if (m_state == eTileBatch)
		{
			for (auto iter : m_tileImages)
			{
				idx++;
				if (idx >= m_maxIndex * m_page)
				{
					RECT rt = {
					900 + (y / 6) * 100,
					(1 + y % 6) * (2 * m_width + 10),
					900 + (y / 6) * 100 + m_width * 2,
					(1 + y % 6) * (2 * m_width + 10) + m_width * 2
					};
					if (rt.left < _ptMouse.x && rt.right > _ptMouse.x && rt.top < _ptMouse.y && rt.bottom>_ptMouse.y)
					{
						m_kind = idx - 1;
					}
					if (idx >= m_maxIndex * (m_page + 1))
					{
						break;
					}
					y++;
				}
			}
		}
		else if (m_state == eStructureBatch)
		{
			for (auto iter : m_structureImages)
			{
				idx++;
				if (idx >= m_maxIndex * m_page)
				{
					RECT rt = {
					900 + (y / 6) * 100,
					(1 + y % 6) * (2 * m_width + 10),
					900 + (y / 6) * 100 + m_width * 2,
					(1 + y % 6) * (2 * m_width + 10) + m_width * 2
					};
					if (rt.left < _ptMouse.x && rt.right > _ptMouse.x && rt.top < _ptMouse.y && rt.bottom>_ptMouse.y)
					{
						m_streuctureKey = iter.first;
					}
					if (idx >= m_maxIndex * (m_page + 1))
					{
						break;
					}
					y++;
				}
			}
			if (m_streuctureKey != "")
			{
				if (_ptMouse.x < 800)
				{
					StructureData* sd = new StructureData();
					sd->key = m_streuctureKey;
					sd->x = _ptMouse.x + IMAGEMANAGER->GetCameraPosition().x;
					sd->y = _ptMouse.y + IMAGEMANAGER->GetCameraPosition().y;
					m_sturctDatas.push_back(sd);
				}
			}
		}
	}

	if (m_kind != -1)
	{
		if (KEYMANAGER->GetStayKeyDown(VK_LBUTTON))
		{
			if (m_state == eTileBatch)
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
		if (m_state == eTileBatch)
		{
			IMAGEMANAGER->UIRender(m_tileImages[m_kind], _ptMouse.x, _ptMouse.y, 0.5f, 0.5f);
		}
	}
	if (m_streuctureKey != "")
	{
		if (m_state == eStructureBatch)
		{
			IMAGEMANAGER->UIRender(m_structureImages[m_streuctureKey], _ptMouse.x, _ptMouse.y, 2, 2);
		}
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