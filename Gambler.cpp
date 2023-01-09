#include "stdafx.h"
#include "Gambler.h"
#include "Card.h"

void Gambler::ImageSetting()
{
	//이미지 삽입
	img[eIdle] = IMAGEMANAGER->FindImageVector("Gambler_Idle");
	img[eIdle]->Setting(0.15f, true);
	img[eWalk] = IMAGEMANAGER->FindImageVector("Gambler_Walk");
	img[eWalk]->Setting(0.1f, true);
	img[eDash] = IMAGEMANAGER->FindImageVector("Gambler_Dash");
	img[eDash]->Setting(0.16f, false);
	img[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Gambler_Attack1");
	img[eAutoAttack_1]->Setting(0.03f, false);
	img[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Gambler_Attack2");
	img[eAutoAttack_2]->Setting(0.03f, false);
	img[eAutoAttack_3] = IMAGEMANAGER->FindImageVector("Gambler_Attack3");
	img[eAutoAttack_3]->Setting(0.06f, false);
	img[eJump] = IMAGEMANAGER->FindImageVector("Gambler_JumpStart");
	img[eJump]->Setting(0.05, true);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Gambler_JumpAttack");
	img[eJumpAttack]->Setting(0.08, false);
	img[eJumpAttack]->Setting(img[eJumpAttack]->GetImageSize() - 1, 0.12);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Gambler_JumpRepeat");
	img[eJumpDown]->Setting(0.1, true);
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Gambler_JumpFall");
	img[eJumpLand]->Setting(0.1, false);
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Gambler_Attack1");
	img[eSkill_2] = IMAGEMANAGER->FindImageVector("Gambler_Attack1");
	img[eTagAction] = IMAGEMANAGER->FindImageVector("Gambler_TagAction");
	img[eTagAction]->Setting(0.07f, false);

	nowImg = img[eIdle];
}

void Gambler::ParameterSetting()
{
	m_species = eSkulSpecies::eGambler;

	m_action = eIdle;

	m_moveSpeed = 200;
	m_isDown = false;

	m_dashSpeed = 300;		//##dash 이동식 수정 필요
	m_dashTime = 0.95 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//대시 누르면 0.4, update시 -
	m_dashCool = 1.5;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//대시 최대 횟수

	m_jumpSpeed = 8;
	m_jumpCount = 0;
	m_jumpMax = 2;

	m_attackCount = 0;
	m_attackMax = 3;
	m_attackCast[0] = false;
	m_attackCast[1] = false;

	m_skillNowCoolA = 0;
	m_skillNowCoolS = 0;
	m_skillCoolA = 15;
	m_skillCoolS = 11;
	m_skillUsing = false;
	m_imageChange = false;

	m_effectOverap = false;
}

void Gambler::CollisionSetting()
{
	m_collAutoAttack->Setting(140, m_obj->x + 35, m_obj->y - 32, "BasicAttack_Gambler");
	m_collAutoAttack->SetIsActive(false);
}

void Gambler::CoolDown()
{
}

void Gambler::ActionArrangement()
{
	if (nowImg->GetIsImageEnded())
	{
		m_effectOverap = false;
		if (m_attackCast[0])
		{
			m_attackCast[0] = false;
			m_attackCast[1] = true;
		}
		else if (m_attackCast[1])
		{
			m_attackCast[0] = false;
			m_attackCast[1] = false;
			if (++m_attackCount > 3) m_attackCount--;
			SetImage(eAutoAttack_1 + m_attackCount - 1, true);
			switch (m_attackCount)
			{
			case 2:
				if (*m_isLeft)
				{
					EFFECTMANAGER->AddEffect<GamblerAttack_2>(m_obj->x - 20, m_obj->y - 40, true, 2);
				}
				else
				{
					EFFECTMANAGER->AddEffect<GamblerAttack_2>(m_obj->x + 20, m_obj->y - 40, false, 2);
				}
				break;
			case 3:
			{
				OBJECTMANAGER->AddObject("Card", *m_x, *m_y - 36, ePlayerProjectile)->AddComponent<Card>();
			}
			break;
			default: break;
			}
		}
		else
		{
			nowImg->Reset();
			nowImg = img[eIdle];
			m_action = eIdle;
			m_attackCount = 0;
		}
		m_skillUsing = false;
	}
	if (m_imageChange)
	{
		m_effectOverap = false;
		m_attackCast[0] = false;
		m_attackCast[1] = false;
		if (m_action<eAutoAttack_1 || m_action>eJumpAttack)
			m_attackCount = 0;
		if (nowImg != img[m_action])
		{
			nowImg->Reset();
			nowImg = img[m_action];
		}
	}

	if (m_action == eAutoAttack_3)
	{
		if (nowImg->GetFrame() == 2)
		{
			float mov = (15 / nowImg->GetFrameDelay(2)) * DELTA_TIME;
			*m_x = *m_isLeft ? *m_x - mov : *m_x + mov;
		}
	}
}

void Gambler::CollisionUpdate()
{
	m_collAutoAttack->SetIsActive(false);

	switch (m_action)
	{
	case eAutoAttack_1:
		if (nowImg->GetFrame() < 3)
		{
			if (*m_isLeft)
				m_collAutoAttack->Setting(80, m_obj->x - 35, m_obj->y);
			else
				m_collAutoAttack->Setting(80, m_obj->x + 20 + 96, m_obj->y);
			m_collAutoAttack->SetIsActive(true);
		}
		break;
	case eAutoAttack_2:
		if (nowImg->GetFrame() < 3)
		{
			if (*m_isLeft)
				m_collAutoAttack->Setting(90, m_obj->x + 20, m_obj->y - 5);
			else
				m_collAutoAttack->Setting(90, m_obj->x + 66, m_obj->y - 5);
			m_collAutoAttack->SetIsActive(true);
		}
		break;
	case eJumpAttack:
		if (nowImg->GetFrame() > 1 || nowImg->GetFrame() < 4)
		{
			if (*m_isLeft)
				m_collAutoAttack->Setting(80, m_obj->x+10, m_obj->y+20);
			else
				m_collAutoAttack->Setting(80, m_obj->x + 60, m_obj->y+20);
			m_collAutoAttack->SetIsActive(true);
		}
		break;
	}
	if (!m_collAutoAttack->GetIsActive())
	{
		m_CollObjList.clear();
		listObj().swap(m_CollObjList);
	}
}

void Gambler::InputSkillKey()
{
	if (KEYMANAGER->GetOnceKeyDown('A'))
	{
	}

	if (KEYMANAGER->GetOnceKeyDown('S'))
	{
	}
}

void Gambler::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
		if (*m_jumpping)
		{
			if (m_attackCount == 0)
			{
				m_action = eJumpAttack;
				m_imageChange = true;
				m_attackCount++;
				if (*m_isLeft)
				{
					EFFECTMANAGER->AddEffect<GamblerJumpAttack>(m_obj->x - 20, m_obj->y, true, 2);
					m_effectOverap = true;
				}
				else
				{
					EFFECTMANAGER->AddEffect<GamblerJumpAttack>(m_obj->x + 20, m_obj->y, false, 2);
					m_effectOverap = true;
				}
			}
		}
		else if (!m_attackCast[1] && !m_attackCast[0])
			switch (m_attackCount)
			{
			case 0:
				m_attackCount++;
				SetAction(eAutoAttack_1, true);
				if (*m_isLeft)
				{
					EFFECTMANAGER->AddEffect<GamblerAttack_1>(m_obj->x - 35, m_obj->y - 32, true, 2);
				}
				else
				{
					EFFECTMANAGER->AddEffect<GamblerAttack_1>(m_obj->x + 35, m_obj->y - 32, false, 2);
				}

				break;
			case 1:
				m_attackCast[0] = true;
				break;
			case 2:
				m_attackCast[0] = true;
				break;
			case 3:

				break;
			default:
				cout << "어택카운트에 이상한 값이 들어갔다. " << m_attackCount << endl;
			}//end switch
	}//end X
}

