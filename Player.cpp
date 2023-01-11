#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"
#include"CSound.h"
#include "HitDamageEffect.h"

void Player::Init()
{
	if (GAMEMANAGER->playerHp <= 0)
	{
		GAMEMANAGER->playerHp = m_HpMax;
		m_Hp = m_HpMax;
	}
	else
	{
		m_Hp = GAMEMANAGER->playerHp;
	}
	if (GAMEMANAGER->goldValue <= 0)
	{
		goldValue = 0;
	}
	else
	{
		goldValue = GAMEMANAGER->goldValue;
	}

	if (GAMEMANAGER->isHeadCheck == false)
	{
		isHeadCheck = false;
	}
	else
	{
		isHeadCheck = true;
	}

	hpBar = IMAGEMANAGER->FindImage("hpBar");
	m_UIImage[ePlayerStatus] = IMAGEMANAGER->FindImage("PlayerStatusUI");
	OBJECTMANAGER->m_player = this;
	m_headList[static_cast<int>(eSkulSpecies::eBasic)] = nullptr;

	for (auto iter : GAMEMANAGER->m_headList)
	{
		if (typeid(*iter) == typeid(LittleBorn))
		{
			m_headList[static_cast<int>(eSkulSpecies::eBasic)] = iter;
			break;
		}
	}
	if (m_headList[static_cast<int>(eSkulSpecies::eBasic)] == nullptr)
	{
		m_headList[static_cast<int>(eSkulSpecies::eBasic)] = new LittleBorn;
		GAMEMANAGER->m_headList.push_back(m_headList[(int)eSkulSpecies::eBasic]);
	}

	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->SetObject(m_obj);
	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->Init();
	m_headList[static_cast<int>(eSkulSpecies::eGambler)] = nullptr;
	for (auto iter : GAMEMANAGER->m_headList)
	{
		if (typeid(*iter) == typeid(Gambler))
		{
			m_headList[static_cast<int>(eSkulSpecies::eGambler)] = iter;
			break;
		}
	}
	if (m_headList[static_cast<int>(eSkulSpecies::eGambler)] == nullptr)
	{
		m_headList[static_cast<int>(eSkulSpecies::eGambler)] = new Gambler;
		GAMEMANAGER->m_headList.push_back(m_headList[(int)eSkulSpecies::eGambler]);
	}
	m_headList[static_cast<int>(eSkulSpecies::eGambler)]->SetObject(m_obj);
	m_headList[static_cast<int>(eSkulSpecies::eGambler)]->Init();
	m_headList[static_cast<int>(eSkulSpecies::eGambler)]->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);

	if (GAMEMANAGER->tag == -1)
		m_headSlot = eSkulSpecies::eGambler;
	else
	{
		m_headSlot = (eSkulSpecies)GAMEMANAGER->tag;
	}
	if (GAMEMANAGER->m_nowHead == nullptr)
	{
		m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eBasic)];
	}
	else
	{
		m_nowHead = GAMEMANAGER->m_nowHead;
	}
	m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashCool, &m_dashMax, &m_dashing, &m_jumpSpeed, &m_jumpMax, &m_jumpping);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_playerHitBox = m_obj->AddComponent<CollisionComponent>();
	m_playerHitBox->Setting(25, m_obj->x + 14, m_obj->y - 15, "PlayerHitRange");
	m_obj->AddCollisionComponent(m_playerHitBox);
	m_obj->AddComponent<RigidBodyComponent>();
	lastCheck = GAMEMANAGER->isHeadCheck;

	m_collAutoAttack = m_obj->AddComponent<CollisionComponent>();
	m_collSkillA = m_obj->AddComponent<CollisionComponent>();
	m_collSkillS = m_obj->AddComponent<CollisionComponent>();
	m_collSkillTag = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_collAutoAttack);
	m_obj->AddCollisionComponent(m_collSkillA);
	m_obj->AddCollisionComponent(m_collSkillS);
	m_obj->AddCollisionComponent(m_collSkillTag);
	m_nowHead->CollisionResetting(m_obj, m_collAutoAttack, m_collSkillA, m_collSkillS, m_collSkillTag);
	m_artifactCoolD = 0;
	m_haveArtifact = false;
	m_supperArmarTime = 0.5f;
	m_knockBackY = 0;
	m_knockBack = false;
	OBJECTMANAGER->m_player = this;
	m_supperArmarNowTime = 0;
}

