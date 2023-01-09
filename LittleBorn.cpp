#include "stdafx.h"
#include "LittleBorn.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"

void LittleBorn::ImageSetting()
{
	//이미지 삽입
	img[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Idle");
	img[eIdle]->Setting(0.15f, true);
	img[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Walk");
	img[eWalk]->Setting(0.1f, true);
	img[eDash] = IMAGEMANAGER->FindImageVector("Basic_Dash");
	img[eDash]->Setting(0.8f, false);
	img[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Attack1");
	img[eAutoAttack_1]->Setting(0.08f, false);
	img[eAutoAttack_1]->Setting(img[eAutoAttack_1]->GetImageSize() - 1, 0.1);
	img[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Attack2");
	img[eAutoAttack_2]->Setting(0.08f, false);
	img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
	img[eJump]->Setting(0.05, true);
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpAttack]->Setting(0.08, false);
	img[eJumpAttack]->Setting(img[eJumpAttack]->GetImageSize() - 1, 0.1);
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");
	img[eJumpDown]->Setting(0.1, true);
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
	img[eJumpLand]->Setting(0.1, false);
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
	img[eSkill_1]->Setting(0.1, false);
	img[eTagAction] = IMAGEMANAGER->FindImageVector("Basic_TagAction");
	img[eTagAction]->Setting(0.05, false);

	img_headless[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Headless_Idle");
	img_headless[eIdle]->Setting(0.15f, true);
	img_headless[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Headless_Walk");
	img_headless[eWalk]->Setting(0.1f, true);
	img_headless[eDash] = IMAGEMANAGER->FindImageVector("Basic_Headless_Dash");
	img_headless[eDash]->Setting(0.8f, false);
	img_headless[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Headless_Attack1");
	img_headless[eAutoAttack_1]->Setting(0.08f, false);
	img_headless[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Headless_Attack2");
	img_headless[eAutoAttack_2]->Setting(0.08f, false);
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

void LittleBorn::ParameterSetting()
{
	m_species = eSkulSpecies::eBasic;
	m_tagCoolTime = 10.0f;

	m_projectileHead = OBJECTMANAGER->AddObject("Head", *m_x, *m_y, ePlayerProjectile)->AddComponent<ProjectileHeadSkull>();
	m_projectileHead->Off();
	m_action = eIdle;

	m_moveSpeed = 180;
	m_isDown = false;

	m_dashSpeed = 240;		//##dash 이동식 수정 필요
	m_dashTime = 0.85 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//대시 누르면 0.4, update시 -
	m_dashCool = 2;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//대시 최대 횟수

	m_jumpSpeed = 8;
	m_jumpCount = 0;
	m_jumpMax = 2;

	m_attackCount = 0;
	m_attackMax = 2;
	m_attackCast[0] = false;
	m_attackCast[1] = false;

	m_skillNowCoolA = 0;
	m_skillNowCoolS = 0;
	m_skillCoolA = 6;
	m_skillCoolS = 3;
	m_skillUsing = false;
	m_headThrow = false;
	m_imageChange = false;
}

void LittleBorn::CollisionSetting()
{
	m_collAutoAttack->Setting(50, *m_x + 46, *m_y - 24 + 72, "BasicAttack_BasicSkul");
	m_collAutoAttack->SetIsActive(false);

	m_collSkillTag->Setting(70, *m_x, *m_y, "TagAttack_BasicSkul");
	m_collSkillTag->SetIsActive(false);
}

void LittleBorn::Release()
{
	m_projectileHead->DestroyProjectileHead();
}

void LittleBorn::CoolDown()
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

void LittleBorn::ActionArrangement()
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
			if (m_attackCast[0])
			{
				m_attackCast[0] = false;
				m_attackCast[1] = true;
			}
			else if (m_attackCast[1])
			{
				m_action = eAutoAttack_2;
				nowImg = img[eAutoAttack_2];
				nowImg->Reset();
				m_attackCount = 2;
				m_attackCast[1] = false;
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
			cout << "이미지 바꾸기 " << action << endl;
			m_attackCast[0] = false;
			m_attackCast[1] = false;
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
			if (m_attackCast[0])
			{
				m_attackCast[0] = false;
				m_attackCast[1] = true;
			}
			else if (m_attackCast[1])
			{
				m_action = eAutoAttack_2;
				nowImg = img_headless[eAutoAttack_2];
				nowImg->Reset();
				m_attackCount = 2;
				m_attackCast[1] = false;
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
			m_attackCast[0] = false;
			m_attackCast[1] = false;
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
	if (nowImg == img[eIdle])
	{
		m_action = eIdle;
		m_attackCount = 0;
	}
}

void LittleBorn::CollisionUpdate()
{
	m_collAutoAttack->SetIsActive(false);
	m_collSkillTag->SetIsActive(false);

	switch (m_action)
	{
	case eAutoAttack_1:
		if (nowImg->GetFrame() > 1 && nowImg->GetFrame() < 3)
		{
			if (count == 0)
			{
				count = 1;
				*m_x += !*m_isLeft ? 20 : -20;

			}
			m_collAutoAttack->SetIsActive(true);
		}
		else
		{
			count = 0;
		}
		break;
	case eAutoAttack_2:
		if (nowImg->GetFrame() > 0 && nowImg->GetFrame() < 2)
		{
			if (count == 0)
			{
				count = 1;
				*m_x += !*m_isLeft ? 20 : -20;
			}
			m_collAutoAttack->SetIsActive(true);
		}
		else
		{
			count = 0;
		}
		break;
	case eJumpAttack:
		if (nowImg->GetFrame() > 0 && nowImg->GetFrame() < 3)
			m_collAutoAttack->SetIsActive(true);
		break;
	case eTagAction:
		m_collSkillTag->SetIsActive(true);
		if(*m_isLeft)
			m_collSkillTag->Setting(*m_x+25, *m_y-20);
		else
			m_collSkillTag->Setting(*m_x+35, *m_y-20);
		m_attackCount++;
		//태그액션시 이동
		{float move = 300 * DELTA_TIME;
		*m_x += ((*m_isLeft) ? -move : move); }
		break;
	default: break;
	}

	if (m_collAutoAttack->GetIsActive() == true)
	{
		if (*m_isLeft)
			m_collAutoAttack->Setting(*m_x, *m_y - 10);
		else
			m_collAutoAttack->Setting(*m_x + 50, *m_y - 10);
	}
	else
	{
		m_CollObjList.clear();
		listObj().swap(m_CollObjList);
	}
}

void LittleBorn::InputSkillKey()
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

void LittleBorn::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
		if (*m_jumpping)
		{
			if (m_attackCount == 0)
			{
				m_action = eJumpAttack;
				m_imageChange = true;
				m_attackCount++;
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
				m_attackCast[0] = true;
			}
		}//end else jumpping
	}//end 'X'
}

void LittleBorn::TagAction()
{
	m_imageChange = true;
	m_action = eTagAction;
}

bool LittleBorn::GetIsAttack()
{
	switch (m_attackCount)
	{
	case 0:
		return false;
		break;
	case 1:
		if (m_attackCast[1] == true)
			return false;
		else return true;
		break;
	case 2:
		return true;
		break;
	default:
		cout << "공격횟수가 이상하다. attackcount = " << m_attackCount << endl;
		return false;
	}
}

void LittleBorn::DrawCharactor()
{
	//float drawPX = m_headThrow ? *m_x - 2 : *m_x;
	float drawPX = *m_x;
	if (m_headThrow)
	{
		if (*m_isLeft)
			drawPX -= 2;
		else drawPX += 2;
	}
	float drawPY = m_headThrow ? *m_y - 54 : *m_y - 56;
	nowImg->CenterRender(drawPX, drawPY, 2, 2, 0, *m_isLeft);
}

void LittleBorn::OnCollisionAutoAttack(Component* enemy, Object* obj, float dmg, float delay)
{
	bool isEnemyHit = false;
	for (auto iter : m_CollObjList)
	{
		if (iter == obj) isEnemyHit = true;
	}
	if (!isEnemyHit)
	{
		enemy->HitEnemy(dmg, delay);
		m_CollObjList.push_back(obj);
	}
}
