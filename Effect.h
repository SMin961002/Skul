#pragma once
#include "Component.h"
class Effect
{
protected:
	vImage* m_img;
	bool m_isReversed;
	float m_scale;
	float  x, y;
public:

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();


	float GetEffectX() { return x; }
	float GetEffectY() { return y; }
	bool GetIsEnded() { return m_img->GetIsImageEnded(); }
	void SetEffectStart(float startX, float startY, bool isReversed, float scale = 1)
	{
		m_isReversed = isReversed;
		x = startX;
		y = startY;
		m_scale = scale;
		m_img->Reset();
	}
	bool GetIsEffectEnded() { return m_img->GetIsImageEnded(); }
	virtual void Move() {};	//이펙트가 움직일 필요가 있을 경우 오버라이드 해서 사용
};