#include "stdafx.h"
#include "Head_Basic.h"
#include "RigidBodyComponent.h"

void Head_Basic::ImageSetting()
{
	//이미지 삽입
	img[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Idle");
	img[eIdle]->Setting(0.15f, true);
	img[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Walk");
	img[eWalk]->Setting(0.1f, true);
	img[eDash] = IMAGEMANAGER->FindImageVector("Basic_Dash");
	img[eDash]->Setting(0.4f, false);
	img[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Attack1");
	img[eAutoAttack_1]->Setting(0.11f, false);
	img[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Attack2");
	img[eAutoAttack_2]->Setting(0.15f, false);
	img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
	img[eJump]->Setting(0.05, true);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpAttack]->Setting(0.07, false);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");
	img[eJumpDown]->Setting(0.1, true);
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
	img[eJumpLand]->Setting(0.1, false);
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
	img[eSkill_1]->Setting(0.1, false);
	img[eTagAction] = IMAGEMANAGER->FindImageVector("Basic_TagAction");
	img[eAutoAttack_2]->Setting(0.15f, false);

	img_headless[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Headless_Idle");
	img_headless[eIdle]->Setting(0.15f, true);
	img_headless[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Headless_Walk");
	img_headless[eWalk]->Setting(0.1f, true);
	img_headless[eDash] = IMAGEMANAGER->FindImageVector("Basic_Headless_Dash");
	img_headless[eDash]->Setting(0.4f, false);
	img_headless[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Headless_Attack1");
	img_headless[eAutoAttack_1]->Setting(0.05f, false);
	img_headless[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Headless_Attack2");
	img_headless[eAutoAttack_2]->Setting(0.05f, false);
	img_headless[eJump] = IMAGEMANAGER->FindImageVector("Basic_Headless_JumpStart");
	img_headless[eJump]->Setting(0.1, true);
	img_headless[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_Headless_JumpAttack");
	img_headless[eJumpAttack]->Setting(0.07, false);
	img_headless[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_Headless_JumpRepeat");
	img_headless[eJumpDown]->Setting(0.1, true);
	img_headless[eJumpLand] = IMAGEMANAGER->FindImageVector("Basic_Headless_JumpFall");
	img_headless[eJumpLand]->Setting(0.1, false);

	img_reborn = IMAGEMANAGER->FindImageVector("Basic_Reborn");
	img_reborn->Setting(0.1f, true);

	nowImg = img[eIdle];
}

void Head_Basic::ParameterSetting()
{
	m_species = eSkulSpecies::eBasic;

	m_projectileHead = OBJECTMANAGER->AddObject("Head", *m_x, *m_y, ePlayerHead)->AddComponent<ProjectileHeadSkull>();
	m_projectileHead->Off();
	m_action = eIdle;

	m_moveSpeed = 180;
	m_isDown = false;

	m_dashSpeed = 240;		//##dash 이동식 수정 필요
	m_dashTime = 2 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//대시 누르면 0.4, update시 -
	m_dashCool = 0.5;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//대시 최대 횟수

	m_jumpSpeed = 8;
	m_jumpCount = 0;
	m_jumpMax = 2;

	m_attackCount = 0;
	m_attackMax = 2;
	m_attackCast = false;

	m_skillNowCoolA = 0;
	m_skillNowCoolS = 0;
	m_skillCoolA = 6;
	m_skillCoolS = 3;
	m_skillUsing = false;
	m_headThrow = false;
	m_imageChange = false;
}

void Head_Basic::CollisionSetting()
{	
	m_BasicHeadAttack = new CollisionComponent;
	m_BasicHeadAttack->Setting(50, *m_x + 6 + 40, *m_y - 24 + 72, "BasicAttack_BasicSkul");
	m_BasicHeadAttack->SetIsActive(false);
	m_collAutoAttack = m_BasicHeadAttack;

	m_TagAttack = new CollisionComponent;
	m_TagAttack->Setting(100, *m_x, *m_y, "TagAttack_BasicSkul");
	m_TagAttack->SetIsActive(false);
	m_collSkill = m_TagAttack;

}

void Head_Basic::Release()
{
	SAFE_DELETE(m_BasicHeadAttack);
	SAFE_DELETE(m_TagAttack);
}

void Head_Basic::CoolDown()
{
	float deltaTime = DELTA_TIME;
	if (m_dashNowCool > 0)
	{
		m_dashNowCool -= deltaTime;
		if (m_dashNowCool < 0) m_dashNowCool = 0;
	}

	if (m_skillNowCoolA > 0)
	{
		m_skillNowCoolA -= deltaTime;
		if (m_skillNowCoolA < 0)
		{
			PutOnHead();
		}
	}
	if (m_skillNowCoolS > 0)
	{
		m_skillNowCoolS -= deltaTime;
		if (m_skillNowCoolS < 0)
		{
			m_skillNowCoolS = 0;
		}
	}
}

void Head_Basic::ActionArrangement()
{
	string action;
	switch (m_action) {
	case eIdle: action = "idle";
		break;
	case eWalk: action = "walk";
	break;
	case eDash: action = "dash";
	break;
	case eJump: action = "jump";
		break;
	}
	if (!m_headThrow)
	{
		if (nowImg->GetIsImageEnded())
		{
			if (nowImg != img[m_action])
				nowImg->Reset();
			if (m_attackCast)
			{
				m_action = eAutoAttack_2;
				nowImg = img[eAutoAttack_2];
				nowImg->Reset();
				m_attackCount = 2;
				m_attackCast = false;
			}
			else
			{
				nowImg = img[eIdle];
				m_action = eIdle;
				m_attackCount = 0;
			}
			m_skillUsing = false;
		}
		if (m_imageChange)
		{
			m_attackCast = false;
			if (nowImg != img[m_action])
			{
				nowImg->Reset();
				nowImg = img[m_action];
				nowImg->Reset();
				if (m_action == eJumpLand) // 점프착지상태는 이미지만 바꾸고 상태는 idle로 취급
				{
					m_action = eIdle;
				}
			}
			//m_attackCount = 0;
		}
		else if (m_action != eIdle && nowImg == img[eIdle])
		{
			SetImage(m_action);
		}
	}//end if !headThrow
	else
	{
		if (nowImg->GetIsImageEnded())
		{
			if (nowImg != img_headless[m_action])
				nowImg->Reset();
			if (m_attackCast)
			{
				m_action = eAutoAttack_2;
				nowImg = img_headless[eAutoAttack_2];
				nowImg->Reset();
				m_attackCount = 2;
				m_attackCast = false;
			}
			else
			{
				nowImg = img_headless[eIdle];
				m_action = eIdle;
				m_attackCount = 0;
			}
			m_skillUsing = false;
		}
		if (m_imageChange)
		{
			m_attackCast = false;
			if (m_action == eSkill_1)
			{
				nowImg->Reset();
				nowImg = img[m_action];
				nowImg->Reset();
			}
			else if (nowImg != img_headless[m_action])
			{
				nowImg->Reset();
				nowImg = img_headless[m_action];
				nowImg->Reset();
				if (m_action == eJumpLand) // 점프착지상태는 이미지만 바꾸고 상태는 idle로 취급
				{
					m_action = eIdle;
				}
			}
			//m_attackCount = 0;
		}
	}
}

void Head_Basic::CollisionUpdate()
{
	m_BasicHeadAttack->SetIsActive(false);
	m_BasicHeadAttack->SetIsActive(false);
	
	switch (m_action)
	{
	case eAutoAttack_1:
		if (nowImg->GetFrame() > 1 && nowImg->GetFrame() < 3)
			m_BasicHeadAttack->SetIsActive(true);
		break;
	case eAutoAttack_2:
		if (nowImg->GetFrame() > 0 && nowImg->GetFrame() < 2)
			m_BasicHeadAttack->SetIsActive(true);
		break;
	case eJumpAttack:
		if (nowImg->GetFrame() > 0 && nowImg->GetFrame() < 3)
			m_BasicHeadAttack->SetIsActive(true);
		break;
	case eTagAction:
		m_TagAttack->SetIsActive(true);
		m_TagAttack->Setting(*m_x, *m_y);
		break;
	default: break;
	}

	if (m_BasicHeadAttack->GetIsActive() == true)
	{
		if (*m_isLeft)
			m_BasicHeadAttack->Setting(*m_x, *m_y - 10);
		else
			m_BasicHeadAttack->Setting(*m_x + 50, *m_y - 10);
	}
}

void Head_Basic::InputSkillKey()
{
	if (KEYMANAGER->GetOnceKeyDown('A'))
	{
		if (m_skillNowCoolA == 0)
			if (!m_headThrow)
			{
				m_headThrow = true;
				m_projectileHead->On();
				m_projectileHead->SetSkullThrow(*m_x, *m_y, *m_isLeft);
				m_skillNowCoolA = m_skillCoolA;
				m_action = eSkill_1;
				m_imageChange = true;
			}
	}//end headThrow
	if (KEYMANAGER->GetOnceKeyDown('S') && m_headThrow)
	{
		if (m_skillNowCoolS == 0) {
			m_action = eIdle;
			EFFECTMANAGER->AddEffect<TeleportationToHead>(*m_x, *m_y, *m_isLeft, 2);
			*m_x = m_projectileHead->GetX();
			*m_y = m_projectileHead->GetY();
			EFFECTMANAGER->AddEffect<TeleportationToHead>(*m_x, *m_y, *m_isLeft, 2);
			m_skillNowCoolS = m_skillCoolS;
			PutOnHead();
		}
	}//end if headThrow
}

void Head_Basic::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
		if (*m_jumpping)
		{
			if (m_action != eJumpAttack)
			{
				m_action = eJumpAttack;
				m_imageChange = true;
			}
		}//end if jumpping
		else
		{
			if (m_attackCount == 0)
			{
				m_action = eAutoAttack_1;
				m_attackCount = 1;
				m_imageChange = true;
			}
			else
			{
				m_attackCast = true;
			}
		}//end else jumpping
	}//end 'X'
}

void Head_Basic::TagAction()
{
	m_imageChange = true;
	m_action = eTagAction;
}

void Head_Basic::DrawCharactor()
{
	nowImg->CenterRender(*m_x, *m_y - 56, 2, 2, 0, *m_isLeft);
}