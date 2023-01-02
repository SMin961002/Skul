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

	template<class T>
	void SetEffectOff()	//##
	{

	}

	//����ó�� �ȵǾ������� Ŭ���� ������ �������ּ���~
	template <class T>
	void AddEffect(float startX, float startY, bool isReversed)
	{
		Effect* effect = new T;
		effect->Init();
		effect->SetEffectStart(startX, startY, isReversed);
		m_vectorEffectList.push_back(effect);
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