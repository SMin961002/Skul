#include "stdafx.h"
#include "Roulette.h"

void Roulette::Init()
{
	m_result = MY_UTILITY::getInt(2);
	m_roulette = IMAGEMANAGER->FindImageVector("Gambler_Roullet");
	m_roulette->Setting(0.05, false);
	if (m_result == eBlack)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletBlack");
	else if(m_result == eRed)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletRed");
	else
	{
		cout << "·ê·¿ °á°ú°ªÀÌ ÀÌ»óÇÏ´Ù. " << m_result << endl;
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletRed");
	}


}
void Roulette::Update()
{

}
void Roulette::Render()
{

}
void Roulette::Release()
{

}
void Roulette::OnCollision(string collisionName, Object* other)
{
	
}