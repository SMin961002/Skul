#include "stdafx.h"
#include "NpcObject.h"

NpcObject::NpcObject()
{
}

NpcObject::~NpcObject()
{
}

void NpcObject::Setting(string name)
{
	m_name = name;
	m_shopImage = IMAGEMANAGER->FindImageVector(name);
	m_shopImage->Setting(0.15f, true);

	if (m_name == "ItemView")
	{
		sItem* item1 = new sItem;
		item1->m_account = 500;
		item1->key = "CaerleonSword";

		m_itemList.push_back(item1);

		sItem* item2 = new sItem;
		item2->m_account = 500;
		item2->key = "CaerleonSword";

		m_itemList.push_back(item2);

		sItem* item3 = new sItem;
		item3->m_account = 500;
		item3->key = "CaerleonSword";

		m_itemList.push_back(item3);

		sItem* item4 = new sItem;
		item4->m_account = 5000;
		item4->key = "CaerleonSword";

		m_itemList.push_back(item4);
	}
}

void NpcObject::Init()
{
	rot = 0;
}

void NpcObject::Update()
{
}

void NpcObject::Render()
{
	int x = -125;
	m_shopImage->CenterRender(m_obj->x, m_obj->y+15, 2, 2, 0, 0);
	if (m_name == "ItemView")
	{
		for (auto iter : m_itemList)
		{
			rot += 0.009f;
			IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage(iter->key), m_obj->x - x, m_obj->y + sinf(rot)*8 - 30, 2.5, 2.5);
			IMAGEMANAGER->D2dTextOut(to_wstring(iter->m_account), m_obj->x - x - IMAGEMANAGER->GetCameraPosition().x - 40, m_obj->y + 68 - IMAGEMANAGER->GetCameraPosition().y, {255,255,255,255}, 0.5);
			x += 167;
		}
	}
}

void NpcObject::Release()
{
	for (auto iter : m_itemList)
	{
		SAFE_DELETE(iter);
	}
	m_itemList.clear();
}
