#include "stdafx.h"
#include "BlackJack.h"
#include "Card.h"
#include "CSound.h"

void BlackJack::Init()
{
	m_shotOn = false;
	m_startDelay = 1.2f;
	m_shotDelay = 0.15;
	m_shotNowDelay = 0.0f;
	m_success = 0;
	SOUNDMANAGER->FindSound("GamblerBlackJackReady")->Play(false);
}

void BlackJack::Update()
{
	if (!m_shotOn)
	{
		m_startDelay -= DELTA_TIME;
		if (m_startDelay <= 0)
		{
			m_shotOn = true;
			(*m_iterCards)->SetShoot();
			m_iterCards++;
		}
	}
	else
	{
		m_shotNowDelay -= DELTA_TIME;
		if (m_shotNowDelay <= 0)
		{
			m_shotNowDelay = m_shotDelay;
			(*m_iterCards)->SetShoot();
			m_iterCards++;
			if (m_iterCards == m_vCards.end())
			{
				m_obj->ObjectDestroyed();
			}//end under21 shot
		}//end  0 delay blackJack
	}//end blackjack on
}

void BlackJack::Setting(int success)
{
	m_success = success;
	for (int i = 0; i < 21; i++)
	{
		m_vCards.push_back(OBJECTMANAGER->AddObject("BlackJackCard", m_obj->x, m_obj->y, ePlayerProjectile)->AddComponent<BlackJackCard>());
		m_vCards.back()->Setting(m_success);
	}
	m_iterCards = m_vCards.begin();

}
