#include "stdafx.h"
#include "LeoniaSoldier.h"
#include "CollisionComponent.h"
#include"Player.h"
#include"PixelCollisionComponent.h"

void LeoniaSoldier::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("Leon_Idle");
	m_vimage[eIdle]->Setting(0.3f, true);

	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("Leon_Attack");
	m_vimage[eAttack]->Setting(0.1f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("Leon_Run");
	m_vimage[eRun]->Setting(0.8f, true);

	m_vimage[eHit] = IMAGEMANAGER->FindImageVector("Leon_Hit");
	m_vimage[eHit]->Setting(0.4f, true);

	m_attack = false;
	//m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	//m_obj->GetCollisionComponent()->Setting(100, m_obj->x, m_obj->y); //<- 충돌범위와 위치
	//m_obj->AddComponent<PixelCollisionComponent>();
	//m_obj->GetComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
}

void LeoniaSoldier::Update()
{
	//if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision() == false)
	//{
	//	m_obj->y += 0.1;
	//}
	//m_obj->GetCollisionComponent()->Setting(20, m_obj->x + 50, m_obj->y + 40);
	move();
}

void LeoniaSoldier::Render()
{
	//m_vimage[eRun]->Render(WINSIZE_X / 2+50, WINSIZE_Y / 2,1,1,0);

	if (!m_attack)m_vimage[eIdle]->CenterRender((int)m_obj->x, (int)m_obj->y, 1.5, 1.5, 0);
	if (m_attack)
	{
		if (OBJECTMANAGER->m_player->GetplayerX() >= m_obj->x)
		{
			m_vimage[eAttack]->CenterRender((int)m_obj->x, (int)m_obj->y, 1.5, 1.5, 0, 0);
		}
		else
		{
			m_vimage[eAttack]->CenterRender((int)m_obj->x, (int)m_obj->y, 1.5, 1.5, 0, 1);
		}
	}
	//m_vimage[eHit]->Render(WINSIZE_X / 2 + 150, WINSIZE_Y / 2, 1, 1, 0);
	if (KEYMANAGER->GetToggleKey(VK_F1))
	{

	}
}

void LeoniaSoldier::Release()
{

}

void LeoniaSoldier::OnCollision(string collisionName, Object* other)
{
	if (other->GetName() == "player")
	{
		m_attack = true;
		//state = eHit;
	}
}

void LeoniaSoldier::move()
{

}
