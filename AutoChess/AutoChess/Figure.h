#pragma once
/****************************************************************************
## Figure ##
@@ Author : ±Ç¼ø¿ì , Date : 2019.03.19
*****************************************************************************/
namespace Figure
{
	class FloatRect final
	{
	public:
		float left;
		float top;
		float right;
		float bottom;
	public:
		FloatRect();
		explicit FloatRect(const float& left, const float& top, const float& right, const float& bottom);
		explicit FloatRect(const int& left, const int& top, const int& right, const int& bottom);
		explicit FloatRect(const Vector2& pos, const Vector2& size, const Pivot::Enum& pivot);
		explicit FloatRect(const RECT& rc);

		const RECT GetRect();
		void Update(const Vector2& pos, const Vector2& size, const Pivot::Enum& pivot);
		void Move(const Vector2& moveValue);
	public:
		static inline FloatRect FloatRectByPivot(const Vector2& pos, const Vector2& size, const Pivot::Enum& pivot);
	};

	class FloatEllipse final
	{
	public:
		Vector2 origin;
		float radius;
	public:
		FloatEllipse();
		explicit FloatEllipse(const float& x, const float& y, const float& radius);
		explicit FloatEllipse(const Vector2& origin, const float& radius);
	};

	struct TagLine final
	{
	private:
		enum { MaxRayRange = 1000 };
	public:
		Vector2 start;
		Vector2 end;

		TagLine() = delete;
		explicit TagLine(const Vector2& start,const Vector2& end);
		explicit TagLine(const Vector2& start,const float& angle,const float& dist = (float)MaxRayRange);
	};

	static inline bool IntersectAABBAABB(const FloatRect* const rc1, const FloatRect*const rc2);
	static inline bool Vector2InRect(const  FloatRect* const rc, const Vector2* const pt);
	static inline bool IntersectEllipseToEllipse(const  FloatEllipse* const ellipse1, const FloatEllipse* const ellipse2);
	static inline bool IntersectLineToLine(Vector2 *const pCollision,const TagLine& lineA,const TagLine& lineB);
	static inline bool IntersectLineToRect(Vector2*const pCollision, const TagLine& line,const FloatRect& rc);
}