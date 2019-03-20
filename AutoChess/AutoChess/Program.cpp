#include "stdafx.h"
#include "Program.h"


Program::Program()
{
	mImage = _ImageManager->AddImage("asd", PathResources(L"TestHouse.png"));
	mFrameImage = _ImageManager->AddFrameImage("asdasd", PathResources(L"TestPlayer.png"),9,4);
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

}

void Program::Render()
{
	_D2DRenderer->BeginRender();
	{
		mImage->SetAlpha(0.3f);
		mImage->SetAngle(45.f);
		mImage->Render(_WinSizeX / 2, _WinSizeY / 2, Pivot::Center, false);

		mFrameImage->SetSize(mFrameImage->GetFrameSize(0));
		mFrameImage->SetScale(2.f);
		mFrameImage->FrameRender(_WinSizeX / 2, _WinSizeY / 2, 0, 0, Pivot::Center, false);

		_D2DRenderer->DrawRectangle(Figure::FloatRect(Vector2((int)_WinSizeX / 2, (int)_WinSizeY / 2), Vector2(50, 50), Pivot::Center),
			D2DRenderer::DefaultBrush::Red, false);
	}
	_D2DRenderer->EndRender();
}
