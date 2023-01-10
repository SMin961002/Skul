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
