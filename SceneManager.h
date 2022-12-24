#pragma once
#include "singleton.h"
#include "Scene.h"
class SceneManager : public Singleton<SceneManager>
{
public:
	Scene* m_curScene;
	Scene* m_nextScene;
	CImage* fadeImage;
	int flag;
	std::map<std::string, Scene*> m_sceneList;

	SceneManager();
	~SceneManager();
public:
	void Init();
	void Update();
	void Render();
	void Release();

	void AddScene(std::string key, Scene* scene);
	void ChangeScene(std::string key);

	bool FadeIn(float t, function<void()> func, int flag);
	bool FadeOut(float t, function<void()> func, int flag);
};

#define SCENEMANAGER SceneManager::GetInstance()