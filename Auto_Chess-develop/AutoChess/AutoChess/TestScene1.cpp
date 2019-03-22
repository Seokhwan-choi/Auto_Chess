#include "stdafx.h"
#include "TestScene1.h"


TestScene1::TestScene1()
{
}


TestScene1::~TestScene1()
{
}

void TestScene1::Init()
{
	meme2 = _ImageManager->AddImage("meme2", PathResources(L"meme2.png"));
}

void TestScene1::Update()
{
}

void TestScene1::Render()
{
	meme2->Render(50, 50, Pivot::LeftTop, false);
}

void TestScene1::Release()
{
}
