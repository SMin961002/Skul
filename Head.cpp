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
	if (!m_skillUsing)	//��ų ���� ������ �ٸ� ������ ���� ���ϰ� �ϱ� ����
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

	//������� ��
	if (m_dashing)
	{		//##dash �̵��� ���� �ʿ�
		if (m_isLeft) { m_obj->x -= m_dashSpeed * DELTA_TIME; }
		else { m_obj->x += m_dashSpeed*DELTA_TIME; }
	}
	else if (m_attackCount == 0)
	{
		InputArrowKey();	//���, �����߿� �ȱ� �Ұ��ϹǷ�
	}

	//�ٴڿ��� ���� ������ ��
	if(!m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
	{
		m_jumpping = true;	//���������� �ν��ϱ�
	}

	//�������� ��
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
			if (m_isDown)	//�Ʒ�����
			{
				m_obj->y += 11;
			}
			else			//�Ϲ�����
			{
				m_obj->y -= 11;			//�������� �ٴ��浹�����ɷ��� Ž���� ���̸�ŭ �̸� �����

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
			//m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);//##��������� �ȵ�
			m_dashNowTime = m_dashTime;
		}
	}
}

void Head::InputArrowKey()
{
	m_isDown = false;
	//����Ű ���� �Է½�
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
	//����Ű ������ �Է½�
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		m_obj->x += m_moveSpeed * DELTA_TIME;
		if(!m_jumpping) {
			m_action = eWalk;
			m_imageChange = true;
		}
	}
	//�Ʒ� ����Ű �Է½�
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_isDown = true;
	}
}

void Head::DrawCharactor()
{
	nowImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}
