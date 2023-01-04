#include "stdafx.h"
#include "GoldResult.h"

void GoldResult::Setting()
{
	this->m_idleImg = IMAGEMANAGER->FindImageVector("GoldResoult");
	this->m_idleImg->Setting(0.1, true);
}

void GoldResult::Reword()
{
}
