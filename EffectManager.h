#pragma once
#include "BossEffect.h"
#include "EnemyEffect.h"
#include "PlayerEffect.h"
class EffectManager : public Singleton<EffectManager>
{
protected:
	vector<Effect*> m_vectorEffectList;
public:

	void Update();
	void Render();
	void Release();

	//T���� ����Ʈ��, ������ x, y��ǥ�� ���� ����� ���� �ִ� Effect�� �Ѱų� ���ϴ�. (3��°���� true : on, false : off)
	template<class T>
	void SetEffectOff(float x, float y, bool OnOff)
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
					}
				}
			}//end classname
		}//end for

		if (index == -1)
		{
			cout << "�ش� ����Ʈ�� ���� �����ϴ�." << endl;
		}
		else
		{
			m_vectorEffectList[index]->SetIsActive(OnOff);
		}
	}


	//<����Ʈ����> �߿��� x,y���� ���� ������ �ִ� ����Ʈ�� �������� ���θ� true false�� ��ȯ�մϴ�.
	template<class T>
	bool GetEffectEnded(float x, float y)
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
					}
				}
			}//end classname
		}//end for

		if (index == -1)
		{
			cout << "�������� �˰���� ����Ʈ�� ���� �����ϴ�. false ��ȯ" << endl;
			return false;
		}
		else
		{
			return m_vectorEffectList[index]->GetIsEffectEnded();
		}
	}

	//����ó�� �ȵǾ������� Ŭ���� ������ �������ּ���~
	template <class T>
	T* AddEffect(float startX, float startY, bool isReversed, float scale = 1)
	{
		Effect* effect = new T;
		effect->Init();
		effect->SetEffectStart(startX, startY, isReversed, scale);
		m_vectorEffectList.push_back(effect);
		return dynamic_cast<T*> (effect);
	}

};

#define EFFECTMANAGER EffectManager::GetInstance()

/*
< ��� ��� >
�غ� : �ְ��� �ϴ� Effect�� �ش��ϴ� Ŭ������ ������ּ���!
	1. �ַ��Ž�����Game��Object��Effect ���Ϳ�
		�ش� ����Ʈ�� ����ϴ� ��ü�� �ش��ϴ� .h, .cpp�� ���ּ���

	2. public Effect Ŭ������ ��ӹ޴� ����Ʈ Ŭ������ ������ּ���
		ex ) class NomalHit : public Effect {}

	3. �ʱⰪ ���ù��� Init�Լ��� ������ּ���.
		Effect�� �ִ� Init�� �������̵� �ϴ� �����Դϴ�.
		Effect::Init()�� �ѹ� �����ϰ�,
		����Ʈ�� �ش��ϴ� �����̹����� m_img������ ���� ��
		m_img->Setting ���ּ���

	4. ����Ʈ�� ����Ǵ� ���� �������� �� ���
		Move�Լ��� �������̵����ּ���

����Ʈ �ֱ� : ����Ʈ�� �����ϴ� ������
		�Ʒ� �ڵ带 �־��ּ���
		EFFECTMANAGER->AddEffect<EffectClassName>(����Ʈ����x, ����Ʈ����y, �̹���������������);
		ex ) EFFECTMANAGER->AddEffect<DoubleJumpSmoke>(m_obj->x, m_obj->y, m_isLeft);

����� ó���� ���� �����־ �˴ϴ�
*/