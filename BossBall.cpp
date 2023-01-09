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

	m_state = eStart;
	img[eStart] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_CreateBall_Start");
	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Phase2_Ball_CreateBall_Idle");
	//img[eDis] = IMAGEMANAGER->AddImageVectorCopy("");
}

void BossBall::Update()
{
	if (dist < 50)
	{
		dist += 0.1;
	}

	m_obj->x = startX + cos(rot) * dist;
	m_obj->y = startX + cos(rot) * dist;
}

void BossBall::Render()
{
	img[m_state]->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void BossBall::Release()
{
}

void BossBall::Setting(float rot)
{
	this->rot = rot;
	dist = 0;
}
