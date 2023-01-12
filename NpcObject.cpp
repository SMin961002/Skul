#include "stdafx.h"
#include "NpcObject.h"
#include "Player.h"

NpcObject::NpcObject()
{
}

NpcObject::~NpcObject()
{
}

void NpcObject::Setting(string name)
{
	m_isState = false;
	m_name = name;
	m_shopImage = IMAGEMANAGER->FindImageVector(name);
	m_shopImage->Setting(0.15f, true);
	if (m_name == "ItemView")
	{
		coll1 = m_obj->AddComponent<CollisionComponent>();
		coll2 = m_obj->AddComponent<CollisionComponent>();
		coll3 = m_obj->AddComponent<CollisionComponent>();
		coll4 = m_obj->AddComponent<CollisionComponent>();

		m_obj->AddCollisionComponent(coll1);
		m_obj->AddCollisionComponent(coll2);
		m_obj->AddCollisionComponent(coll3);
		m_obj->AddCollisionComponent(coll4);


		sItem* item1 = new sItem;
		item1->m_account = 500;
		item1->key = "CaerleonSword";

		m_itemList.push_back(item1);

		sItem* item2 = new sItem;
		item2->m_account = 500;
		item2->key = "FireKnife";

		m_itemList.push_back(item2);

		sItem* item3 = new sItem;
		item3->m_account = 500;
		item3->key = "Caerleonarmor";

		m_itemList.push_back(item3);

		sItem* item4 = new sItem;
		item4->m_account = 5000;
		item4->key = "BoneOfMana";

		m_itemList.push_back(item4);

	}
	OBJECTMANAGER->m_player->goldValue = 5000;
}

void NpcObject::Init()
{
	rot = 0;
	m_isState = true;
}

void NpcObject::Update()
{
	m_isState = false;
}

void NpcObject::Render()
{
	int x = -125;
	m_shopImage->CenterRender(m_obj->x, m_obj->y + 15, 2, 2, 0, 0);
	if (m_name == "ItemView")
	{
		int  i = 0;
		for (auto iter : m_itemList)
		{
			rot += 0.009f;
			i++;
			if (i > 4)
			{
				return;
			}
			switch (i)
			{
			case 1:
				if (coll1->GetIsActive() == true)
				{
					coll1->Setting(30, m_obj->x - x, m_obj->y + 50, "first");
					IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage(iter->key), m_obj->x - x, m_obj->y + sinf(rot) * 8 - 30, 2.5, 2.5);
					IMAGEMANAGER->D2dTextOut(to_wstring(iter->m_account), m_obj->x - x - IMAGEMANAGER->GetCameraPosition().x - 40, m_obj->y + 68 - IMAGEMANAGER->GetCameraPosition().y, { 255,255,255,255 }, 0.5);
				}
				break;
			case 2:
				if (coll2->GetIsActive() == true)
				{
					coll2->Setting(30, m_obj->x - x, m_obj->y + 50, "second");
					IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage(iter->key), m_obj->x - x-10, m_obj->y + sinf(rot) * 8 - 30, 2.5, 2.5);
					IMAGEMANAGER->D2dTextOut(to_wstring(iter->m_account), m_obj->x - x - IMAGEMANAGER->GetCameraPosition().x - 40, m_obj->y + 68 - IMAGEMANAGER->GetCameraPosition().y, { 255,255,255,255 }, 0.5);
				}
				break;
			case 3:
				coll3->Setting(30, m_obj->x - x, m_obj->y + 50, "third");
				if (coll3->GetIsActive() == true)
				{
					IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage(iter->key), m_obj->x - x-10, m_obj->y + sinf(rot) * 8 - 30, 2.5, 2.5);
					IMAGEMANAGER->D2dTextOut(to_wstring(iter->m_account), m_obj->x - x - IMAGEMANAGER->GetCameraPosition().x - 40, m_obj->y + 68 - IMAGEMANAGER->GetCameraPosition().y, { 255,255,255,255 }, 0.5);
				}
				break;
			case 4:
				coll4->Setting(30, m_obj->x - x, m_obj->y + 50, "forth");
				if (coll4->GetIsActive() == true)
				{
					IMAGEMANAGER->CenterRender(IMAGEMANAGER->FindImage(iter->key), m_obj->x - x, m_obj->y + sinf(rot) * 8 - 30, 2.5, 2.5);
					IMAGEMANAGER->D2dTextOut(to_wstring(iter->m_account), m_obj->x - x - IMAGEMANAGER->GetCameraPosition().x - 40, m_obj->y + 68 - IMAGEMANAGER->GetCameraPosition().y, { 255,255,255,255 }, 0.5);
				}
				break;
			}



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

