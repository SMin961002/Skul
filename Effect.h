#pragma once
#include "Component.h"
class Effect : public Component
{
protected:
	vImage* m_img;
	bool m_isReversed;
	float m_scale;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	
	bool GetIsEffectActive() { return m_obj->GetIsActive(); }
	bool GetIsEffectEnded() { return m_img->GetIsImageEnded(); }
	float GetEffectX() { return m_obj->x; }
	float GetEffectY() { return m_obj->y; }
	void SetEffectStart(float startX, float startY, bool isReversed, float scale = 1)
	{
		m_isReversed = isReversed;
		m_obj->x = startX;
		m_obj->y = startY;
		m_scale = scale;
		m_img->Reset();
		m_obj->SetIsActive(true);
	}
	void SetIsEffectActiveOff() { m_obj->SetIsActive(false); }
	virtual void Move() {};	//이펙트가 움직일 필요가 있을 경우 오버라이드 해서 사용
};