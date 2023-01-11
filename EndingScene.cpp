#include "stdafx.h"
#include "EndingScene.h"

void EndingScene::Init()
{
	_imgSmallMountain = IMAGEMANAGER->FindImage("Ending_BG_SmallMountain");
	_imgBigMountain = IMAGEMANAGER->FindImage("Ending_BG_BigMountain");
	_imgSmallCloud = IMAGEMANAGER->FindImage("Ending_BG_SmallCloud");
	_imgMediumCloud = IMAGEMANAGER->FindImage("Ending_BG_MediumCloud");
	_imgBigCloud = IMAGEMANAGER->FindImage("Ending_BG_BigCloud");
	_imgSunset= IMAGEMANAGER->FindImage("Ending_BG_Sunset");

	_imgCastleBack = IMAGEMANAGER->FindImage("Ending_Castle_Back");
	_imgCastleFront = IMAGEMANAGER->FindImage("Ending_Castle_Front");

	_imgDuoTalkLoop = IMAGEMANAGER->FindImage("Ending_Duo_Talk_Loop");
	//_imgDuoSeeWitchLoop = IMAGEMANAGER->FindImage("");
	//_imgDuoReturnKing = IMAGEMANAGER->FindImage("");
	//_imgDuoThanksLoop = IMAGEMANAGER->FindImage("");

	//_duoImg[dSeeWitch] = IMAGEMANAGER->FindImageVector("");
	//_duoImg[dReturnKing] = IMAGEMANAGER->FindImageVector("");
	//_duoImg[dReturnSkul] = IMAGEMANAGER->FindImageVector("");
	//_duoImg[dThanks] = IMAGEMANAGER->FindImageVector("");

	//_imgCatPolymorphLoop = IMAGEMANAGER->FindImage("");
	_catImg[cWalk] = IMAGEMANAGER->FindImageVector("Ending_Cat_Walk");
	//_catImg[cPolymorph] = IMAGEMANAGER->FindImageVector("");
	//_catImg[cIdle] = IMAGEMANAGER->FindImageVector("");

	_catImg[cWalk]->Setting(0.1, true);
	//_catImg[cPolymorph]->Setting(0.1, false);
	//_catImg[cIdle]->Setting(0.1, false);

	_smallCloudLocate = 0;
	_mediumCloudLocate = 0;
	_bigCloudLocate = 0;
	_smallCloudLocate1 = -_imgSmallCloud->GetWidth();
	_mediumCloudLocate1 = -_imgMediumCloud->GetWidth();
	_bigCloudLocate1 = -_imgBigCloud->GetWidth();

	_catLocate = 0;

	m_catState = cWalk;
	m_duoState = dSeeWitch;
}

void EndingScene::Update()
{
	_smallCloudLocate += 1.5f;
	_mediumCloudLocate += 1.0f;
	_bigCloudLocate += 0.5f;
	_smallCloudLocate1 += 1.5f;
	_mediumCloudLocate1 += 1.0f;
	_bigCloudLocate1 += 0.5f;

	if (_smallCloudLocate > _imgSmallCloud->GetWidth())
	{
		_smallCloudLocate = 0-_imgSmallCloud->GetWidth();
	}
	if (_mediumCloudLocate > _imgMediumCloud->GetWidth())
	{
		_mediumCloudLocate = 0-_imgMediumCloud->GetWidth();
	}
	if (_bigCloudLocate > _imgBigCloud->GetWidth())
	{
		_bigCloudLocate = 0-_imgBigCloud->GetWidth();
	}

	if (_smallCloudLocate1 > _imgSmallCloud->GetWidth())
	{
		_smallCloudLocate1 = 0 - _imgSmallCloud->GetWidth();
	}
	if (_mediumCloudLocate1 > _imgMediumCloud->GetWidth())
	{
		_mediumCloudLocate1 = 0 - _imgMediumCloud->GetWidth();
	}
	if (_bigCloudLocate1 > _imgBigCloud->GetWidth())
	{
		_bigCloudLocate = 0 - _imgBigCloud->GetWidth();
	}

	if (_catLocate < 200)
	{
		_catLocate += 0.5f;
	}
}

void EndingScene::Render()
{
	// 노을 출력
	IMAGEMANAGER->Render(_imgSunset, 0, 0, 0.8, 0.8, 0, 0);

	// 구름 2단출력
	IMAGEMANAGER->Render(_imgBigCloud, _bigCloudLocate, 0, 1, 1, 0, 0);
	IMAGEMANAGER->Render(_imgMediumCloud, _mediumCloudLocate, 0, 1, 1, 0, 0);
	IMAGEMANAGER->Render(_imgSmallCloud, _smallCloudLocate, 0, 1, 1, 0, 0);
	IMAGEMANAGER->Render(_imgBigCloud, _bigCloudLocate1, 0, 1, 1, 0, 0);
	IMAGEMANAGER->Render(_imgMediumCloud, _mediumCloudLocate1, 0, 1, 1, 0, 0);
	IMAGEMANAGER->Render(_imgSmallCloud, _smallCloudLocate1, 0, 1, 1, 0, 0);

	// 산 출력
	IMAGEMANAGER->Render(_imgBigMountain, 0, 0, 1, 1, 0, 0);
	IMAGEMANAGER->Render(_imgSmallMountain, 0, 0, 1, 1, 0, 0);

	IMAGEMANAGER->Render(_imgCastleBack, 600, 0, 3, 3, 0, 0);

	IMAGEMANAGER->Render(_imgDuoTalkLoop, 700, 340, 2, 2, 0, 0);

	//m_catState->CenterRender(WINSIZE_X-_catLocate, 398, 2, 2, 0);

	//IMAGEMANAGER->Render(_imgCastleFront, 600, 0, 3, 3, 0, 0);
}

void EndingScene::Release()
{
}