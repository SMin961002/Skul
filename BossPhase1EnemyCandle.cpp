#include "stdafx.h"
#include "BossPhase1EnemyCandle.h"
#include "RigidBodyComponent.h"
#include "PixelCollisionComponent.h"
#include "Player.h"
#include "FireKnife.h"
void BossPhase1EnemyCandle::Init()
{
	m_state = eUp;
	m_isL = false;
	m_ratherImg = IMAGEMANAGER->FindImage("Rather");
	m_ratherY = 200;
	img[eUp] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Up");
	img[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Fire");
	img[eAttackReady] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_FireReady");
	img[eWalk] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Move");
	img[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Normal_Monster1_Idle");

	img[eUp]->Setting(0.1, false);
	img[eAttack]->Setting(0.1, false);
	img[eAttackReady]->Setting(0.1, false);
	img[eWalk]->Setting(0.1, true);
	img[eIdle]->Setting(0.1, false);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	m_obj->AddComponent<RigidBodyComponent>();
}

void BossPhase1EnemyCandle::Update()
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
		if (abs(m_obj->x - OBJECTMANAGER->m_player->GetplayerX()) < 200 || m_state == eAttackReady || m_state == eAttack)
		{
			if (img[eIdle]->GetIsImageEnded() == true)
			{
				if (img[eAttackReady]->GetIsImageEnded() == true)
				{
					if (m_state == eAttackReady)
					{
						OBJECTMANAGER->AddObject("Knife", m_obj->x, m_obj->y - 100, eObject)->AddComponent<FireKnife>();
					}
					m_state = eAttack;
					if (img[m_state]->GetIsImageEnded() == true)
					{
						img[eAttackReady]->Reset();
						img[eAttack]->Reset();
						img[eIdle]->Reset();
						m_state = eIdle;
					}
				}
				else
				{
					m_state = eAttackReady;
				}
			}
			else
			{
				m_state = eIdle;
				m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
			}
		}
		else if (img[eIdle]->GetIsImageEnded() == true)
		{
			m_state = eWalk;
			m_obj->x += DELTA_TIME * (OBJECTMANAGER->m_player->GetplayerX() > m_obj->x ? 30 : -30);
			m_isL = OBJECTMANAGER->m_player->GetplayerX() < m_obj->x;
		}
		else
		{
			m_state = eIdle;
		}
		m_ratherY += 9;
	}

}

void BossPhase1EnemyCandle::Render()
{

	IMAGEMANAGER->CenterRender(m_ratherImg, m_obj->x, m_obj->y + 100 + m_ratherY, 2, 2, 0, 0);
	img[m_state]->CenterRender(m_obj->x, m_obj->y + 30, 2, 2, 0, m_isL);
}

void BossPhase1EnemyCandle::Release()
{
}
