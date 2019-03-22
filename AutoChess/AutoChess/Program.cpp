#include "stdafx.h"
#include "Program.h"

#include "Transform.h"
Program::Program()
{
	
}


Program::~Program()
{

}

void Program::Init()
{
	_SceneManager->AddScene("test", new TestScene);
	_SceneManager->AddScene("test1", new TestScene1);
	_SceneManager->SetCurrentScene("test");
}

void Program::Release()
{

}

void Program::Update()
{
	

	_SceneManager->Update();
}

void Program::Render()
{
	_D2DRenderer->BeginRender();
	{
		_SceneManager->Render();
	}
	_D2DRenderer->EndRender();
}
