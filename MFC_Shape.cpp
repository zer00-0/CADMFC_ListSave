#include "stdafx.h"
#include "MFC_Shape.h"
#include "Data.h"

//List�����ʵ��

void List::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����

	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
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

void List::Insert(List * L, int index, int value)		//��������
{

}

void List::Increate(List * L)	//��������
{

}

void List::Delete(List * L)		//ɾ������
{

}

List * List::Find(List * L)		//��������
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
//		//����������������
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


//ֱ��������
LineList* LineList::Add(Cline * line)		//��ͷ�巨���ܷ������undo��,shapeΪ������Ŀռ�
{
	this->linenext = new(LineList);			//�������ڵ�����ռ䱣������
	this->linenext->line = line;			//ʹ��DataList���������DrawShape�����shape��������
	this->linenext->linenext = NULL;
	this->linenext->m_Index = this->m_Index++;
	linelast = this->linenext;
	return this->linenext;
}


LineList * LineList::Initialize()			//��ʼ��������ͷ���ֵ
{
	linehead->m_Index = 1;
	linehead->linenext = NULL;
	return linehead;
}

//������
DotList* DotList::Add(Cdot * dot)		//β�巨��ͷ�巨���ܷ������undo��,shapeΪ������Ŀռ�
{
	this->dotnext = new(DotList);			//�������ڵ�����ռ䱣������
	this->dotnext->dot = dot;			//ʹ��DataList���������DrawShape�����shape��������
	this->dotnext->dotnext = NULL;
	this->dotnext->m_Index = this->m_Index++;
	dotlast = this->dotnext;
	return this->dotnext;
}


DotList * DotList::Initialize()			//��ʼ��������ͷ���ֵ
{
	dothead->m_Index = 1;
	dothead->dotnext = NULL;
	return dothead;
}


//��������
RectangleList* RectangleList::Add(Crectangle * rectangle)		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
{
	this->rectnext = new(RectangleList);			//�������ڵ�����ռ䱣������
	this->rectnext->rectangle = rectangle;			//ʹ��DataList���������DrawShape�����shape��������
	this->rectnext->rectnext = NULL;
	this->rectnext->m_Index = this->m_Index++;
	rectlast = this->rectnext;
	return this->rectnext;
}


RectangleList* RectangleList::Initialize()			//��ʼ��������ͷ���ֵ
{	
	recthead->m_Index = 1;
	recthead->rectnext = NULL;
	return recthead;
}

//Բ����
CircleList* CircleList::Add(Ccircle * circle)		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
{
	this->circlenext = new(CircleList);			//�������ڵ�����ռ䱣������
	this->circlenext->circle = circle;			//ʹ��DataList���������DrawShape�����shape��������
	this->circlenext->circlenext = NULL;
	this->circlenext->m_Index = this->m_Index++;
	circlelast = this->circlenext;
	return this->circlenext;
}


CircleList* CircleList::Initialize()			//��ʼ��������ͷ���ֵ
{
	circlehead->m_Index = 1;
	circlehead->circlenext = NULL;
	return circlehead;
}

//Բ��
ArcList* ArcList::Add(Carc * arc)		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
{
	this->arcnext = new(ArcList);			//�������ڵ�����ռ䱣������
	this->arcnext->arc = arc;			//ʹ��DataList���������DrawShape�����shape��������
	this->arcnext->arcnext = NULL;
	this->arcnext->m_Index = this->m_Index++;
	arclast = this->arcnext;
	return this->arcnext;
}


ArcList* ArcList::Initialize()			//��ʼ��������ͷ���ֵ
{
	archead->m_Index = 1;
	archead->arcnext = NULL;
	return archead;
}

//���������
PolygonList* PolygonList::Add(Cpolygon * polygon)		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
{
	this->polynext = new(PolygonList);			//�������ڵ�����ռ䱣������
	this->polynext->polygon = polygon;			//ʹ��DataList���������DrawShape�����shape��������
	this->polynext->polynext = NULL;
	this->polynext->m_Index = this->m_Index++;
	polygonlast = this->polynext;
	return this->polynext;
}


PolygonList* PolygonList::Initialize()			//��ʼ��������ͷ���ֵ
{
	polygonhead->m_Index = 1;
	polygonhead->polynext = NULL;
	return polygonhead;
}

//��Բ
EllipseList* EllipseList::Add(Cellipse * ellipse)		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
{
	this->ellipsenext = new(EllipseList);			//�������ڵ�����ռ䱣������
	this->ellipsenext->ellipse = ellipse;			//ʹ��DataList���������DrawShape�����shape��������
	this->ellipsenext->ellipsenext = NULL;
	this->ellipsenext->m_Index = this->m_Index++;
	ellipselast = this->ellipsenext;
	return this->ellipsenext;
}


EllipseList* EllipseList::Initialize()			//��ʼ��������ͷ���ֵ
{
	ellipsehead->m_Index = 1;
	ellipsehead->ellipsenext = NULL;
	return ellipsehead;
}

//���๫���ӿ�ʵ��
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


//��

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

//ֱ��

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

//Բ

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

void Ccircle::Squaring(CPoint &pFirst, CPoint &pSecond)		//ʹ���ο������������ڻ�ͼ
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

//��Բ

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



//����
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

//Բ����
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

//�����
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
//������ʵ��
