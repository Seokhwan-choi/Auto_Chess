#pragma once
//--------------------------------------------
// author : ������  date : 2019 - 03 - 22
//--------------------------------------------
#ifndef UI_H
#define UI_H

//* ���������� ����
namespace ACHESSGUI
{
	//-------------------------------------
    // ���� ����
	class WidgetCallBack;
	class WidgetFactory;

	//-------------------------------------
	//* UI ��Ÿ��
	//* ��Ʈ���� || �� �̿��Ͽ� ���
	enum class UIStyle : int
	{
		WRITE,       // ���� 
		DRAW,        // �׸���
		INTERECTION, // ��ȣ�ۿ�
	};

	//-------------------------------------
	//* ��� UI ��ü�� ����ڿ��� �����ϴ� �������̽� 
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

		//* ���丮�������� ���� ����
		friend class WidgetFactory;
		Widget() {}
		virtual ~Widget() {}

	public:


	};

	//-------------------------------------
	//* Widget�� �����ϱ����� ���丮 
	class WidgetFactory
	{
	public:
		WidgetFactory() {}
		virtual ~WidgetFactory() {}
	};

	//-------------------------------------
	//* ��� Widget�� Call Back �Լ��� �����ϱ����� �Ŵ���
	class WidgetCallBack
	{
	public:
		WidgetCallBack() {}
		virtual ~WidgetCallBack() {}
	};


#define ENDOFGUI 
}// !End of GUI
#endif // !UI_H