void NpcObject::UIRender()
{
	if (m_isState == true)
	{
		IMAGEMANAGER->UICenterRender(IMAGEMANAGER->FindImage("ItemUI"), WINSIZE_X / 2 - 300, WINSIZE_Y / 2 - 100, 1.7, 1.7);
		if (m_itemList[kind]->key == "CaerleonSword")
		{
			IMAGEMANAGER->D2dTextOut(L"보급형 칼레온 검", 170, 50, { 0,0,0,1 }, 0.8f);
			IMAGEMANAGER->D2dTextOut(L"묵직한 칼레온 군 보급용 검. 성능은 의심이 들지만, \n관리 된 검날은 예사롭지 않다.", 90, 115, { 0,0,0,1 }, 0.5f);
			IMAGEMANAGER->UICenterRender(IMAGEMANAGER->FindImage("CaerleonSword"), 170, 215, 1.5, 1.5);
			IMAGEMANAGER->D2dTextOut(L"F 구매하기  ( " + to_wstring(m_itemList[kind]->m_account) + L" )", 160, 270, { 0,0,0,1 }, 0.8f);
		}
		if (m_itemList[kind]->key == "FireKnife")
		{
			IMAGEMANAGER->D2dTextOut(L"불의 검", 210, 50, { 0,0,0,1 }, 0.8f);
			IMAGEMANAGER->D2dTextOut(L"묵직한 불의 검. 때렸을 때 불이 붙지 않지만, \n멋있다.", 90, 115, { 0,0,0,1 }, 0.5f);
			IMAGEMANAGER->UICenterRender(IMAGEMANAGER->FindImage("CaerleonSword"), 170, 215, 1.5, 1.5);
			IMAGEMANAGER->D2dTextOut(L"F 구매하기  ( " + to_wstring(m_itemList[kind]->m_account) + L" )", 160, 270, { 0,0,0,1 }, 0.8f);
		}
		if (m_itemList[kind]->key == "Caerleonarmor")
		{
			IMAGEMANAGER->D2dTextOut(L"보급형 칼레온 갑옷", 155, 50, { 0,0,0,1 }, 0.8f);
			IMAGEMANAGER->D2dTextOut(L"보기만 해도 진절머리 나는 칼레온 군 보급형 갑옷.", 93, 115, { 0,0,0,1 }, 0.5f);
			IMAGEMANAGER->UICenterRender(IMAGEMANAGER->FindImage("Caerleonarmor"), 163, 215, 1.5, 1.5);
			IMAGEMANAGER->D2dTextOut(L"F 구매하기  ( " + to_wstring(m_itemList[kind]->m_account) + L" )", 160, 270, { 0,0,0,1 }, 0.8f);
		}
		if (m_itemList[kind]->key == "BoneOfMana")
		{
			IMAGEMANAGER->D2dTextOut(L"마나의 뼈", 200, 50, { 0,0,0,1 }, 0.8f);
			IMAGEMANAGER->D2dTextOut(L"대체 어떤 부유한 스켈레톤이 이런걸 만들어서 쓸까?", 90, 115, { 0,0,0,1 }, 0.5f);
			IMAGEMANAGER->UICenterRender(IMAGEMANAGER->FindImage("BoneOfMana"), 163, 215, 1.5, 1.5);
			IMAGEMANAGER->D2dTextOut(L"F 구매하기  ( " + to_wstring(m_itemList[kind]->m_account) + L" )", 160, 270, { 0,0,0,1 }, 0.8f);
		}
	}
}

void NpcObject::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "player")
	{
		if (coll1->GetName()  == "first")
		{
			m_isState = true;
			kind = 0;
			if (KEYMANAGER->GetOnceKeyDown('F'))
			{
				if (OBJECTMANAGER->m_player->goldValue >= m_itemList[kind]->m_account)
				{
					this->coll1->SetIsActive(false);
					OBJECTMANAGER->m_player->goldValue -= m_itemList[kind]->m_account;
				}
			}
		}
		if (coll1->GetName() == "second")
		{
			m_isState = true;
			kind = 1;
			if (KEYMANAGER->GetOnceKeyDown('F'))
			{
				if (OBJECTMANAGER->m_player->goldValue >= m_itemList[kind]->m_account)
				{
					this->coll2->SetIsActive(false);
					OBJECTMANAGER->m_player->goldValue -= m_itemList[kind]->m_account;
				}
			}
		}
		if (coll1->GetName() == "third")
		{
			m_isState = true;
			kind = 2;
			if (KEYMANAGER->GetOnceKeyDown('F'))
			{
				if (OBJECTMANAGER->m_player->goldValue >= m_itemList[kind]->m_account)
				{
					this->coll3->SetIsActive(false);
					OBJECTMANAGER->m_player->goldValue -= m_itemList[kind]->m_account;
				}
			}
		}
		if (coll1->GetName() == "forth")
		{
			m_isState = true;
			kind = 3;
			if (KEYMANAGER->GetOnceKeyDown('F'))
			{
				if (OBJECTMANAGER->m_player->goldValue >= m_itemList[kind]->m_account)
				{
					this->coll4->SetIsActive(false);
					OBJECTMANAGER->m_player->goldValue -= m_itemList[kind]->m_account;
				}
			}
		}
	}
}
