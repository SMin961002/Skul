#include "stdafx.h"
#include "EffectManager.h"

void EffectManager::Update()
{
	if (!m_vectorEffectList.empty())
	{
		vector<Effect*>::iterator iter;
		for (iter = m_vectorEffectList.begin(); iter != m_vectorEffectList.end();)
		{
			if ((*iter)->GetIsActive() == true)
			{
				(*iter)->Update();
				iter++;
			}
			else {
				(*iter)->Release();
				iter = m_vectorEffectList.erase(iter);
			}
		}//end for
	}//end exist Effect
}

void EffectManager::Render()
{
	if (!m_vectorEffectList.empty())
	{
		vector<Effect*>::iterator iter;
		for (iter = m_vectorEffectList.begin(); iter != m_vectorEffectList.end(); iter++)
		{
			(*iter)->Render();
		}//end for
	}//end exist Effect
}

void EffectManager::Release()
{
	if (!m_vectorEffectList.empty())
	{
		vector<Effect*>::iterator iter;
		for (iter = m_vectorEffectList.begin(); iter != m_vectorEffectList.end();)
		{
			(*iter)->Release();
			iter = m_vectorEffectList.erase(iter);
		}//end for
		m_vectorEffectList.clear();
		vector<Effect*> emptyV;
		emptyV.swap(m_vectorEffectList);
	}//end exist Effect
}