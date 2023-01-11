#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "IllusionEffect.h"
#include"CSound.h"

void Player::Move()
{
	if (m_nowHead->GetAction() == m_nowHead->eWalk)
	{
		m_nowHead->SetAction(m_nowHead->eIdle, true);
	}

	InputDashKey();

	//������� ��
	if (m_dashing)
	{		//##dash �̵��� ���� �ʿ�
		illusionEffectCount += DELTA_TIME;

		if (illusionEffectCount > 0.18)
		{
			if (typeid(*m_nowHead) == typeid(LittleBorn))
			{
				OBJECTMANAGER->AddObject("Effect", m_obj->x, m_obj->y - 54, eObject)->AddComponent<IllusionEffect>()->Setting(m_nowHead->GetNowImage(), m_isLeft);
			}
			else
			{
				OBJECTMANAGER->AddObject("Effect", m_obj->x, m_obj->y - 40, eObject)->AddComponent<IllusionEffect>()->Setting(m_nowHead->GetNowImage(), m_isLeft);
			}
			illusionEffectCount = 0;
		}
		if (m_isLeft) { m_obj->x -= m_dashNowSpeed * DELTA_TIME; }
		else { m_obj->x += m_dashNowSpeed * DELTA_TIME; }
		m_obj->y -= 1;
	}
	else
	{
		InputArrowKey();	//���, �����߿� �ȱ� �Ұ��ϹǷ�
	}

	//�ٴڿ��� ���� ������ ��
	if (!m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
	{
		m_jumpping = true;	//���������� �ν��ϱ�
	}

	//�������� ��
	if (m_jumpping)
	{
		if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
		{
			ResetJump();
			m_nowHead->SetAction(m_nowHead->eJumpLand);
			m_knockBack = false;
			m_knockBackY = 0;
		}
		else if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsTopCollision())
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(0);
		if (m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() < 0)
		{
			//##�����׼����Ǽ����ʿ�
			if (m_knockBack)
			{
				if (m_obj->y - m_knockBackY >= 20)
				{
					m_knockBack = false;
					m_knockBackY = 0;
				}
			}
			else if (!m_dashing && !m_nowHead->GetIsAttack())
			{
				m_nowHead->SetAction(m_nowHead->eJumpDown, true);
			}
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
			SOUNDMANAGER->FindSound("Jump")->SetVolume(50);
			SOUNDMANAGER->FindSound("Jump")->Play(false);
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			if (m_isDown)	//�Ʒ�����
			{
				m_obj->y += 11;
			}
			else			//�Ϲ�����
			{
				m_obj->y -= 11;			//�������� �ٴ��浹�����ɷ��� Ž���� ���̸�ŭ �̸� �����

				m_nowHead->ResetAttack();
				m_jumpping = true;
				m_nowHead->SetAction(Head::eJump);
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(m_jumpSpeed);
				if (++m_jumpCount >= 2)
				{
					EFFECTMANAGER->AddEffect<DoubleJumpSmoke>(m_obj->x, m_obj->y, m_isLeft);
				}

				SOUNDMANAGER->AddSound("Jump", "./Resources/Sound/Jump.wav");
				SOUNDMANAGER->FindSound("Jump")->SetVolume(50);
				SOUNDMANAGER->FindSound("Jump")->Play(false);
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
			SOUNDMANAGER->FindSound("Dash")->SetVolume(50);
			SOUNDMANAGER->FindSound("Dash")->Play(false);

			m_jumpping = false;
			m_nowHead->ResetAttack();
			m_dashNowSpeed = m_dashSpeed;
			if (m_dashing)
			{
				m_dashCount = 2;
			}
			m_dashing = true;
			m_nowHead->SetAction(m_nowHead->eDash, true, true);
			EFFECTMANAGER->AddEffect<DashSmoke>(m_obj->x, m_obj->y, m_isLeft);
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(0);
			m_dashNowTime = m_dashTime;
			m_playerHitBox->SetIsActive(false);

			SOUNDMANAGER->AddSound("Dash", "./Resources/Sound/Dash.wav");
			SOUNDMANAGER->FindSound("Dash")->SetVolume(50);
			SOUNDMANAGER->FindSound("Dash")->Play(false);
		}
	}
}

void Player::InputArrowKey()
{
	m_isDown = false;
	//����Ű ���� �Է½�
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
	//����Ű ������ �Է½�
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
	//�Ʒ� ����Ű �Է½�
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_isDown = true;
	}
}