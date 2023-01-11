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

	float _smallCloudLocate;
	float _mediumCloudLocate;
	float _bigCloudLocate;
	float _smallCloudLocate1;
	float _mediumCloudLocate1;
	float _bigCloudLocate1;
	float _catLocate;

	int m_duoState;
	int m_catState;

	enum DuoState
	{
		dSeeWitch,
		dReturnKing,
		dReturnSkul,
		dThanks,
		dEnd
	};

	enum CatState
	{
		cWalk,
		cIdle,
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
};

