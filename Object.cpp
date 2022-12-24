#include "stdafx.h"
#include "Object.h"

void Object::Init()
{
}

void Object::Update()
{
	for (auto iter : m_components)
	{
		iter->Update();
	}
}

void Object::Render()
{
	for (auto iter : m_components)
	{
		iter->Render();
	}
}

void Object::Release()
{
	for (auto iter : m_components)
	{
		SAFE_DELETE(iter);
	}
	m_components.clear();
}

void Object::OnCollision(Object* other)
{
	for (auto iter : m_components)
	{
		iter->OnCollision(other);
	}
}
