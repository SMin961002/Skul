#pragma once
#include"Item.h"
class Gold : public Item
{
private:
	enum ImageState
	{
		eGlod,
		eGetgold,
		eEnd
	};

	vImage* m_vimage[eEnd];
	bool m_grvitonoff;
	bool m_drop;
	int state;
	int m_updown;
	int m_goldy;
	int m_goldy2;
	int m_goldx;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

