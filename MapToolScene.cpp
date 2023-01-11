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
	mdsfa = 0;
	m_page = 0;
	m_streuctureKey = "";
	m_triggerPage = 0;
	m_state = eTileBatch;

	m_tileImages = IMAGEMANAGER->GetTileImages();
	m_structureImages = IMAGEMANAGER->GetStructureImages();
	m_objectImages = IMAGEMANAGER->GetObjectImages();
	m_width = m_tileImages[0]->GetWidth() - 1;
	m_kind = -1;
	HRESULT hr = FILEMANAGER->TileFileRead(&m_tiles);
	if (hr != S_OK)
	{
		m_tiles.resize(100, vector<int>(100)); // 맵크기 변경 100x100 // 다찍엇는데 모자라다 하면 태웅이한테 쉬프트 엔터, 스페이스바 레프트 쉬프트로 저정
		for (auto iter : m_tiles)
		{
			iter.resize(100, -1);
		}

		for (auto& iter : m_tiles)
		{
			for (auto& _iter : iter)
			{
				_iter = -1;
			}
		}
	}
	IMAGEMANAGER->SetCameraPosition(0, 0);
	string strData;
	strData = FILEMANAGER->GetFileData("Structure", "batch");
	string objData;
	objData = FILEMANAGER->GetFileData("Object", "batch");

	MY_UTILITY::ConvertStructureString2Vec(&m_sturctDatas, strData);
	MY_UTILITY::ConvertStructureString2Vec(&m_objectDatas, objData);

}

void MapToolScene::Update()
{
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x - 5, IMAGEMANAGER->GetCameraPosition().y);
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x + 5, IMAGEMANAGER->GetCameraPosition().y);
	}
	if (KEYMANAGER->GetStayKeyDown(VK_UP))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y - 5);
	}
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		IMAGEMANAGER->SetCameraPosition(IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y + 5);
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
		m_state = eObjectBatch;
		m_streuctureKey = "";
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_RSHIFT))
	{
		vector<int> v;
		v.resize(100, -1);
		m_tiles.push_back(v);
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_RETURN))
	{
		m_tiles.pop_back();
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_LSHIFT))
	{
		for (auto& iter : m_tiles)
		{
			iter.pop_back();
		}
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_SPACE))
	{
		for (auto& iter : m_tiles)
		{
			iter.push_back(-1);
		}
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_INSERT) && m_triggerPage != 3)
	{
		m_triggerPage++;
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_HOME) && m_triggerPage != 0)
	{
		m_triggerPage--;
	}
}

void MapToolScene::Render()
{
	IMAGEMANAGER->Render(IMAGEMANAGER->FindImage("exBg"), IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y, 2, 1);

	IMAGEMANAGER->DrawMapStructureBack(m_sturctDatas);

	IMAGEMANAGER->DrawMapTile(m_tiles);

	IMAGEMANAGER->DrawMapStructureFoward(m_sturctDatas);

	for (auto iter : m_objectDatas)
	{
		IMAGEMANAGER->CenterRender(m_objectImages[iter->key], iter->x, iter->y, 2, 2);
	}
	if (KEYMANAGER->GetToggleKey(VK_F11))
	{
		IMAGEMANAGER->DrawMapTilePixel(m_tiles);
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
	else if (m_state == eObjectBatch)
	{
		for (auto iter : m_objectImages)
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

	if (KEYMANAGER->GetOnceKeyDown(VK_F4))
	{
		m_page += m_page >= 10 ? -10 : 10;
	}
	if (KEYMANAGER->GetOnceKeyDown(VK_RBUTTON))
	{
		if (m_streuctureKey != "")
		{
			if (_ptMouse.x < 800)
			{
				StructureData* sd = new StructureData();
				sd->key = m_streuctureKey;
				sd->x = _ptMouse.x + IMAGEMANAGER->GetCameraPosition().x;
				sd->y = _ptMouse.y + IMAGEMANAGER->GetCameraPosition().y;
				sd->isBack = true;
				m_sturctDatas.push_back(sd);
			}
		}
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_CONTROL))
	{
		if (m_state == eStructureBatch)
		{
			if (m_sturctDatas.size() != 0)
			{
				SAFE_DELETE(*(m_sturctDatas.end() - 1));
				m_sturctDatas.pop_back();
			}
		}
		else if (m_state == eObjectBatch)
		{
			if (m_objectDatas.size() != 0)
			{
				SAFE_DELETE(*(m_objectDatas.end() - 1));
				m_objectDatas.pop_back();
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
					sd->isBack = false;
					m_sturctDatas.push_back(sd);
				}
			}
		}
		else if (m_state == eObjectBatch)
		{
			for (auto iter : m_objectImages)
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
					sd->isBack = false;
					sd->page = m_triggerPage;
					m_objectDatas.push_back(sd);
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
							(*_iter) = -1;
						}
						x2++;
					}
				}
				y2++;
			}
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
		else if (m_state == eObjectBatch)
		{
			IMAGEMANAGER->UICenterRender(m_objectImages[m_streuctureKey], _ptMouse.x, _ptMouse.y, 2, 2);
		}
	}

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
						IMAGEMANAGER->DrawRect(rt);
					}
					x2++;
				}
			}
			y2++;
		}
	}

	if (KEYMANAGER->GetOnceKeyDown(VK_BACK))
	{
		string str = "";
		MY_UTILITY::ConvertVec2StructureString(m_sturctDatas, &str);
		FILEMANAGER->WriteFileData("Structure", "batch", str);
		FILEMANAGER->TileFileWrite("Test1", "TileMap", m_tiles);
		string objStr = "";
		MY_UTILITY::ConvertVec2StructureString(m_objectDatas, &objStr);
		FILEMANAGER->WriteFileData("Object", "batch", objStr);

		cout << "저장";
		SCENEMANAGER->ChangeScene("MapToolMapSelectScene");
	}
}

void MapToolScene::Release()
{
	for (auto iter : m_sturctDatas)
	{
		SAFE_DELETE(iter);
	}
	m_sturctDatas.clear();

	for (auto iter : m_tiles)
	{
		iter.clear();
	}
	m_tiles.clear();
	m_tileImages.clear();

	for (auto iter : m_objectDatas)
	{
		SAFE_DELETE(iter);
	}
	m_objectDatas.clear();
}