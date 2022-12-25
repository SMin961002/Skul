#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
	img = IMAGEMANAGER->FindImageVector("Basic_Idle");
	img->Setting(3, true);
	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
	m_action = eIdle;
	m_action_prev = eIdle;


	m_moveSpeed = 3;
	m_isLeft = false;
	m_down = false;

	m_dashDelay = 2000;
	m_dashWaitingTime = 1000;
	m_dashCount = 0;

	m_jumpSpeed = 3;
	m_jumpDelay = 2000;
	m_jumpWaitingTime = 1000;
	m_jumpCount=0;


	m_attackWaitingTime = 1000;
	m_attackCount = 0;
	
	m_skillCoolA = 6000;
	m_skillCoolS = 3000;
	m_skillCoolD = 0;

}

void Player::Update()
{
	Move();
	Action();

}

void Player::Render()
{
	Draw();
}

void Player::Release()
{
}

void Player::Draw()
{
	//프레임끝에 도달한 시간을 WaitingTime에 +delay해서 저장, 커맨드 추가로 입력된 시간이 이 안에 있으면 2회차
	//프레임 순환이 끝나면 현재 action을 idle로 바꾸기
	switch(m_action)
	{
	case eAutoAttack_1:
		break;
	case eAutoAttack_2:
		break;
	case eJump : 
		break;
	case eDash:
		break;
	case eSkill_1:
		break;
	case eSkill_2:

		break;

		case eIdle:
		default:
	}
		img->Render(m_obj->x, m_obj->y, 1, 1, 0);
}

void Player::Move()
{
	m_down = false;
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		m_action = eWalk;
		m_obj->x -= m_moveSpeed;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		m_action = eWalk;
		m_obj->x += m_moveSpeed;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_down = true;
	}
	if (KEYMANAGER->GetOnceKeyDown('C'))
	{
		m_action = m_down ? eJumpDown : eJump;
	}
	if (KEYMANAGER->GetOnceKeyDown('Z'))
	{
		m_action = eDash;
	}

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Action()
{
	//z대시 x공격 c점프
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
			m_action = eAutoAttack_1;
	}

	//a s스킬
	if (KEYMANAGER->GetOnceKeyDown('A'))
	{
		m_action = eSkill_1;
	}
	if (KEYMANAGER->GetOnceKeyDown('S'))
	{
		m_action = eSkill_2;
	}
	//d정수
	if (KEYMANAGER->GetOnceKeyDown('D'))
	{
	}
}