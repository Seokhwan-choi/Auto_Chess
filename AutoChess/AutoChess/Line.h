#pragma once
/****************************************************************************
## Figure::Line ##
@@ Author : ±Ç¼ø¿ì , Date : 2019.03.19
*****************************************************************************/
namespace Figure
{
	class Line final
	{
	private:
		enum { MaxRayRange = 1000 };
	public:
		Vector2 start;
		Vector2 end;

		Line() = delete;
		explicit Line(const Vector2& start, const Vector2& end);
		explicit Line(const Vector2& start, const float& angle, const float& dist = (float)MaxRayRange);
	};
}