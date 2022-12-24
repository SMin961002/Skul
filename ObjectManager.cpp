#include "stdafx.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

Object* ObjectManager::AddObject(string name, float x, float y, int tagNum)
{
	if (tagNum < eEndTag)
	{
		Object* _obj = new Object;
		_obj->SetName(name);
		_obj->SetPosition(x, y);
		m_objects[tagNum].push_back(_obj);
		return _obj;
	}
	cout << "�±װ� ���� �Ѿ ���׳� tagNum: " << tagNum << " eEndTag: " << eEndTag;
	return nullptr;
}

void ObjectManager::Update()
{
	for (int i = 0; i < eEndTag; i++)
	{
		for (auto iter : m_objects[i])
		{
			iter->Update();
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < eEndTag; i++) // ���� �׷��ָ� �ڿ� �׷����ϱ� ���� ������ ������ eEndTag F12������ ���ʼ�
	{
		for (auto iter : m_objects[i])
		{
			iter->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < eEndTag; i++)
	{
		for (auto iter : m_objects[i])
		{
			iter->Release();
			SAFE_DELETE(iter)
		}
		m_objects[i].clear();
	}
}
