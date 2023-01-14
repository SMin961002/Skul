#include "stdafx.h"
#include "ObjectManager.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"Item.h"
#include "PixelCollisionComponent.h"
#include "BossObject.h"
#include "RigidBodyComponent.h"
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
	cout << "태그가 끝을 넘어서 버그남 tagNum: " << tagNum << " eEndTag: " << eEndTag;
	return nullptr;
}

void ObjectManager::Update()
{
	for (int i = 0; i < eEndTag; i++)
	{
		for (auto iter : m_objects[i])
		{
			(iter)->Update();
		}
	}
	for (int i = 0; i < eEndTag; i++)
	{
		for (auto iter = m_objects[i].begin(); iter != m_objects[i].end();)
		{
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
								if (other != nullptr)
								{
									for (auto coll2 : other->GetCollisionComponent())
									{
										if (coll2->GetIsActive())
										{
											if (coll2 != coll1 && coll1 != nullptr && coll2 != nullptr)
											{
												if (coll2->GetIsActive() && coll1->GetIsActive())
												{
													float d = sqrt((coll1->GetCollisionPosX() - coll2->GetCollisionPosX()) * (coll1->GetCollisionPosX() - coll2->GetCollisionPosX()) +
														(coll1->GetCollisionPosY() - coll2->GetCollisionPosY()) * (coll1->GetCollisionPosY() - coll2->GetCollisionPosY()));
													if (d < coll1->GetRange() + coll2->GetRange())
													{
														(*iter)->OnCollision(coll1, coll2, other);
													}
												}
											}
										}
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
				*iter = nullptr;
				iter = m_objects[i].erase(iter);
			}
			else
				iter++;
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < eEndTag; i++) // 먼저 그려주면 뒤에 그려지니까 렌더 순서를 정해줌 eEndTag F12눌러서 보십쇼
	{
		for (auto iter : m_objects[i])
		{
			iter->Render();
		}
	}
}

void ObjectManager::UIRender()
{
	for (int i = 0; i < eEndTag; i++) // 먼저 그려주면 뒤에 그려지니까 렌더 순서를 정해줌 eEndTag F12눌러서 보십쇼
	{
		for (auto iter : m_objects[i])
		{
			iter->UIRender();
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
