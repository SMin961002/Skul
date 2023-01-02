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
		m_isReversed = isReversed;
		m_obj->x = startX;
		m_obj->y = startY;
		m_img->Reset();
		m_obj->SetIsActive(true);
		cout << m_isReversed << endl;
	}

	virtual void Move() {};	//����Ʈ�� ������ �ʿ䰡 ���� ��� �������̵� �ؼ� ���
};