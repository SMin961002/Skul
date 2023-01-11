#include "stdafx.h"
#include "Object.h"

void Object::Init()
{
}

void Object::Update()
{
	for (auto iter =m_components.begin(); iter !=m_components.end();)
	{
		if ((*iter)->GetIsDelete() == true)
		{
			(*iter)->Release();
			SAFE_DELETE(*iter);
			iter = m_components.erase(iter);
		}
		else
		{
			(*iter)->Update();
			iter++;
		}
	}
}

void Object::Render()
{
	for (auto iter : m_components)
	{
		if (iter->GetIsActive() == true)
			iter->Render();
	}
}

void Object::Release()
{
	for (auto iter : m_components)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_components.clear();
}

void Object::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	for (auto iter : m_components)
	{
		iter->OnCollision(coll1,coll2, other);
	}
}

void Object::UIRender()
{
	for (auto iter : m_components)
	{
		iter->UIRender();
	}
}
