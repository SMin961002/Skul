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

template<class T>
inline void EffectManager::SetEffectOff(float x, float y, bool OnOff)
{
	const char* effect;
	effect = typeid<T>.name();

	int index = -1;
	float distance = 0;
	for (int i = 0; i < m_vectorEffectList.size(); i++)
	{
		if (strcmp(effect, typeid(m_vectorEffectList.[i]).name()) != 0)
			continue;
		else
		{
			if (index == -1)
			{
				index = i;
				distance = MY_UTILITY::GetDistance(x, y, m_vectorEffectList[i]->GetEffectX(), m_vectorEffectList[i]->GetEffectY());
				if (distance < 0) distance = -distance;
				if (distance == 0) break;
			}
			else
			{
				float tmpD =
					MY_UTILITY::GetDistance(x, y, m_vectorEffectList[i]->GetEffectX(), m_vectorEffectList[i]->GetEffectY());
				if (tmpD < 0) tmpD = -tmpD;
				if (distance < tmpD)
				{
					distance = tmpD;
					index = i;
					if (distance == 0) break;
				}
			}
		}//end classname
	}//end for

	if (index == -1)
	{
		cout << "해당 이펙트가 지금 없습니다." << endl;
	}
	else
	{
		m_vectorEffectList[index]->SetIsActive(OnOff);
	}
}

template<class T>
bool EffectManager::GetEffectEnded(float x, float y)
{
	const char* effect;
	effect = typeid<T>.name();

	int index = -1;
	float distance = 0;
	for (int i = 0; i < m_vectorEffectList.size(); i++)
	{
		if (strcmp(effect, typeid(m_vectorEffectList.[i]).name()) != 0)
			continue;
		else
		{
			if (index == -1)
			{
				index = i;
				distance = MY_UTILITY::GetDistance(x, y, m_vectorEffectList[i]->GetEffectX(), m_vectorEffectList[i]->GetEffectY());
				if (distance < 0) distance = -distance;
				if (distance == 0) break;
			}
			else
			{
				float tmpD =
					MY_UTILITY::GetDistance(x, y, m_vectorEffectList[i]->GetEffectX(), m_vectorEffectList[i]->GetEffectY());
				if (tmpD < 0) tmpD = -tmpD;
				if (distance < tmpD)
				{
					distance = tmpD;
					index = i;
					if (distance == 0) break;
				}
			}
		}//end classname
	}//end for

	if (index == -1)
	{
		cout << "끝났는지 알고싶은 이펙트가 지금 없습니다. false 반환" << endl;
		return false;
	}
	else
	{
		return m_vectorEffectList[index]->GetIsEffectEnded();
	}
}