void Player::Update()
{

	Vector2 v;
	m_nowHead->SetImageChange(false);
	if (lastCheck != isHeadCheck)
	{
		lastCheck = isHeadCheck;
		ChangeHead();
	}
	if (m_isDead == false)
	{
		if (!m_nowHead->GetNonActionCansle())
		{
			Move();
			if (isHeadCheck == true)
			{
				if (KEYMANAGER->GetOnceKeyDown(VK_SPACE))
				{
					if (m_headTagCool == 0)
						ChangeHead();
				}
			}
		}
		InputArtifactKey();

		m_playerHitBox->Setting(m_obj->x + 14, m_obj->y - 15);
		if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
		{
			m_obj->y += 1;
		}

		CoolDown();
		m_nowHead->Update();
	}
}

void Player::Release()
{
	GAMEMANAGER->playerHp = m_Hp;
	GAMEMANAGER->goldValue = goldValue;
	GAMEMANAGER->isHeadCheck = isHeadCheck;
	GAMEMANAGER->m_nowHead = m_nowHead;
	GAMEMANAGER->tag = (int)m_headSlot;
	if (m_Hp <= 0)
		m_Hp = 0;
}

void Player::Render()
{
	m_nowHead->Render();
}

void Player::UIRender()
{
	IMAGEMANAGER->UIRender(m_UIImage[ePlayerStatus], 0, 430, 2, 2, 0);
	IMAGEMANAGER->UIRender(hpBar, 89, 518, 231.f / m_HpMax * m_Hp, 2, 0, 1);

	IMAGEMANAGER->UIRender(IMAGEMANAGER->FindImage("goldUI"), 0, 0, 1, 1);
	IMAGEMANAGER->UIRender(IMAGEMANAGER->FindImage("enemyUI"), 0, 0, 1, 1);

	IMAGEMANAGER->D2dTextOut(to_wstring(goldValue), 970, 515, { 255,255,255,1 }, 0.8f);
	IMAGEMANAGER->D2dTextOut(to_wstring(GAMEMANAGER->enemyCount), 970, 481, { 255,255,255,1 }, 0.8f);

	if (m_Hp <= 0)
	{
		IMAGEMANAGER->UIRender(IMAGEMANAGER->FindImage("deathUI"), 0, 0, 1, 1);
		if (KEYMANAGER->GetStayKeyDown('X'))
		{
			FILEMANAGER->SetNowStageFile("map_5");
			SCENEMANAGER->ChangeScene("Stage");
		}
	}

}

void Player::InputArtifactKey()
{
	if (KEYMANAGER->GetOnceKeyDown('D'))
	{

	}
}

void Player::CoolDown()
{
	float deltaT = DELTA_TIME;
	if (m_dashNowTime > 0)
	{
		m_dashNowSpeed -= deltaT * m_dashSpeed;

		m_dashNowTime -= deltaT;
		if (m_dashNowTime < 0)
		{
			m_dashNowTime = 0;
			m_dashCount = 0;
			m_dashing = false;
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			m_playerHitBox->SetIsActive(true);
			m_dashNowCool = m_dashCool;
		}
	}
	if (m_dashNowCool > 0)
	{
		m_dashNowCool -= deltaT;
		if (m_dashNowCool < 0)
		{
			m_dashNowCool = 0;
		}
	}
	if (m_supperArmarNowTime > 0)
	{
		m_supperArmarNowTime -= deltaT;
		if (m_supperArmarNowTime <= 0)
		{
			m_supperArmarNowTime = 0;
			m_playerHitBox->SetIsActive(true);
		}
	}
	if (m_headTagCool > 0)
	{
		m_headTagCool -= deltaT;
		if (m_headTagCool <= 0)
		{
			m_headTagCool = 0;
		}
	}
}

