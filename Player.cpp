#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"

void Player::Init()
{
	m_UIImage[ePlayerStatus] = IMAGEMANAGER->FindImage("PlayerStatusUI");
	OBJECTMANAGER->m_player = this;
	m_headList[static_cast<int>(eSkulSpecies::eBasic)] = new Head_Basic;
	m_headList[static_cast<int>(eSkulSpecies::eBasic)]->Init();
	m_headList[static_cast<int>(eSkulSpecies::eGambler)] = new Gambler;
	m_headList[static_cast<int>(eSkulSpecies::eGambler)]->Init();

	m_headSlot = eSkulSpecies::eGambler;
	m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eBasic)];
	m_nowHead->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
	m_nowHead->Init();
	m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashMax, &m_dashing, &m_jumpSpeed, &m_jumpMax, &m_jumpping);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_playerHitBox = m_obj->AddComponent<CollisionComponent>();
	m_playerHitBox->Setting(25, m_obj->x + 14, m_obj->y - 15, "PlayerHitRange");
	m_obj->AddCollisionComponent(m_playerHitBox);
	m_obj->AddComponent<RigidBodyComponent>();

	//m_collAutoAttack = m_nowHead->GetCollAutoAttack();
	//m_collSkill = m_nowHead->GetCollSkill();
	//m_obj->AddCollisionComponent(m_collAutoAttack);
	//m_obj->AddCollisionComponent(m_collSkill);
	//m_collAutoAttack->SetObject(m_obj);
	//m_collSkill->SetObject(m_obj);
	////cout << m_collAutoAttack << "플레이어 m_collAuto 주소" << endl;

	m_HpMax = 100;
	m_life = 100;
	m_artifactCoolD = 0;
	m_haveArtifact = false;
	m_supperArmarTime = 0.5f;

	//m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };

	OBJECTMANAGER->m_player = this;
	//m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	//coll = m_obj->AddComponent<CollisionComponent>();
	//coll->Setting(25, m_obj->x + 14, m_obj->y - 15, "PlayerHitRange");
	//m_obj->AddCollisionComponent(coll);
	//m_obj->AddComponent<RigidBodyComponent>();
	//m_obj->GetComponent<PixelCollisionComponent>()->BSettingRect({ -10 , -10, 10 , 0 });

	m_supperArmarNowTime = 0;
}

void Player::Update()
{
	Vector2 v;
	//m_obj->GetCollisionComponent()->Setting(20, m_obj->x, m_obj->y);

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
			m_dashNowCool = m_dashCool;
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			m_playerHitBox->SetIsActive(true);
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
			m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eBasic)];

			m_collAutoAttack = m_nowHead->GetCollAutoAttack();
			m_collSkill = m_nowHead->GetCollSkill();
			//m_obj->AddCollisionComponent(m_collAutoAttack);
			//m_obj->AddCollisionComponent(m_collSkill);
			//m_collAutoAttack->SetObject(m_obj);
			//m_collSkill->SetObject(m_obj);

			cout << "스컬 변경 : 리틀본" << endl;
			break;
		case eSkulSpecies::eGambler:
			m_nowHead = m_headList[static_cast<int>(eSkulSpecies::eGambler)];
			cout << "스컬 변경 : 갬블러" << endl;
			break;
		default:	//##스컬종류 추가후 변경 필요 필수필수필수
			m_nowHead = new Head_Basic;
			cout << "스컬 슬롯에 잘못된게 들어갔다." << endl;
			break;
		}
		m_headSlot = tmp;
		m_nowHead->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
		m_nowHead->Init();
		m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashMax, &m_dashing, &m_jumpSpeed, &m_jumpMax, &m_jumpping);

		//m_collAutoAttack = m_nowHead->GetCollAutoAttack();
		//m_collSkill = m_nowHead->GetCollSkill();
		//m_obj->AddCollisionComponent(m_collAutoAttack);
		//m_obj->AddCollisionComponent(m_collSkill);
		//m_collAutoAttack->SetObject(m_obj);
		//m_collSkill->SetObject(m_obj);
	}
}

void Player::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collAutoAttack->GetName())
	{
		if (other->GetName() == "Enemy")
		{
			cout << "적에게공격" << endl;

			//Enemy* a = dynamic_cast<Enemy*>(other);
			m_nowHead->OnCollisionAutoAttack(other->GetComponent<Enemy>(), 10);
			//EFFECTMANAGER->AddEffect<PlayerHit>(m_obj->x, m_obj->y, m_isLeft);
		}
	}//end collision Name BasicAttack
}