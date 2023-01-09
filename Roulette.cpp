#include "stdafx.h"
#include "Roulette.h"
#include "Player.h"

void Roulette::Init()
{
	m_result = MY_UTILITY::getInt(2);
	m_roulette = IMAGEMANAGER->FindImageVector("Gambler_Roullet");
	if (m_result == eBlack)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletBlack");
	else if(m_result == eRed)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletRed");
	else
	{
		cout << "·ê·¿ °á°ú°ªÀÌ ÀÌ»óÇÏ´Ù. " << m_result << endl;
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletRed");
	}
	m_imageResult->SetDelay(1);

	if (OBJECTMANAGER->m_player->GetplayerIsLeft())
	{
		m_obj->x += 100;
	}
	else m_obj->x -= 100;
	m_obj->y -= 108;
	m_rotateCount = 0;
	m_printResult = false;
}
void Roulette::Update()
{
	if (m_roulette->GetIsImageEnded())
	{
		if (++m_rotateCount < 3)
			m_roulette->Reset();
		else m_printResult = true;
	}
}
void Roulette::Render()
{
	if (!m_printResult)
		m_roulette->CenterRender(m_obj->x, m_obj->y, 2, 2,0);
	else IMAGEMANAGER->CenterRender(m_imageResult, m_obj->x, m_obj->y, 2, 2);
}
void Roulette::Release()
{

}
void Roulette::OnCollision(string collisionName, Object* other)
{
	
}