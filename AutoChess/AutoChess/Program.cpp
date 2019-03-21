#include "stdafx.h"
#include "Program.h"

#include "Transform.h"
Program::Program()
{
	mRoot = new Transform(Vector2(_WinSizeX / 2, _WinSizeY / 2), Vector2(50, 50));
	mChild = new Transform(mRoot->GetWorldPosition() - Vector2(200, 0), Vector2(100, 100));
	mChild->AttachTo(mRoot);
}


Program::~Program()
{
	SafeDelete(mChild);
	SafeDelete(mRoot);
	//mRoot->ReleaseParent();
	//mChild->ReleaseParent();
}

void Program::Init()
{
	
}

void Program::Release()
{
}

void Program::Update()
{
	if (_Input->GetKey('D'))
		mRoot->Move(Vector2(3.f, 0.f));
	if (_Input->GetKey('A'))
		mRoot->Move(Vector2(-3.f, 0.f));
}

void Program::Render()
{
	_D2DRenderer->BeginRender();
	{
		mRoot->Render(D2DRenderer::DefaultBrush::Red);
		mChild->Render(D2DRenderer::DefaultBrush::Blue);
	}
	_D2DRenderer->EndRender();
}
