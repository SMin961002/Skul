#include "stdafx.h"
#include"LobbyObject.h"


void Spider::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("Spider");
	_img->Setting(0.1f, true);
	GAMEMANAGER->enemyCount++;

}

void Spider::Update()
{
}

void Spider::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void Spider::Release()
{
	GAMEMANAGER->enemyCount--;

}

void LobbyNpc1::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("LobbyNpc");
	_img->Setting(0.1f, true);
}

void LobbyNpc1::Update()
{
}

void LobbyNpc1::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void LobbyNpc1::Release()
{
}

void LobbyNpc2::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("LobbyNpc2");
	_img->Setting(0.1f, true);
}

void LobbyNpc2::Update()
{
}

void LobbyNpc2::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void LobbyNpc2::Release()
{
}

void LobbyNpc3::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("LobbyNpc3");
	_img->Setting(0.1f, true);
}

void LobbyNpc3::Update()
{
}

void LobbyNpc3::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void LobbyNpc3::Release()
{
}

void LobbyNpc4::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("LobbyNpc4");
	_img->Setting(0.1f, true);
}

void LobbyNpc4::Update()
{
}

void LobbyNpc4::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void LobbyNpc4::Release()
{
}

void LobbyNpc5::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("LobbyNpc5");
	_img->Setting(0.1f, true);
}

void LobbyNpc5::Update()
{
}

void LobbyNpc5::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void LobbyNpc5::Release()
{
}

void Cat::Init()
{
	m_movetimer = 0;
	m_move = false;
	m_isleft = false;
	m_isleftcount = 0;
	_img = IMAGEMANAGER->AddImageVectorCopy("CatIdle");
	_img->Setting(0.1f, true);
	_img2 = IMAGEMANAGER->AddImageVectorCopy("CatWalk");
	_img2->Setting(0.1f, true);
}

void Cat::Update()
{
	m_movetimer += DELTA_TIME;
	if (m_movetimer >= MY_UTILITY::getFromFloatTo(6,13))
	{
		m_move = true;
	}
	if (m_movetimer <= 1.0f)
	{
		m_move = false;
	}
	if (m_movetimer >= MY_UTILITY::getFromFloatTo(13, 18))
	{
		m_move = false;
		m_isleftcount++;
		m_movetimer = 0;
	}
	if (m_isleftcount >= MY_UTILITY::getFromFloatTo(0, 4) && m_isleft == false)
	{
		m_isleft = true; 
		m_isleftcount = 0;
	}
	if (m_isleftcount >= MY_UTILITY::getFromFloatTo(0, 4) && m_isleft ==true)
	{
		m_isleft = false;
		m_isleftcount = 0;
	}
	if (m_move == false)
	{
	}
	if (m_move == true && m_isleft == false)
	{
		m_obj->x += 1;
	}
	if (m_move == true && m_isleft == true)
	{
		m_obj->x -= 1;
	}
	cout << m_isleftcount << endl;

}

void Cat::Render()
{
	if (m_move == false && m_isleft == false)
	{
		_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
	}
	if (m_move == true && m_isleft == false)
	{
		_img2->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
	}
	if (m_move == false && m_isleft == true)
	{
		_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0,1);
	}
	if (m_move == true && m_isleft == true)
	{
		_img2->CenterRender(m_obj->x, m_obj->y, 2, 2, 0,1);
	}
}

void Cat::Release()
{
}

void SpaerSkul::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("SpaerSkul");
	_img->Setting(0.1f, true);
}

void SpaerSkul::Update()
{
}

void SpaerSkul::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void SpaerSkul::Release()
{
}

void Elevator::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("Elevator");
	_img->Setting(0.1f, true);
}

void Elevator::Update()
{
}

void Elevator::Render()
{
	_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0);
}

void Elevator::Release()
{
}
