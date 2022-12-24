#pragma once
#include "Object.h"

class Object;
class Component
{
protected:
	Object* m_obj = nullptr;
public:
	Component();
	~Component();
public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	void SetObject(Object* obj) { m_obj = obj; }
};

