#include "stdafx.h"
#include "IntroTitleScene.h"

void IntroTitleScene::Init()
{
	img = IMAGEMANAGER->FindImage("IntroBg");
	imgTitle = IMAGEMANAGER->FindImage("IntroTitle");
	imgtxt = IMAGEMANAGER->FindImage("IntroClick");
	m_isTitleStart = false;
	alpha = 0;
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
	}

	for (int i = 0; i < 256; i++)
	{
		if (KEYMANAGER->GetOnceKeyDown(i))
		{
			SCENEMANAGER->ChangeScene("EnemyTestScene");
		}
	}
}

void IntroTitleScene::Render()
{
	IMAGEMANAGER->UIRender(img, 0, 0, 1, 1, 0, 1);
	IMAGEMANAGER->UIRender(imgTitle, 0, 0, 1, 1, 0, alpha);
	if (alpha >= 1)
		IMAGEMANAGER->UIRender(imgtxt, 0, 0, 1, 1, 0, alpha2);
	SCENEMANAGER->FadeIn(0.01, [&]() { m_isTitleStart = true; }, 5);
}

void IntroTitleScene::Release()
{
}
