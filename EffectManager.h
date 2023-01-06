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
	void SetEffectOff(float x, float y, bool OnOff);

	//<����Ʈ����> �߿��� x, y���� ���� ������ �ִ� ����Ʈ�� �������� ���θ� true false�� ��ȯ�մϴ�.
	template<class T>
	bool GetEffectEnded(float x, float y);

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