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
	vector<vector<int>> m_tiles;
	bool m_isMenuActive;
	bool m_isInvenActive;

	SceneManager();
	~SceneManager();
public:
	void Init();
	void Update();
	void Render();
	void UIRender();
	void Release();

	void AddScene(std::string key, Scene* scene);
	void ChangeScene(std::string key);

	bool FadeIn(float t, function<void()> func, int flag);
	bool FadeInColor(float t, function<void()> func, int flag);

	bool FadeOut(float t, function<void()> func, int flag);

	void SetMenuActive(bool active) { m_isMenuActive = active; }
	bool GetMenuActive() { return m_isMenuActive; }
	void SetInvenActive(bool active) { m_isInvenActive = active; }
	bool GetInvenActive() { return m_isInvenActive; }

	CImage* GetPadeImage() { return fadeImage; }
};

#define SCENEMANAGER SceneManager::GetInstance()