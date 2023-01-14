#include "stdafx.h"
#include "Thunder.h"
#include "Enemy.h"

void Thunder::Init()
{
	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(10, m_obj->x + 50, m_obj->y + 5, "GamblerThunder");
}

void Thunder::Update()
{
	if (m_thunder->GetIsEnded())
		m_obj->ObjectDestroyed();
	CollisionUpdate();
}

void Thunder::Release()
{
}

void Thunder::Render()
{
}

void Thunder::CollisionUpdate()
{
	if (m_isBigHit)
	{
		m_coll->Setting(192, m_obj->x + 96, m_obj->y + 188);
	}
	else
	{
		m_coll->Setting(110, m_obj->x + 55, m_obj->y + 55);
	}
}

void Thunder::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1 == m_coll)
	{
		if (coll2->GetName() == "hitBox")
		{
			if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
			{
				bool hited = false;
				for (auto iter : m_CollObjList)
				{
					if (other == iter)
					{
						hited = true;
						break;
					}
				}

				Component* e = nullptr;
				e = other->GetComponent<Component>();
				if (e != nullptr)
				{
					if (!hited)
					{
						e->HitEnemy(15, 0);
						SOUNDMANAGER->FindSound("SkulAttack")->Play(false);
						m_CollObjList.push_back(other);
					}
					else
					{
						e->HitEnemy(0, 0);
					}
				}
			}
		}
	}
}

//==================================================================================================

void ThunderShoter::Init()
{
	m_shotCount = 0;
	m_isBigHit = false;
	m_delay = 0.5;
	m_dmg = 15;

	m_shot = false;

	m_checkTargetRange = 50;
	m_checkTarget = true;

	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(50, m_obj->x + 25, m_obj->y + 25, "GamblerThunderTargetRange");
}

void ThunderShoter::Update()
{
	if (m_shot)
	{
		m_delay -= DELTA_TIME;
		if (m_delay <= 0)
		{
			m_delay = 0.3;
			m_shotCount--;
			if (m_isBigHit)
			{
				OBJECTMANAGER->AddObject("SlotMachineThunder", m_obj->x - 300 + MY_UTILITY::getFromFloatTo(0, 600), m_obj->y, ePlayerProjectile)->AddComponent<Thunder>()->Setting(m_isBigHit);
			}//end if bighit
			else
			{
				if (m_targetList.empty())
				{
					OBJECTMANAGER->AddObject("SlotMachineThunder", m_obj->x, m_obj->y, ePlayerProjectile)->AddComponent<Thunder>()->Setting(m_isBigHit);
				}
				else
				{
					OBJECTMANAGER->AddObject("SlotMachineThunder", m_targetList.front()->x, m_targetList.front()->y, ePlayerProjectile)->AddComponent<Thunder>()->Setting(m_isBigHit);
					m_targetList.pop_front();
				}
			}//end if no bighit
			if (m_shotCount <= 0)
				m_obj->ObjectDestroyed();

		}//end if delay 0
	}//end if shot

	if (m_checkTarget)
	{
		CollisionUpdate();
	}
}

void ThunderShoter::CollisionUpdate()
{
	if (m_targetList.size() >= m_shotCount)
	{
		m_coll->SetIsActive(false);
		m_checkTarget = false;
		return;
	}
	m_checkTargetRange += 6;
	m_coll->Setting(m_checkTargetRange, m_obj->x + 0.5 * m_checkTargetRange, m_obj->y + 0.5 * m_checkTargetRange);
}

void ThunderShoter::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1 == m_coll)
		if (coll2->GetName() == "hitBox")
			if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
			{
				bool isChecked = false;
				for (auto iter : m_targetList)
				{
					if (iter == other)
					{
						isChecked = true;
						break;
					}
				}
				if (!isChecked)
				{
					m_targetList.push_back(other);
				}
			}
	if (m_targetList.size() > 3)
	{
		m_coll->SetIsActive(true);
		m_checkTarget = false;
	}
};

