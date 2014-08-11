#include "Draw.h"

Draw::Draw()
{
}

bool Draw::LineDirection(CPoint point1, CPoint point2)
{
	if( (abs(point2.y - point1.y) <= abs(point2.x - point1.x)) && (point1.x > point2.x) )
		return true;
	else if( (abs(point2.y - point1.y) > abs(point2.x - point1.x)) && (point1.y > point2.y) )
		return true;
	return false;
}

void Draw::SmallerXFirst(CPoint &point1, CPoint &point2)
{
	if(point1.x>point2.x)
	{
		CPoint nPoint;
		nPoint = point1;
		point1 = point2;
		point2 = nPoint;
	}
}

void Draw::SmallerYFirst(CPoint &point1, CPoint &point2)
{
	if(point1.y>point2.y)
	{
		CPoint nPoint;
		nPoint = point1;
		point1 = point2;
		point2 = nPoint;
	}
}

void Draw::DDALineDraw(CPoint point1, CPoint point2, int color, CWnd *fWnd)
{
	CDC *pDC = fWnd->GetDC();
	double x,y;
	double dx, dy, k;
	dx = (double)(point2.x - point1.x);
	dy = (double)(point2.y - point1.y);
	if(dx != 0){
		k  = dy / dx;
	}else{
		k = 999;
	}
	if(abs(k) <= 1){
		this->SmallerXFirst(point1, point2);
		x = point1.x;
		y = point1.y;
		for(x = point1.x; x <= point2.x; x++ ){
			pDC->SetPixel(x, int(y + 0.5), color);
			y = y + k;
		}
	}
	if(abs(k) > 1){
		this->SmallerYFirst(point1, point2);
		x = point1.x;
		y = point1.y;
		for(y = point1.y; y <= point2.y; y++ ){
			pDC->SetPixel(int(x + 0.5), y, color);
			if(dx != 0){
				x = x + 1/k;
			}
		}
	}
	fWnd->ReleaseDC(pDC);
}

void Draw::MiddlePointLineDraw(CPoint point1, CPoint point2, int color, CWnd *fWnd)
{
	CDC *pDC = fWnd->GetDC();
	int a, b, d1, d2, d;
	int flag = 0;
	CPoint nPoint;
	this->SmallerXFirst(point1, point2);
	a = point1.y - point2.y;
	b = point2.x - point1.x;
	nPoint = point1;
	if(a < 0)
	{
		flag = 1;	
	}else if(a > 0)
	{
		flag = -1;
		a = -a;
	}
	d = 2 * a + b;
	d1 = 2 * a;
	d2 = 2 * (a + b);
	pDC->SetPixel(nPoint.x, nPoint.y, color);
	while(nPoint.x < point2.x)
	{
		if(d < 0)
		{
			nPoint.x++;
			nPoint.y += flag;
			d += d2;
		}else{
			nPoint.x++;
			d += d1;
		}
		pDC->SetPixel(nPoint.x, nPoint.y, color);
	}
	if(b == 0)
	{
		this->SmallerYFirst(point1, point2);
		nPoint = point1;
		while(nPoint.y < point2.y)
		{
			nPoint.y++;
			pDC->SetPixel(nPoint.x, nPoint.y, color);
		}
	}
	fWnd->ReleaseDC(pDC);
}

void Draw::BresenhamLineDraw(CPoint point1, CPoint point2, int color, CWnd *fWnd)
{
	CDC *pDC = fWnd->GetDC();
	CPoint nPoint;
	int dx, dy, e;
	this->SmallerXFirst(point1, point2);
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	e = -dx;
	nPoint = point1;
	for(int i = 0; i <= dx; i++ )
	{
		pDC->SetPixel(nPoint.x, nPoint.y, color);
		nPoint.x++;
		e = e + 2 * dy;
		if(e >= 0)
		{
			nPoint.y++;
			e = e - 2 * dx;
		}
	}
	if(dx == 0)
	{
		this->SmallerYFirst(point1, point2);
		nPoint.y++;
		pDC->SetPixel(nPoint.x, nPoint.y, color);
	}
	fWnd->ReleaseDC(pDC);
}

