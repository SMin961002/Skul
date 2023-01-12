#include "stdafx.h"
#include "EndingScene.h"
#include "CSound.h"

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
	_imgDuoThanksLoop = IMAGEMANAGER->FindImage("Ending_Duo_DuoThanks_Loop");

	_duoImg[dSeeWitch] = IMAGEMANAGER->FindImageVector("Ending_Duo_SeeWitch");
	_duoImg[dSeeWitch]->Setting(0.1, false);
	_duoImg[dReturnKing] = IMAGEMANAGER->FindImageVector("Ending_Duo_ReturnKing");
	_duoImg[dReturnKing]->Setting(0.1, false);
	_duoImg[dReturnSkul] = IMAGEMANAGER->FindImageVector("Ending_Duo_ReturnSkul");
	_duoImg[dReturnSkul]->Setting(0.1, false);
	_duoImg[dThanks] = IMAGEMANAGER->FindImageVector("Ending_Duo_DuoThanks");
	_duoImg[dThanks]->Setting(0.1, false);

	_catImg[cWalk] = IMAGEMANAGER->FindImageVector("Ending_Cat_Walk");
	_catImg[cPolymorph] = IMAGEMANAGER->FindImageVector("Ending_Cat_Polymorph");

	_catImg[cWalk]->Setting(0.1, true);
	_catImg[cPolymorph]->Setting(0.1, false);

	_smallCloudLocate = 0;
	_mediumCloudLocate = 0;
	_bigCloudLocate = 0;
	_smallCloudLocate1 = -_imgSmallCloud->GetWidth();
	_mediumCloudLocate1 = -_imgMediumCloud->GetWidth();
	_bigCloudLocate1 = -_imgBigCloud->GetWidth();

	_catLocate = 0;
	_polymorphY = 0;
	_ReturnKingDeltaTime = 0;
	_ReturnSkulDeltaTime = 0;
	_ThanksDeltaTime = 0;
	_ThanksLoopDeltaTime = 0;

	m_catState = cWalk;
	m_duoState = dNone;

	SOUNDMANAGER->FindSound("EndingScene")->Play(true);
}

void EndingScene::Update()
{
	_smallCloudLocate += 0.3f;
	_mediumCloudLocate += 0.2f;
	_bigCloudLocate += 0.1f;
	_smallCloudLocate1 += 0.3f;
	_mediumCloudLocate1 += 0.2f;
	_bigCloudLocate1 += 0.1f;

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

	if (_catLocate <= 200)
	{
		_catLocate += 0.5f;
	}
	if (_catLocate == 200)
	{
		m_catState = cPolymorph;
		_polymorphY = 51;
	}
	if (m_catState == cPolymorph)
	{
		m_duoState = dSeeWitch;
		if (_ReturnKingDeltaTime <= 2 && _catImg[cPolymorph]->GetIsImageEnded() == true)
		{
			_ReturnKingDeltaTime += DELTA_TIME;
		}
	}
	if (_ReturnKingDeltaTime >= 2)
	{
		m_duoState = dReturnKing;
		if (_ReturnSkulDeltaTime <= 3 && _duoImg[dReturnKing]->GetIsImageEnded() == true)
		{
			_ReturnSkulDeltaTime += DELTA_TIME;
		}
	}
	if (_ReturnSkulDeltaTime >= 3)
	{
		m_duoState = dReturnSkul;
		if (_ThanksDeltaTime <= 3 && _duoImg[dReturnSkul]->GetIsImageEnded() == true)
		{
			_ThanksDeltaTime += DELTA_TIME;
		}
	}
	if (_ThanksDeltaTime >= 3)
	{
		m_duoState = dThanks;
		if (_ThanksLoopDeltaTime <= 3 && _duoImg[dThanks]->GetIsImageEnded() == true)
		{
			_ThanksLoopDeltaTime += DELTA_TIME;
		}
	}
	if (_ThanksLoopDeltaTime >= 3)
	{
		m_duoState = dNone;
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

	if (m_duoState == dNone && _duoImg[dThanks]->GetIsImageEnded() == false) IMAGEMANAGER->Render(_imgDuoTalkLoop, 700, 340, 2, 2, 0, 0);
	if (m_duoState == dNone && _duoImg[dThanks]->GetIsImageEnded() == true) IMAGEMANAGER->Render(_imgDuoThanksLoop, 700, 340, 2, 2, 0, 0);

	if (!m_duoState == dNone) _duoImg[m_duoState]->Render(700, 340, 2, 2, 0);

	_catImg[m_catState]->CenterRender(WINSIZE_X-_catLocate, 398-_polymorphY, 2, 2, 0);

	IMAGEMANAGER->Render(_imgCastleFront, 600, 0, 3, 3, 0, 0);
}

void EndingScene::Release()
{
	SOUNDMANAGER->FindSound("EndingScene")->Stop();
	SOUNDMANAGER->FindSound("Intro")->Play(true);
}