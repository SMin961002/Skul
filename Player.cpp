#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
    OBJECTMANAGER->m_player = this;
    //이미지 삽입
    img[eIdle] = IMAGEMANAGER->FindImageVector("Basic_Idle");
    img[eIdle]->Setting(0.15f, true);
    img[eWalk] = IMAGEMANAGER->FindImageVector("Basic_Walk");
    img[eWalk]->Setting(0.1f, true);
    img[eDash] = IMAGEMANAGER->FindImageVector("Basic_Dash");
    img[eAutoAttack_1] = IMAGEMANAGER->FindImageVector("Basic_Attack1");
    img[eAutoAttack_1]->Setting(0.15f, false);
    img[eAutoAttack_2] = IMAGEMANAGER->FindImageVector("Basic_Attack2");
    img[eAutoAttack_2]->Setting(0.15f, false);
    img[eJump] = IMAGEMANAGER->FindImageVector("Basic_JumpStart");
    img[eJumpDown] = IMAGEMANAGER->FindImageVector("Basic_JumpRepeat");   //JumpFall 이미지는 착지순간만 재생, img변수 따로 두었음
    img_jumpFall = IMAGEMANAGER->FindImageVector("Basic_JumpFall");
    img[eSkill_1] = IMAGEMANAGER->FindImageVector("Basic_Skill");
    img[eSkill_2] = IMAGEMANAGER->FindImageVector("Basic_Idle");   //머리가본체는 별도의 이미지가 없음(서있는상태로 뿅 이펙트만 존재)
    img_reborn = IMAGEMANAGER->FindImageVector("Basic_Reborn");
    img_jumpFall->Setting(0.1f, true);
    img_reborn->Setting(0.1f, true);

    nowImg = img[eIdle];

    m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
    m_action = eIdle;
    m_action_prev = eIdle;
    m_actionTick = 0;

    m_moveSpeed = 3;
    m_isLeft = false;
    m_down = false;
    m_commandInput = false;

    m_dashSpeed = 3.5;
    m_dashDelay = 2000;
    m_dashTime = 400;
    m_dashCount = 0;
    m_dashMax = 2;

    m_jumpSpeed = 3;
    m_jumpGravity = 0.2;
    m_jumpCount = 0;
    m_jumpMax = 2;


    m_attackWaitingTime = 1000;
    m_attackCount = 0;

    m_skillCoolA = 6000;
    m_skillCoolS = 3000;
    m_skillCoolD = 0;

    m_obj->SetCollisionComponent(m_obj->AddComponent<CollisionComponent>());
    m_obj->GetCollisionComponent()->Setting(100, m_obj->x, m_obj->y);
}

void Player::Update()
{
    Move();
    //Action();
    IMAGEMANAGER->SetCameraPosition(m_obj->x - WINSIZE_X / 2, m_obj->y - 150);
    m_obj->GetCollisionComponent()->Setting(20, m_obj->x, m_obj->y);
}

void Player::Render()
{
    Draw();
}

void Player::Release()
{
}

void Player::Draw()
{
    img[m_action]->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isLeft);
}

void Player::Move()
{
    switch (m_action)
    {
    case eDash:
    {
        if (m_isLeft)
        {
            m_obj->x -= m_dashSpeed;
        }
        else m_obj->x += m_dashSpeed;
        if (KEYMANAGER->GetOnceKeyDown('Z') && m_dashCount < 2)
        {
            m_action = eDash;
            m_actionTick = 0.4 + TIMERMANAGER->GetWorldTime();
            m_dashCount++;
        }
    }//end case dash
    break;

    case eAutoAttack_1:
        if (TIMERMANAGER->GetWorldTime() > m_actionTick - 0.3)
            if (KEYMANAGER->GetOnceKeyDown('X'))
            {
                m_action = eAutoAttack_2;
                m_actionTick = 0.15 * (img[eAutoAttack_2]->GetImageSize()) + TIMERMANAGER->GetWorldTime();
                img[eAutoAttack_2]->Reset();
                nowImg = img[eAutoAttack_2];
            }
        break;
    case eAutoAttack_2:
        break;
    case eJump:
        break;
    case eJumpDown:
        break;

    case eWalk:
        if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
        {
            m_isLeft = true;
            if (m_action == eIdle) {
                m_actionTick += 0.3;
            }
            m_obj->x -= m_moveSpeed;
        }
        if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
        {
            m_isLeft = false;
            if (m_action == eIdle) {
                m_actionTick += 0.3;
                //m_actionTick = 0.3 + TIMERMANAGER->GetWorldTime();
            }
            m_obj->x += m_moveSpeed;
        }

        break;
    case eIdle:
    default:
    {
        m_down = false;
        if (KEYMANAGER->GetStayKeyDown(VK_LEFT))
        {
            m_isLeft = true;
            if (m_action == eIdle) {
                m_action = eWalk;
                m_actionTick = 0.3 + TIMERMANAGER->GetWorldTime();
                nowImg = img[eWalk];
            }
            m_obj->x -= m_moveSpeed;
        }
        if (KEYMANAGER->GetStayKeyDown(VK_RIGHT))
        {
            m_isLeft = false;
            if (m_action == eIdle) {
                m_action = eWalk;
                m_actionTick = 0.3 + TIMERMANAGER->GetWorldTime();
                nowImg = img[eWalk];
            }
            m_obj->x += m_moveSpeed;
        }
        if (KEYMANAGER->GetStayKeyDown(VK_DOWN))
        {
            m_down = true;
        }
        if (KEYMANAGER->GetOnceKeyDown('C'))
        {
            m_action = m_down ? eJumpDown : eJump;
            m_commandInput = true;

        }
        if (KEYMANAGER->GetOnceKeyDown('Z'))
        {
            m_action = eDash;
            m_actionTick = 0.4 + TIMERMANAGER->GetWorldTime();
            nowImg = img[eDash];
            m_dashCount++;
        }
        if (KEYMANAGER->GetOnceKeyDown('X'))
        {
            if (TIMERMANAGER->GetWorldTime() > m_actionTick - 0.3)
                m_action = eAutoAttack_1;
            m_actionTick = 0.15 * (img[eAutoAttack_1]->GetImageSize()) + TIMERMANAGER->GetWorldTime();
            img[eAutoAttack_1]->Reset();
            nowImg = img[eAutoAttack_1];
        }
    }//end case idle&walk&default
    }//end switch
    if (m_actionTick < TIMERMANAGER->GetWorldTime())
    {
        m_action = eIdle;
        nowImg = img[eIdle];
        m_dashCount = 0;
        m_jumpCount = 0;
    }

    m_hitBox = { (int)(m_obj->x) - 7, (int)(m_obj->y) - 15, (int)(m_obj->x) + 7, (int)(m_obj->y) + 15 };
}
void Player::OnCollision(Object* other)
{
	if (other->GetName() == "Enemy")
	{
	}
}
