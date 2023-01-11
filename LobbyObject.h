#pragma once
#include"Item.h"
class Spider : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

class LobbyNpc1 : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};


class LobbyNpc2 : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

class LobbyNpc3 : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

class LobbyNpc4 : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

class LobbyNpc5 : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};
class SpaerSkul : public Item
{
	vImage* _img;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

class Cat : public Item
{
	vImage* _img;
	vImage* _img2;
	float m_movetimer;
	int m_isleftcount;
	bool m_move;
	bool m_isleft;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

class Elevator : public Item
{
	bool isUp = false;
	vImage* _img;
	vImage* _img2;
	CollisionComponent* coll;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;
};
