#include "stdafx.h"
#include "stdafx.h"
#include "SlotMachine.h"
#include "Player.h"
#include "Thunder.h"
#include"CSound.h"

void SlotMachine::Init()
{
	SOUNDMANAGER->FindSound("SlotMachineStart")->Play(false);
	m_obj->y -= 46;

	m_resultExplosion = 0;
	m_resultThunder = 0;
	m_resultLaiser = 0;

	m_isLeft = OBJECTMANAGER->m_player->GetplayerIsLeft();
	m_slotMachineRunning = true;
	m_printResult = false;
	m_action = false;

	m_delay = 0;
	m_alpha = 1.5;

	int tmp = MY_UTILITY::getInt(2);	//����� ���� 2ĭ, 3ĭ¥�� ����� ����ϹǷ� 2�� ������
	switch (tmp)
	{
	case 0:	//����2, ���1 - ���� + ���(��� �̱���)
		SOUNDMANAGER->FindSound("SlotMachineRunning")->Play(false);
		m_imgResult = IMAGEMANAGER->FindImage("GamblerSlotMachineExplosion_Thunder");
		m_imgExplosion = IMAGEMANAGER->FindImageVector("Gambler_SlotMachine_Explosion");
		m_imgExplosion->Setting(0.05, false);
		m_resultExplosion = 2;
		m_resultThunder = 1;
		break;
	case 1:	//����3 - ���� �뼺��
		SOUNDMANAGER->FindSound("SlotMachineJackpot")->Play(false);
		m_imgResult = IMAGEMANAGER->FindImage("GamblerSlotMachineExplosion_BigHit");
		m_imgExplosion = IMAGEMANAGER->FindImageVector("Gambler_SlotMachine_ExplosionBigHit");
		m_imgExplosion->Setting(0.117, false);
		for (int i = 7; i < 17; i++)
		{
			m_imgExplosion->Setting(i, 0.05);
		}
		m_resultExplosion = 3;
		break;
	}
	m_imgSlotMachine = IMAGEMANAGER->FindImageVector("Gambler_SlotMachine");
	m_imgSlotMachine->Setting(0.016, false);
	m_loopChecker = 0;

	m_coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_coll);
	m_coll->Setting(10, m_obj->x + 5, m_obj->y + 5, "GamblerSlotMachine");
	m_coll->SetIsActive(false);
}

void SlotMachine::Update()
{
	if (m_slotMachineRunning)
	{
		if (m_imgSlotMachine->GetIsImageEnded())
		{
			if (m_loopChecker <15)
			{
				m_loopChecker++;
				m_imgSlotMachine->Reset();
			}
			else
			{
				m_slotMachineRunning = false;
				m_printResult = true;
				SOUNDMANAGER->FindSound("SlotMachineFinish")->Play(false);
				if (m_resultExplosion == 3)
				{
					EFFECTMANAGER->AddEffect<SlotMachineBigHit>(OBJECTMANAGER->m_player->GetplayerX(), OBJECTMANAGER->m_player->GetplayerY(), false, 2);
					SOUNDMANAGER->FindSound("GamblerBigHit")->Play(false);
				}

				m_delay = 1.85;
			}
		}
	}
	else if (m_printResult)
	{
		m_delay -= DELTA_TIME;
		if (m_delay < 1)
		{
			if (m_action == false)
			{
				m_action = true;
				if (m_resultExplosion > 0&& m_resultExplosion<3)
				{
					SOUNDMANAGER->FindSound("SlotMachineExplosion")->Play(false);
				}
				if (m_resultExplosion == 3)
				{
					SOUNDMANAGER->FindSound("SlotMachineExplosion3")->Play(false);
				}
			}
		}
		if (m_delay <= 0)
		{
			m_printResult = false;
			if (m_resultExplosion == 0)	//������ �ȶ߸� ������ ���� ������ �̹��� ���������� object�ٷ� ����
				m_obj->ObjectDestroyed();
		}
	}
	if (m_action)
	{
		if (m_alpha > 0)
		{
			m_alpha -= 10*DELTA_TIME;
			if (m_alpha < 0)
				m_alpha = 0;
		}
		if (m_imgExplosion->GetIsImageEnded())	//���� �ִϸ��̼� �̹����� ������ ���Ҵٸ�
			m_obj->ObjectDestroyed();	//������Ʈ ����
	}

	CollisionUpdate();
}

void SlotMachine::Release()
{
	//������Ʈ �ı��ϱ� ���� ����� �̹����� �����Ѵ�
	m_imgSlotMachine->Reset();
	m_imgExplosion->Reset();
}

void SlotMachine::Render()
{
	if (m_slotMachineRunning)
		m_imgSlotMachine->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
	else if (m_printResult)
		IMAGEMANAGER->CenterRender(m_imgResult, m_obj->x, m_obj->y, 2, 2, 0, m_isLeft, m_delay);
	if (m_action && m_resultExplosion > 0)
	{
		if (m_resultExplosion == 3 && m_alpha > 0)
		{
			m_imgExplosion->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft, 0);

			IMAGEMANAGER->CenterRender(m_imgExplosion->GetImages()[0], m_obj->x, m_obj->y, 2, 2, 0, m_isLeft, m_alpha);
			IMAGEMANAGER->CenterRender(m_imgExplosion->GetImages()[1], m_obj->x, m_obj->y, 2, 2, 0, m_isLeft, 1 - m_alpha);
		}
		else
			m_imgExplosion->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
	}
}

void SlotMachine::CollisionUpdate()
{
	if (m_resultExplosion != 0)	//������ �� ���->����
	{
		if (m_resultExplosion == 3)	//3ĭ ������ ��� �뼺��
		{
			switch (m_imgExplosion->GetFrame())
			{
			case 4:
				m_coll->Setting(350, m_obj->x + 175, m_obj->y + 175);
				m_coll->SetIsActive(true);
				break;
			case 11:
				m_coll->SetIsActive(false);
				break;
			}
		}//end if 3����
		else	//3ĭ�� �ƴ� ��� �Ϲ�����
		{
			switch (m_imgExplosion->GetFrame())
			{
			case 2:
				m_coll->Setting(180, m_obj->x + 90, m_obj->y + 90);
				m_coll->SetIsActive(true);
				break;
			case 7:
				m_coll->SetIsActive(false);
				break;
			}
		}
	}
}

void SlotMachine::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_coll->GetName())
	{
		bool hited = false;
		for (auto iter : m_CollObjList)
		{
			if (iter == other)
			{
				hited = true;
				break;
			}
		}//end for
		if (!hited)
		{
			if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
			{
				Component* e = nullptr;
				e = other->GetComponent<Component>();
				if (e != nullptr)
				{
					if (m_resultExplosion == 3)
					{
						e->HitEnemy(20, 0);
					}
					else { e->HitEnemy(15, 0); }
					m_CollObjList.push_back(other);
				}
			}
		}//end nohit

		Enemy* e = nullptr;
		e = other->GetComponent<Enemy>();
		if (e != nullptr)
		{
			if (m_resultExplosion == 3)
			{
				if (e->GetX() > m_obj->x)
					e->SetPosition(e->GetX() + 2, e->GetY() - 3);
				else if (e->GetX() > m_obj->x)
					e->SetPosition(e->GetX() - 2, e->GetY() - 3);
			}
			else
			{
				if (e->GetX() < m_obj->x)
					e->SetPosition(e->GetX() + 1.5, e->GetY() - 2);
				else if (e->GetX() > m_obj->x)
					e->SetPosition(e->GetX() - 1.5, e->GetY() - 2);
			}
		}
	}//end m_coll
}
