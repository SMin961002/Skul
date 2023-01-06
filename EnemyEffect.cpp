#include "stdafx.h"
#include "EnemyEffect.h"

void Secrifice::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("Secrifice");
	m_img->Setting(0.1, false);
}

void SkulAttack::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("SkulAttack");
	m_img->Setting(0.01, false);
}

void DeadEffect::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("DeadEffect");
	m_img->Setting(0.05, false);
}

void Appear::Init()
{
	Effect::Init();
	m_img = IMAGEMANAGER->AddImageVectorCopy("AppearEffect");
	m_img->Setting(0.08, false);
}
