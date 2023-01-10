#include "stdafx.h"
#include "Lazer.h"

void Lazer::Init()
{
	img[eStart] = IMAGEMANAGER->AddImageVectorCopy("Boss_Consecration_Start");
	img[eLoop] = IMAGEMANAGER->AddImageVectorCopy("Boss_Consecration_Loop");
	img[eLast] = IMAGEMANAGER->AddImageVectorCopy("Boss_Consecration_End");
	img[eStart]->Setting(DELTA_TIME, false);
	img[eLoop]->Setting(0.06, false);
	img[eLast]->Setting(0.07, false);
	/*
	Boss_Consecration_Start
	Boss_Consecration_Sign"
	Boss_Consecration_Loop"
	Boss_Consecration_End",
	*/
	m_state = eStart;
}

void Lazer::Update()
{
}

void Lazer::Render()
{
	if (img[eStart]->GetIsImageEnded() == true)
	{
		m_state = eLoop;
	}
	if (img[eLoop]->GetIsImageEnded() == true)
	{
		m_state = eLast;
	}
	if (img[eLast]->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
	}
	if (m_state == eLoop)
	{
		img[m_state]->CenterRender(m_obj->x + 250, m_obj->y, 1.5, 3, 90);
	}
	else if (m_state == eStart)
	{
		img[m_state]->CenterRender(m_obj->x + 250, m_obj->y, 1.5, 3, 90);
	}
	else
	{
		img[m_state]->CenterRender(m_obj->x + 250, m_obj->y, 1.5, 3, 90);
	}
}

void Lazer::Release()
{
}
