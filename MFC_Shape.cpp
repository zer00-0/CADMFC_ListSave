#include "stdafx.h"
#include "MFC_Shape.h"
#include "Data.h"

//List类操作实现

void List::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码

	}
	else
	{
		// TODO: 在此添加加载代码
	}

}

void List::OnDraw(CDC * pDC)
{

}

List * List::Initialize()
{
	List * Linkhead = new(List);
	Linkhead->Nnext = NULL;
	return Linkhead;
}

void List::Insert(List * L, int index, int value)		//插入链表
{

}

void List::Increate(List * L)	//增加链表
{

}

void List::Delete(List * L)		//删除链表
{

}

List * List::Find(List * L)		//查找链表
{
	List * find = NULL;
	return find;
}

void List::DestoryList(List * L)
{

}

void List::Isempty(List * L)
{

}




//void LineList::Serialize(CArchive &ar)
//{
//	if (ar.IsStoring())
//	{
//		ar.WriteCount(m_Index);
//		for (LineList * pNode = linehead; pNode != NULL; pNode = pNode->linenext)
//		{
//			//ASSERT(AfxIsValidAddress(pNode, sizeof(DataList)));
//			ar << pNode->shape;
//		}
//	}
//	else
//	{
//		DWORD nNewCount = ar.ReadCount();
//		//输入类型重载问题
//		//CArchive ar(NULL, CArchive::load);
//
//		LineList * list = new(LineList);
//		DrawShape shape;
//		while (nNewCount--)
//		{
//			shape.Serialize(ar);
//			list->shape = &shape;
//			list->linenext = new(LineList);
//			list = list->linenext;
//		}
//	}
//}


//直线类链表
LineList* LineList::Add(Cline * line)		//（头插法可能方便后续undo）,shape为以申请的空间
{
	this->linenext = new(LineList);			//给新增节点申请空间保存数据
	this->linenext->line = line;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->linenext->linenext = NULL;
	this->linenext->m_Index = this->m_Index++;
	linelast = this->linenext;
	return this->linenext;
}


LineList * LineList::Initialize()			//初始化并返回头结点值
{
	linehead->m_Index = 1;
	linehead->linenext = NULL;
	return linehead;
}

//点链表
DotList* DotList::Add(Cdot * dot)		//尾插法（头插法可能方便后续undo）,shape为以申请的空间
{
	this->dotnext = new(DotList);			//给新增节点申请空间保存数据
	this->dotnext->dot = dot;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->dotnext->dotnext = NULL;
	this->dotnext->m_Index = this->m_Index++;
	dotlast = this->dotnext;
	return this->dotnext;
}


DotList * DotList::Initialize()			//初始化并返回头结点值
{
	dothead->m_Index = 1;
	dothead->dotnext = NULL;
	return dothead;
}


//矩形链表
RectangleList* RectangleList::Add(Crectangle * rectangle)		//头插法（可能方便后续undo）,shape为以申请的空间
{
	this->rectnext = new(RectangleList);			//给新增节点申请空间保存数据
	this->rectnext->rectangle = rectangle;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->rectnext->rectnext = NULL;
	this->rectnext->m_Index = this->m_Index++;
	rectlast = this->rectnext;
	return this->rectnext;
}


RectangleList* RectangleList::Initialize()			//初始化并返回头结点值
{	
	recthead->m_Index = 1;
	recthead->rectnext = NULL;
	return recthead;
}

//圆链表
CircleList* CircleList::Add(Ccircle * circle)		//头插法（可能方便后续undo）,shape为以申请的空间
{
	this->circlenext = new(CircleList);			//给新增节点申请空间保存数据
	this->circlenext->circle = circle;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->circlenext->circlenext = NULL;
	this->circlenext->m_Index = this->m_Index++;
	circlelast = this->circlenext;
	return this->circlenext;
}


CircleList* CircleList::Initialize()			//初始化并返回头结点值
{
	circlehead->m_Index = 1;
	circlehead->circlenext = NULL;
	return circlehead;
}

//圆弧
ArcList* ArcList::Add(Carc * arc)		//头插法（可能方便后续undo）,shape为以申请的空间
{
	this->arcnext = new(ArcList);			//给新增节点申请空间保存数据
	this->arcnext->arc = arc;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->arcnext->arcnext = NULL;
	this->arcnext->m_Index = this->m_Index++;
	arclast = this->arcnext;
	return this->arcnext;
}


ArcList* ArcList::Initialize()			//初始化并返回头结点值
{
	archead->m_Index = 1;
	archead->arcnext = NULL;
	return archead;
}

