#include "stdafx.h"
#include "LittleBorn.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"
#include "HitDamageEffect.h"
#include"CSound.h"

void LittleBorn::ImageSetting()
{
	//?̹??? ????
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
	img[eReborn] = IMAGEMANAGER->FindImageVector("Basic_Reborn");

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

	m_soundTrigerReborn1 = false;
	m_soundTrigerReborn2 = false;

	m_dashSpeed = 500;		//##dash ?̵??? ???? ?ʿ?
	m_dashTime = 0.85 * img[eDash]->GetTotalDelay();
	m_dashNowTime = 0.0f;	//???? ?????? 0.4, update?? -
	m_dashCool = 1;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;			//???? ?ִ? Ƚ??

	m_jumpSpeed = 8;
	m_jumpCount = 0;
	m_jumpMax = 2;

	m_attackCount = 0;
	m_attackMax = 2;
	m_attackCool = 0.3;
	m_attackCast[0] = false;
	m_attackCast[1] = false;

	m_tagCoolTime = 10;
	m_skillNowCoolA = 0;
	m_skillNowCoolS = 0;
	m_skillCoolA = 6;
	m_skillCoolS = 3;
	m_headThrow = false;
	m_imageChange = false;

	m_attacksound = false;

	m_nonCansleAction = false;
	m_tagAttackDelay = 0.38;
	m_tagAttackNowDelay = 0;
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
}

void LittleBorn::CoolDown()
{
	float deltaTime = DELTA_TIME;

	if (m_action == eTagAction)
	{
		if (m_tagAttackNowDelay > 0)
		{
			m_tagAttackNowDelay -= deltaTime;
			if (m_tagAttackNowDelay < 0)
			{
				m_tagAttackNowDelay = m_tagAttackDelay;
				m_CollObjList.clear();
				listObj().swap(m_CollObjList);
			}
		}
	}
	if (m_skillNowCoolA > 0)
	{
		m_skillNowCoolA -= deltaTime;
		if (m_projectileHead->GetSkullOnOff() == false || m_skillNowCoolA <= 0)
		{
			PutOnHead();
		}
	}
	CoolDownDelay(&m_skillNowCoolS, deltaTime);
	CoolDownDelay(&m_dashNowCool, deltaTime);
	CoolDownDelay(&m_attackNowCool, deltaTime);
}

void LittleBorn::ActionArrangement()
{
	if (m_action == eReborn)
	{
		if (m_soundTrigerReborn1 == false)
		{
			if (nowImg->GetFrame() == 1)
			{
				SOUNDMANAGER->FindSound("SkulRise")->Play(false);
				m_soundTrigerReborn1 = true;
			}
		}
		else if (m_soundTrigerReborn2 == false)
		{
			if (nowImg->GetFrame() == 11)
			{
				SOUNDMANAGER->FindSound("SkulCape")->Play(false);
				m_soundTrigerReborn2 = true;
			}
		}
		if (nowImg->GetFrame() == 0)
		{
			if (KEYMANAGER->GetOnceKeyDown(VK_LEFT) || KEYMANAGER->GetOnceKeyDown(VK_RIGHT)
				|| KEYMANAGER->GetOnceKeyDown('Z') || KEYMANAGER->GetOnceKeyDown('X') || KEYMANAGER->GetOnceKeyDown('C'))
			{
				nowImg->Setting(0, 0.0f);
			}
		}
	}
	if (!m_headThrow)
	{
		if (nowImg->GetIsImageEnded())
		{
			m_nonCansleAction = false;

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
				if (GetIsAttack() && m_action != eAutoAttack_2)
				{
					m_attackNowCool = m_attackCool;
				}
				nowImg = img[eIdle];
				m_action = eIdle;
				m_attackCount = 0;
			}
		}
		if (m_imageChange)
		{
			m_attackCast[0] = false;
			m_attackCast[1] = false;
			if (nowImg != img[m_action])
			{
				nowImg->Reset();
				nowImg = img[m_action];
				nowImg->Reset();
				if (m_action == eJumpLand) // ???????????´? ?̹????? ?ٲٰ? ???´? idle?? ????
				{
					m_action = eIdle;
				}
			}
			if (m_action <eAutoAttack_1 || m_action >eJumpAttack)
			{
				m_attackCount = 0;
			}
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
			m_nonCansleAction = false;

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
				if (m_action == eJumpLand) // ???????????´? ?̹????? ?ٲٰ? ???´? idle?? ????
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
		m_nonCansleAction = false;
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
		if (*m_isLeft)
			m_collSkillTag->Setting(*m_x + 25, *m_y - 20);
		else
			m_collSkillTag->Setting(*m_x + 35, *m_y - 20);
		m_attackCount++;
		//?±׾׼ǽ? ?̵?
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
	else if (m_collSkillTag->GetIsActive() == false)
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
				SOUNDMANAGER->FindSound("SkulSkill1")->Play(false);
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
			m_projectileHead->Off();
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
				if (m_attackNowCool == 0)
				{
					SOUNDMANAGER->FindSound("SkulAttack2")->Play(false);
					m_action = eJumpAttack;
					m_imageChange = true;
					m_attackCount++;
				}
			}
		}//end if jumpping
		else
		{
			if (m_attackCount == 0)
			{
				if (m_attackNowCool == 0)
				{
					SOUNDMANAGER->FindSound("SkulAttack1")->Play(false);
					m_action = eAutoAttack_1;
					m_attackCount = 1;
					m_imageChange = true;
					m_attacksound = true;
				}
			}
			else
			{
				if (m_attacksound == true)
				{
					SOUNDMANAGER->FindSound("SkulAttack2")->Play(false);
					m_attacksound = false;
				}
				m_attackCast[0] = true;
			}
		}//end else jumpping
	}//end 'X'
}

void LittleBorn::TagAction()
{
	m_headThrow = false;
	m_nonCansleAction = true;
	m_imageChange = true;
	m_action = eTagAction;
	img[eTagAction]->Reset();
	m_tagAttackNowDelay = m_tagAttackDelay;
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
		cout << "????Ƚ???? ?̻??ϴ?. attackcount = " << m_attackCount << endl;
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
		OBJECTMANAGER->AddObject("Effect", obj->x + MY_UTILITY::getFromFloatTo(-40, 40), obj->y - MY_UTILITY::getFromFloatTo(40, 100), eBossObject)->AddComponent<HitDamageEffect>()->Setting(10);
		SOUNDMANAGER->FindSound("SkulAttackBluntSmall")->Play(false);
	}
}

void LittleBorn::OnCollisionTagAttack(Component* enemy, Object* obj, float dmg, float delay)
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
		SOUNDMANAGER->FindSound("SkulAttackBluntLarge")->Play(false);
		OBJECTMANAGER->AddObject("Effect", obj->x + MY_UTILITY::getFromFloatTo(-40, 40), obj->y - MY_UTILITY::getFromFloatTo(40, 100), eBossObject)->AddComponent<HitDamageEffect>()->Setting(10);

		Enemy* e = obj->GetComponent<Enemy>();
		if (e != nullptr)
		{
			if (e->GetX() > *m_x)
			{
				e->SetPosition(e->GetX() + 10, e->GetY() + 5);
			}
			else if (e->GetX() < *m_x)
			{
				e->SetPosition(e->GetX() - 10, e->GetY() + 5);
			}
		}
	}
}
