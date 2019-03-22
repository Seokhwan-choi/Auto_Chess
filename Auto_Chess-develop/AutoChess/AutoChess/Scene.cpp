#include "stdafx.h"
#include "Scene.h"


Scene::~Scene()
{

}

void Scene::Init()
{

}

void Scene::Update()
{
	mUpdPool.update();
}

void Scene::Render()
{
	mRdPool.Render();
}

void Scene::Release()
{
	mRdPool.Release();
	mUpdPool.Release();
	mOsPool.Release();

}