//多边形链表
PolygonList* PolygonList::Add(Cpolygon * polygon)		//头插法（可能方便后续undo）,shape为以申请的空间
{
	this->polynext = new(PolygonList);			//给新增节点申请空间保存数据
	this->polynext->polygon = polygon;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->polynext->polynext = NULL;
	this->polynext->m_Index = this->m_Index++;
	polygonlast = this->polynext;
	return this->polynext;
}


PolygonList* PolygonList::Initialize()			//初始化并返回头结点值
{
	polygonhead->m_Index = 1;
	polygonhead->polynext = NULL;
	return polygonhead;
}

//椭圆
EllipseList* EllipseList::Add(Cellipse * ellipse)		//头插法（可能方便后续undo）,shape为以申请的空间
{
	this->ellipsenext = new(EllipseList);			//给新增节点申请空间保存数据
	this->ellipsenext->ellipse = ellipse;			//使用DataList类里面的用DrawShape定义的shape保存数据
	this->ellipsenext->ellipsenext = NULL;
	this->ellipsenext->m_Index = this->m_Index++;
	ellipselast = this->ellipsenext;
	return this->ellipsenext;
}


EllipseList* EllipseList::Initialize()			//初始化并返回头结点值
{
	ellipsehead->m_Index = 1;
	ellipsehead->ellipsenext = NULL;
	return ellipsehead;
}

//基类公共接口实现
DrawShape::DrawShape(CPoint StartPoint, CPoint EndPoint, CPoint OldPoint, COLORREF Color,
	int LineType, int LineSize, int DrawType)
{
	m_StartPoint = StartPoint;
	m_EndPoint = EndPoint;
	m_OldPoint = OldPoint;
	m_Color = Color;
	m_LineType = LineType;
	m_LineSize = LineSize;
	m_DrawType = DrawType;
}


void DrawShape::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
		ar << m_StartPoint << m_EndPoint << m_OldPoint << m_Color << m_LineType << 
			m_LineSize << m_DrawType;
	else
		ar >> m_StartPoint >> m_EndPoint >> m_OldPoint >> m_Color >> m_LineType >>
		m_LineSize >> m_DrawType;
}

void DrawShape::OnDraw(CDC * pDC)
{

}


//点

Cdot::Cdot(POINT point, int drawtype, int linetype, int linesize, COLORREF color)
{
	m_firpoint = point;
	m_drawtype = drawtype;
	m_linesize = linesize;
	m_linetype = linetype;
	m_color = color;
}

void Cdot::OnDraw(CDC * pDC)
{
	CPen NewPen, *pOldPen;
	if (moveFlag == 2 || moveFlag == 1)
		NewPen.CreatePen(m_linetype, m_linesize, m_Color);
	else if (moveFlag == 0)
		NewPen.CreatePen(m_linetype, m_linesize, m_color);
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->SetPixel(m_firpoint.x, m_firpoint.y, m_color);
	pDC->SelectObject(pOldPen);
}

void Cdot::Change(CPoint point)
{
	m_firpoint = point;
}

//直线

Cline::Cline(CPoint firpoint, CPoint secpoint, int drawtype, int linetype, int linesize, COLORREF color)
{
	m_firpoint = firpoint;
	m_secpoint = secpoint;
	m_drawtype = drawtype;
	m_linetype = linetype;
	m_linesize = linesize;
	m_color = color;
}

void Cline::OnDraw(CDC *pDC)
{
	CPen NewPen, *pOldPen = NULL;
	if (moveFlag == 0) {
		NewPen.CreatePen(m_linetype, m_linesize, m_color);
		pOldPen = pDC->SelectObject(&NewPen);
	}
	pDC->MoveTo(m_firpoint);
	pDC->LineTo(m_secpoint);
	pDC->SelectObject(pOldPen);
}

void Cline::Change(CPoint point)
{
	m_firpoint = m_firpoint + point;
	m_secpoint = m_secpoint + point;
}

//圆

Ccircle::Ccircle(POINT firpoint, POINT secpoint, int drawtype, int linetype,
	int linesize, COLORREF color)
{
	m_firpoint = firpoint;
	m_secpoint = secpoint;
	m_drawtype = drawtype;
	m_linetype = linetype;
	m_linesize = linesize;
	m_color = color;
}

void Ccircle::OnDraw(CDC *pDC)
{
	CPen NewPen, *pOldPen = NULL;
	if (moveFlag == 0) {
		NewPen.CreatePen(m_linetype, m_linesize, m_color);
		pOldPen = pDC->SelectObject(&NewPen);
	}
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	pDC->Ellipse(m_firpoint.x, m_firpoint.y, m_secpoint.x, m_secpoint.y);
	pDC->SelectObject(pOldPen);
}

