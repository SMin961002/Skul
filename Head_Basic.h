#pragma once
#include "Head.h" //94,64 �⺻���ݹ��� x-30~x+42(�߽��� x+6, ���������� 36). y-56~y+8(�߽��� y-24, ���������� 32)
class Head_Basic : public Head
{
private:
	vImage* img_headless[eActionTagNumber];
	bool m_headThrow;

public:
	virtual void ImageSetting() override;
	virtual void ParameterSetting() override;
	virtual void CollisionSetting() override;

	virtual void ActionArrangement() override;
	virtual void DrawCharactor() override;

	void InputSkillKey();
};