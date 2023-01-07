#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"
/*
플레이어가 가진
collision컴포넌트를
head에 전달해서 가공하기
*/
void Player::Init()
{
	m_UIImage[ePlayerStatus] = IMAGEMANAGER->FindImage("PlayerStatusUI");
	OBJECTMANAGER->m_player = this;
	m_headList[static_cast<int>(eSkulSpecies::eBasic)] = new Head_Basic;
	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->SetObject(m_obj);
	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->Init();
	m_headList[static_cast<int>(eSkulSpecies::eGambler)] = new Gambler;
	m_headList[static_cast<int>(eSkulSpecies::eGambler)]->SetObject(m_obj);
	m_headList[static_cast<int>(eSkulSpecies::eGambler)]->Init();
	m_headSlot = eSkulSpecies::eGambler;
	m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eBasic)];
	m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashMax, &m_dashing, &m_jumpSpeed, &m_jumpMax, &m_jumpping);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_playerHitBox = m_obj->AddComponent<CollisionComponent>();
	m_playerHitBox->Setting(25, m_obj->x + 14, m_obj->y - 15, "PlayerHitRange");
	m_obj->AddCollisionComponent(m_playerHitBox);
	m_obj->AddComponent<RigidBodyComponent>();

	m_collAutoAttack = m_obj->AddComponent<CollisionComponent>();
	m_collSkillA = m_obj->AddComponent<CollisionComponent>();
	m_collSkillS = m_obj->AddComponent<CollisionComponent>();
	m_collSkillTag = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(m_collAutoAttack);
	m_obj->AddCollisionComponent(m_collSkillA);
	m_obj->AddCollisionComponent(m_collSkillS);
	m_obj->AddCollisionComponent(m_collSkillTag);
	m_nowHead->CollisionResetting(m_obj, m_collAutoAttack, m_collSkillA, m_collSkillS, m_collSkillTag);

	m_HpMax = 100;
	m_life = 100;
	m_artifactCoolD = 0;
	m_haveArtifact = false;
	m_supperArmarTime = 0.5f;

	OBJECTMANAGER->m_player = this;
	m_supperArmarNowTime = 0;
}

void Player::Update()
{
	Vector2 v;

	m_nowHead->SetImageChange(false);

	Move();
	InputArtifactKey();

	if (KEYMANAGER->GetOnceKeyDown(VK_SPACE))
	{
		ChangeHead();
	}

	m_playerHitBox->Setting(m_obj->x + 14, m_obj->y - 15);
	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
	}

	CoolDown();
	m_nowHead->Update();
}

void Player::Release()
{
	m_nowHead->Release();
	SAFE_DELETE(m_nowHead);
}

void Player::Render()
{
	m_nowHead->Render();
}

void Player::UIRender()
{
	IMAGEMANAGER->UIRender(m_UIImage[ePlayerStatus], 0, 430, 2, 2, 0);
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

		//coll tag에 문제있어
		switch (m_headSlot)
		{
		case eSkulSpecies::eBasic:
			m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eBasic)];
			m_nowHead->CollisionResetting(m_obj, m_collAutoAttack, m_collSkillA, m_collSkillS, m_collSkillTag);
			cout << "스컬 변경 : 리틀본" << endl;
			break;
		case eSkulSpecies::eGambler:
			m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eGambler)];
			m_nowHead->CollisionResetting(m_obj, m_collAutoAttack, m_collSkillA, m_collSkillS, m_collSkillTag);
			cout << "스컬 변경 : 갬블러" << endl;
			break;
		default:	//##스컬종류 추가후 변경 필요 필수필수필수
			m_nowHead = new Head_Basic;
			cout << "스컬 슬롯에 잘못된게 들어갔다." << endl;
			break;
		}
		m_headSlot = tmp;
		m_nowHead->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
		m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashMax, &m_dashing, &m_jumpSpeed, &m_jumpMax, &m_jumpping);
	}
}

void Player::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collAutoAttack->GetName())
	{
		if (other->GetName() == "Enemy")
		{
			cout << "적에게공격" << endl;

			m_nowHead->OnCollisionAutoAttack(other->GetComponent<Enemy>(), 10);
			//m_nowHead->OnCollisionAutoAttack(other->GetComponent<Enemy>(), 10, m_nowHead->GetNowActionTime());
		}
	}//end collision Name BasicAttack
}