#include "DXUT.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::AddScene(string key, Scene* scene)
{
	m_scene[key] = scene;
}

void SceneManager::ChangeScene(string key)
{
	NextScene = m_scene[key];
}

void SceneManager::Update()
{
	if (NextScene)
	{
		if (NowScene)
			NowScene->Release();
		NowScene = NextScene;
		NextScene = nullptr;
		NowScene->Init();
	}
	if (NowScene)
	{
		NowScene->Update();
	}
}

void SceneManager::Render()
{
	if (NowScene)
	{
		NowScene->Render();
	}
}

void SceneManager::Release()
{
	if (NowScene)
	{
		NowScene->Release();
	}
	for (auto iter : m_scene)
	{
		SAFE_DELETE(iter.second);
	}
	m_scene.clear();
}