void Player::ChangeHead()
{
	if (m_headSlot != eSkulSpecies::Empty)
	{
		eSkulSpecies tmp = m_nowHead->GetSpecies();
		m_headTagCool = m_nowHead->GetTagCoolTime();
		m_nowHead->ResetAll();
		switch (m_headSlot)
		{
		case eSkulSpecies::eBasic:
			SOUNDMANAGER->FindSound("SkulSwitch")->Play(false);
			m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eBasic)];
			m_nowHead->CollisionResetting(m_obj, m_collAutoAttack, m_collSkillA, m_collSkillS, m_collSkillTag);
			m_nowHead->TagAction();

			cout << "스컬 변경 : 리틀본" << endl;
			break;
		case eSkulSpecies::eGambler:
			SOUNDMANAGER->FindSound("Switch")->Play(false);
			m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eGambler)];
			m_nowHead->CollisionResetting(m_obj, m_collAutoAttack, m_collSkillA, m_collSkillS, m_collSkillTag);
			m_nowHead->TagAction();
			cout << "스컬 변경 : 갬블러" << endl;
			break;
		default:	//##스컬종류 추가후 변경 필요 필수필수필수
			m_nowHead = new LittleBorn;
			cout << "스컬 슬롯에 잘못된게 들어갔다." << endl;
			break;
		}
		m_headSlot = tmp;
		m_nowHead->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
		m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashCool, &m_dashMax, &m_dashing, &m_jumpSpeed, &m_jumpMax, &m_jumpping);
	}
}

void Player::OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)
{
	if (coll1->GetName() == m_collAutoAttack->GetName())
	{
		if (coll2->GetName() == "hitBox")
			if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
		{
			cout << "적에게공격 - Auto" << endl;

			m_nowHead->OnCollisionAutoAttack(other->GetComponent<Component>(), other, 10, 0.01);
		}
	}//end collision Name BasicAttack
	else if (coll1->GetName() == m_collSkillTag->GetName())
	{
		if(coll2->GetName() == "hitBox")
		if (other->GetName() == "Enemy" || other->GetName() == "EnemyBoss")
		{
			cout << "적에게공격 - Tag" << endl;
			m_nowHead->OnCollisionTagAttack(other->GetComponent<Component>(), other, 10, 0.01);
		}
	}//end collision Name TagAttack
}

void Player::HitPlayerPhysicAttack(float dmg)
{
	m_supperArmarNowTime = m_supperArmarTime;
	m_playerHitBox->SetIsActive(false);
	m_Hp -= dmg;
	if (m_Hp <= 0) m_isDead = true;
	cout << "데미지 : " << dmg << ", 플레이어 HP : " << m_Hp << endl;
}
void Player::HitPlayerMagicAttack(float dmg)
{
	m_supperArmarNowTime = m_supperArmarTime;
	m_playerHitBox->SetIsActive(false);
	m_Hp -= dmg;
	if (m_Hp <= 0) m_isDead = true;
	cout << "데미지 : " << dmg << ", 플레이어 HP : " << m_Hp << endl;
}
void Player::HitPlayerKnockBack(float moveX, float moveY)
{
	//##위로밀림시 점프하강모션뜨는거 idle로 바꾸기
	if (moveY > 0)
		m_knockBack = true;
	if (m_knockBackY < 0)
		m_knockBackY = 0;
	m_obj->x += moveX;
	m_obj->y += moveY;
	m_knockBackY = m_obj->y;
}
void Player::HitPlayerEffect()
{
	EFFECTMANAGER->AddEffect<PlayerHit>((m_obj->GetComponent<CollisionComponent>()->GetCollisionPosX())
		, m_obj->GetComponent<CollisionComponent>()->GetCollisionPosY(), m_isLeft);
}
void Player::CritialHitPlayerEffect()
{

}