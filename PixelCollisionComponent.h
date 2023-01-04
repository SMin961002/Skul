#pragma once
#include"Component.h"
class PixelCollisionComponent : public Component
{
private:
	float* x;
	float* y;
	bool m_isCheck;
	float m_checkY;
	float m_checkX;
	bool m_platformCheck;

	bool m_isLeftCheck;
	bool m_isRightCheck;
	bool m_isBottomCheck;
	bool m_isTopCheck;
	RECT rtL, rtT, rtB, rtR;

	GImage* m_image;
	GImage* m_imagePlatform;

	vector<vector<int>> m_tiles;
public:
	bool m_isGold;
	bool GetIsCollision() { return m_isCheck; }
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void setting(vector<vector<int>>tiles, float* x, float* y);
	float GetCheckY() { return m_checkY; }
	float GetCheckX() { return m_checkX; }

	void BottomCollision();
	void TopCollision();
	void LeftCollision();
	void RightCollision();

	bool GetIsLeftCollision() { return m_isLeftCheck; }
	bool GetIsRightCollision() { return m_isRightCheck; }
	bool GetIsTopCollision() { return m_isTopCheck; }
	bool GetIsBottomCollision() { return m_isBottomCheck; }
	bool GetIsPlatformCollision() { return m_platformCheck; }

	void RSettingRect(RECT rt) { rtR = rt; }
	void LSettingRect(RECT rt) { rtL = rt; }
	void TSettingRect(RECT rt) { rtT = rt; }
	void BSettingRect(RECT rt) { rtB = rt; }

	void PixcelCollision(float w, float h, bool isCheck, string dir);

	PixelCollisionComponent() {}
	~PixelCollisionComponent() {}
};

