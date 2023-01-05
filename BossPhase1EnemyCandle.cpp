#include "stdafx.h"
#include "BossPhase1EnemyCandle.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
void BossPhase1EnemyCandle::Init()
{
	m_ratherImg = IMAGEMANAGER->FindImage("Rather");
	m_ratherY = 200;
	img = IMAGEMANAGER->AddImageVectorCopy("Phase1_Boss_Enemy_Fnatic_Candle_G");
	img->Setting(0.1, false);
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	m_obj->AddComponent<RigidBodyComponent>();
}

void BossPhase1EnemyCandle::Update()
{
}

void BossPhase1EnemyCandle::Render()
{
	if (img->GetIsImageEnded() == false)
	{

		if (m_ratherY > 0)
		{
			m_ratherY -= 3;
		}
	}
	else
	{
		m_ratherY += 9;
	}

	IMAGEMANAGER->CenterRender(m_ratherImg, m_obj->x, m_obj->y + 100 + m_ratherY, 2, 2, 0, 0);
	img->CenterRender(m_obj->x, m_obj->y+30, 2, 2, 0, 0);
}

void BossPhase1EnemyCandle::Release()
{
}
