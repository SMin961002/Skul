#pragma once
#include"Item.h"
class Hporb : public Item
{
private:
	enum ImageState
	{
		eIdle,
		eEnd
	};

	vImage* m_vimage[eEnd];
	int state;
	float m_uphightimer;
	float m_rotation;
	CollisionComponent* m_collision;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;


	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
};

