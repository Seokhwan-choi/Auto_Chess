#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"

void SceneManager::Update()
{
	currentScene->Update();
}

void SceneManager::Render()
{
	currentScene->Render();
}

void SceneManager::Release()
{
	for (auto &a : scenePool)
	{
		a.second->Release();
		SafeDelete(a.second);
	}
}

void SceneManager::SwapScene(const string st)
{
	SetCurrentScene(st);
}

void SceneManager::AddScene(const string st, Scene * sc)
{
	scenePool.insert(make_pair(st, sc));
}

void SceneManager::SetCurrentScene(const string st)
{
	if (!scenePool.count(st))
	{
		assert(SUCCEEDED(E_FAIL));
	}
	else
	{
		if (currentScene != nullptr)
		{
			currentScene->Release();
		}
		currentScene = scenePool.find(st)->second;
		currentScene->Init();
	}
}
