#include "stdafx.h"
#include "SceneManager.h"

#include "Scene.h"
void SceneManager::Update()
{
	SwapScene(currentScene->Changescene());
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
	if (st != "")
	{
		SetCurrentScene(st);
	}
}

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
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
		currentScene = scenePool.find(st)->second;
		currentScene->Init();
	}
}
