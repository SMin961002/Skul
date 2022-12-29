#pragma once
#include"Component.h"
class PixelCollisionComponent : public Component
{
private:
	float* x;
	float* y;
	GImage* m_image;
	vector<vector<int>> m_tiles;
public:

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void setting(vector<vector<int>>tiles,float* x,float* y);

	PixelCollisionComponent() {}
	~PixelCollisionComponent() {}
};

