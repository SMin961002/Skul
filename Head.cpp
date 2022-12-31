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
}

void Head::Render()
{
	DrawCharactor();
	DrawEffect();
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

void Head::CollisionSetting()
{
	/*
	Do Nothing
	*/
}

void Head::CoolDown()
{
	float deltaTime = DELTA_TIME;
	if (m_dashNowCool > 0)
	{
		m_dashNowCool -= deltaTime;
		if (m_dashNowCool < 0) m_dashNowCool = 0;
	}
	if (m_dashNowTime > 0)
	{
		m_dashNowTime -= deltaTime;
		if (m_dashNowTime < 0)
		{
			m_dashNowTime = 0;
			m_dashCount = 0;
			m_dashing = false;
			m_dashNowCool = m_dashCool;
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
		}
	}

	if (m_skillNowCoolA > 0)
	{
		m_skillNowCoolA -= deltaTime;
		if (m_skillNowCoolA < 0)m_skillNowCoolA = 0;
	}
	if (m_skillNowCoolS > 0)
	{
		m_skillNowCoolS -= deltaTime;
		if (m_skillNowCoolS < 0) m_skillNowCoolS = 0;
	}
}

void Head::Move()
{
	if (m_action == eWalk)
	{
		m_action = this->eIdle;
		m_imageChange = true;
	}
	InputJumpKey();
	InputDashKey();

	//대시중일 때
	if (m_dashing)
	{		//##dash 이동식 수정 필요
		if (m_isLeft) { m_obj->x -= m_dashSpeed; }
		else { m_obj->x += m_dashSpeed; }
	}
	else if (m_attackCount == 0)
	{
		InputArrowKey();	//대시, 공격중에 걷기 불가하므로
	}

	//점프중일 때
	if (m_jumpping)
	{
		m_obj->y += m_jumpNowSpeed;
		//천장머리쿵 구현되어있음 적용방법 고민해보기
		m_jumpNowSpeed = -m_obj->GetComponent<RigidBodyComponent>()->GetGravity();
		if (m_jumpNowSpeed < 0)
		{
			m_jumpNowSpeed = 0;
		}
		if (m_jumpNowSpeed == 0)
		{
			if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision() == true)
			{
				ResetJump();
				nowImg->Reset();
				nowImg = img[eJumpLand];
				nowImg->Reset();
				m_action = eIdle;
			}
		}
	}
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
			m_attackCount = 0;

			m_action = eJump;
			m_jumpCount++;
			m_jumpNowSpeed = m_jumpSpeed;
			m_jumpping = true;
			m_imageChange = true;
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
			m_jumpNowSpeed = 0;

			ResetAttack();

			m_dashing = true;
			m_dashCount++;
			m_action = eDash;
			img[eDash]->Reset();
			nowImg = img[eDash];
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);//##중력이 왜 안꺼질까
			m_dashNowTime = m_dashTime;
			
			if (m_dashing) cout << "dash" << endl;
		}
	}
}

void Head::InputArrowKey()
{
	//방향키 왼쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		if(m_attackCount == 0)
		m_obj->x -= m_moveSpeed;
		if (!m_jumpping) {
			m_action = eWalk;
			m_imageChange = true;
		}
	}
	//방향키 오른쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		m_obj->x += m_moveSpeed;
		if(!m_jumpping) {
			m_action = eWalk;
			m_imageChange = true;
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
				m_imageChange = true;
			}
		}//end if jumpping
		else
		{
			if (m_attackCount == 0)
			{
				m_action = eAutoAttack_1;
				m_attackCount++;
				m_imageChange = true;
			}
			else 
			{
				cout << "attack cast" << endl;
				m_attackCast = true;
			}
		}//end else jumpping
	}//end 'X'
}


void Head::InputSkillKey()
{
/*
	Do Nothing
*/
}

void Head::ActionArrangement()
{
	if (nowImg->GetIsImageEnded())
	{
		nowImg->Reset();	
		if (m_attackCast)
		{
			nowImg = img[eAutoAttack_2];
			m_attackCount = 2;
			m_attackCast = false;
		}
		else
		{
			nowImg = img[eIdle];
			m_attackCount = 0;
		}
	}
	if (m_imageChange)
	{
		m_attackCast = false;

		if (nowImg != img[m_action])
		{
			nowImg->Reset();
			nowImg = img[m_action];
		}
		//m_attackCount = 0;
	}
}

void Head::DrawCharactor()
{
	nowImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}

void Head::DrawEffect()
{
}