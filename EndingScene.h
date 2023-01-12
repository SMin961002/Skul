#pragma once
#include "Scene.h"

class EndingScene : public Scene
{
private:
	CImage* _imgSmallMountain;
	CImage* _imgBigMountain;
	CImage* _imgSmallCloud;
	CImage* _imgMediumCloud;
	CImage* _imgBigCloud;
	CImage* _imgSunset;
	CImage* _imgCastleFront;
	CImage* _imgCastleBack;

	CImage* _imgDuoTalkLoop;
	CImage* _imgDuoThanksLoop;

	float _smallCloudLocate;
	float _mediumCloudLocate;
	float _bigCloudLocate;
	float _smallCloudLocate1;
	float _mediumCloudLocate1;
	float _bigCloudLocate1;
	float _catLocate;
	float _ReturnKingDeltaTime;
	float _ReturnSkulDeltaTime;
	float _ThanksDeltaTime;
	float _ThanksLoopDeltaTime;

	int m_duoState;
	int m_catState;
	int _polymorphY;

	enum DuoState
	{
		dNone,
		dSeeWitch,
		dReturnKing,
		dReturnSkul,
		dThanks,
		dEnd
	};

	enum CatState
	{
		cWalk,
		cPolymorph,
		cEnd
	};

	vImage* _duoImg[DuoState::dEnd];
	vImage* _catImg[CatState::cEnd];

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	float alpha= 0;
	virtual void UIRender() override;
};

