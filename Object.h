#pragma once
#include "Component.h"
#include "CollisionComponent.h"
class Object : public Component
{
public:
	float x, y;
private:
	string name;
	vector<Component*> m_components;
	vector < CollisionComponent*> m_collisions;
	bool m_isObjectDestroyed = false;
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void OnCollision(string collisionName, Object* other);
	void UIRender();
	void SetPosition(float x, float y) { this->x = x; this->y = y; }
	void SetName(string str) { name = str; }
	string GetName() { return name; }

	bool GetIsObjectDestroyed() { return m_isObjectDestroyed; }
	void ObjectDestroyed() { m_isObjectDestroyed = true; }


	void AddCollisionComponent(CollisionComponent* coll) { m_collisions.push_back(coll); };
	vector<CollisionComponent*> GetCollisionComponent()
	{
		return m_collisions;
	}

	template <class T>
	T* AddComponent()
	{
		T* p = new T;
		p->SetObject(this);
		m_components.push_back(p);
		p->Init();
		// ex.) 그레비티 컴포넌트를 생성하면 객체의 위치값을 받아오고 중력값을 넣어줌 or
		// 콜라이더 컴포넌트를 생성하면 객체의 위치랑 크기를 받아와서 충돌을 시켜줌
		return p;
	}

	template <class T>
	T* GetComponent()
	{
		for (auto& iter : m_components) // 컴포넌트 벡터를 순환해서
		{
			if (typeid(*iter) == typeid(T)) //한개마다 템플릿과 타입을 확인함
			{
				return static_cast<T*>(iter); // 모든 컴포넌트는 부모인 컴포넌트를 상속받고있음 그래서 템플릿과 형을 맞춰줌
			}
		}
		T* cast;
		for (auto& iter : m_components)
		{
			cast = dynamic_cast<T*>(iter); // 만약 못찾으면 컴포넌트마다 변환해서 변환이 가능하면
			if (cast != nullptr) // 반환함
			{
				return cast;
			}
		}
		return nullptr;
	}

};

