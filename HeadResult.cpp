#include "stdafx.h"
#include "HeadResult.h"

void HeadResult::Reword()
{
}

void HeadResult::Setting()
{
	this->m_idleImg = IMAGEMANAGER->FindImageVector("HeadResult");
	this->m_idleImg->Setting(0.1f,true);
	this->m_activeImg = IMAGEMANAGER->FindImageVector("HeadResultActive");
	this->m_activeImg->Setting(0.1, false);
}
