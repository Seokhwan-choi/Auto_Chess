#include "stdafx.h"
#include "TestScene.h"


TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}

void TestScene::Init()
{
	meme = _ImageManager->AddImage("meme", PathResources(L"meme.png"));

}

void TestScene::Update()
{
	if (_Input->GetKeyDown(VK_F1))
	{
		_SceneManager->SwapScene("test1");
	}
}

void TestScene::Render()
{
	meme->Render(50, 50, Pivot::LeftTop, false);
}

void TestScene::Release()
{
}
