#include "stdafx.h"
#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
{
}

CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::Init()
{
}

void CollisionComponent::Update()
{
}

void CollisionComponent::Render()
{
	if (IMAGEMANAGER->GetViewCollision())
		IMAGEMANAGER->DrawCircle(m_collisionX, m_collisionY, m_range);
}

void CollisionComponent::Release()
{
}

void CollisionComponent::Setting(float range, float x, float y, string name)
{
	m_collisionName = name;
	m_collisionX = x;
	m_collisionY = y;
	m_range = range;
}
