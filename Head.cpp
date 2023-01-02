#include "stdafx.h"
#include "Head.h"
#include "RigidBodyComponent.h"

void Head::Init()
{
	ImageSetting();
	ParameterSetting();
	CollisionSetting();
}

void Head::Update()
{
	m_imageChange = false;
	
	CoolDown();
	if (!m_skillUsing)	//스킬 끝날 때까지 다른 동작이 들어가지 못하게 하기 위함
	{
		Move();
		Act();
	}
	ActionArrangement();
	CollisionUpdate();
}

void Head::Render()
{
	DrawCharactor();
}

void Head::Release()
{
}

void Head::Move()
{
	if (m_action == eWalk)
	{
		m_action = this->eIdle;
		m_imageChange = true;
	}
	InputDashKey();

	//대시중일 때
	if (m_dashing)
	{		//##dash 이동식 수정 필요
		if (m_isLeft) { m_obj->x -= m_dashSpeed * DELTA_TIME; }
		else { m_obj->x += m_dashSpeed*DELTA_TIME; }
	}
	else if (m_attackCount == 0)
	{
		InputArrowKey();	//대시, 공격중에 걷기 불가하므로
	}

	//바닥에서 발이 떠있을 때
	if(!m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
	{
		m_jumpping = true;	//점프중으로 인식하기
	}

	//점프중일 때
	if (m_jumpping)
	{

		if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
		{
			ResetJump();
			img[eJumpDown]->Reset();
			nowImg->Reset();
			m_action = eJumpLand;
		}
		else if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsTopCollision())
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(0);
		if (m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() < 0)
			if(!m_dashing && m_action != eJumpAttack) m_action = eJumpDown;

		m_imageChange = true;
	}
	InputJumpKey();
}

void Head::Act()
{
	if (m_attackCount < m_attackMax)
	{
		InputAttackKey();
	}
	InputSkillKey();
}

void Head::InputJumpKey()
{
	if (KEYMANAGER->GetOnceKeyDown('C'))
	{
		if (m_jumpCount < m_jumpMax)
		{
			if (m_isDown)	//아래점프
			{
				m_obj->y += 11;
			}
			else			//일반점프
			{
				m_obj->y -= 11;			//점프직후 바닥충돌판정걸려서 탐지봉 길이만큼 미리 띄워줌

				m_attackCount = 0;
				m_jumpping = true;
				m_action = eJump;
				m_imageChange = true;
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(m_jumpSpeed);
				if (++m_jumpCount >= 2)
				{
					EFFECTMANAGER->AddEffect<DoubleJumpSmoke>(m_obj->x, m_obj->y, m_isLeft);
				}				
			}
		}
	}//end 'C'
}

void Head::InputDashKey()
{
	if (KEYMANAGER->GetOnceKeyDown('Z'))
	{
		if (m_dashCount < m_dashMax && m_dashNowCool <= 0)
		{
			m_imageChange = true;
			m_jumpping = false;
			ResetAttack();

			m_dashing = true;
			m_dashCount++;
			m_action = eDash;
			img[eDash]->Reset();
			nowImg = img[eDash];
			EFFECTMANAGER->AddEffect<DashSmoke>(m_obj->x, m_obj->y, m_isLeft);
			//m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);//##점프상승이 안들어가
			m_dashNowTime = m_dashTime;
		}
	}
}

void Head::InputArrowKey()
{
	m_isDown = false;
	//방향키 왼쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		if(m_attackCount == 0)
		m_obj->x -= m_moveSpeed * DELTA_TIME;
		if (!m_jumpping) {
			m_action = eWalk;
			m_imageChange = true;
		}
	}
	//방향키 오른쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		m_obj->x += m_moveSpeed * DELTA_TIME;
		if(!m_jumpping) {
			m_action = eWalk;
			m_imageChange = true;
		}
	}
	//아래 방향키 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_isDown = true;
	}
}

void Head::DrawCharactor()
{
	nowImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}
