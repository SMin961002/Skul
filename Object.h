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
		// ex.) �׷���Ƽ ������Ʈ�� �����ϸ� ��ü�� ��ġ���� �޾ƿ��� �߷°��� �־��� or
		// �ݶ��̴� ������Ʈ�� �����ϸ� ��ü�� ��ġ�� ũ�⸦ �޾ƿͼ� �浹�� ������
		return p;
	}

	template <class T>
	T* GetComponent()
	{
		for (auto& iter : m_components) // ������Ʈ ���͸� ��ȯ�ؼ�
		{
			if (typeid(*iter) == typeid(T)) //�Ѱ����� ���ø��� Ÿ���� Ȯ����
			{
				return static_cast<T*>(iter); // ��� ������Ʈ�� �θ��� ������Ʈ�� ��ӹް����� �׷��� ���ø��� ���� ������
			}
		}
		T* cast;
		for (auto& iter : m_components)
		{
			cast = dynamic_cast<T*>(iter); // ���� ��ã���� ������Ʈ���� ��ȯ�ؼ� ��ȯ�� �����ϸ�
			if (cast != nullptr) // ��ȯ��
			{
				return cast;
			}
		}
		return nullptr;
	}

};

