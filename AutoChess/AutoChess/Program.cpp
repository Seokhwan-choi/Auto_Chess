#include "stdafx.h"
#include "Program.h"

#include "Transform.h"
Program::Program()
{
	mRoot = new Transform(Vector2(_WinSizeX / 2, _WinSizeY / 2),Vector2(100,100),Pivot::Center);
	mChild = new Transform(Vector2(_WinSizeX / 2 - 200, _WinSizeY / 2), Vector2(50, 50), Pivot::Center);
	mChild->AttachTo(mRoot);
	mChildSibling = new Transform(Vector2(_WinSizeX / 2 - 200, _WinSizeY / 2 - 200),Vector2(50, 50), Pivot::Center);
	mChildSibling->AttachTo(mRoot);
	mChildSibling2 = new Transform(Vector2(_WinSizeX / 2 - 200, _WinSizeY / 2 - 400), Vector2(50, 50), Pivot::Center);
	mChildSibling2->AttachTo(mRoot);
	mChild2 = new Transform(Vector2(_WinSizeX / 2 - 400, _WinSizeY / 2 - 200), Vector2(50, 50), Pivot::Center);
	mChild2->AttachTo(mChildSibling);

	mTransformList.push_back(mRoot);
	mTransformList.push_back(mChild);
	mTransformList.push_back(mChildSibling);
	mTransformList.push_back(mChildSibling2);
	mTransformList.push_back(mChild2);

	mTarget = mRoot;
}


Program::~Program()
{
	for (UINT i = 0; i < mTransformList.size(); ++i)
		SafeDelete(mTransformList[i]);
	mTransformList.clear();
}

void Program::Init()
{
	
}

void Program::Release()
{
}

void Program::Update()
{
	if (_Input->GetKeyDown(VK_LBUTTON))
	{
		for (UINT i = 0; i < mTransformList.size(); ++i)
		{
			if (Figure::Vector2InRect(&mTransformList[i]->GetRect(), &_Input->GetMousePosition()))
			{
				mTarget = mTransformList[i];
				break;
			}
		}
	}

	if (_Input->GetKey('A'))
		mTarget->Move(Vector2(-3.f, 0.f));
	else if (_Input->GetKey('D'))
		mTarget->Move(Vector2(3.f, 0.f));
	if (_Input->GetKey('W'))
		mTarget->Move(Vector2(0.f, -3.f));
	else if (_Input->GetKey('S'))
		mTarget->Move(Vector2(0.f, 3.f));
}

void Program::Render()
{
	_D2DRenderer->BeginRender();
	{
		_D2DRenderer->RenderText(10, 10, L"Red : 부모자식관계", 30, D2DRenderer::DefaultBrush::White);
		_D2DRenderer->RenderText(10, 60, L"Blue : 형제관계", 30, D2DRenderer::DefaultBrush::White);
		mRoot->RenderAll();
		_D2DRenderer->FillRectangle(mTarget->GetRect(), D2DRenderer::DefaultBrush::White,false);
	}
	_D2DRenderer->EndRender();
}
