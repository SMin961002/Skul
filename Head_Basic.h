#pragma once
#include "Head.h"
class Head_Basic : public Head
{
private:
	vImage* img_headless[eActionTagNumber];
	bool m_headThrow;

public:
	virtual void ImageSetting() override;
	virtual void ParameterSetting() override;

	virtual void DrawCharactor() override;


	void InputSkillKey();
};

