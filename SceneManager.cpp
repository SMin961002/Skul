#include "stdafx.h"
#include "SceneManager.h"
#include "LobbyScene.h"
#include "MapToolScene.h"
#include "MapToolMapSelectScene.h"
#include "EnemyTestScene.h"
#include "ShopScene.h"
#include "BossScene.h"
#include "IntroTitleScene.h"
#include "Stage.h"
#include "EndingScene.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{

	Release();
}

void SceneManager::Init()
{
	m_isInvenActive = false;
	m_isMenuActive = false;

	AddScene("BossScene", new BossScene);
	AddScene("LobbyScene", new LobbyScene);
	AddScene("MapToolMapSelectScene", new MapToolMapSelectScene);
	AddScene("MapToolScene", new MapToolScene);
	AddScene("EnemyTestScene", new EnemyTestScene);
	AddScene("ShopScene", new ShopScene);
	AddScene("IntroTitleScene", new IntroTitleScene);
	AddScene("Stage", new Stage);
	AddScene("EndingScene", new EndingScene);
	AddScene("IntroTitleScene", new IntroTitleScene);

	flag = 0;
	// 페이드인아웃 할때 다른플레그이면 알파값을 초기화해줌
	// 초기화를해줘야하는데 어떻게 해야할지 몰라서 해둠

	//페이드인 아웃 만드려고
	//아직 이미지없으니까 주석처리해뒀음
	fadeImage = IMAGEMANAGER->AddImage("fadeImage", L"./Resources/FadeImage.png");
}

void SceneManager::Update()
{
	if (m_nextScene != nullptr)
	{
		if (m_curScene != nullptr)
		{
			m_curScene->Release();
			OBJECTMANAGER->Release();
		}
		m_curScene = m_nextScene;
		m_nextScene = nullptr;
		m_curScene->Init();
	}
	if (m_curScene != nullptr)
	{
		m_curScene->Update();
	}
}

void SceneManager::Render()
{
	if (m_curScene != nullptr)
	{
		m_curScene->Render();
	}
}

void SceneManager::UIRender()
{
	if (m_curScene != nullptr)
	{
		m_curScene->UIRender();
	}
}

void SceneManager::Release()
{
	for (auto iter : m_tiles)
	{
		iter.clear();
	}
	m_tiles.clear();
	for (auto iter : m_sceneList)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_sceneList.clear();
}

void SceneManager::AddScene(std::string key, Scene* scene)
{
	auto find = m_sceneList.find(key);
	if (find == m_sceneList.end())
	{
		m_sceneList.insert(make_pair(key, scene));
		return;
	}
	cout << "이미 씬이 만들어져 있음";
}

void SceneManager::ChangeScene(std::string key)
{
	auto find = m_sceneList.find(key);
	if (find != m_sceneList.end())
	{
		m_nextScene = find->second;
		return;
	}
	cout << "씬이 없음 key :" << key;
}

bool SceneManager::FadeIn(float t, function<void()> func, int flag)
{
	if (this->flag != flag)
	{
		fadeImage->SetAlpha(1.f);
		this->flag = flag;
	}

	fadeImage->SetAlpha(fadeImage->GetAlpha() - t);

	if (fadeImage->GetAlpha() <= 0)
	{
		func();
	}

	IMAGEMANAGER->UIRender(fadeImage, 0, 0, 2, 2, 0, fadeImage->GetAlpha());

	return false;
}

bool SceneManager::FadeInColor(float t, function<void()> func, int flag)
{
	if (this->flag != flag)
	{
		fadeImage->SetAlpha(1.f);
		this->flag = flag;
	}

	fadeImage->SetAlpha(fadeImage->GetAlpha() - t);

	if (fadeImage->GetAlpha() <= 0)
	{
		func();
	}

	IMAGEMANAGER->CenterRender(fadeImage, WINSIZE_X / 2 + IMAGEMANAGER->GetCameraPosition().x, WINSIZE_Y / 2 + IMAGEMANAGER->GetCameraPosition().y, { 255,255,255,fadeImage->GetAlpha() }, 2, 2, 0);

	return false;
}

bool SceneManager::FadeOut(float t, function<void()> func, int flag)
{
	if (this->flag != flag)
	{
		fadeImage->SetAlpha(0.f);
		this->flag = flag;
	}

	fadeImage->SetAlpha(fadeImage->GetAlpha() + t);

	if (fadeImage->GetAlpha() >= 1)
	{
		func();
	}
	IMAGEMANAGER->UIRender(fadeImage, 0, 0, 2, 2, 0, fadeImage->GetAlpha());

	return false;
}

bool SceneManager::FadeOutColor(float t, function<void()> func, int flag)
{
	if (this->flag != flag)
	{
		fadeImage->SetAlpha(0.f);
		this->flag = flag;
	}

	fadeImage->SetAlpha(fadeImage->GetAlpha() + t);

	if (fadeImage->GetAlpha() >= 1)
	{
		func();
	}
	IMAGEMANAGER->CenterRender(fadeImage, WINSIZE_X / 2 + IMAGEMANAGER->GetCameraPosition().x, WINSIZE_Y / 2 + IMAGEMANAGER->GetCameraPosition().y, { 255,255,255,fadeImage->GetAlpha() }, 2, 2, 0);

	return false;
}
