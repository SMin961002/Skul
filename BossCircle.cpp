#include "stdafx.h"
#include "BossCircle.h"

void BossCircle::Init()
{
	img[eCreate] = IMAGEMANAGER->AddImageVectorCopy("Circle");
	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("CircleIdle");
	img[eDis] = IMAGEMANAGER->AddImageVectorCopy("CircleDis");

	img[eCreate]->Setting(0.1, false);
	img[eIdle]->Setting(0.1, false);
	img[eDis]->Setting(0.1f, false);
	m_state = eCreate;
}

void BossCircle::Update()
{
	if (img[eCreate]->GetIsImageEnded() == true)
	{
		m_state = eIdle;
	}
}

void BossCircle::Render()
{
	img[m_state]->CenterRender(m_obj->x, m_obj->y, 1.5f, 1.5f, 0, 0);
}

void BossCircle::Release()
{
}
