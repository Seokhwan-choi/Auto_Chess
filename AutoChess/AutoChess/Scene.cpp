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
	uPdPool.update();
}

void Scene::Render()
{
	mRdPool.Render();
}

void Scene::Release()
{

}
