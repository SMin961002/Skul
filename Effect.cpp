#include "stdafx.h"
#include "Effect.h"

void Effect::Init()
{
	Object* obj = new Object;
	m_obj = obj;
}

void Effect::Update()
{
	if (m_obj->GetIsActive() == true)
	{
		Move();
	}
	if (m_img->GetIsImageEnded())
	{
		m_obj->SetIsActive(false);
		//m_obj->ObjectDestroyed();
	}
	else m_obj->SetIsActive(true);
}

void Effect::Render()
{
	m_img->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, m_isReversed);
	cout << "���� m_isReversed:" << m_isReversed << endl;
}

void Effect::Release()
{
	m_obj->Release();
	SAFE_DELETE(m_obj);
}