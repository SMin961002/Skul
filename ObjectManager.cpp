#include "stdafx.h"
#include "ObjectManager.h"
#include "CollisionComponent.h"
#include"Player.h"
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
		for (auto iter = m_objects[i].begin(); iter != m_objects[i].end();)
		{
			(*iter)->Update();
			for (int j = 0; j < ObjectTag::eEndTag; j++)
			{
				for (auto& other : m_objects[j])
				{
					if (i != j)
					{
						for (auto coll1 : (*iter)->GetCollisionComponent())
						{
							if (coll1->GetIsActive())
							{
								for (auto coll2 : other->GetCollisionComponent())
								{
									if (coll2->GetIsActive())
									{
										(*iter)->OnCollision(coll2->GetName(), other);
									}
								}
							}
						}
					}
				}
			}
			if ((*iter)->GetIsObjectDestroyed() == true)
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = m_objects[i].erase(iter);
			}
			else
				iter++;
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
