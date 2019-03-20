#include "stdafx.h"
#include "Figure.h"

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


/**************************************************************************************************
## FloatEllipse ##
**************************************************************************************************/

Figure::FloatEllipse::FloatEllipse()
	:origin(), radius(0.f) {}

Figure::FloatEllipse::FloatEllipse(const float & x, const float & y, const float & radius)
	: origin(x, y), radius(radius) {}

Figure::FloatEllipse::FloatEllipse(const Vector2 & origin, const float & radius)
	: origin(origin), radius(radius) {}
/**************************************************************************************************
## TagLine ##
**************************************************************************************************/
Figure::TagLine::TagLine(const Vector2& start, const Vector2& end)
	: start(start), end(end) {}
//�߽� ���� ���� �������� line����
Figure::TagLine::TagLine(const Vector2& start,const float& angle,const float& dist)
	:start(start)
{
	end.x = cosf(angle) * dist;
	end.y = -sinf(angle) * dist;
}


/****************************************************************************************************
## IntersectAABBAABB ##
@@ FloatRect* rc1 : ��Ʈ 1
@@ FloatRect* rc2 : ��Ʈ 2

@@ return bool : �浿 ���� 

ȸ������ ���� FloatRect�浹 �˻� �� ��� �� ��ȯ 
*****************************************************************************************************/
inline bool Figure::IntersectAABBAABB(const FloatRect* const rc1, const FloatRect* const rc2)
{
	if (rc1->right < rc2->left || rc1->left > rc2->right) return false;
	if (rc1->bottom < rc2->top || rc1->top > rc2->bottom) return false;
	return true;
}

/****************************************************************************************************
## Vector2InRect ##
@@ FloatRect* rc : ��Ʈ 
@@ Vector2* pt : ��ǥ 
*****************************************************************************************************/
inline bool Figure::Vector2InRect(const FloatRect * const rc, const Vector2 * const pt)
{
	if (rc->left > pt->x)return false;
	if (rc->right < pt->x)return false;
	if (rc->top > pt->y)return false;
	if (rc->bottom < pt->y)return false;
	return false;
}

/****************************************************************************************************
## IntersectEllipseEllipse ##
@@ FloatEllipse* ellipse1 : ��
@@ FloatEllipse* ellipse2 : �� 

@@ return bool : �浹 ��� �� 

��,�� �浹�˻��� ��� �� ��ȯ 
*****************************************************************************************************/
inline bool Figure::IntersectEllipseToEllipse(const FloatEllipse * const ellipse1, const FloatEllipse * const ellipse2)
{
	Vector2 dirVector;
	//dirVector = ellipse1->origin - ellipse2->origin;
	dirVector.x = ellipse1->origin.x - ellipse2->origin.x;
	dirVector.y = ellipse1->origin.y - ellipse2->origin.y;
	float length = Vector2::Length(&dirVector);

	if (length > ellipse1->radius + ellipse2->radius)
		return false;

	return true;
}

/****************************************************************************************************
## IntersectLineToLine ##
@@ Vector2* pCollision : �浹 ���� ��ȯ ��
@@ TagLine lineA : �� A
@@ TagLine lineB : �� B

@@ return bool : �浹 ��� �� 
*****************************************************************************************************/
bool Figure::IntersectLineToLine(Vector2 *const pCollision,const TagLine& lineA,const TagLine& lineB)
{
	float uA = ((lineB.end.x - lineB.start.x)*(lineA.start.y - lineB.start.y) - (lineB.end.y - lineB.start.y)*(lineA.start.x - lineB.start.x)) / ((lineB.end.y - lineB.start.y)*(lineA.end.x - lineA.start.x) - (lineB.end.x - lineB.start.x)*(lineA.end.y - lineA.start.y));
	float uB = ((lineA.end.x - lineA.start.x)*(lineA.start.y - lineB.start.y) - (lineA.end.y - lineA.start.y)*(lineA.start.x - lineB.start.x)) / ((lineB.end.y - lineB.start.y)*(lineA.end.x - lineA.start.x) - (lineB.end.x - lineB.start.x)*(lineA.end.y - lineA.start.y));

	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

		if (pCollision)
		{
			pCollision->x = lineA.start.y + (uA * (lineA.end.y - lineA.start.y));
			pCollision->y = lineA.start.x + (uA * (lineA.end.x - lineA.start.x));
		}
		return true;
	}
	return false;
}

/****************************************************************************************************
## IntersectLineToRect ##
@@ Vector2* pCollision : �浹 ���� ��ȯ�� 
@@ TagLine line : �� 
@@ FloatRect rc : ��Ʈ 

@@ return bool : �浿 ��� �� 
*****************************************************************************************************/
bool Figure::IntersectLineToRect(Vector2 *const pCollision,const TagLine& line,const FloatRect& rc)
{
	Vector2 leftTop((rc.left), (rc.top));
	Vector2 leftBottom((rc.left), (rc.bottom));
	Vector2 rightTop((rc.right), (rc.top));
	Vector2 rightBottom((rc.right), (rc.bottom));
	//#   1	  #
	//4		  2
	//#   3   #
	if (IntersectLineToLine(pCollision, line, TagLine(leftTop, rightTop)))
		return true;
	if (IntersectLineToLine(pCollision, line, TagLine(rightTop, rightBottom)))
		return true;
	if (IntersectLineToLine(pCollision, line, TagLine(leftBottom, rightBottom)))
		return true;
	if (IntersectLineToLine(pCollision, line, TagLine(leftTop, leftBottom)));

	return false;
}