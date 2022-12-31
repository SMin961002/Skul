#include "stdafx.h"
#include "Head_Basic.h"

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

	//↓↓setting 필요↓↓
	//↓↓setting 필요↓↓
	//↓↓setting 필요↓↓	##
	img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
	img[eJump]->Setting(0.1, false);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpAttack]->Setting(0.1, false);
	img[eJumpAttack]->Setting(img[eJumpAttack]->GetImageSize()-1,0.2);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");	//JumpFall 이미지는 착지순간만 재생, img변수 따로 두었음
	img[eJumpDown]->Setting(0.1, true);
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
	img[eJumpLand]->Setting(0.1, false);
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
	img[eSkill_1]->Setting(0.1, false);

	img_headless[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Headless_Idle");
	img_headless[eIdle]->Setting(0.15f, true);
	img_headless[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Headless_Walk");
	img_headless[eWalk]->Setting(0.1f, true);
	img_headless[eDash] = IMAGEMANAGER->FindImageVector("Basic_Headless_Dash");
	img_headless[eDash]->Setting(0.4f, false);
	img_headless[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Headless_Attack1");
	img_headless[eAutoAttack_1]->Setting(0.11f, false);
	img_headless[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Headless_Attack2");
	img_headless[eAutoAttack_2]->Setting(0.15f, false);

	//↑↑setting 필요↑↑
	//↑↑setting 필요↑↑
	//↑↑setting 필요↑↑
	img_reborn = IMAGEMANAGER->FindImageVector("Basic_Reborn");
	img_reborn->Setting(0.1f, true);

	nowImg = img[eIdle];
}

void Head_Basic::ParameterSetting()
{
	m_species = eSkulSpecies::eBasic;

	m_action = eIdle;

	m_moveSpeed = 3;
	m_isLeft = false;

	m_dashSpeed = 3.5;	//##dash 이동식 수정 필요
	m_dashTime = 2 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//대시 누르면 0.4, update시 -
	m_dashCool = 1;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//대시 최대 횟수
	m_dashing = false;

	m_jumpSpeed = 50;
	m_jumpNowSpeed = 0.2;
	m_jumpCount = 0;
	m_jumpMax = 2;
	m_jumpping = false;

	m_attackCount = 0;
	m_attackMax = 2;
	m_attackCast = false;

	m_skillCoolA = 6;
	m_skillCoolS = 3;
	m_skillUsing = false;
	m_headThrow = false;
	m_imageChange = false;
}

void Head_Basic::CollisionSetting()
{
	collision[eAutoAttack_1coll] = m_obj->AddComponent<CollisionComponent>();
	
}

void Head_Basic::InputSkillKey()
{
	if (KEYMANAGER->GetOnceKeyDown('A'))
	{
		m_skillNowCoolS = m_skillCoolA;
		m_action = eSkill_1;
		m_skillUsing = true;
		m_headThrow = true;
		m_imageChange = true;
	}
	else if (KEYMANAGER->GetOnceKeyDown('S'))
	{
		m_action = eIdle;
		m_headThrow = false;
		//m_obj->x = 머리obj.x ; m_obj->y = 머리obj->y;
		m_skillNowCoolS = m_skillCoolS;
	}
}

void Head_Basic::ActionArrangement()
{
	Head::ActionArrangement();
}

void Head_Basic::DrawCharactor()
{
	nowImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}