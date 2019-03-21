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
	
}

void Program::Release()
{
}

void Program::Update()
{
	
		mRoot->Move(Vector2(-3.f, 0.f));
}

void Program::Render()
{
	_D2DRenderer->BeginRender();
	{
		
	}
	_D2DRenderer->EndRender();
}
