#pragma once
#include "Component.h"
class Effect : public Component
{
protected:
	vImage* m_img;
	bool m_isReversed;
	float m_scale;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	
	bool GetIsActive() { return m_obj->GetIsActive(); }
	void SetEffectStart(float startX, float startY, bool isReversed, float scale = 1)
	{
		m_isReversed = isReversed;
		m_obj->x = startX;
		m_obj->y = startY;
		m_scale = scale;
		m_img->Reset();
		m_obj->SetIsActive(true);
	}
	void SetIsActiveOff() { m_obj->SetIsActive(false); }
	virtual void Move() {};	//이펙트가 움직일 필요가 있을 경우 오버라이드 해서 사용
};