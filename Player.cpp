#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
	//�̹��� ����
	img[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Idle");
	img[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Walk");
	img[eDash] = IMAGEMANAGER->FindImageVector("Basic_Dash");
	img[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Attack1");
	img[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Attack2");
	img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");	//JumpFall �̹����� ���������� ���, img���� ���� �ξ���
	img_jumpFall = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
	img[eSkill_2] = IMAGEMANAGER->FindImageVector("Basic_Idle");	//�Ӹ�����ü�� ������ �̹����� ����(���ִ»��·� �� ����Ʈ�� ����)
	img_reborn = IMAGEMANAGER->FindImageVector("Basic_Reborn");
	
	for (short i = 0; i < eActionTagNumber; i++)
	{
	img[i]->Setting(0.1f, true);
	}
	img_jumpFall->Setting(0.1f, true);
	img_reborn->Setting(0.1f, true);

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
	//Action();

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
	//�����ӳ��� ������ �ð��� WaitingTime�� +delay�ؼ� ����, Ŀ�ǵ� �߰��� �Էµ� �ð��� �� �ȿ� ������ 2ȸ��
	//������ ��ȯ�� ������ ���� action�� idle�� �ٲٱ�
	//switch(m_action)
	//{
	//case eAutoAttack_1:
	//	break;

	//case eAutoAttack_2:
	//	break;

	//case eJump : 
	//	break;

	//case eDash:
	//	break;

	//case eSkill_1:
	//	break;

	//case eSkill_2:

	//	break;

	//	case eIdle:
	//	default:
	//}
	img[m_action]->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}

void Player::Move()
{
	m_down = false;
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		if (m_action == eIdle) {
			m_action = eWalk;
		}
		m_obj->x -= m_moveSpeed;
	}
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		if (m_action == eIdle) {
			m_action = eWalk;
		}
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