void Draw::CirclePoints(CPoint sPoint, CPoint cPoint, int color, CWnd *fWnd)
{
	CDC *pDC = fWnd->GetDC();
	pDC->SetPixel(sPoint.x + cPoint.x, sPoint.y + cPoint.y, color);
	pDC->SetPixel(sPoint.x - cPoint.x, sPoint.y + cPoint.y, color);
	pDC->SetPixel(sPoint.x + cPoint.x, sPoint.y - cPoint.y, color);
	pDC->SetPixel(sPoint.x - cPoint.x, sPoint.y - cPoint.y, color);
	pDC->SetPixel(sPoint.x + cPoint.y, sPoint.y + cPoint.x, color);
	pDC->SetPixel(sPoint.x - cPoint.y, sPoint.y + cPoint.x, color);
	pDC->SetPixel(sPoint.x + cPoint.y, sPoint.y - cPoint.x, color);
	pDC->SetPixel(sPoint.x - cPoint.y, sPoint.y - cPoint.x, color);
	fWnd->ReleaseDC(pDC);
}

void Draw::MiddleCircleDraw(CPoint point, int r, int color, CWnd *fWnd)
{
	CPoint nPoint;
	double d;
	nPoint.x = 0;
	nPoint.y = r;
	d = 1.25 - r;
	this->CirclePoints(point, nPoint, color, fWnd);
	while(nPoint.x <= nPoint.y)
	{
		if(d < 0)
		{
			d += 2 * nPoint.x + 3;
		}else{
			d += 2 * (nPoint.x - nPoint.y) + 5;
			nPoint.y--;
		}
		nPoint.x++;
		this->CirclePoints(point, nPoint, color, fWnd);
	}
}

void Draw::BresenhamCircleDraw(CPoint point, int r, int color, CWnd *fWnd)
{
	CPoint nPoint;
	int p;
	nPoint.x = 0;
	nPoint.y = r;
	p = 3 - 2 * r;
	while(nPoint.x < nPoint.y)
	{
		this->CirclePoints(point, nPoint, color, fWnd);
		if(p < 0)
		{
			p = p + 4 * nPoint.x + 6;
		}else{
			p = p + 4 * (nPoint.x - nPoint.y) + 10;
			nPoint.y -= 1;
		}
		nPoint.x += 1;
	}
	if(nPoint.x = nPoint.y)
	{
		this->CirclePoints(point, nPoint, color, fWnd);
	}
}

void Draw::EllipsePoints(CPoint sPoint, CPoint cPoint, int color, CWnd *fWnd)
{
	CDC *pDC = fWnd->GetDC();
	pDC->SetPixel(sPoint.x + cPoint.x, sPoint.y + cPoint.y, color);
	pDC->SetPixel(sPoint.x - cPoint.x, sPoint.y + cPoint.y, color);
	pDC->SetPixel(sPoint.x + cPoint.x, sPoint.y - cPoint.y, color);
	pDC->SetPixel(sPoint.x - cPoint.x, sPoint.y - cPoint.y, color);
	fWnd->ReleaseDC(pDC);
}

void Draw::MiddleEllipseDraw(CPoint point, int a, int b, int color, CWnd *fWnd)
{
	CPoint nPoint;
	double d1, d2;
	nPoint.x = 0;
	nPoint.y = b;
	d1 = b * b + a * a * (-b + 0.25);
	this->EllipsePoints(point, nPoint, color, fWnd);
	while(b * b * (nPoint.x + 1) < a * a * (nPoint.y - 0.5))
	{
		if(d1 < 0)
		{
			d1 += b * b * (2 * nPoint.x + 3);
			nPoint.x++;
		}else{
			d1 += b * b * (2 * nPoint.x + 3) + a * a * (-2 * nPoint.y + 2);
			nPoint.x++;
			nPoint.y--;
		}
		this->EllipsePoints(point, nPoint, color, fWnd);
	}
	d2 = sqrt(b * (nPoint.x + 0.5)) + a * (nPoint.y - 1) - a * b;
	while(nPoint.y > 0)
	{
		if(d2 < 0)
		{
			d2 += b * b * (2 * nPoint.x + 2) + a * a * (-2 * nPoint.y + 3);
			nPoint.x++;
			nPoint.y--;
		}else{
			d2 += a * a * (-2 * nPoint.y + 3);
			nPoint.y--;
		}
		this->EllipsePoints(point, nPoint, color, fWnd);
	}
}