﻿
/*********************************************************************************
## WinMain ##
@@ Author : 권순우 , Data : 2019-03-20
*********************************************************************************/
#include "stdafx.h"
#include "AutoChess.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	Window::Desc desc;
	desc.appName = L"AutoChess";			//윈도우 이름 
	desc.width = 1600;						//윈도우 가로 길이
	desc.height = 900;						//윈도우 세로 길이 
	desc.instance = hPrevInstance;			//윈도우 hInstance 
	desc.command = nCmdShow;				//윈도우 cmdShow
	desc.handle = NULL;						//윈도우 Handle
	desc.bFullScreen = false;				//전체화면 여부 
	Window::SetDesc(&desc);				
	//타임 시드 초기화 
	srand((UINT)time(0));
	//윈도우 생성 및 메인 루프 
	Window* window = new Window();
	WPARAM wParam = window->Run();
	SafeDelete(window);

	return static_cast<int>(wParam);
}