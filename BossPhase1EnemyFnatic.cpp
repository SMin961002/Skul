#include "stdafx.h"
#include "BossPhase1EnemyFnatic.h"
#include "Player.h"

void BossPhase1EnemyFnatic::Init()
{

	m_ratherImg = IMAGEMANAGER->FindImage("Rather");
	m_ratherY = 200;

	m_state = eUp;
	m_isL = false;

	img[eUp] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Up");
	img[eUp]->Setting(0.1, false);

	img[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Attack");
	img[eAttack]->Setting(0.1, false);

	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Idle");
	img[eIdle]->Setting(0.1, false);

	img[eWalk] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster2_Move");
	img[eWalk]->Setting(0.1, true);

}

void BossPhase1EnemyFnatic::Update()
{
}

void BossPhase1EnemyFnatic::Render()
{
	if (img[eUp]->GetIsImageEnded() == false)
	{
		if (m_ratherY > 0)
		{
			m_ratherY -= 3;
		}
	}
	else
	{
		if (img[eIdle]->GetIsImageEnded() == true)
		{
			if (abs(OBJECTMANAGER->m_player->GetplayerX() - m_obj->x) < 100 || m_state == eAttack)
			{
				m_state = eAttack;
				if (img[eAttack]->GetIsImageEnded() == true)
				{
					img[eIdle]->Reset();
					img[eAttack]->Reset();
				}
			}
			else
			{
				m_obj->x += DELTA_TIME * (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x ? 150 : -150);
				m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
				m_state = eWalk;
			}

		}
		else
		{
			m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
			m_state = eIdle;
			m_ratherY += 9;
		}
	}


	IMAGEMANAGER->CenterRender(m_ratherImg, m_obj->x, m_obj->y + 80 + m_ratherY, 2, 2, 0, 0);

	img[m_state]->CenterRender(m_obj->x, m_obj->y + 70, 2, 2, 0, m_isL);
}

void BossPhase1EnemyFnatic::Release()
{
}
