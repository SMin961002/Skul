#include "stdafx.h"
#include "BossBall.h"

BossBall::BossBall()
{
}

BossBall::~BossBall()
{
}

void BossBall::Init()
{
	startX = m_obj->x;
	startY = m_obj->y;
	ldist = false;
	m_state = eStart;
	img[eStart] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_CreateBall_Start");
	img[eStart]->Setting(0.1, false);
	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_CreateBall_Idle");
	img[eIdle]->Setting(0.07, true);
	//img[eDis] = IMAGEMANAGER->AddImageVectorCopy("");
}

void BossBall::Update()
{
	if (ldist == false)
	{
		if (dist < 200)
		{
			dist += 1;
		}
		else
		{
			if (dist > 200)
			{
				dist -= 1;
			}
			rot += 0.01;
		}
	}
	else
	{
		if (dist < 500)
		{
			dist += 1;
		}
		rot += 0.01;
	}

	m_obj->x = startX + cos(rot) * dist;
	m_obj->y = startY + sin(rot) * dist;
}

void BossBall::Render()
{
	if (img[eStart]->GetIsImageEnded() == true)
	{
		m_state = eIdle;
	}
	img[m_state]->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0);
}

void BossBall::Release()
{
}

void BossBall::Setting(float rot)
{
	this->rot = rot;
	dist = 0;
}
