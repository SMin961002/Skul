#include "stdafx.h"
#include "Roulette.h"

void Roulette::Init()
{
	m_result = MY_UTILITY::getInt(2);
	if (m_result == eBlack)
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletBlack");
	else
		m_imageResult = IMAGEMANAGER->FindImage("GamblerRoulletRed");
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