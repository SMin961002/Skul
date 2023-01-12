#include "stdafx.h"
#include "CSound.h"
#include "IntroTitleScene.h"

void IntroTitleScene::Init()
{
	IMAGEMANAGER->SetCameraPosition(0, 0);
	img = IMAGEMANAGER->FindImage("IntroBg");
	imgTitle = IMAGEMANAGER->FindImage("IntroTitle");
	imgtxt = IMAGEMANAGER->FindImage("IntroClick");
	m_isTitleStart = false;
	alpha = 0;

	SOUNDMANAGER->FindSound("Intro")->Play(true);
	alpha2 = 0;
}

void IntroTitleScene::Update()
{
	if (m_isTitleStart == true)
		alpha += 0.005;
	if (alpha >= 1)
	{
		r += 0.01;
		alpha2 = cos(r) / 2 + 0.5;

		for (int i = 1; i < 256; i++)
		{
			if (KEYMANAGER->GetStayKeyDown(i))
			{
				FILEMANAGER->SetNowStageFile("map_5");
				SCENEMANAGER->ChangeScene("Stage");
			}
		}
	}
	for (int i = 1; i < 256; i++)
	{
		if (KEYMANAGER->GetStayKeyDown(i))
		{
		}
	}

}

void IntroTitleScene::Render()
{
	IMAGEMANAGER->UIRender(img, 0, 0, 1, 1, 0, 1);
	IMAGEMANAGER->UIRender(imgTitle, 0, 0, 1, 1, 0, alpha);
	if (alpha >= 1)
		IMAGEMANAGER->UIRender(imgtxt, 0, 0, 1, 1, 0, alpha2);
	if (m_isTitleStart == false)
		SCENEMANAGER->FadeIn(0.01, [&]() { m_isTitleStart = true; }, 5);
}

void IntroTitleScene::Release()
{
	//SOUNDMANAGER->FindSound("Lobby")->Play(true);
	SOUNDMANAGER->FindSound("Intro")->Stop();
}
