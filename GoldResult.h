#pragma once
#include "ResultValue.h"
class GoldResult : public ResultValue
{
public:
	GoldResult() {}
	~GoldResult() {}

	virtual void Setting() override;
	virtual void Reword() override;
};

