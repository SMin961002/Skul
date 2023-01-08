#include "stdafx.h"
#include "Card.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "Enemy.h"
//speed  ¹Ù²ãº¸±â
void Card::Init()
{
	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(10, m_obj->x + 120, m_obj->y - 8, "GamblerCard");
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);
	m_isJokerHit = false;
	m_isLeft = OBJECTMANAGER->m_player->GetplayerIsLeft();
	m_startX = OBJECTMANAGER->m_player->GetplayerX();
	int a = MY_UTILITY::getInt(5);
	if (a == 0)
	{
		m_isJoker = true;
		m_img = IMAGEMANAGER->FindImage("GamblerCardJoker");
	}
	else
	{
		m_isJoker = false;
		m_img = IMAGEMANAGER->FindImage("GamblerCardNormal");
	}
}

void Card::Update()
{
	cout << "startX : " << m_startX << endl;
	if (m_isJokerHit)
	{
		if (m_jokerExplosion->GetIsEffectEnded())
		{
			m_coll->SetIsActive(false);
			m_coll->SetIsDelete(true);
			m_obj->ObjectDestroyed();
		}
	}//end jokerExplosion
	else {
		m_obj->x = m_isLeft ? m_obj->x - m_speed * DELTA_TIME : m_obj->x + m_speed * DELTA_TIME;
		cout << m_obj->x << endl;
		float distance = m_obj->x - m_startX;
		if (distance < 0) distance = -distance;
		cout << "distance : " << distance << endl;
		PixelCollisionComponent* px = m_obj->GetComponent<PixelCollisionComponent>();
		if (px->GetIsBottomCollision() || px->GetIsTopCollision()
			|| px->GetIsLeftCollision() || px->GetIsRightCollision()
			|| distance > WINSIZE_X)
		{
			m_obj->ObjectDestroyed();
		}
		if (m_isLeft)
			m_coll->Setting(m_obj->x - 19, m_obj->y+4);
		else
			m_coll->Setting(m_obj->x + 24, m_obj->y+4);
	}//end else
}

void Card::Render()
{
	if (!m_isJokerHit)
	{
		if (m_isLeft)
			IMAGEMANAGER->CenterRender(m_img, m_obj->x - 16, m_obj->y - 3, 2, 2, 0, m_isLeft);
		else
			IMAGEMANAGER->CenterRender(m_img, m_obj->x + 16, m_obj->y - 3, 2, 2, 0, m_isLeft);
	}
}

void Card::Release()
{
}

void Card::OnCollision(string collisionName, Object* other)
{
	if (other->GetName() == "Enemy")
	{
		bool isOtherHit = false;
		for (auto iter : m_vectorCollisionList)
		{
			if (iter == other)
			{
				isOtherHit = true;
			}
			else false;
		}
		if (!isOtherHit)
		{
			Enemy* e = other->GetComponent<Enemy>();
			if (m_isJoker)
			{
				e->HitEnemy(20, IMAGEMANAGER->FindImageVector("Gambler_JockerExplosion")->GetTotalDelay());

				if (!m_isJokerHit)
				{
					m_jokerExplosion = EFFECTMANAGER->AddEffect<JokerExplosion>(m_obj->x, m_obj->y, m_isLeft, 2);
					m_jokerExplosion->Init();
					if (m_isLeft)
						m_coll->Setting(120, m_obj->x+60, m_obj->y+60);
					else
						m_coll->Setting(120, m_obj->x + 60, m_obj->y+60);
					m_isJokerHit = true;
				}//end if not jokerhit
			}//end joker
			else
			{
				e->HitEnemy(10, 0.2);
			}//end not joker
			m_vectorCollisionList.push_back(other);
		}//end if nohit
	}
}
