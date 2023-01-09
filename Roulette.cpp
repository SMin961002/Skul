#include "stdafx.h"
#include "Roulette.h"
#include "Player.h"

void Roulette::Init()
{
	string boombImage = "Gambler_Roulette_";
	m_resultColor = MY_UTILITY::getInt(2);
	if (m_resultColor == eRed) boombImage.append("Red");
	else boombImage.append("Black");

	//int tmp = MY_UTILITY::getInt(10);
	int tmp = 9;
	if (tmp == 9)
	{
		m_resultSuccess = 1;
		boombImage.append("Big");
	}
	else if (tmp > 1)
	{
		m_resultSuccess = 0;
	}
	else
	{
		m_resultSuccess = -1;
	}

	m_explosion = IMAGEMANAGER->FindImageVector(boombImage);
	m_explosion->Setting(0.05, false);
	if (m_resultColor == eRed && m_resultSuccess == 1)
	{
		for (int i = 31; i < 38; i++)
		{
			m_explosion->Setting(i, 0.07);
		}
	}

	if (m_resultSuccess == 1)
	{
		m_roulette = IMAGEMANAGER->FindImageVector("Gambler_RouletteBigShot");
		EFFECTMANAGER->AddEffect<RouletteBigShot>(m_obj->x, m_obj->y, false, 2);
	}
	else
	{
		m_roulette = IMAGEMANAGER->FindImageVector("Gambler_Roulette");
		EFFECTMANAGER->AddEffect<RouletteShot>(m_obj->x, m_obj->y, false, 2);
	}

	if (m_resultColor == eBlack)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRouletteBlack");
	else if (m_resultColor == eRed)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRouletteRed");
	else
	{
		cout << "룰렛 결과값이 이상하다. " << m_resultColor << endl;
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRouletteRed");
	}

	if (OBJECTMANAGER->m_player->GetplayerIsLeft())
	{
		m_obj->x += 100;
	}
	else m_obj->x -= 100;
	m_obj->y -= 108;

	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(10, m_obj->x + 120, m_obj->y - 8, "GamblerRoulette");
	m_coll->SetIsActive(true);

	m_rotateCount = 0;
	m_boombRoulette = false;
	m_printRouletteResult = false;
	m_isInBreakEffect = false;
	m_delay = 2;

	EFFECTMANAGER->AddEffect<RouletteReady>(m_obj->x, m_obj->y, false, 2);
}
void Roulette::Update()
{
	if (m_roulette->GetIsImageEnded())
	{
		if (++m_rotateCount < 4)
		{
			m_roulette->Reset();
			if (m_resultSuccess == 1)
				EFFECTMANAGER->AddEffect<RouletteBigShot>(m_obj->x, m_obj->y, false, 2);
			else
				EFFECTMANAGER->AddEffect<RouletteShot>(m_obj->x, m_obj->y, false, 2);
		}
		else if(!m_boombRoulette) m_printRouletteResult = true;
	}

	if (m_printRouletteResult)
	{
		if (!m_isInBreakEffect)
		{
				m_isInBreakEffect = true;
				if (m_resultSuccess == 1)
					EFFECTMANAGER->AddEffect<RouletteBrokenEffectBigShot>(m_obj->x, m_obj->y, false, 2);
				else
					EFFECTMANAGER->AddEffect<RouletteBrokenEffect>(m_obj->x, m_obj->y, false, 2);
		}
		m_delay -= DELTA_TIME;
		if (m_delay <= 0)
		{
			m_printRouletteResult = false;
			m_boombRoulette = true;
			m_delay = 1;
		}
	}
	if (m_boombRoulette)
	{
		m_delay -= DELTA_TIME;
		if (m_delay <= 0)
		{
			m_delay = 1;
			m_vectorCollisionList.clear();
			vector<Object*>().swap(m_vectorCollisionList);
		}
		//##프레임당 collision 영역 세팅하기
	}

	if (m_explosion->GetIsImageEnded())
	{
		if (m_resultColor == eBlack)
		{
			for (auto iter : m_vectorCollisionList)
			{
				Enemy* e = nullptr;
				e = iter->GetComponent<Enemy>();
				if(e!=nullptr)
					e->SetPosition(m_obj->x, m_obj->y);
			}
		}
		else
		{
			for (auto iter : m_vectorCollisionList)
			{
				Enemy* e = nullptr;
				e = iter->GetComponent<Enemy>();
				if (e != nullptr)
				{
					if (e->GetX() > m_obj->x)
						e->SetPosition(e->GetX() + 50, e->GetY() + 20);
					else if (e->GetX() < m_obj->x)
						e->SetPosition(e->GetX() - 50, e->GetY() + 20);
					else
						e->SetPosition(e->GetX(), e->GetY() + 50);
				}
				iter->GetComponent<Component>()->SetPosition(m_obj->x, m_obj->y);
			}
		}
		m_obj->ObjectDestroyed();
	}
	CollisionUpdate();
}
void Roulette::Render()
{
	if(m_rotateCount<4)
		m_roulette->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);

	if (m_printRouletteResult)
		IMAGEMANAGER->CenterRender(m_imageResult, m_obj->x, m_obj->y, 2, 2, 0,false, m_delay);
	if (m_boombRoulette)
	{
		m_explosion->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
	}
}
void Roulette::Release()
{
	m_roulette->Reset();
	m_explosion->Reset();
}
void Roulette::CollisionUpdate()
{
	if (m_resultColor == eRed)
	{
		switch (m_resultSuccess)
		{
		case -1:
			break;
		case 0:
			break;
		case 1:
			if (m_explosion->GetFrame() < 8)
				m_coll->Setting(26, m_obj->x+13, m_obj->y+13);
			else if (m_explosion->GetFrame() < 28)
				m_coll->Setting(56, m_obj->x+28, m_obj->y + 28);
			else if (m_explosion->GetFrame() < 30)
				m_coll->Setting(110, m_obj->x+55, m_obj->y + 55);
			else if (m_explosion->GetFrame() == 30)
				m_coll->Setting(140, m_obj->x+70, m_obj->y+70);
			else if (m_explosion->GetFrame() == 31)
				m_coll->Setting(150, m_obj->x+75, m_obj->y+75);
			else if (m_explosion->GetFrame() < 36)
				m_coll->Setting(164, m_obj->x+82, m_obj->y+82);
			else if (m_explosion->GetFrame() < 45)
				m_coll->Setting(54, m_obj->x+27, m_obj->y+27);
			else m_coll->SetIsActive(false);

			break;
		default:
			cout << "red 룰렛 충돌범위 에러" << endl;
		}
	}
	if (m_resultColor == eBlack)
	{
		switch (m_resultSuccess)
		{
		case -1:
			break;
		case 0:
			break;
		case 1:
			if (m_explosion->GetFrame() > 18)
			{
				m_coll->SetIsActive(true);
				m_coll->Setting(200, m_obj->x + 80, m_obj->y + 115);
			}
			else m_coll->SetIsActive(false);

			break;
		default:
			cout << "red 룰렛 충돌범위 에러" << endl;
		}
	}
}
void Roulette::OnCollision(string collisionName, Object* other)
{
	bool hited = false;
	for (auto iter : m_vectorCollisionList)
	{
		if (other == iter)
		{
			hited = true;
			break;
		}
	}

	if (m_resultColor == eBlack)
	{
		Enemy* e = nullptr;
		e = other->GetComponent<Enemy>();
		if (e != nullptr)
		{
			if (e->GetX() < m_obj->x)
				e->SetPosition(e->GetX() +1, e->GetY());
			else if (e->GetX() > m_obj->x)
				e->SetPosition(e->GetX() -1, e->GetY());
		}
	}//end black

	if (!hited)
	{
		other->GetComponent<Component>()->HitEnemy(15, 0.1);
		m_vectorCollisionList.push_back(other);
	}
}