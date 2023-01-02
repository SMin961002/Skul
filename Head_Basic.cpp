#include "stdafx.h"
#include "Head_Basic.h"
#include "RigidBodyComponent.h"

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
	img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
	img[eJump]->Setting(0.1, true);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpAttack]->Setting(0.1, false);
	img[eJumpAttack]->Setting(img[eJumpAttack]->GetImageSize()-1,0.2);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");
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

	img_reborn = IMAGEMANAGER->FindImageVector("Basic_Reborn");
	img_reborn->Setting(0.1f, true);

	nowImg = img[eIdle];
}

void Head_Basic::ParameterSetting()
{
	m_species = eSkulSpecies::eBasic;

	//m_projectileHead = new ProjectileHeadSkull;
	//m_projectileHead->Init();

	m_action = eIdle;

	m_moveSpeed = 180;
	m_isLeft = false;
	m_isDown = false;

	m_dashSpeed = 240;		//##dash �̵��� ���� �ʿ�
	m_dashTime = 2 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//��� ������ 0.4, update�� -
	m_dashCool = 0.5;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//��� �ִ� Ƚ��
	m_dashing = false;

	m_jumpSpeed = 8;
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
	attack1->Setting(50, m_obj->x + 6 + 40, m_obj->y - 24 + 72, "BasicAttack_BasicSkul");
	attack1->SetIsActive(false);
	m_obj->AddCollisionComponent(attack1);
}

void Head_Basic::CoolDown()
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
	if (m_headThrow) {
		if (KEYMANAGER->GetOnceKeyDown('S'))
		{
			m_action = eIdle;
			m_headThrow = false;
			//##m_obj->x = �Ӹ�obj.x ; m_obj->y = �Ӹ�obj->y;
			m_skillNowCoolS = m_skillCoolS;
		}
	}//end if headThrow
}

void Head_Basic::ActionArrangement()
{
	if (nowImg->GetIsImageEnded())
	{
		vImage* tempActionImage = new vImage;
		tempActionImage = m_headThrow ? img_headless[m_action] : img[m_action];
		if(nowImg!=tempActionImage)
			nowImg->Reset();
		if (m_attackCast)
		{
			m_action = eAutoAttack_2;
			nowImg = m_headThrow ? img_headless[eAutoAttack_2] : img[eAutoAttack_2];
			nowImg->Reset();
			m_attackCount = 2;
			m_attackCast = false;
			if (m_isLeft)
			{
				m_obj->x -= m_moveSpeed/10;
			}
			else m_obj->x += m_moveSpeed/10;
		}
		else
		{
			nowImg = m_headThrow ? img_headless[eIdle] : img[eIdle];
			m_action = eIdle;
			m_attackCount = 0;
		}
		m_skillUsing = false;
	}
	if (m_imageChange)
	{
		m_attackCast = false;
		if (m_headThrow)	//�Ӹ� ������
		{
			switch (m_action)
			{
			case eIdle:
			case eDash:
			case eAutoAttack_1:
			case eAutoAttack_2:
			case eJump:
			case eJumpDown:
			case eJumpAttack:
				if (nowImg != img_headless[m_action])
				{
					nowImg->Reset();
					nowImg = img_headless[m_action];
					if (m_action == eJumpLand) // �����������´� �̹����� �ٲٰ� ���´� idle�� ���
					{
						m_action = eIdle;
					}
				}
				//m_attackCount = 0;
				break;
			case eSkill_1:
				nowImg = img[eSkill_1];
			default:
				NULL;
				break;
			}//end switch
		}//end if headTrow
		else	//�Ӹ� ������
		{
			if (nowImg != img[m_action])
			{
				nowImg->Reset();
				nowImg = img[m_action];
				nowImg->Reset();
				if (m_action == eJumpLand) // �����������´� �̹����� �ٲٰ� ���´� idle�� ���
				{
					m_action = eIdle;
				}
			}
			//m_attackCount = 0;
		}//end else headThrow
	}
}

void Head_Basic::CollisionUpdate()
{
	for (auto iter : (m_obj->GetCollisionComponent()))
	{
		if (iter->GetName() == "BasicAttack_BasicSkul")
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
			else if (m_action == eJumpAttack)
			{
				if (img[eJumpAttack]->GetFrame() > 0 && img[eJumpAttack]->GetFrame() < 3)
				{
					iter->SetIsActive(true);
				}
				else
				{
					iter->SetIsActive(false);
				}
			}
			else iter->SetIsActive(false);

			if (m_isLeft)
				iter->Setting(m_obj->x, m_obj->y-10);
			else iter->Setting(m_obj->x + 50, m_obj->y-10);

			break;
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

void ProjectileHeadSkull::Init()
{
	m_img = IMAGEMANAGER->FindImage("Basic_Skull");
	m_isThrowed = false;
	m_isReverse = false;
	m_hit = false;
	m_speed = 60;
	m_rot = 0;
	m_obj->AddComponent<RigidBodyComponent>();
	m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);
	m_colHeadSkull = m_obj->AddComponent<CollisionComponent>();
	m_colHeadSkull->Setting(14, m_obj->x, m_obj->y - 24, "ThrowHeadSkull");
	m_colHeadSkull->SetIsActive(false);
}

void ProjectileHeadSkull::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_colHeadSkull->GetName())
	{
		if (other->GetName() == "Enemy")
		{
			m_hit = true;
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			other->GetComponent<Enemy>()->HitEnemy(20);
		}
		else if (other->GetName() == "PlayerHitRange")
		{
			m_isThrowed = false;
		}
	}
	if (collisionName == "BasicAttack_BasicSkul")
	{
		if (other->GetName() == "Enemy")
		{
		}
	}
}
