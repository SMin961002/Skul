#include "stdafx.h"
#include "ResultValue.h"

void ResultValue::Init()
{
	Setting();
	m_isCheck = false;
}

void ResultValue::Update()
{
}

void ResultValue::Render()
{
	if (m_isCheck == false)
	{
		m_idleImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
	}
	else
	{
		m_activeImg->CenterRender(m_obj->x, m_obj->y, 2, 2, 0, 0);
	}
}

void ResultValue::Release()
{
}
