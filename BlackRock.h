#pragma once
#include"Item.h"
class BlackRock : public Item
{
private:
	enum ImageState
	{
		eBlackRock,
		eGetBlackRock,
		eEnd
	};

	vImage* m_vimage[eEnd];
	bool m_grvitonoff;
	bool m_drop;
	int state;
	int m_updown;
	float m_rocky;
	float m_rocky2;
	float m_rockx;

public:
	void Setting(float y) { m_rocky += y; }
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

