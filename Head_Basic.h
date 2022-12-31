#pragma once
#include "Head.h" //94,64 기본공격범위 x-30~x+42(중심점 x+6, 범위반지름 36). y-56~y+8(중심점 y-24, 범위반지름 32)
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