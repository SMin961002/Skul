#include "stdafx.h"
#include "Component.h"
#include "Object.h"

Component::Component()
{
}

Component::~Component()
{
}

void Component::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
}

void Component::SetPosition(float x, float y)
{
	m_obj->x = x; m_obj->y = y;
}