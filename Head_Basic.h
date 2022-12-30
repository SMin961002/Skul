#pragma once
#include "Head.h"
class Head_Basic : public Head
{
private:

public:
	virtual void ImageSetting() override;
	virtual void ParameterSetting() override;

	void InputSkillKey();
};

