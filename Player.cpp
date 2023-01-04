#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"
#include "Enemy.h"
void Player::Init()
{
	m_UIImage[ePlayerStatus] = IMAGEMANAGER->FindImage("PlayerStatusUI");
	OBJECTMANAGER->m_player = this;

	m_headSlot = eSkulSpecies::Empty;
	m_nowHead = new Head_Basic;
	m_nowHead->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
	m_nowHead->Init();
	m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashMax, &m_dashing,&m_jumpSpeed, &m_jumpMax,&m_jumpping);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_playerHitBox = m_obj->AddComponent<CollisionComponent>();
	m_playerHitBox->Setting(25, m_obj->x + 14, m_obj->y - 15, "PlayerHitRange");
	m_obj->AddCollisionComponent(m_playerHitBox);
	m_obj->AddComponent<RigidBodyComponent>();

	m_collAutoAttack = m_nowHead->GetCollAutoAttack();
	m_collSkill = m_nowHead->GetCollSkill();
	m_obj->AddCollisionComponent(m_collAutoAttack);
	m_obj->AddCollisionComponent(m_collSkill);
	m_collAutoAttack->SetObject(m_obj);
	m_collSkill->SetObject(m_obj);
	cout << m_collAutoAttack << "플레이어 m_collAuto 주소" << endl;

	m_life = 100;
	m_artifactCoolD = 0;
	m_haveArtifact = false;
	m_supperArmarTime = 0.5f;


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

void Player::Move()
{
	if (m_nowHead->GetAction() == Head::eWalk)
	{
		m_nowHead->SetAction(Head::eIdle,true);
	}

	InputDashKey();

	//대시중일 때
	if (m_dashing)
	{		//##dash 이동식 수정 필요
		if (m_isLeft) { m_obj->x -= m_dashSpeed * DELTA_TIME; }
		else { m_obj->x += m_dashSpeed * DELTA_TIME; }
		m_obj->y -= 1;
	}
	else if (!m_nowHead->GetIsAttack())
	{
		InputArrowKey();	//대시, 공격중에 걷기 불가하므로
	}

	//바닥에서 발이 떠있을 때
	if (!m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
	{
		m_jumpping = true;	//점프중으로 인식하기
	}

	//점프중일 때
	if (m_jumpping)
	{
		if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsBottomCollision())
		{
			ResetJump();
			m_nowHead->SetImage(Head::eJumpLand, true);
		}
		else if (m_obj->GetComponent<PixelCollisionComponent>()->GetIsTopCollision())
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(0);
		if (m_obj->GetComponent<RigidBodyComponent>()->GetGravityPower() < 0)
			if (!m_dashing && m_nowHead->GetAction() != Head::eJumpAttack)
				m_nowHead->SetImage(Head::eJumpDown,true);
	}
	InputJumpKey();
}

void Player::InputJumpKey()
{
	if (KEYMANAGER->GetOnceKeyDown('C'))
	{
		if (m_jumpCount < m_jumpMax)
		{
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(true);
			if (m_isDown)	//아래점프
			{
				m_obj->y += 11;
			}
			else			//일반점프
			{
				m_obj->y -= 11;			//점프직후 바닥충돌판정걸려서 탐지봉 길이만큼 미리 띄워줌

				m_nowHead->ResetAttack();
				m_jumpping = true;
				m_nowHead->SetAction(Head::eJump);
				m_obj->GetComponent<RigidBodyComponent>()->SetGravityPower(m_jumpSpeed);
				if (++m_jumpCount >= 2)
				{
					EFFECTMANAGER->AddEffect<DoubleJumpSmoke>(m_obj->x, m_obj->y, m_isLeft);
				}
			}
		}
	}//end 'C'
}

void Player::InputDashKey()
{
	if (KEYMANAGER->GetOnceKeyDown('Z'))
	{
		if (m_dashCount < m_dashMax && m_dashNowCool <= 0)
		{
			m_jumpping = false;
			m_nowHead->ResetAttack();

			m_dashing = true;
			m_dashCount++;
			m_nowHead->SetImage(Head::eDash);
			EFFECTMANAGER->AddEffect<DashSmoke>(m_obj->x, m_obj->y, m_isLeft);
			m_obj->GetComponent<RigidBodyComponent>()->SetGravityOnOff(false);//##점프상승이 안들어가
			m_dashNowTime = m_dashTime;
			m_playerHitBox->SetIsActive(false);
		}
	}
}

void Player::InputArrowKey()
{
	m_isDown = false;
	//방향키 왼쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		if (!m_nowHead->GetIsAttack() || m_nowHead->GetAction() == Head::eJumpAttack)
			m_obj->x -= m_moveSpeed * DELTA_TIME;
		if (!m_jumpping) {
			m_nowHead->SetAction(Head::eWalk);
		}
	}
	//방향키 오른쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		if (!m_nowHead->GetIsAttack() || m_nowHead->GetAction() == Head::eJumpAttack)
			m_obj->x += m_moveSpeed * DELTA_TIME;
		if (!m_jumpping) {
			m_nowHead->SetAction(Head::eWalk);
		}
	}
	//아래 방향키 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
	{
		m_isDown = true;
	}
}

void Player::CoolDown()
{
	if (m_dashNowTime > 0)
	{
		m_dashNowTime -= DELTA_TIME;
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
		m_supperArmarNowTime -= DELTA_TIME;
		if (m_supperArmarNowTime <= 0)
		{
			m_supperArmarNowTime = 0;
			m_playerHitBox->SetIsActive(true);
		}
	}
}

void Player::ChangeHead()
{
	if (m_headSlot != eSkulSpecies::Empty)
	{
		switch (m_headSlot)
		{
		case eSkulSpecies::eBasic:
		default:	//##스컬종류 추가후 변경 필요 필수필수필수
			m_headSlot = m_nowHead->GetSpecies();
			
			m_nowHead->Release();
			SAFE_DELETE(m_nowHead);

			m_nowHead = new Head_Basic;
			m_nowHead->SetPlayerXY(&m_obj->x, &m_obj->y, &m_isLeft, &m_isDown);
			m_nowHead->Init();
			m_nowHead->SetPlayerMoveParameter(&m_moveSpeed, &m_dashSpeed, &m_dashTime, &m_dashMax, &m_dashing,&m_jumpSpeed, &m_jumpMax,&m_jumpping);
			break;
		}
	}
}

void Player::OnCollision(string collisionName, Object* other)
{
	if (collisionName == m_collAutoAttack->GetName())
	{
		if (other->GetName() == "Enemy")
		{
			cout << "적에게공격" << endl;
			other->GetComponent<Enemy>()->HitEnemy(10);
			//EFFECTMANAGER->AddEffect<PlayerHit>(m_obj->x, m_obj->y, m_isLeft);
		}
	}//end collision Name BasicAttack
}