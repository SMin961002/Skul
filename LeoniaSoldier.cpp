#include "stdafx.h"
#include "LeoniaSoldier.h"
#include "CollisionComponent.h"

void LeoniaSoldier::Init()
{
	m_vimage[eIdle] = IMAGEMANAGER->FindImageVector("leonidle");
	m_vimage[eIdle]->Setting(0.3f,true);
	
	m_vimage[eAttack] = IMAGEMANAGER->FindImageVector("leonattack");
	m_vimage[eAttack]->Setting(0.8f, true);

	m_vimage[eRun] = IMAGEMANAGER->FindImageVector("leonrun");
	m_vimage[eRun]->Setting(0.8f, true);

	m_vimage[eHit] = IMAGEMANAGER->FindImageVector("leonhit");
	m_vimage[eHit]->Setting(0.4f, true);

	m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	//m_obj->GetCollisionComponent()->Setting(); //<- 충돌범위와 위치

}

void LeoniaSoldier::Update()
{

	
}

void LeoniaSoldier::Render()
{
	m_vimage[eRun]->Render(WINSIZE_X / 2+50, WINSIZE_Y / 2,1,1,0);
	m_vimage[eIdle]->Render(WINSIZE_X / 2, WINSIZE_Y / 2,1,1,0);
	m_vimage[eAttack]->Render(WINSIZE_X / 2 + 100, WINSIZE_Y / 2, 1, 1, 0);
	m_vimage[eHit]->Render(WINSIZE_X / 2 + 150, WINSIZE_Y / 2, 1, 1, 0);
}

void LeoniaSoldier::Release()
{

}

void LeoniaSoldier::OnCollision(Object* other)
{
	if (other->GetName() == "player")
	{
		//state = eHit;
	}
}
