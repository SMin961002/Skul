#pragma once
#include "ResultValue.h"

class HeadResult : public ResultValue
{
public:
	HeadResult() {}
	~HeadResult() {}
	// ResultValue을(를) 통해 상속됨
	virtual void Reword() override;

	// ResultValue을(를) 통해 상속됨
	virtual void Setting() override;
};