void Gambler::TagAction()
{
}

bool Gambler::GetIsAttack()
{
	switch (m_attackCount)
	{
	case 0:
		return false;
		break;
	case 1:
		if (m_attackCast[1] == true)
			return false;
		else return true;
		break;
	case 2:
		return true;
		break;
	case 3:
		return true;
		break;
	default:
		cout << "공격횟수가 이상하다. attackcount = " << m_attackCount << endl;
		return false;
	}
}

void Gambler::DrawCharactor()
{
	if (!m_effectOverap)
	{
		if (m_attackCount > 0 && m_attackCount < 3)
		{
			switch (m_attackCount)
			{
			case 1:
				if (m_action == eAutoAttack_1 && nowImg->GetFrame() == 1)
					if (*m_isLeft)
					{
						EFFECTMANAGER->AddEffect<GamblerAttack_1>(m_obj->x - 35, m_obj->y - 32, true, 2);
					}
					else
					{
						EFFECTMANAGER->AddEffect<GamblerAttack_1>(m_obj->x + 35, m_obj->y - 32, false, 2);
					}
			m_effectOverap = true;
				break;
			case 2:
				if (nowImg->GetFrame() == 1)
					if (*m_isLeft)
					{
						EFFECTMANAGER->AddEffect<GamblerAttack_2>(m_obj->x - 20, m_obj->y - 40, true, 2);
					}
					else
					{
						EFFECTMANAGER->AddEffect<GamblerAttack_2>(m_obj->x + 20, m_obj->y - 40, false, 2);
					}
			m_effectOverap = true;
				break;
			default: break;
			}//end switch
		}//end if attack
	}//end not effect overap

	nowImg->CenterRender(*m_x, *m_y - 35, 2, 2, 0, *m_isLeft);


}
