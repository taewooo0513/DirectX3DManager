#pragma once
#include "singleton.h"
#include "Scene.h"
class SceneManager : public singleton<SceneManager>
{
public:
	Scene* NowScene = nullptr, * NextScene = nullptr;
	map<string, Scene*>m_scene;
	SceneManager();
	~SceneManager();
public:
	void AddScene(string key, Scene* scene);
	void ChangeScene(string key);
	void Update();
	void Render();
	void Release();
};

#define SCENE SceneManager::GetInstance()