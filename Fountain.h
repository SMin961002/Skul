#pragma once
#include"Item.h"
class Fountain : public Item
{

	vImage* _img;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

