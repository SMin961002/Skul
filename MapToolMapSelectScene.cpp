#include "stdafx.h"
#include "MapToolMapSelectScene.h"

MapToolMapSelectScene::MapToolMapSelectScene()
{
}

MapToolMapSelectScene::~MapToolMapSelectScene()
{
}

void MapToolMapSelectScene::Init()
{
	FILEMANAGER->MapFileRead("Map", "name", &m_maps);
}

void MapToolMapSelectScene::Update()
{
}

void MapToolMapSelectScene::Render()
{
	RECT rt = { };
	int x = 0;
	for (auto iter : m_maps)
	{
		wstring wstr = L"";
		wstr.assign(iter.begin(), iter.end());
		IMAGEMANAGER->DrawRect({ 50 + x % 4 * 200,50 + x / 4 * 200,50 + 150 + x % 4 * 200,200 + x / 4 * 200 });
		IMAGEMANAGER->D2dTextOut(wstr, 44 + x % 4 * 100, x / 4 * 100);
		x++;
	}

	IMAGEMANAGER->UIRender(IMAGEMANAGER->FindImage("newFile"), 50 + x % 4 * 200, 50 + x / 4 * 200, 1, 1);
	rt = { 50 + x % 4 * 200,50 + x / 4 * 200,50 + 150 + x % 4 * 200,200 + x / 4 * 200 };

	x = 0;
	if (KEYMANAGER->GetOnceKeyDown(VK_LBUTTON))
	{
		for (auto iter : m_maps)
		{
			rt = { 50 + x % 4 * 200,50 + x / 4 * 200,50 + 150 + x % 4 * 200,200 + x / 4 * 200 };
			if (rt.left < _ptMouse.x && rt.right > _ptMouse.x && rt.top < _ptMouse.y && rt.bottom > _ptMouse.y)
			{
				FILEMANAGER->SetNowStageFile("map_" + to_string(x));
				SCENEMANAGER->ChangeScene("MapToolScene");
			}
			x++;
		}
		rt = { 50 + x % 4 * 200,50 + x / 4 * 200,50 + 150 + x % 4 * 200,200 + x / 4 * 200 };

		if (rt.left < _ptMouse.x && rt.right > _ptMouse.x && rt.top < _ptMouse.y && rt.bottom > _ptMouse.y)
		{
			m_maps.push_back("map_" + to_string(x));
			FILEMANAGER->MapFileWrite("Map", "name", m_maps, "./MapFile/mapList.ini");
		}
	}

	
}

void MapToolMapSelectScene::Release()
{
	m_maps.clear();
}
