#pragma once
#include "ResultValue.h"

class HeadResult : public ResultValue
{
public:
	HeadResult() {}
	~HeadResult() {}
	// ResultValue��(��) ���� ��ӵ�
	virtual void Reword() override;

	// ResultValue��(��) ���� ��ӵ�
	virtual void Setting() override;
};

