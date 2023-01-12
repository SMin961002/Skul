#include "stdafx.h"
#include "Card.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "HitDamageEffect.h"
#include "Enemy.h"
#include "CSound.h"
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
		float distance = m_obj->x - m_startX;
		if (distance < 0) distance = -distance;
		PixelCollisionComponent* px = m_obj->GetComponent<PixelCollisionComponent>();
		if (px->GetIsBottomCollision() || px->GetIsTopCollision()
			|| px->GetIsLeftCollision() || px->GetIsRightCollision()
			|| distance > 400)
		{
			m_obj->ObjectDestroyed();
		}
		if (m_isLeft)
			m_coll->Setting(m_obj->x - 19, m_obj->y + 4);
		else
			m_coll->Setting(m_obj->x + 24, m_obj->y + 4);
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

void Card::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "Enemy"||other->GetName() == "EnemyBoss")
	{
		bool isOtherHit = false;
		for (auto iter : m_CollObjList)
		{
			if (iter == other)
			{
				isOtherHit = true;
			}
			else false;
		}
		if (!isOtherHit)
		{
			Component* e = other->GetComponent<Component>();
			SOUNDMANAGER->FindSound("SkulAttackBluntSmall")->Play(false);;
			if (m_isJoker)
			{
				e->HitEnemy(20, IMAGEMANAGER->FindImageVector("Gambler_JockerExplosion")->GetTotalDelay());
				OBJECTMANAGER->AddObject("Effect", other->x + MY_UTILITY::getFromFloatTo(-40, 40), other->y - MY_UTILITY::getFromFloatTo(40, 100), eBoss)->AddComponent<HitDamageEffect>()->Setting(20);

				if (!m_isJokerHit)
				{
					m_jokerExplosion = EFFECTMANAGER->AddEffect<JokerExplosion>(m_obj->x, m_obj->y, m_isLeft, 2);
					m_jokerExplosion->Init();
					if (m_isLeft)
						m_coll->Setting(120, m_obj->x + 60, m_obj->y + 60);
					else
						m_coll->Setting(120, m_obj->x + 60, m_obj->y + 60);
					m_isJokerHit = true;
				}//end if not jokerhit
			}//end joker
			else
			{
				e->HitEnemy(10, 0.2);
			}//end not joker
			m_CollObjList.push_back(other);
		}//end if nohit
	}
}

void BlackJackCard::Init()
{
	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(15, m_obj->x + 120, m_obj->y - 8, "GamblerCard");
	m_coll->SetIsActive(false);
	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);
	m_isLeft = OBJECTMANAGER->m_player->GetplayerIsLeft();
	m_startX = OBJECTMANAGER->m_player->GetplayerX();
	m_shoot = false;

	m_dx = MY_UTILITY::getFromFloatTo(80, 125);
	m_dy = -80 + MY_UTILITY::getFromFloatTo(0, 48);
}

void BlackJackCard::Update()
{
	if (m_shoot)	//발사시 동작
	{
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
			float distance = m_obj->x - m_startX;
			if (distance < 0) distance = -distance;
			PixelCollisionComponent* px = m_obj->GetComponent<PixelCollisionComponent>();
			if (px->GetIsBottomCollision() || px->GetIsTopCollision()
				|| px->GetIsLeftCollision() || px->GetIsRightCollision()
				|| distance > WINSIZE_X)
			{
				m_obj->ObjectDestroyed();
			}
			if (m_isLeft)
				m_coll->Setting(m_obj->x - 19, m_obj->y + 4);
			else
				m_coll->Setting(m_obj->x + 24, m_obj->y + 4);
		}//end else
	}//end shot
	else	//발사 전 동작
	{
		m_obj->x = OBJECTMANAGER->m_player->GetplayerX() + (m_isLeft ? m_dx : -m_dx);
		m_obj->y = OBJECTMANAGER->m_player->GetplayerY() + m_dy;
		m_isLeft = OBJECTMANAGER->m_player->GetplayerIsLeft();
	}
}

void BlackJackCard::Render()
{
	if (!m_isJokerHit)
		IMAGEMANAGER->CenterRender(m_img, m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}

void BlackJackCard::Release()
{
}

void BlackJackCard::Setting(int success)
{
	m_success = success;
	switch (success)
	{
	case -1:
		m_isJoker = false;
		m_isJokerHit = false;
		m_img = IMAGEMANAGER->FindImage("GamblerCardNormal");
		break;
	case 1:
		m_isJoker = true;
		m_isJokerHit = false;
		m_img = IMAGEMANAGER->FindImage("GamblerCardJoker");
		break;

	default:
		m_isJoker = false;
		m_isJokerHit = false;
		m_img = IMAGEMANAGER->FindImage("GamblerCardNormal");
		break;
	}
}

void BlackJackCard::SetShoot()
{
	m_shoot = true;
	m_coll->SetIsActive(true);
		string sound = "GamblerBlackJack"+to_string(m_success+2);
		SOUNDMANAGER->FindSound(sound)->Play(false);
	if (m_success >= 0)
		EFFECTMANAGER->AddEffect<BlackJackSpark>(m_obj->x, m_obj->y, m_isLeft, 2);
}

void BlackJackCard::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
	{
		if (m_success == -1)	//실패의 경우
		{
			Component* e = other->GetComponent<Component>();
			e->HitEnemy(12, 0);
			m_obj->ObjectDestroyed();
			SOUNDMANAGER->FindSound("SkulAttackBluntSmall")->Play(false);
			return;			//공격판정시 바로 파괴되므로 아래의 hited판정을 돌리지 않고 조기return한다
		}

		bool hited = false;
		for (auto iter : m_CollObjList)
		{
			if (iter == other)
			{
				hited = true;
				break;
			}
			else false;
		}
		if (!hited)
		{
			if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
			{
				m_CollObjList.push_back(other);
				Component* e = other->GetComponent<Component>();
				if (m_isJoker)
				{
					e->HitEnemy(15, 0);
					OBJECTMANAGER->AddObject("Effect", other->x + MY_UTILITY::getFromFloatTo(-40, 40), other->y - MY_UTILITY::getFromFloatTo(40, 100), eBoss)->AddComponent<HitDamageEffect>()->Setting(15);
					SOUNDMANAGER->FindSound("SkulAttackBluntLarge")->Play(false);

					if (!m_isJokerHit)
					{
						m_isJokerHit = true;
						m_jokerExplosion = EFFECTMANAGER->AddEffect<BlackJackJokerExplosion>(m_obj->x, m_obj->y, m_isLeft, 2);
						m_coll->Setting(120, m_obj->x + 60, m_obj->y + 60);
						if (MY_UTILITY::getInt(2) == 0)	//2분의 1의 확률로 폭발음 출력하기 위함
						{
							SOUNDMANAGER->FindSound("GamblerBlackJackBigHit")->Play(false);
						}
					}//end if not jokerhit
				}//end joker
				else
				{
					OBJECTMANAGER->AddObject("Effect", other->x + MY_UTILITY::getFromFloatTo(-40, 40), other->y - MY_UTILITY::getFromFloatTo(40, 100), eBoss)->AddComponent<HitDamageEffect>()->Setting(12);
					SOUNDMANAGER->FindSound("SkulAttackBluntSmall")->Play(false);

					e->HitEnemy(12, 0);
				}//end not joker

			}//end if other Enemy ||EnemyBoss
		}//end if nohit
	}
}
