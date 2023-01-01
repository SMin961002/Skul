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
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);

	m_hp = 10;
	m_vimage[eIdle] = IMAGEMANAGER->AddImageVectorCopy("Leon_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->AddImageVectorCopy("Leon_Attack");
	m_vimage[eAttack]->Setting(0.1f, false);
	m_vimage[eAttack]->Setting(0,1.0f);

	m_vimage[eRun] = IMAGEMANAGER->AddImageVectorCopy("Leon_Run");
	m_vimage[eRun]->Setting(0.1f, true);

	m_vimage[eHit] = IMAGEMANAGER->AddImageVectorCopy("Leon_Hit");
	m_vimage[eHit]->Setting(0.4f, true);

	m_attack = false;
	collision = m_obj->AddComponent<CollisionComponent>();
	collision2 = m_obj->AddComponent<CollisionComponent>();

	m_obj->GetCollisionComponent().push_back(collision);
	m_obj->GetCollisionComponent().push_back(collision2);
	
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->AddCollisionComponent(collision);
}

void LeoniaSoldier::Update()
{
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);

	collision->Setting(30,m_obj->x+17,m_obj->y-20,"Attack");
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

	//collision2->Setting(5, m_obj->x, m_obj->y, "Attack2");

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
	
}

void LeoniaSoldier::Render()
{
	if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x && m_attack == false && m_move == true)
	{
		m_attackleft = true;
		m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y-45, 2, 2, 0,1);
	}
	else if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x && m_attack == false && m_move == true)
	{
		m_vimage[eRun]->CenterRender((int)m_obj->x, (int)m_obj->y-45, 2, 2, 0,0);
		m_attackleft = false;
	}	
	if(!m_attack && m_move == false)m_vimage[eIdle]->CenterRender((int)m_obj->x ,(int)m_obj->y-45,2,2,0);
	if (m_attack && m_move == false)
	{
			m_vimage[eAttack]->CenterRender((int)m_obj->x, (int)m_obj->y-45, 2, 2, 0, m_attackleft);			
	}
	if (KEYMANAGER->GetOnceKeyDown('p'))
	{
		m_vimage[eHit]->CenterRender((int)m_obj->x, (int)m_obj->y - 45, 2, 2, 0, m_attackleft);
	}
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

void LeoniaSoldier::HitEnemy(float dmg)
{
	/*m_isAttack = false;
	m_isHit = true;
	m_state = eHit;*/
	m_vimage[eHit]->Reset();
	m_obj->x += m_obj->x > OBJECTMANAGER->m_player->GetplayerX() ? DELTA_TIME * 500 : -DELTA_TIME * 500;
	m_obj->y -= 10;
	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(false);
}