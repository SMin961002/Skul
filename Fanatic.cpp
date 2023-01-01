#include "stdafx.h"
#include "Fanatic.h"
#include "RigidBodyComponent.h"
#include "CollisionComponent.h"
#include "Player.h"
void Fanatic::Init()
{
	m_maxhp = 300.0f;
	m_currenthp = 300.0f;
	m_hpbar = 0;
	m_hitTimer = 0;
	m_isHit = false;
	m_state = eIdle;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Idle");
	m_vimage[eIdle]->Setting(0.1f, true);
	m_vimage[eAttackIdle] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_AttackIdle");
	m_vimage[eAttackIdle]->Setting(0.1f, true);
	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eRunAttack] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Runattack");
	m_vimage[eRunAttack]->Setting(0.1f, true);
	m_vimage[eRun] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Run");
	m_vimage[eRun]->Setting(0.1f, true);
	m_vimage[Setcrifice] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Setcrifice");
	m_vimage[Setcrifice]->Setting(0.1f, true);
	m_vimage[SetcrificeLoop] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Setcrificeloop");
	m_vimage[SetcrificeLoop]->Setting(0.1f, true);
	m_vimage[SetcrificeReady] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Setcrificeready");
	m_vimage[SetcrificeReady]->Setting(0.1f, true);
	m_vimage[eHit] = IMAGEMANAGER->AddImageVectorCopy("Fanatic_Hit");
	m_vimage[eHit]->Setting(0.2f, false);

	m_vimage[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	m_vimage[eHPbarEmpty]->Setting(0.4f, false);
	m_vimage[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	m_vimage[eHpbarDown]->Setting(0.4f, false);
	m_vimage[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	m_vimage[eHpbarUp]->Setting(0.4f, false);

	m_isReverse = false;
	m_isAttack = false;

	m_hitCollision = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_hitCollision);
}

void Fanatic::Update()
{
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);

	m_hitCollision->Setting(30,m_obj->x+15,m_obj->y-10,"HitCollision");
	if (m_isHit == true)
	{
		m_hitTimer += DELTA_TIME;
	}
	else
	{
	}
	float xDest = m_obj->x - OBJECTMANAGER->m_player->GetplayerX();
	if (m_isAttack == false && m_isHit == false)
	{
		if (xDest < 300 && xDest > -300)
		{
			if (xDest < 100 && xDest > -100)
			{
				m_state = eAttack;
				m_vimage[eAttack]->Reset();

				m_isAttack = true;
			}
			else
			{
				m_state = eRun;
				m_obj->x += m_isReverse ? -DELTA_TIME * 50 : DELTA_TIME * 50;
			}
			m_isReverse = xDest > 0;
		}
		else
		{
			m_state = eIdle;
		}
	}
	m_hpbar = (1 / m_maxhp);
	ImageResetCheck();
	if (KEYMANAGER->GetOnceKeyDown(VK_F3))
	{

	}
}

void Fanatic::Render()
{
	if (m_currenthp >= 0)
	{
		m_vimage[m_state]->CenterRender(m_obj->x, m_obj->y - 55, 2, 2, 0, m_isReverse);
		m_vimage[eHPbarEmpty]->Render(m_obj->x - 20, m_obj->y + 15, 1, 1, 0);
		m_vimage[eHpbarDown]->Render(m_obj->x - 20, m_obj->y + 15, 1, 1, 0);
		m_vimage[eHpbarUp]->Render(m_obj->x - 20, m_obj->y + 15, (m_currenthp * m_hpbar), 1, 0);
	}
	else
	{
		m_obj->Release();
	}
}

void Fanatic::Release()
{
}

void Fanatic::OnCollision(string collisionName, Object* other)
{
}

void Fanatic::HitEnemy(float dmg)
{
	m_isAttack = false;
	m_isHit = true;
	m_state = eHit;
	m_vimage[eHit]->Reset();
	m_obj->x += m_isReverse ? DELTA_TIME * 500 : -DELTA_TIME * 500;
	m_obj->y -= 10;
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	dmg = 10; //-= 플레이어 어택 데미지 상의
	m_currenthp -= dmg;
}

void Fanatic::ImageResetCheck()
{
	if (m_isAttack == true && m_vimage[eAttack]->GetIsImageEnded() == true)
	{
		m_isAttack = false;
	}
	else if (m_hitTimer >= 0.3f)
	{
		m_isHit = false;
		m_hitTimer = 0;
	}
}
