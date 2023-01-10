#include "stdafx.h"
#include"LobbyObject.h"

void Spider::Init()
{
	_img = IMAGEMANAGER->AddImageVectorCopy("Spider");
	_img->Setting(0.1f, true);
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
