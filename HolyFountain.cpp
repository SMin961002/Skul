#include "stdafx.h"
#include "HolyFountain.h"
#include "PixelCollisionComponent.h"
#include "RigidBodyComponent.h"
#include "Player.h"
#include "BossObject.h"

void HolyFountainLeft::Init()
{
	_imgLeftFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgLeftFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgLeftFountainActivate->Setting(0.1, true);

	_isLeftPlayOn = false;

	_collisionLeft = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collisionLeft);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);

}

void HolyFountainLeft::Update()
{

	if (OBJECTMANAGER->m_boss->getIdleOn() == true)
	{
		_isLeftPlayOn = true;
	}

	m_obj->GetComponent<RigidBodyComponent>()->SetIsActive(true);
	m_obj->GetComponent<PixelCollisionComponent>()->SetIsActive(true);
	_collisionLeft->Setting(50, m_obj->x+30, m_obj->y+50, "Attack");

}

void HolyFountainLeft::Render()
{
	if (_isLeftPlayOn == false)
	{
		IMAGEMANAGER->CenterRender(_imgLeftFountainDeActivate, m_obj->x, m_obj->y, 2, 2, 0, false);
	}
	if (_isLeftPlayOn == true)
	{
		_imgLeftFountainActivate->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, false);
	}
}

void HolyFountainLeft::Release()
{

}


void HolyFountainRight::Init()
{
	_imgRightFountainDeActivate = IMAGEMANAGER->FindImage("Fountain_Deactivate");

	_imgRightFountainActivate = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Activate");
	_imgRightFountainActivate->Setting(0.1, true);

	_collisionRight = m_obj->AddComponent<CollisionComponent>();
	m_obj->AddCollisionComponent(_collisionRight);

	m_obj->AddComponent<PixelCollisionComponent>()->setting(SCENEMANAGER->m_tiles, &m_obj->x, &m_obj->y);
	m_obj->AddComponent<RigidBodyComponent>()->SetGravityOnOff(false);

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
}

void HolyFountainRight::Render()
{
	if (_isRightPlayOn == false)
	{
		IMAGEMANAGER->CenterRender(_imgRightFountainDeActivate, m_obj->x, m_obj->y, 2, 2, 0, false);
	}
	if (_isRightPlayOn == true)
	{
		_imgRightFountainActivate->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, false);
	}
}

void HolyFountainRight::Release()
{
}

void HolyOrbLeft::Init()
{
	_imgLeftOrbStart = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Start_Left");
	_imgLeftOrbStart->Setting(0.05, false);

	_imgLeftOrbActing = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_Orb");
	_imgLeftOrbActing->Setting(0.1, true);

	_imgLeftOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End");
	_imgLeftOrbEnd->Setting(0.1, false);

	_isLeftOrbActing = false;
}

void HolyOrbLeft::Update()
{
	if (OBJECTMANAGER->m_boss->getIdleOn() == true)
	{
		_isLeftPlayOn = true;
	}
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
		_imgLeftOrbActing->CenterRender(m_obj->x-1, m_obj->y+2, 2, 2, 0, false);

		_isLeftOrbActing = true;
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

	_imgRightOrbEnd = IMAGEMANAGER->FindImageVector("Boss_HolyFountain_End");
	_imgRightOrbEnd->Setting(0.05, false);

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
		_imgRightOrbActing->CenterRender(m_obj->x-1, m_obj->y+2, 2, 2, 0, false);

		_isRightOrbActing = true;
	}
}

void HolyOrbRight::Release()
{
}
