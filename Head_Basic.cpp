#include "stdafx.h"
#include "Head_Basic.h"

void Head_Basic::ImageSetting()
{
	//�̹��� ����
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

	//���setting �ʿ���
	//���setting �ʿ���
	//���setting �ʿ���	##
	img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");	//JumpFall �̹����� ���������� ���, img���� ���� �ξ���
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
	img[eSkill_2] = IMAGEMANAGER->FindImageVector("Basic_Idle");	//�Ӹ�����ü�� ������ �̹����� ����(���ִ»��·� �� ����Ʈ�� ����)
	//���setting �ʿ���
	//���setting �ʿ���
	//���setting �ʿ���
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
	m_down = false;

	m_dashSpeed = 3.5;	//##dash �̵��� ���� �ʿ�
	m_dashTime = 0.4f;
	m_dashNowTime = 0.0f;	//��� ������ 0.4, update�� -
	m_dashCool = 1;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//��� �ִ� Ƚ��
	m_dashing = false;

	m_jumpSpeed = 3;
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
	m_artifactCoolD = 0;
	m_haveArtifact = false;
	m_commandInput = false;
}


void Head_Basic::InputSkillKey()
{
	if (KEYMANAGER->GetOnceKeyDown('A'))
	{
		m_action = eSkill_1;
		m_skillUsing = true;
		m_commandInput = true;
	}
	else if (KEYMANAGER->GetOnceKeyDown('S'))
	{
		m_action = eSkill_2;
		m_skillUsing = true;
		m_commandInput = true;
	}
}