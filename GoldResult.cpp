#include "stdafx.h"
#include "GoldResult.h"
#include "Gold.h"
void GoldResult::Setting()
{
	this->m_idleImg = IMAGEMANAGER->AddImageVectorCopy("GoldResoult");
	this->m_idleImg->Setting(0.1, true);

	this->m_activeImg = IMAGEMANAGER->AddImageVectorCopy("GoldResoultActive");
	this->m_activeImg->Setting(0.1, false);
}

void GoldResult::Reword()
{
	for (int i = 0; i < 30; i++)
	{
		m_obj->ObjectDestroyed();
		OBJECTMANAGER->AddObject("Gold", m_obj->x, m_obj->y, eItem)->AddComponent<Gold>()->Setting(10);
	}
}
