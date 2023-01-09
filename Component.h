#pragma once

class Object;
class Component
{
protected:
	Object* m_obj = nullptr;
private:
	bool m_isActive = true;
	bool m_isDel = false;
public:
	Component();
	~Component();
public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	virtual void OnCollision(string collisionName, Object* other);
	virtual void HitEnemy(float dmg, float time) {}
	virtual void UIRender() {}
	bool GetIsActive()
	{
		return m_isActive;
	}
	bool GetIsDelete()
	{
		return m_isDel;
	}

	void SetIsActive(bool active)
	{
		m_isActive = active;
	}
	void SetIsDelete(bool del)
	{
		m_isDel = del;
	}
	void SetObject(Object* obj) { m_obj = obj; }

	void SetPosition(float x, float y);
};

