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
	float m_goldy;
	float m_goldy2;
	float m_goldx;

public:
	void Setting(float y) { m_goldy += y; }
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

