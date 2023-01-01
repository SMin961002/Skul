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
	img[eJump]->Setting(0.1, false);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpAttack]->Setting(0.1, false);
	img[eJumpAttack]->Setting(img[eJumpAttack]->GetImageSize() - 1, 0.2);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");	//JumpFall �̹����� ���������� ���, img���� ���� �ξ���
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
	m_isDown = false;

	m_dashSpeed = 3.5;	//##dash �̵��� ���� �ʿ�
	m_dashTime = 2 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//��� ������ 0.4, update�� -
	m_dashCool = 1;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//��� �ִ� Ƚ��
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
	CollisionComponent* attack1 = m_obj->AddComponent<CollisionComponent>();
	attack1->Setting(50, m_obj->x + 6 + 40, m_obj->y - 24 + 72, "�⺻����");
	attack1->SetIsActive(false);
	m_obj->AddCollisionComponent(attack1);
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
		//m_obj->x = �Ӹ�obj.x ; m_obj->y = �Ӹ�obj->y;
		m_skillNowCoolS = m_skillCoolS;
	}
}

void Head_Basic::ActionArrangement()
{
	if (nowImg->GetIsImageEnded())
	{
		nowImg->Reset();
		if (m_attackCast)
		{
			m_action = eAutoAttack_2;
			nowImg = img[eAutoAttack_2];
			m_attackCount = 2;
			for (auto iter : m_obj->GetCollisionComponent())
			{
				if (iter->GetName() == "�⺻����")
				{
					iter->SetIsActive(true);
				}
			}
			m_attackCast = false;
		}
		else
		{
			nowImg = img[eIdle];
			m_attackCount = 0;
			for (auto iter : m_obj->GetCollisionComponent())
			{
				if (iter->GetName() == "�⺻����")
				{
					iter->SetIsActive(false);
				}
			}//end colli autoAttack false
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

void Head_Basic::CollisionUpdate()
{
	for (auto iter : (m_obj->GetCollisionComponent()))
	{
		if (iter->GetName() == "�⺻����")
		{
			if (m_action == eAutoAttack_1)
			{
				if (img[eAutoAttack_1]->GetFrame() > 1 && img[eAutoAttack_1]->GetFrame() < 3)
				{
					iter->SetIsActive(true);
				}
				else
				{
					iter->SetIsActive(false);
				}
			}
			else if (m_action == eAutoAttack_2)
			{
				if (img[eAutoAttack_2]->GetFrame() > 0 && img[eAutoAttack_2]->GetFrame() < 2)
				{
					iter->SetIsActive(true);
				}
				else
				{
					iter->SetIsActive(false);
				}
			}



			if (m_isLeft)
				iter->Setting(m_obj->x, m_obj->y);
			else iter->Setting(m_obj->x + 50, m_obj->y - 16);
		}
	}
}

void Head_Basic::InputAttackKey()
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
				m_attackCount = 1;
				for (auto iter : m_obj->GetCollisionComponent())
				{
					if (iter->GetName() == "�⺻����")
					{
						iter->SetIsActive(true);
					}
				}
				m_imageChange = true;
			}
			else
			{
				m_attackCast = true;
			}
		}//end else jumpping
	}//end 'X'
}

void Head_Basic::DrawCharactor()
{
	nowImg->CenterRender(m_obj->x, m_obj->y - 56, 2, 2, 0, m_isLeft);
}