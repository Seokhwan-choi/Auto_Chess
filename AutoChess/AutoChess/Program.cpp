#include "stdafx.h"
#include "Program.h"

#include "Transform.h"
Program::Program()
{
	mRoot = new Transform(Vector2(_WinSizeX / 2, _WinSizeY / 2),Vector2(100,100),Pivot::Center);
	mTransformList.push_back(mRoot);

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
	_SceneManager->AddScene("test", new TestScene);
	_SceneManager->AddScene("test1", new TestScene1);
	_SceneManager->SetCurrentScene("test");
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
	if (_Input->GetKey(VK_LBUTTON))
	{
		if (mTarget)
		{
			mTarget->SetWorldPosition(_Input->GetMousePosition());
		}
	}
	else if (_Input->GetKeyDown('E'))
	{
		for (UINT i = 0; i < mTransformList.size(); ++i)
		{
			if (mTransformList[i] == mTarget && mTransformList[i] != mRoot)
			{
				SafeDelete(mTransformList[i]);
				mTransformList.erase(mTransformList.begin() + i);
				mTarget = mRoot;
				break;
			}
		}
	}
	else if (_Input->GetKeyDown('Q'))
	{
		//int randomIndex = Math::Random(0, mTransformList.size() - 1);
		Vector2 randomPos = Vector2(Math::Random(0, _WinSizeX), Math::Random(0, _WinSizeY));
		Vector2 randomSize = Vector2(Math::Random(30, 80), Math::Random(30, 80));
		Transform* newT = new Transform(randomPos, randomSize, Pivot::Center);
		newT->AttachTo(mTarget);
		mTransformList.push_back(newT);
	}

	if (_Input->GetKey('A'))
		mTarget->Move(Vector2(-3.f, 0.f));
	else if (_Input->GetKey('D'))
		mTarget->Move(Vector2(3.f, 0.f));
	if (_Input->GetKey('W'))
		mTarget->Move(Vector2(0.f, -3.f));
	else if (_Input->GetKey('S'))
		mTarget->Move(Vector2(0.f, 3.f));

	_SceneManager->Update();
}

void Program::Render()
{
	_D2DRenderer->BeginRender();
	{
		for (UINT i = 0; i < mTransformList.size(); ++i)
			mTransformList[i]->RenderHierarchy();
		_D2DRenderer->FillRectangle(mTarget->GetRect(), D2DRenderer::DefaultBrush::White,false);

		_D2DRenderer->RenderText(10, 10, L"Red : �θ��ڽİ���", 30, D2DRenderer::DefaultBrush::White);
		_D2DRenderer->RenderText(10, 60, L"Blue : ��������", 30, D2DRenderer::DefaultBrush::White);
		_D2DRenderer->RenderText(10, 110, L"Q : �ش��忡 �ڽ� ����", 30, D2DRenderer::DefaultBrush::White);
		_D2DRenderer->RenderText(10, 160, L"E : �ش� ��� ����", 30, D2DRenderer::DefaultBrush::White);
	
		_SceneManager->Render();
	}
	_D2DRenderer->EndRender();
}
