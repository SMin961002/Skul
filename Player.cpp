#include "stdafx.h"
#include "Player.h"
#include "RigidBodyComponent.h"

void Player::Init()
{
	//이미지 삽입

	OBJECTMANAGER->m_player = this;

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
	img[eJumpAttack] = IMAGEMANAGER->FindImageVector("Basic_JumpAttack");
	img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");	//JumpFall 이미지는 착지순간만 재생, img변수 따로 두었음
	img[eJumpLand] = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
	img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
	img[eSkill_2] = IMAGEMANAGER->FindImageVector("Basic_Idle");	//머리가본체는 별도의 이미지가 없음(서있는상태로 뿅 이펙트만 존재)
	//↑↑setting 필요↑↑
	//↑↑setting 필요↑↑
	//↑↑setting 필요↑↑
	img_reborn = IMAGEMANAGER->FindImageVector("Basic_Reborn");
	img_reborn->Setting(0.1f, true);

	nowImg = img[eIdle];

	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
	m_action = eIdle;

	m_moveSpeed = 3;
	m_isLeft = false;
	m_down = false;

	m_dashSpeed = 3.5;	//##dash 이동식 수정 필요
	m_dashTime = 0.4f;
	m_dashNowTime = 0.0f;	//대시 누르면 0.4, update시 -
	m_dashCool = 1;
	m_dashNowCool = 0;
	m_dashCount = 0;
	m_dashMax = 2;
	m_dashing = false;

	m_jumpSpeed = 3;
	m_jumpNowSpeed = 0.2;
	m_jumpCount = 0;
	m_jumpMax = 2;
	m_jumpping = false;

	m_attackCount = 0;

	m_skillCoolA = 6;
	m_skillCoolS = 3;
	m_skillUsing = false;
	m_artifactCoolD = 0;
	m_haveArtifact = false;
	//m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());
	coll = m_obj->AddComponent<CollisionComponent>();
	m_obj->GetCollisionComponent().push_back(coll);

	m_obj->AddComponent<RigidBodyComponent>();
	//m_obj->GetComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles,&m_obj->x, &m_obj->y);
	m_commandInput = false;
}

void Player::Update()
{


	Vector2 v;
	MY_UTILITY::GetLerpVec2(&v, { m_obj->x - WINSIZE_X / 2,m_obj->y - 400 }, { IMAGEMANAGER->GetCameraPosition().x, IMAGEMANAGER->GetCameraPosition().y }, 0.5);
	IMAGEMANAGER->SetCameraPosition(v.x, v.y);
	Move();
	//Action();
	//m_obj->GetCollisionComponent()->Setting(20, m_obj->x, m_obj->y);

	if (false == m_obj->GetComponent<PixelCollisionComponent>()->GetIsCollision())
	{
		m_obj->y += 1;
	}

	if (!m_skillUsing)	//스킬 끝날 때까지 다른 동작이 들어가지 못하게 하기 위함
	{
		Move();
		Act();
	}
	InputArtifactKey();
	m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}

void Player::Render()
{
	DrawCharactor();
}

void Player::Release()
{
}

void Player::DrawCharactor()
{
	if (m_commandInput)
	{
		nowImg = img[m_action];
	}
	if (nowImg->IsImageEnded())
	{
		nowImg->Reset();
		if (m_skillUsing) m_skillUsing = false;
		if (m_attackCast) m_action = eAutoAttack_2;	//3타가 있으면 switch(m_attackCount)로 검사
		else m_action = eIdle;
		nowImg = img[m_action];
	}

	nowImg->CenterRender(m_obj->x, m_obj->y - 50, 2, 2, 0, m_isLeft);
}

void Player::DrawEffect()
{
}

void Player::Move()
{
	m_commandInput = false;
	if (m_action == this->eWalk)
	{
		m_action = this->eIdle;
	}
	InputJumpKey();
	if (!m_dashing)
	{
		InputArrowKey();

		if (m_dashNowCool != 0)
		{
			if (m_dashNowCool > 0)	m_dashNowCool -= DELTA_TIME;
			else
			{
				ResetDash();
			}
		}
	}
	else	//대시 발동중일때
	{		//##dash 이동식 수정 필요
		if (m_isLeft) { m_obj->x -= m_dashSpeed; }
		else { m_obj->x += m_dashSpeed; }

		if (nowImg != img[eDash])
		{
			m_dashing = false;
			m_dashNowCool = m_dashCool;
		}
	}
	InputDashKey();
	if (nowImg != img[m_action])
	{

	}
}

void Player::Act()
{
	InputAttackKey();
	InputSkillKey();
}

void Player::InputArrowKey()
{
	//방향키 왼쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
	{
		m_isLeft = true;
		m_obj->x -= m_moveSpeed;
		/*if (!m_jumpping)##*/m_action = eWalk;
		m_commandInput = true;
	}
	//방향키 오른쪽 입력시
	if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
	{
		m_isLeft = false;
		m_obj->x += m_moveSpeed;
		/*if (!m_jumpping)##*/m_action = eWalk;
		m_commandInput = true;
	}
}

void Player::InputDashKey()
{
	if (KEYMANAGER->GetOnceKeyDown('Z'))
	{
		if (m_dashCount < 2 && m_dashNowCool <= 0)
		{
			ResetJump();
			m_dashing = true;
			m_dashCount++;
			m_action = eDash;
			if (m_dashing) cout << "dash" << endl;
			m_commandInput = true;
			img[eDash]->Reset();
			nowImg = img[eDash];
		}
	}
}

void Player::InputAttackKey()
{
	if (KEYMANAGER->GetOnceKeyDown('X'))
	{
		if (m_jumpping)
		{
			m_action = eJumpAttack;
		}
		else //##
			m_commandInput = true;
	}
}

void Player::InputArtifactKey()
{

}

void Player::InputSkillKey()
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

void Player::InputJumpKey()
{
	m_commandInput = true;
}

void Player::OnCollision(string collisionName, Object* other)
{
	if (collisionName == "EnemyAttack")
	{
		if (other->GetName() == "Enemy")
		{
		}
	}
}
