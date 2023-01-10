#include "stdafx.h"
#include "HolyFountain.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "BossObject.h"

void HolyFountainLeft::Init()
{
	left = OBJECTMANAGER->AddObject("OrbLeft", 100, 450, 0)->AddComponent<HolyOrbLeft>();

	_imgLeftFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgLeftFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgLeftFountainActivate->Setting(0.1, true);

	_isLeftPlayOn = false;

	_collisionLeft = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collisionLeft);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);

	m_MaxHP = 300;
	m_CurrentHP = 300;
	m_HPBarTimer = 0;
	m_HPBar = 0;
	m_DieTimer = 0;

	m_Hit = false;
}

void HolyFountainLeft::Update()
{

	if (OBJECTMANAGER->m_boss->getIdleOn() == true)
	{
		_isLeftPlayOn = true;
	}

	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);
	_collisionLeft->Setting(50, m_obj->x + 30, m_obj->y + 50, "Attack");

	left->isLeftDes = m_CurrentHP <= 0;
	
	if (KEYMANAGER->GetOnceKeyDown('O'))
	{
		m_CurrentHP = -10;
	}
}

void HolyFountainLeft::Render()
{
	if (_isLeftPlayOn == false)
	{
		IMAGEMANAGER->CenterRender(_imgLeftFountainDeActivate, m_obj->x, m_obj->y, 2, 2, 0, false);
	}
	if (_isLeftPlayOn == true)
	{
		if (m_CurrentHP >= 0) _imgLeftFountainActivate->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, false);
	}
}

void HolyFountainLeft::Release()
{

}

void HolyFountainLeft::HitEnemy(float dmg, float time)
{
	if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 0, 1.5);
	}
	else
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 1, 1.5);
	}
	//m_hit = true;
	//m_hiteffecttimer = 0;
	//m_currenthp -= dmg;
}


void HolyFountainRight::Init()
{
	right = OBJECTMANAGER->AddObject("OrbRight", 1500, 450, 0)->AddComponent<HolyOrbRight>();

	_imgRightFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgRightFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgRightFountainActivate->Setting(0.1, true);

	_collisionRight = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collisionRight);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);
	
	m_MaxHP = 300;
	m_CurrentHP = 300;
	m_HPBarTimer = 0;
	m_HPBar = 0;
	m_DieTimer = 0;

	_isRightPlayOn = false;
}

void HolyFountainRight::Update()
{
	if (OBJECTMANAGER->m_boss->getIdleOn() == true)
	{
		_isRightPlayOn = true;
	}

	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);
	_collisionRight->Setting(50, m_obj->x + 30, m_obj->y + 50, "Attack");

	right->isRightDes = m_CurrentHP <= 0;

	if (KEYMANAGER->GetOnceKeyDown('P'))
	{
		m_CurrentHP = -10;
	}
}

void HolyFountainRight::Render()
{
	if (_isRightPlayOn == false)
	{
		IMAGEMANAGER->CenterRender(_imgRightFountainDeActivate, m_obj->x, m_obj->y, 2, 2, 0, false);
	}
	if (_isRightPlayOn == true)
	{
		if(m_CurrentHP >= 0) _imgRightFountainActivate->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, false);
	}
}

void HolyFountainRight::Release()
{
}

void HolyFountainRight::HitEnemy(float dmg, float time)
{
	if (OBJECTMANAGER->m_player->GetplayerX() <= m_obj->x)
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 0, 1.5);
	}
	else
	{
		EFFECTMANAGER->AddEffect<SkulAttack>(m_obj->x - 5, m_obj->y - 10, 1, 1.5);
	}
	//m_hit = true;
	//m_hiteffecttimer = 0;
	//m_currenthp -= dmg;
}

void HolyOrbLeft::Init()
{
	_imgLeftOrbStart = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Start_Left");
	_imgLeftOrbStart->Setting(0.05, false);

	_imgLeftOrbActing = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Orb");
	_imgLeftOrbActing->Setting(0.1, true);

	_imgLeftOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End_Left");
	_imgLeftOrbEnd->Setting(0.1, false);

	isLeftDes = false;
	_isLeftOrbActing = false;
}

void HolyOrbLeft::Update()
{
	if (OBJECTMANAGER->m_boss->getIdleOn() == true)
	{
		_isLeftPlayOn = true;
	}

	//if ()
	//{
	//	m_obj->ObjectDestroyed();
	//}
}

void HolyOrbLeft::Render()
{
	if (_isLeftPlayOn == true)
	{
		if (_isLeftOrbActing == false)
		{
			_imgLeftOrbStart->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, false);
		}
	}
	if (_imgLeftOrbStart->GetIsImageEnded() == true)
	{
		if (isLeftDes == false)
		{
			_imgLeftOrbActing->CenterRender(m_obj->x - 1, m_obj->y + 2, 2, 2, 0, false);
		}

		_isLeftOrbActing = true;
	}
	if (isLeftDes == true)
	{
		_imgLeftOrbEnd->CenterRender(m_obj->x - 1, m_obj->y + 2, 2, 2, 0, false);
	}
}

void HolyOrbLeft::Release()
{
}

void HolyOrbRight::Init()
{
	_imgRightOrbStart = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Start_Right");
	_imgRightOrbStart->Setting(0.05, false);

	_imgRightOrbActing = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Orb");
	_imgRightOrbActing->Setting(0.1, true);

	_imgRightOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End_Right");
	_imgRightOrbEnd->Setting(0.05, false);

	isRightDes = false;
	_isRightPlayOn = false;
	_isRightOrbActing = false;
}

void HolyOrbRight::Update()
{
	if (OBJECTMANAGER->m_boss->getIdleOn() == true)
	{
		_isRightPlayOn = true;
	}
}

void HolyOrbRight::Render()
{
	if (_isRightPlayOn == true)
	{
		if (_isRightOrbActing == false)
		{
			_imgRightOrbStart->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, false);
		}
	}
	if (_imgRightOrbStart->GetIsImageEnded() == true)
	{
		if (isRightDes == false)
		{
			_imgRightOrbActing->CenterRender(m_obj->x - 1, m_obj->y + 2, 2, 2, 0, false);
		}
		_isRightOrbActing = true;
	}
	if (isRightDes == true)
	{
		_imgRightOrbEnd->CenterRender(m_obj->x - 1, m_obj->y + 2, 2, 2, 0, false);
	}
}

void HolyOrbRight::Release()
{
}
