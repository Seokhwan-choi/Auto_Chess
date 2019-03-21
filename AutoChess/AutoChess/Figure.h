#pragma once
#include "FloatRect.h"
#include "FloatEllipse.h"
#include "Line.h"
/****************************************************************************
## Figure::Collision ##
@@ Author : ±Ç¼ø¿ì , Date : 2019.03.19
*****************************************************************************/
namespace Figure
{
	static inline FloatRect RectMakePivot(const Vector2& pos, const Vector2& size, const Pivot::Enum& pivot);
	static inline bool IntersectRectToRect(const FloatRect* const rc1, const FloatRect*const rc2);
	static inline bool Vector2InRect(const  FloatRect* const rc, const Vector2* const pt);
	static inline bool Vector2InEllipse(const Vector2* const pVector, const FloatEllipse* const pEllipse);
	static inline bool IntersectEllipseToEllipse(const  FloatEllipse* const ellipse1, const FloatEllipse* const ellipse2);
	static inline bool IntersectLineToLine(Vector2 *const pCollision,const Line& lineA,const Line& lineB);
	static inline bool IntersectLineToRect(Vector2*const pCollision, const Line& line,const FloatRect& rc);
	static inline bool IntersectRectToEllipse(const FloatRect*const pRect, const FloatEllipse* const pEllipse);
}