#include "stdafx.h"
#include "LeoniaSoldier.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"

void LeoniaSoldier::Init()
{	
	m_maxhp = 300.0f;
	m_currenthp = 300.0f;
	m_hpbar = 0;
	m_attackleft = false;
	m_attack = false;
	m_move = false;
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Leon_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Leon_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eAttack]->Setting(0,1.0f);

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
}

void LeoniaSoldier::Update()
{
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);

	m_collision->Setting(30,m_obj->x+17,m_obj->y-20,"Attack");
	if (m_vimage[eAttack]->GetFrame() >= 1)
	{
		if (m_attackleft)
		{
			m_obj->x -= DELTA_TIME * 50.0f;
		}
		else
		{
			m_obj->x += DELTA_TIME * 50.0f;
		}
	}


	if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x - 400 && OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x + 400)
	{
		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false)
		{
			m_obj->x -= DELTA_TIME*150.0f;
			m_move = true;
		}
		if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false)
		{
			m_obj->x += DELTA_TIME*150.0f;
			m_move = true;
		}
	}
	else
	{
		m_move = false;
	}
	if(m_vimage[eAttack]->GetIsImageEnded())
	{
		m_vimage[eAttack]->Reset();
		m_attack = false;
	}
	m_hpbar = (1 / m_maxhp);
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
		m_vimage[eHPbarEmpty]->Render(m_obj->x-20, m_obj->y + 15, 1, 1, 0);
		m_vimage[eHpbarDown]->Render(m_obj->x-20, m_obj->y + 15, 1, 1, 0);
		m_vimage[eHpbarUp]->Render(m_obj->x-20, m_obj->y + 15, (m_currenthp * m_hpbar), 1, 0);
	}
	else
	{
		m_obj->Release();
	}

	cout << m_currenthp*m_hpbar << endl;
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
}



void LeoniaSoldier::HitEnemy(float dmg)
{
	/*m_isAttack = false;
	m_isHit = true;
	m_state = eHit;*/
	m_vimage[eHit]->Reset();
	m_obj->x += m_obj->x > OBJECTMANAGER->m_player->GetplayerX() ? DELTA_TIME * 500 : -DELTA_TIME * 500;
	m_obj->y -= 10;
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
	dmg = 10; //-= 플레이어 어택 데미지 상의
	m_currenthp -= dmg;
}