#include "stdafx.h"
#include "LeoniaSoldier.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"
#include"RigidBodyComponent.h"

void LeoniaSoldier::Init()
{	
	m_attackleft = false;
	m_move = false;
	m_hp = 10;
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Leon_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("Leon_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eAttack]->Setting(0,1.0f);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("Leon_Run");
	m_vimage[eRun]->Setting(0.1f, true);

	m_vimage[eHit] = IMAGEMANAGER->FindImageVector("Leon_Hit");
	m_vimage[eHit]->Setting(0.4f, true);

	m_attack = false;
	collision = m_obj->AddComponent<CollisionComponent>();
	collision2 = m_obj->AddComponent<CollisionComponent>();

	m_obj->GetCollisionComponent().push_back(collision);
	m_obj->GetCollisionComponent().push_back(collision2);
	//m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	//m_obj->GetCollisionComponent()->Setting(100, m_obj->x, m_obj->y); //<- 충돌범위와 위치
	//m_obj->AddComponent<PixelCollisionComponent>();
	//m_obj->GetComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	//m_obj->GetCollisionComponent()->Setting(80, m_obj->x, m_obj->y); //<- 충돌범위와 위치
	m_obj->AddComponent<RigidBodyComponent>();
	
	m_obj->AddCollisionComponent(collision);
}

void LeoniaSoldier::Update()
{
	collision->Setting(30,m_obj->x+17,m_obj->y-20,"Attack");
	
	//collision2->Setting(5, m_obj->x, m_obj->y, "Attack2");

	if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x - 300 && OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x + 300)
	{
		if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false)
		{
			m_obj->x -= DELTA_TIME*100.0f;
			m_move = true;
		}
		if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false)
		{
			m_obj->x += DELTA_TIME*100.0f;
			m_move = true;
		}
	}
	else
	{
		m_move = false;
	}
	if(m_vimage[eAttack]->GetIsImageEnded())
	{
		if (m_attackleft)
		{
			m_obj->x += DELTA_TIME * 100.0f;
		}
		else 
		{ m_obj->x -= DELTA_TIME * 100.0f; }

		m_vimage[eAttack]->Reset();
		m_attack = false;
	}
	
}

void LeoniaSoldier::Render()
{
	if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false && m_move == true)
	{
		m_attackleft = true;
		//state = eHit;
		m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y-36, 1.5, 1.5, 0,1);
	}
	else if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false && m_move == true)
	{
		m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y-36, 1.5, 1.5, 0,0);
		m_attackleft = false;
	}
	
	if(!m_attack && m_move == false)m_vimage[eIdle]->CenterRender((int)m_obj->x ,(int)m_obj->y-36,1.5,1.5,0);
	if (m_attack && m_move == false)
	{
			m_vimage[eAttack]->CenterRender((int)m_obj->x, (int)m_obj->y-36, 1.5, 1.5, 0, m_attackleft);	
	}
	//m_vimage[eHit]->Render(WINSIZE_X / 2 + 150, WINSIZE_Y / 2, 1, 1, 0);
}

void LeoniaSoldier::Release()
{

}

void LeoniaSoldier::OnCollision(string collisionName, Object* other)
{
	if (collisionName == collision->GetName())
	{
		if (other->GetName() == "player")
		{
			//other->GetComponent<Player>()-플레이어 상태쉉
			m_attack = true;
			m_move = false;	
		}
	}
}
