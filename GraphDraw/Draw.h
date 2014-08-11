#include "stdafx.h"
#include "math.h"

class Draw
{
	public:
		Draw();
		void DDALineDraw(CPoint point1, CPoint point2, int color, CWnd *fWnd);
		void MiddlePointLineDraw(CPoint point1, CPoint point2, int color, CWnd *fWnd);
		void BresenhamLineDraw(CPoint point1,CPoint point2, int color, CWnd *fWnd);
		void MiddleCircleDraw(CPoint point, int r, int color, CWnd *fWnd);
		void BresenhamCircleDraw(CPoint point, int r, int color, CWnd *fWnd);
		void MiddleEllipseDraw(CPoint point, int a, int b, int color, CWnd *fWnd);
	private:
		bool LineDirection(CPoint point1, CPoint point2);
		void SmallerXFirst(CPoint &point1, CPoint &point2);
		void SmallerYFirst(CPoint &point1, CPoint &point2);
		void CirclePoints(CPoint sPoint, CPoint cPoint, int color, CWnd *fWnd);
		void EllipsePoints(CPoint sPoint, CPoint cPoint, int color, CWnd *fWnd);
};