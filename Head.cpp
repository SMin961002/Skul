#include "stdafx.h"
#include "Head.h"
#include "RigidBodyComponent.h"

void Head::Init()
{
	ImageSetting();
	ParameterSetting();
}

void Head::Update()
{
	if (!m_skillUsing)	//��ų ���� ������ �ٸ� ������ ���� ���ϰ� �ϱ� ����
	{
		Move();
		Act();
	}
}

void Head::Render()
{
	DrawCharactor();
}

void Head::Release()
{
}

void Head::ImageSetting()
{
	/*
	Do Nothing
	*/
}

void Head::ParameterSetting()
{
	/*
	Do Nothing
	*/
}

void Head::Move()
{
	m_commandInput = false;
	if (m_action == this->eWalk)
	{
		m_action = this->eIdle;
	}
	InputJumpKey();
	InputDashKey();
	if (!m_dashing)
	{
		//if(m_attackCount == 0)
		InputArrowKey();

		if (m_dashNowCool != 0)
		{
			if (m_dashNowCool > 0)	m_dashNowCool -= DELTA_TIME;
			else
			{
				ResetDash();
			}
		}
	}
	else	//��� �ߵ����϶�
	{		//##dash �̵��� ���� �ʿ�
		if (m_isLeft) { m_obj->x -= m_dashSpeed; }
		else { m_obj->x += m_dashSpeed; }
		m_dashNowTime -= DELTA_TIME;
		if (m_dashNowTime <= 0)
		{
			m_dashing = false;
			m_dashNowCool = m_dashCool;
			m_obj->GetComponent<RigidBodyComponent>()->SetGravity(true);
		}
	}
}

void Head::Act()
{
	if (!m_attackCast && m_attackCount < m_attackMax)
	{
		cout << "attack count " << m_attackCount << endl;
		InputAttackKey();
	}
	InputSkillKey();
}

void Head::InputJumpKey()
{
	if (KEYMANAGER->GetOnceKeyDown('C'))
	{
		m_jumpCount++;

		m_attackCount = 0;
		m_commandInput = true;
	}
}

void Head::InputDashKey()
{
	if (KEYMANAGER->GetOnceKeyDown('Z'))
	{
		if (m_dashCount < m_dashMax && m_dashNowCool <= 0)
		{
			ResetJump();
			ResetAttack();
			m_dashing = true;
			m_dashCount++;
			m_action = eDash;
			if (m_dashing) cout << "dash" << endl;
			m_commandInput = true;
			img[eDash]->Reset();
			nowImg = img[eDash];
			m_obj->GetComponent<RigidBodyComponent>()->SetGravity(false);//##�߷��� �� �Ȳ�����
			m_dashNowTime = m_dashTime;
		}
	}
}

void Head::InputArrowKey()
{
	m_commandInput = true;
	//����Ű ���� �Է½�
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		m_obj->x -= m_moveSpeed;
		if (!m_jumpping) {
			m_action = eWalk;
			m_commandInput = true;
		}
	}
	//����Ű ������ �Է½�
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		m_obj->x += m_moveSpeed;
		if(!m_jumpping) {
			m_action = eWalk;
			m_commandInput = true;
		}
	}
}

void Head::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
		if (m_jumpping)
		{
			if (m_attackCount < 1)
			{
				m_action = eJumpAttack;
				m_attackCount = m_attackMax;
				m_commandInput = true;
			}
		}//end if jumpping
		else
		{
			if (m_attackCount == 0)
			{
				m_commandInput = true;
				m_action = eAutoAttack_1;
				++m_attackCount;
			}
			else 
			{
				cout << "attackCount"<< m_attackCount << endl;
				m_attackCast = true;
			}
		}//end else jumpping
	}//end donw 'X'
}

void Head::InputSkillKey()
{
/*
	Do Nothing
*/
}

void Head::DrawCharactor()
{
	if (m_commandInput)
	{
		if (nowImg != img[m_action])
			img[m_action]->Reset();
		nowImg = img[m_action];
	}

	if (nowImg->GetIsImageEnded())
	{
		cout << m_attackCast << endl;
		switch (m_action)
		{
		case eAutoAttack_1:
			if (m_attackCast)
			{
				m_action = eAutoAttack_2;
				m_attackCast = false;
			}//end if 
			else
			{
				ResetAttack();
				m_action = eIdle;
			}
			break;
		case eJumpDown:
			/*
			* ## ���� ���������� eJumpLand�� �ٲٴ� ��� �־����
			*/
			break;
		default:
			ResetAll();
		}

		//##����, ����, ���, ��Ÿ��� count�ʱ�ȭ�ϴ��� ��� �������� ����ϰ� �����ϱ�
		nowImg->Reset();
		nowImg = img[m_action];
	}
	
	nowImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}

void Head::DrawEffect()
{
}
