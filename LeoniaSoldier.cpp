#include "stdafx.h"
#include "LeoniaSoldier.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"
#include"EnemyEffect.h"
#include"Gold.h"


void LeoniaSoldier::Init()
{
	m_maxhp = 100.0f;
	m_currenthp = 100.0f;
	m_hiteffecttimer = 0;
	m_hpbartimer = 0;
	m_hpbar = 0;
	m_die = false;
	m_attackleft = false;
	m_attack = false;
	m_move = false;
	m_hit = false;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Leon_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Leon_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eAttack]->Setting(0, 1.0f);

	m_vimage[eRun] = IMAGEMANAGER->AddImageVectorCopy("Leon_Run");
	m_vimage[eRun]->Setting(0.1f, true);

	m_vimage[eHit] = IMAGEMANAGER->AddImageVectorCopy("Leon_Hit");
	m_vimage[eHit]->Setting(0.4f, true);

	m_vimage[eHPbarEmpty] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Empty");
	m_vimage[eHPbarEmpty]->Setting(0.4f, false);

	m_vimage[eHpbarDown] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Down");
	m_vimage[eHpbarDown]->Setting(0.4f, false);

	m_vimage[eHpbarUp] = IMAGEMANAGER->AddImageVectorCopy("Hpbar_Up");
	m_vimage[eHpbarUp]->Setting(0.4f, false);


	m_collision = m_obj->AddComponent<CollisionComponent>();
	m_hitpointcollision = m_obj->AddComponent<CollisionComponent>();

	m_obj->GetCollisionComponent().push_back(m_collision);
	m_obj->GetCollisionComponent().push_back(m_hitpointcollision);


	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(m_collision);
	m_obj->AddCollisionComponent(m_hitpointcollision);
}

void LeoniaSoldier::Update()
{
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_collision->Setting(30, m_obj->x + 17, m_obj->y - 20, "Attack");
	if (m_hit)
	{
		m_hpbartimer += DELTA_TIME;
	}
	if (m_vimage[eAttack]->GetFrame() >= 1)
	{
		m_hitpointcollision->SetIsActive(true);
		if (m_attackleft)
		{
			m_obj->x -= DELTA_TIME * 50.0f;
			m_hitpointcollision->Setting(40, m_obj->x - 17, m_obj->y - 20, "AttackPoint");
		}
		else
		{
			m_obj->x += DELTA_TIME * 50.0f;
			m_hitpointcollision->Setting(40, m_obj->x + 40, m_obj->y - 20, "AttackPoint");
		}
	}


	if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x - 400 && OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x + 400)
	{
		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false)
		{
			m_obj->x -= DELTA_TIME * 150.0f;
			m_move = true;
		}
		if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false)
		{
			m_obj->x += DELTA_TIME * 150.0f;
			m_move = true;
		}
	}
	else
	{
		m_move = false;
	}
	if (m_vimage[eAttack]->GetIsImageEnded())
	{
		m_vimage[eAttack]->Reset();
		m_attack = false;
	}
	if (m_attack == false)
	{
		m_hitpointcollision->SetIsActive(false);
	}
	m_hpbar = (1 / m_maxhp);
	m_hiteffecttimer += DELTA_TIME;
	m_dietimer += DELTA_TIME;
}

void LeoniaSoldier::Render()
{
	if (m_currenthp >= 0)
	{
		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false && m_move == true)
		{
			m_attackleft = true;
			m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, 1);
		}
		else if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false && m_move == true)
		{
			m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, 0);
			m_attackleft = false;
		}
		if (!m_attack && m_move == false)m_vimage[eIdle]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0);
		if (m_attack && m_move == false)
		{
			m_vimage[eAttack]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, m_attackleft);
		}
		if (KEYMANAGER->GetOnceKeyDown('p'))
		{
			m_vimage[eHit]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, m_attackleft);
		}
		if (m_hpbartimer <= 2 && m_hit == true)
		{
			m_vimage[eHPbarEmpty]->Render(m_obj->x - 35, m_obj->y + 15, 1, 1, 0);
			m_vimage[eHpbarDown]->Render(m_obj->x - 35, m_obj->y + 15, 1, 1, 0);
			m_vimage[eHpbarUp]->Render(m_obj->x - 35, m_obj->y + 15, (m_currenthp * m_hpbar), 1, 0);
		}
		else
		{
			m_hit = false;
			m_hpbartimer = 0;
		}
	}
	else
	{

		if (!m_die && m_dietimer >= 1)
		{
			EFFECTMANAGER->AddEffect<DeadEffect>(m_obj->x, m_obj->y, 1, 1.5);
			m_dietimer = 0;
		}
		m_die = true;
		if (m_dietimer >= 0.5f)
		{
			m_hitpointcollision->SetIsActive(false);
			for (int i = 0; i < 4; i++)
			{
				OBJECTMANAGER->AddObject("Gold", m_obj->x, m_obj->y - 50, ObjectTag::eItem)->AddComponent<Gold>();
			}
			m_obj->ObjectDestroyed();
		}
	}
	cout << m_currenthp << endl;
}

void LeoniaSoldier::Release()
{
}

void LeoniaSoldier::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collision->GetName())
	{
		if (other->GetName() == "player")
		{
			//other->GetComponent<Player>()-플레이어 상태쉉
			m_attack = true;
			m_move = false;
		}
	}

	if (collisionName == m_hitpointcollision->GetName())
	{
		if (other->GetName() == "player")
		{
			m_hitpoint = true;
		}
	}
}



void LeoniaSoldier::HitEnemy(float dmg)
{
	/*m_isAttack = false;
	m_isHit = true;
	m_state = eHit;*/
	if (m_hiteffecttimer >= 0.7f)
	{
		m_vimage[eHit]->Reset();
		m_obj->x += m_obj->x > OBJECTMANAGER->m_player->GetplayerX() ? DELTA_TIME * 500 : -DELTA_TIME * 500;
		m_obj->y -= 10;
		m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
		dmg = 10; //-= 플레이어 어택 데미지 상의
		m_currenthp -= dmg;
		
		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
		{
			EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 0, 2);
		}
		else
		{
			EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 1, 2);
		}
		m_hit = true;
		m_hiteffecttimer = 0;
		
	}
}