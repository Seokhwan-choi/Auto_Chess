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
@@ return RECT : LONG형 RECT로 변환 후 반환
**************************************************************************************************/
const RECT Figure::FloatRect::GetRect()
{
	return { (LONG)left,(LONG)top,(LONG)right,(LONG)bottom };
}
/**************************************************************************************************
## FloatRect::Update ##
@@ Vector2 pos : 좌표 
@@ Vector2 size : 사이즈 
@@ Pivot::Enum pivot : 피봇 

FLOATRECT 정보 갱신
**************************************************************************************************/
void Figure::FloatRect::Update(const Vector2 & pos, const Vector2 & size, const Pivot::Enum & pivot)
{
	*this = FloatRect::FloatRectByPivot(pos, size, pivot);
}
/**************************************************************************************************
## FloatRect::Move ##
@@ Vector2 moveValue : 이동방향 * 이동량 
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
@@ Vector2 pos : 좌표 
@@ Vector2 size : 크기 
@@ Pivot::Enum pivot : 피봇 

@@ return FloatRect : 피봇 기준으로 생성된 렉트 
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
//중심 점과 각도 기준으로 line생성
Figure::TagLine::TagLine(const Vector2& start,const float& angle,const float& dist)
	:start(start)
{
	end.x = cosf(angle) * dist;
	end.y = -sinf(angle) * dist;
}


/****************************************************************************************************
## IntersectAABBAABB ##
@@ FloatRect* rc1 : 렉트 1
@@ FloatRect* rc2 : 렉트 2

@@ return bool : 충동 여부 

회전값이 없는 FloatRect충돌 검사 후 결과 값 반환 
*****************************************************************************************************/
inline bool Figure::IntersectAABBAABB(const FloatRect* const rc1, const FloatRect* const rc2)
{
	if (rc1->right < rc2->left || rc1->left > rc2->right) return false;
	if (rc1->bottom < rc2->top || rc1->top > rc2->bottom) return false;
	return true;
}

/****************************************************************************************************
## Vector2InRect ##
@@ FloatRect* rc : 렉트 
@@ Vector2* pt : 좌표 
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
@@ FloatEllipse* ellipse1 : 원
@@ FloatEllipse* ellipse2 : 원 

@@ return bool : 충돌 결과 값 

원,원 충돌검사후 결과 값 반환 
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
@@ Vector2* pCollision : 충돌 지점 반환 값
@@ TagLine lineA : 선 A
@@ TagLine lineB : 선 B

@@ return bool : 충돌 결과 값 
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
@@ Vector2* pCollision : 충돌 지점 반환값 
@@ TagLine line : 선 
@@ FloatRect rc : 렉트 

@@ return bool : 충동 결과 값 
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