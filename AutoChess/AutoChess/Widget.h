#pragma once
//--------------------------------------------
// author : 유동현  date : 2019 - 03 - 22
//--------------------------------------------
#ifndef UI_H
#define UI_H

//* 유동현님의 제공
namespace ACHESSGUI
{
	//-------------------------------------
    // 전방 선언
	class WidgetCallBack;
	class WidgetFactory;

	//-------------------------------------
	//* UI 스타일
	//* 비트연산 || 을 이용하여 사용
	enum class UIStyle : int
	{
		WRITE,       // 쓰기 
		DRAW,        // 그리기
		INTERECTION, // 상호작용
	};

	//-------------------------------------
	//* 모든 UI 객체가 사용자에게 제공하는 인터페이스 
	class Widget
	{
	protected:
		string mName;
		string mDescription;
		UIStyle mStyle;
		Vector2 mSize;
		Figure::FloatRect mRect;

		int mMaxWriteWidth;
		int mMaxWriteHeight;

		Widget* mParent;
		vector<Widget*>mChindList;

		//* 팩토리내에서만 생성 가능
		friend class WidgetFactory;
		Widget() {}
		virtual ~Widget() {}

	public:


	};

	//-------------------------------------
	//* Widget을 생성하기위한 팩토리 
	class WidgetFactory
	{
	public:
		WidgetFactory() {}
		virtual ~WidgetFactory() {}
	};

	//-------------------------------------
	//* 모든 Widget의 Call Back 함술를 관리하기위한 매니저
	class WidgetCallBack
	{
	public:
		WidgetCallBack() {}
		virtual ~WidgetCallBack() {}
	};


#define ENDOFGUI 
}// !End of GUI
#endif // !UI_H