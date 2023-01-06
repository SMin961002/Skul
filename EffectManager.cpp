#include "stdafx.h"
#include "EffectManager.h"

void EffectManager::Update()
{
	if (!m_vectorEffectList.empty())
	{
		for (auto& iter = m_vectorEffectList.begin(); iter != m_vectorEffectList.end();)
		{
			(*iter)->Update();
			if ((*iter)->GetIsEnded() == true)
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				*iter = nullptr;
				iter = m_vectorEffectList.erase(iter);
			}
			else {
				iter++;
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