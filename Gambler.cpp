#include "stdafx.h"
#include "Gambler.h"

void Gambler::ImageSetting()
{
	//이미지 삽입
	img[eIdle] = IMAGEMANAGER->FindImageVector("Gambler_Idle");
	img[eIdle]->Setting(0.15f, true);
	img[eWalk] = IMAGEMANAGER->FindImageVector("Gambler_Walk");
	img[eWalk]->Setting(0.1f, true);
	img[eDash] = IMAGEMANAGER->FindImageVector("Gambler_Dash");
	img[eDash]->Setting(0.4f, false);
	img[eAutoAttack_A1] = IMAGEMANAGER->FindImageVector("Gambler_AttackA1");
	img[eAutoAttack_A1]->Setting(0.11f, false);
	img[eAutoAttack_A2] = IMAGEMANAGER->FindImageVector("Gambler_AttackA2");
	img[eAutoAttack_A2]->Setting(0.15f, false);
	img[eAutoAttack_B1] = IMAGEMANAGER->FindImageVector("Gambler_AttackB1");
	img[eAutoAttack_B1]->Setting(0.15f, false);
	img[eAutoAttack_B2] = IMAGEMANAGER->FindImageVector("Gambler_AttackB2");
	img[eAutoAttack_B2]->Setting(0.11f, false);
	img[eAutoAttack_B3] = IMAGEMANAGER->FindImageVector("Gambler_AttackB3");
	img[eAutoAttack_B3]->Setting(0.15f, false);
	img[eJump] = IMAGEMANAGER->FindImageVector("Gambler_JumpStart");
	img[eJump]->Setting(0.05, true);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Gambler_JumpAttack");
	img[eJumpAttack]->Setting(0.08, false);
	img[eJumpAttack]->Setting(img[eJumpAttack]->GetImageSize() - 1, 0.1);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Gambler_JumpRepeat");
	img[eJumpDown]->Setting(0.1, true);
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Gambler_JumpFall");
	img[eJumpLand]->Setting(0.1, false);
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Gambler_AttackB1");
	img[eSkill_1]->Setting(0.1, false);
	img[eSkill_2] = IMAGEMANAGER->FindImageVector("Gambler_AttackB1");
	img[eSkill_2]->Setting(0.1, false);
	img[eTagAction] = IMAGEMANAGER->FindImageVector("Gambler_TagAction");
	img[eTagAction]->Setting(0.15f, false);

	nowImg = img[eIdle];
}

void Gambler::ParameterSetting()
{
	m_species = eSkulSpecies::eGambler;

	m_action = eIdle;

	m_moveSpeed = 200;
	m_isDown = false;

	m_dashSpeed = 300;		//##dash 이동식 수정 필요
	m_dashTime = 2 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//대시 누르면 0.4, update시 -
	m_dashCool = 0.9;
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
}

void Gambler::CollisionSetting()
{
}

void Gambler::CoolDown()
{
}

void Gambler::ActionArrangement()
{
	if (m_imageChange)
	{
		if (nowImg != img[m_action])
		{
			nowImg->Reset();
			nowImg = img[m_action];
		}
	}
	if (nowImg->GetIsImageEnded())
	{
		//공격기일 경우 이미지캐스팅을 보아야한다
		nowImg->Reset();
		nowImg = img[eIdle];
		m_action = eIdle;
	}
}

void Gambler::CollisionUpdate()
{
}

void Gambler::InputSkillKey()
{
	if(KEYMANAGER->GetOnceKeyDown('A'))
	{ }

	if(KEYMANAGER->GetOnceKeyDown('S'))
	{ }
}

void Gambler::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
		if (m_attackCount == 0)
		{

		}
	}
}

void Gambler::TagAction()
{
}

void Gambler::DrawCharactor()
{
	nowImg->CenterRender(*m_x, *m_y, 2, 2, 0, *m_isLeft);
}
