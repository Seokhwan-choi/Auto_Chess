#include "stdafx.h"
#include "FloatRect.h"


/**************************************************************************************************
## FloatRect::FloatRect ##
**************************************************************************************************/
Figure::FloatRect::FloatRect()
	:left(0.f), top(0.f), right(0.f), bottom(0.f) {}

Figure::FloatRect::FloatRect(const float & left, const float & top, const float & right, const float & bottom)
	: left(left), top(0.f), right(0.f), bottom(0.f) {}

Figure::FloatRect::FloatRect(const int & left, const int & top, const int & right, const int & bottom)
	: left((float)left), top((float)top), right((float)right), bottom((float)bottom) {}

Figure::FloatRect::FloatRect(const Vector2 & pos, const Vector2 & size, const Pivot::Enum & pivot)
{
	*this = FloatRect::FloatRectByPivot(pos, size, pivot);
}

Figure::FloatRect::FloatRect(const RECT & rc)
	:left((float)rc.left), top((float)rc.top), right((float)rc.right), bottom((float)rc.bottom) {}

/**************************************************************************************************
## FloatRect::GetRect ##
@@ return RECT : LONG�� RECT�� ��ȯ �� ��ȯ
**************************************************************************************************/
const RECT Figure::FloatRect::GetRect()
{
	return { (LONG)left,(LONG)top,(LONG)right,(LONG)bottom };
}
/**************************************************************************************************
## FloatRect::Update ##
@@ Vector2 pos : ��ǥ
@@ Vector2 size : ������
@@ Pivot::Enum pivot : �Ǻ�

FLOATRECT ���� ����
**************************************************************************************************/
void Figure::FloatRect::Update(const Vector2 & pos, const Vector2 & size, const Pivot::Enum & pivot)
{
	*this = FloatRect::FloatRectByPivot(pos, size, pivot);
}
/**************************************************************************************************
## FloatRect::Move ##
@@ Vector2 moveValue : �̵����� * �̵���
**************************************************************************************************/
void Figure::FloatRect::Move(const Vector2 & moveValue)
{
	left += moveValue.x;
	right += moveValue.x;
	top += moveValue.y;
	bottom += moveValue.y;
}

/**************************************************************************************************
## FloatRect::operator = ## 
@@ RECT rc : RECT 
***************************************************************************************************/
Figure::FloatRect Figure::FloatRect::operator=(const RECT& rc)
{
	this->left = (float)rc.left;
	this->right = (float)rc.right;
	this->top = (float)rc.top;
	this->bottom = (float)rc.bottom;
	return *this;
}

/**************************************************************************************************
## Static FloatRect::FloatRectByPivot ##
@@ Vector2 pos : ��ǥ
@@ Vector2 size : ũ��
@@ Pivot::Enum pivot : �Ǻ�

@@ return FloatRect : �Ǻ� �������� ������ ��Ʈ
**************************************************************************************************/
inline Figure::FloatRect Figure::FloatRect::FloatRectByPivot(const Vector2 & pos, const Vector2 & size, const Pivot::Enum & pivot)
{
	FloatRect result;
	switch (pivot)
	{
	case Pivot::LeftTop:
		result.left = pos.x;
		result.top = pos.y;
		result.right = pos.x + size.x;
		result.bottom = pos.y + size.y;
		return result;
	case Pivot::Center:
		result.left = pos.x - size.x / 2.f;
		result.top = pos.y - size.y / 2.f;
		result.right = pos.x + size.x / 2.f;
		result.bottom = pos.y + size.y / 2.f;
		return result;
	case Pivot::Bottom:
		result.left = pos.x - size.x / 2.f;
		result.top = pos.y - size.y;
		result.right = pos.x + size.x / 2.f;
		result.bottom = pos.y;
		return result;
	}
	return result;
}