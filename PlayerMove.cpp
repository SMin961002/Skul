#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"

void Player::Move()
{
	if (m_nowHead->GetAction() == m_nowHead->eWalk)
	{
		m_nowHead->SetAction(m_nowHead->eIdle, true);
	}

	InputDashKey();

	//대시중일 때
	if (m_dashing)
	{		//##dash 이동식 수정 필요
		if (m_isLeft) { m_obj->x -= m_dashSpeed * DELTA_TIME; }
		else { m_obj->x += m_dashSpeed * DELTA_TIME; }
		m_obj->y -= 1;
	}
	else
	{
		InputArrowKey();	//대시, 공격중에 걷기 불가하므로
	}

	//바닥에서 발이 떠있을 때
	if (!m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
	{
		m_jumpping = true;	//점프중으로 인식하기
	}

	//점프중일 때
	if (m_jumpping)
	{
		if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
		{
			ResetJump();
			m_nowHead->SetAction(m_nowHead->eJumpLand);
		}
		else if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsTopCollision())
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(0);
		if (m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() < 0)
		{
			//##점프액션조건수정필요
			if (!m_dashing && !m_nowHead->GetIsAttack())
				m_nowHead->SetAction(m_nowHead->eJumpDown, true);
		}
	}
	InputJumpKey();
}

void Player::InputJumpKey()
{
	if (KEYMANAGER->GetOnceKeyDown('C'))
	{
		if (m_jumpCount < m_jumpMax)
		{
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			if (m_isDown)	//아래점프
			{
				m_obj->y += 11;
			}
			else			//일반점프
			{
				m_obj->y -= 11;			//점프직후 바닥충돌판정걸려서 탐지봉 길이만큼 미리 띄워줌

				m_nowHead->ResetAttack();
				m_jumpping = true;
				m_nowHead->SetAction(Head::eJump);
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(m_jumpSpeed);
				if (++m_jumpCount >= 2)
				{
					EFFECTMANAGER->AddEffect<DoubleJumpSmoke>(m_obj->x, m_obj->y, m_isLeft);
				}
			}
		}
	}//end 'C'
}

void Player::InputDashKey()
{
	if (KEYMANAGER->GetOnceKeyDown('Z'))
	{
		if (m_dashCount < m_dashMax && m_dashNowCool <= 0)
		{
			m_jumpping = false;
			m_nowHead->ResetAttack();

			m_dashing = true;
			m_dashCount++;
			m_nowHead->SetAction(m_nowHead->eDash, true, true);
			EFFECTMANAGER->AddEffect<DashSmoke>(m_obj->x, m_obj->y, m_isLeft);
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(0);
			m_dashNowTime = m_dashTime;
			m_playerHitBox->SetIsActive(false);
		}
	}
}

void Player::InputArrowKey()
{
	m_isDown = false;
	//방향키 왼쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		if (!m_nowHead->GetIsAttack() || m_nowHead->GetAction() == m_nowHead->eJumpAttack)
		{
			m_obj->x -= m_moveSpeed * DELTA_TIME;
			if (!m_jumpping)
				m_nowHead->SetAction(Head::eWalk);
		}
	}
	//방향키 오른쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		if (!m_nowHead->GetIsAttack() || m_nowHead->GetAction() == m_nowHead->eJumpAttack)
		{
			m_obj->x += m_moveSpeed * DELTA_TIME;
			if (!m_jumpping)
				m_nowHead->SetAction(Head::eWalk);
		}
	}
	//아래 방향키 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_isDown = true;
	}
}