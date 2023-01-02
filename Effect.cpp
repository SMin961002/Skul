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
	m_img->CenterRender(m_obj->x, m_obj->y, 2, 2, m_isReversed);
}

void Effect::Release()
{
	m_obj->Release();
	SAFE_DELETE(m_obj);
}

void EffectManager::Update()
{
	if (!m_vEffect.empty())
	{
		vector<Effect*>::iterator iter;
		for (iter = m_vEffect.begin(); iter != m_vEffect.end();)
		{
			if ((*iter)->GetIsActive() == true)
			{
				(*iter)->Update();
				iter++;
			}
			else {
				(*iter)->Release();
				iter = m_vEffect.erase(iter);
			}
		}//end for
	}//end exist Effect
}

void EffectManager::Render()
{
	if (!m_vEffect.empty())
	{
		vector<Effect*>::iterator iter;
		for (iter = m_vEffect.begin(); iter != m_vEffect.end(); iter++)
		{
			(*iter)->Render();
		}//end for
	}//end exist Effect
}

void EffectManager::Release()
{
	if (!m_vEffect.empty())
	{
		vector<Effect*>::iterator iter;
		for (iter = m_vEffect.begin(); iter != m_vEffect.end();)
		{
			(*iter)->Release();
			iter = m_vEffect.erase(iter);	
		}//end for
	}//end exist Effect
}