void Ccircle::Squaring(CPoint &pFirst, CPoint &pSecond)		//使矩形框变成正方形用于画图
{
	int tempx, tempy;
	tempx = (pFirst.x<pSecond.x) ? (pSecond.x - pFirst.x) : (pFirst.x - pSecond.x);
	tempy = (pFirst.y<pSecond.y) ? (pSecond.y - pFirst.y) : (pFirst.y - pSecond.y);
	if (tempx<tempy)
		if (pFirst.x<pSecond.x)
			pSecond.x = pFirst.x + tempy;
		else
			pSecond.x = pFirst.x - tempy;
	else
		if (pFirst.y<pSecond.y)
			pSecond.y = pFirst.y + tempx;
		else
			pSecond.y = pFirst.y - tempx;
}

void Ccircle::Change(CPoint point1, CPoint point2)
{
	m_firpoint = point1;
	m_secpoint = point2;
}

//椭圆

Cellipse::Cellipse(CPoint firpoint, CPoint secpoint, int drawtype, int linetype,
	int linesize, COLORREF color)
{
	m_firpoint = firpoint;
	m_secpoint = secpoint;
	m_drawtype = drawtype;
	m_linetype = linetype;
	m_linesize = linesize;
	m_color = color;
}

void Cellipse::OnDraw(CDC *pDC)
{
	CPen NewPen, *pOldPen = NULL;
	if (moveFlag == 0) {
		NewPen.CreatePen(m_linetype, m_linesize, m_color);
		pOldPen = pDC->SelectObject(&NewPen);
	}
	pDC->SelectStockObject(NULL_BRUSH);
	CBrush NewBrush, *pOldBrush = NULL;
	pDC->Ellipse(m_firpoint.x, m_firpoint.y, m_secpoint.x, m_secpoint.y);
	pDC->SelectObject(pOldPen);
}

void Cellipse::Change(CPoint point1, CPoint point2)
{
	m_firpoint = point1;
	m_secpoint = point2;
}



//矩形
Crectangle::Crectangle(POINT firpoint, POINT secpoint, int drawtype, int linetype,
	int linesize, COLORREF color)
{
	m_firpoint = firpoint;
	m_secpoint = secpoint;
	m_drawtype = drawtype;
	m_linetype = linetype;
	m_linesize = linesize;
	m_color = color;
}

void Crectangle::OnDraw(CDC * pDC)
{
	CPen NewPen, *pOldPen = NULL;
	if (moveFlag == 0) {
		NewPen.CreatePen(m_linetype, m_linesize, m_color);
		pOldPen = pDC->SelectObject(&NewPen);
	}
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Rectangle(m_firpoint.x, m_firpoint.y, m_secpoint.x, m_secpoint.y);
	pDC->SelectObject(pOldPen);
}

void Crectangle::Change(CPoint point1, CPoint point2)
{
	m_firpoint = point1;
	m_secpoint = point2;
}

//圆弧类
Carc::Carc(CPoint *points, int drawtype, int linetype,
	double R, int linesize, COLORREF color)
{
	for(int i = 0;i<3;i++)
		m_points[i] = points[i];
	m_drawtype = drawtype;
	m_linetype = linetype;
	m_linesize = linesize;
	m_color = color;
	m_R = R;
}

void Carc::OnDraw(CDC * pDC)
{
	pDC->Arc(m_points[0].x - m_R, m_points[0].y - m_R, m_points[0].x + m_R, m_points[0].y + m_R,
		m_points[1].x, m_points[1].y,m_points[2].x, m_points[2].y);
}

void Carc::Change(CPoint *point,int R)
{
	for (int i = 0; i < 3; i++)
		m_points[i] = point[i];
	m_R = R;
}

//多边形
Cpolygon::Cpolygon(CPoint points[50], int num, int drawtype, int linetype,
	int linesize, COLORREF color)
{
	for (int i = 0; i<num; i++)
		m_points[i] = points[i];
	m_num = num;
	m_drawtype = drawtype;
	m_linetype = linetype;
	m_linesize = linesize;
	m_color = color;

}

void Cpolygon::OnDraw(CDC * pDC)
{
	CPen NewPen, *pOldPen = NULL;
	if (moveFlag == 0) {
		NewPen.CreatePen(m_linetype, m_linesize, m_color);
		pOldPen = pDC->SelectObject(&NewPen);
	}
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Polygon(m_points, m_num);
	pDC->SelectObject(pOldPen);
}

void Cpolygon::Change(CPoint * point, int num)
{
	for(int i = 0;i<num;i++)
		m_points[i] = point[i];

}
//链表类实现
