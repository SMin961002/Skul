#include "stdafx.h"
#include "SceneManager.h"
#include "LobbyScene.h"
#include "MapToolScene.h"
#include "MapToolMapSelectScene.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::Init()
{
	AddScene("LobbyScene", new LobbyScene);
	AddScene("MapToolMapSelectScene", new MapToolMapSelectScene);
	AddScene("MapToolScene",new MapToolScene);
	flag = 0;
	// ���̵��ξƿ� �Ҷ� �ٸ��÷����̸� ���İ��� �ʱ�ȭ����
	// �ʱ�ȭ��������ϴµ� ��� �ؾ����� ���� �ص�

	//���̵��� �ƿ� �������
	//���� �̹��������ϱ� �ּ�ó���ص���
	//fadeImage = IMAGEMANAGER->AddImage("fadeImage",L"fadeImage"); 
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

void SceneManager::Release()
{
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
	cout << "�̹� ���� ������� ����";
}

void SceneManager::ChangeScene(std::string key)
{
	auto find = m_sceneList.find(key);
	if (find != m_sceneList.end())
	{
		m_nextScene = find->second;
		return;
	}
	cout << "���� ���� key :" << key;
}

bool SceneManager::FadeIn(float t, function<void()> func, int flag)
{
	if (this->flag != flag)
	{
		fadeImage->SetAlpha(1.f);
		this->flag = flag;
	}
	else
	{
		fadeImage->SetAlpha(fadeImage->GetAlpha() - t);
	}

	if (fadeImage->GetAlpha() <= 0)
	{
		func();
		return true;
	}
	//���⼭ ����������ϴµ� ���� ������ ���� �ȸ������
	//fadeImage
	return false;
}

bool SceneManager::FadeOut(float t, function<void()> func, int flag)
{
	if (this->flag != flag)
	{
		fadeImage->SetAlpha(0.f);
		this->flag = flag;
	}
	else
	{
		fadeImage->SetAlpha(fadeImage->GetAlpha() + t);
	}

	if (fadeImage->GetAlpha() >= 1)
	{
		func();
		return true;
	}
	//���⼭ ����������ϴµ� ���� ������ ���� �ȸ������
	//fadeImage
	return false;
}
