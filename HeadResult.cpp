#include "stdafx.h"
#include "HeadResult.h"
#include "CollisionComponent.h"
#include "HeadItem.h"

void HeadResult::Reword()
{
	OBJECTMANAGER->AddObject("Item", m_obj->x, m_obj->y, eBoss)->AddComponent<HeadItem>();
	m_obj->ObjectDestroyed();
}

void HeadResult::Setting()
{
	m_obj->GetComponent<CollisionComponent>()->Setting(m_obj->x + 50, m_obj->y + 120);
	this->m_idleImg = IMAGEMANAGER->AddImageVectorCopy("HeadResult");
	this->m_idleImg->Setting(0.1f, true);
	this->m_idleImg->Reset();
	this->m_activeImg = IMAGEMANAGER->AddImageVectorCopy("HeadResultActive");
	this->m_activeImg->Setting(0.1, false);
	this->m_activeImg->Reset();
}
