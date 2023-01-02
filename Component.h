#pragma once
#include "Object.h"

class Object;
class Component
{
protected:
	Object* m_obj = nullptr;
private:
	bool m_isActive = true;
public:
	Component();
	~Component();
public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	virtual void OnCollision(string collisionName, Object* other);
	virtual void UIRender() {}
	bool GetIsActive()
	{
		return m_isActive;
	}

	void SetIsActive(bool active)
	{
		m_isActive = active;
	}

	void SetObject(Object* obj) { m_obj = obj; }
};

