#include "stdafx.h"
#include "Thunder.h"
#include "Enemy.h"

void Thunder::Init()
{
	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(10, m_obj->x + 50, m_obj->y + 5, "GamblerThunder");
	m_delay = 1;
}

void Thunder::Update()
{
	if (m_thunder->GetIsEnded())
	{
		m_obj->ObjectDestroyed();
	}
	m_delay -= DELTA_TIME;
	if (m_delay < 0)
	{
		m_delay = 1;
		m_CollObjList.clear();
	}
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
		m_coll->Setting(110, m_obj->x + 55, m_obj->y + 200 + 55);
	}
	else
	{
		m_coll->Setting(110, m_obj->x + 55, m_obj->y + 55);
	}
}

void Thunder::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
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

	if (hited == false)
	{
		if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
		{
			if (coll2->GetName() == "hitBox")
			{
				m_CollObjList.push_back(other);
				Component* e = nullptr;
				e = other->GetComponent<Component>();
				if (e != nullptr)
				{
					e->HitEnemy(m_dmg, 0);
					SOUNDMANAGER->FindSound("SkulAttack")->Play(false);
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
		if (m_shotCount > 0)
		{
			m_delay -= DELTA_TIME;
			if (m_delay <= 0)
			{
				m_delay = MY_UTILITY::getFloat();
				if (m_isBigHit)
				{
					OBJECTMANAGER->AddObject("SlotMachineThunder", m_obj->x - 400 + MY_UTILITY::getFromFloatTo(0, 800), m_obj->y, ePlayerProjectile)->AddComponent<Thunder>()->Setting(m_isBigHit, m_dmg);
				}//end if bighit
				else
				{
					if (m_targetList.empty())
					{
						OBJECTMANAGER->AddObject("SlotMachineThunder", m_obj->x + m_shotCount, m_obj->y, ePlayerProjectile)->AddComponent<Thunder>()->Setting(m_isBigHit, m_dmg);
					}
					else
					{
						OBJECTMANAGER->AddObject("SlotMachineThunder", (*m_iterList)->x, (*m_iterList)->y, ePlayerProjectile)->AddComponent<Thunder>()->Setting(m_isBigHit, m_dmg);
						m_iterList++;
						if (m_iterList == m_targetList.end())
						{
							m_iterList = m_targetList.begin();
						}
					}
				}//end if no bighit
				m_shotCount--;
			}//end if delay 0
		}
		else
		{
			m_obj->ObjectDestroyed();
		}
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

