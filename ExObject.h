#pragma once
#include "Component.h"

class ExObject : public Component
{
public:
	vImage* img;
	ExObject() {}
	~ExObject() {}
	// Component��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

