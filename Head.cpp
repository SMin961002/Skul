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
	if (!m_skillUsing)	//스킬 끝날 때까지 다른 동작이 들어가지 못하게 하기 위함
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
	else	//대시 발동중일때
	{		//##dash 이동식 수정 필요
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
			m_obj->GetComponent<RigidBodyComponent>()->SetGravity(false);//##중력이 왜 안꺼질까
			m_dashNowTime = m_dashTime;
		}
	}
}

void Head::InputArrowKey()
{
	m_commandInput = true;
	//방향키 왼쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		m_obj->x -= m_moveSpeed;
		if (!m_jumpping) {
			m_action = eWalk;
			m_commandInput = true;
		}
	}
	//방향키 오른쪽 입력시
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
			* ## 점프 떨어지고나서 eJumpLand로 바꾸는 방식 넣어야함
			*/
			break;
		default:
			ResetAll();
		}

		//##공격, 점프, 대시, 기타등등 count초기화하는짓 어디서 구현할지 깔끔하게 생각하기
		nowImg->Reset();
		nowImg = img[m_action];
	}
	
	nowImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}

void Head::DrawEffect()
{
}
