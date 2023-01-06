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

	//T종류 이펙트중, 지정한 x, y좌표에 가장 가까운 곳에 있는 Effect를 켜거나 끕니다. (3번째인자 true : on, false : off)
	template<class T>
	void SetEffectOff(float x, float y, bool OnOff);

	//<이펙트종류> 중에서 x, y값에 가장 가까이 있는 이펙트가 끝났는지 여부를 true false로 반환합니다.
	template<class T>
	bool GetEffectEnded(float x, float y);

	//예외처리 안되어있으니 클래스 넣을때 주의해주세요~
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
< 사용 방법 >
준비 : 넣고자 하는 Effect에 해당하는 클래스를 만들어주세요!
	1. 솔루션탐색기→Game→Object→Effect 필터에
		해당 이펙트를 사용하는 주체에 해당하는 .h, .cpp를 들어가주세요

	2. public Effect 클래스를 상속받는 이펙트 클래스를 만들어주세요
		ex ) class NomalHit : public Effect {}

	3. 초기값 세팅받을 Init함수를 만들어주세요.
		Effect에 있는 Init을 오버라이드 하는 형식입니다.
		Effect::Init()을 한번 실행하고,
		이펙트에 해당하는 벡터이미지를 m_img변수에 넣은 후
		m_img->Setting 해주세요

	4. 이펙트가 실행되는 동안 움직여야 할 경우
		Move함수를 오버라이드해주세요

이펙트 넣기 : 이펙트가 들어가야하는 순간에
		아래 코드를 넣어주세요
		EFFECTMANAGER->AddEffect<EffectClassName>(이펙트시작x, 이펙트시작y, 이미지뒤집어지는지);
		ex ) EFFECTMANAGER->AddEffect<DoubleJumpSmoke>(m_obj->x, m_obj->y, m_isLeft);

지우는 처리는 따로 안해주어도 됩니다
*/