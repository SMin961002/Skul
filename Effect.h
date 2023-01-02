#pragma once
#include "Component.h"
class Effect : public Component
{
protected:
	vImage* m_img;
	bool m_isReversed;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	
	bool GetIsActive() { return m_obj->GetIsActive(); }
	void SetEffectStart(float startX, float startY, bool isReversed)
	{
		m_obj->x = startX;
		m_obj->y = startY;
		m_img->Reset();
		m_obj->SetIsActive(true);
		m_isReversed = isReversed;
	}

	virtual void Move() {};	//이펙트가 움직일 필요가 있을 경우 오버라이드 해서 사용
};

class EffectManager : public Singleton<ImageManager>
{
protected:
	vector<Effect*> m_vEffect;
public:

	void Update();
	void Render();
	void Release();

	//예외처리 안되어있으니 클래스 넣을때 주의 필요
	template <class T>
	T* AddEffect(float startX, float startY, bool isReversed)
	{
		Effect* effect = new T;
		effect->Init();
		effect->SetEffectStart(startX, startY, isReversed);
		m_vEffect.push_back(effect);
	}
};