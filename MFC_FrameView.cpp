
// MFC_FrameView.cpp : CMFC_FrameView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_Frame.h"
#endif

#include "MFC_FrameDoc.h"
#include "MFC_FrameView.h"
#include "Data.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_FrameView

IMPLEMENT_DYNCREATE(CMFC_FrameView, CView)

BEGIN_MESSAGE_MAP(CMFC_FrameView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(ID_Line, &CMFC_FrameView::OnLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CMFC_FrameView ����/����

CMFC_FrameView::CMFC_FrameView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_FrameView::~CMFC_FrameView()
{
}

BOOL CMFC_FrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_FrameView ����

void CMFC_FrameView::OnDraw(CDC* pDC)
{
	CMFC_FrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	LineList *linelist = linehead;
	ArcList *arclist = archead;
	CircleList *circlelist = circlehead;
	PolygonList * polygonlist = polygonhead;
	RectangleList * rectlist = recthead;
	DotList *dotlist = dothead;
	EllipseList *ellipselist = ellipsehead;
	if (LinkFlag == 0) {
		while (linelist != NULL)
		{
			linelist->line->OnDraw(pDC);
			linelist = linelist->linenext;
		}

		while (arclist != NULL)
		{
			arclist->arc->OnDraw(pDC);
			arclist = arclist->arcnext;
		}
		while (circlelist != NULL)
		{
			circlelist->circle->OnDraw(pDC);
			circlelist = circlelist->circlenext;
		}
		while (dotlist != NULL)
		{
			dotlist->dot->OnDraw(pDC);
			dotlist = dotlist->dotnext;
		}
		while (polygonlist != NULL)
		{
			polygonlist->polygon->OnDraw(pDC);
			polygonlist = polygonlist->polynext;
		}

		while (ellipselist != NULL)
		{
			ellipselist->ellipse->OnDraw(pDC);
			ellipselist = ellipselist->ellipsenext;
		}
		while (rectlist != NULL)
		{
			rectlist->rectangle->OnDraw(pDC);
			rectlist = rectlist->rectnext;
		}

	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_FrameView ��ӡ

BOOL CMFC_FrameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_FrameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_FrameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_FrameView ���

#ifdef _DEBUG
void CMFC_FrameView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_FrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_FrameDoc* CMFC_FrameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_FrameDoc)));
	return (CMFC_FrameDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_FrameView ��Ϣ�������



void CMFC_FrameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_firPoint = point;
	m_secPoint = point;
	m_oldPoint = point;
	if (LinkFlag == 1)				//��һ�����г�ʼ��
	{
		linelink = linelink->Initialize();
		arclink = arclink->Initialize();
		rectlink = rectlink->Initialize();
		circlelink = circlelink->Initialize();
		dotlink = dotlink->Initialize();
		polygonlink = polygonlink->Initialize();
		ellipselink = ellipselink->Initialize();
		LinkFlag = 0;
		m_points[m_num] = point;
		m_num++;
	}
	LBottomDown = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_FrameView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (!LBottomDown)
		return;
	CMFC_FrameDoc * pDoc = GetDocument();
	CDC * dc = GetDC();
	CPen pen;
	pen.CreatePen(LineType, LineSize, m_Color);
	dc->SelectObject(pen);
	COLORREF nowcolor = m_Color;
	Cline * line;
	Crectangle * rectangle;
	Carc * arc;
	Ccircle * circle = NULL;
	Cdot * dot;
	Cpolygon * polygon;
	Cellipse * ellipse;

	switch (DrawType)
	{
	case DRAW_LINE:
		dc->SetROP2(R2_COPYPEN);
		line = new Cline(m_firPoint, m_secPoint, DrawType, LineType, LineSize, m_Color);
		line->OnDraw(dc);
		pDoc->AddLine(line);
		LBottomDown = false;
		break;
	case DRAW_RECTANGLE:
		dc->SetROP2(R2_COPYPEN);
		rectangle = new Crectangle(m_firPoint, m_secPoint, DrawType, LineType, LineSize, m_Color);
		rectangle->OnDraw(dc);
		pDoc->AddRect(rectangle);
		LBottomDown = false;
		break;
	case DRAW_CIRCLE:
		dc->SetROP2(R2_COPYPEN);
		circle->Squaring(m_firPoint, m_secPoint);			//ʹ���α�Ϊ������	
		circle = new Ccircle(m_firPoint,m_secPoint, DrawType, LineType,
			 LineSize, m_Color);
		circle->OnDraw(dc);
		pDoc->AddCircle(circle);
		LBottomDown = false;
		break;
	case DRAW_ELLIPSE:
		dc->SetROP2(R2_COPYPEN);
		ellipse = new Cellipse(m_firPoint, m_secPoint, DrawType, LineType, LineSize, m_Color);
		ellipse->OnDraw(dc);
		pDoc->AddElli(ellipse);
		LBottomDown = false;
		break;
	case DRAW_ARC:
		dc->SetROP2(R2_COPYPEN);

		if (arcnum == 0)
		{
			m_Cenpoint[arcnum] = point;
			m_Cenpoint[arcnum + 1] = point;
			arcnum++;
			dc->SetPixel(point.x, point.y, m_Color);
		}
		else if (arcnum == 1)
		{
			m_Cenpoint[arcnum] = point;
			m_Cenpoint[arcnum + 1] = point;
			m_secPoint = point;
			m_lastPoint = m_firPoint;
			arcnum++;
		}
		else
		{
			m_Cenpoint[2] = point;
			arc = new Carc(m_Cenpoint, DrawType, LineType, R,LineSize, m_Color);
			arc->OnDraw(dc);
			pDoc->AddArc(arc);
			LBottomDown = false;
			arcnum = 0;
		}
		R = sqrt(pow((m_Cenpoint[0].x - m_Cenpoint[1].x), 2) +
			pow((m_Cenpoint[0].y - m_Cenpoint[1].y), 2));

		break;
	case DRAW_DOT:
		dc->SetROP2(R2_COPYPEN);
		dot = new Cdot(point, DrawType, LineType, LineSize, m_Color);
		pDoc->AddDot(dot);
		dot->OnDraw(dc);
		LBottomDown = false;
		break;
	case DRAW_POLYGON:
		dc->SetROP2(R2_COPYPEN);
		dc->MoveTo(m_firPoint);
		dc->LineTo(m_secPoint);
		m_points[m_num] = point;
		m_num++;
		break;
	case DRAW_MOVE:
		LBottonUpnum++;
		if (LBottonUpnum == 1) {
			pDoc->FindPoint(point,dc);
		}	
		else if (LBottonUpnum == 2) {
			pDoc->Move(m_firPoint,point);
			linelist->line->OnDraw(dc);
			LBottonUpnum = 0;
			moveFlag = 0;
		}
		
		break;
	case DRAW_BIGORSMALL:

		break;
	case DRAW_ROUND:

		break;
	default:
		break;
	}
	m_Color = nowcolor;
	/*CMFC_FrameView::OnDraw(dc);*/
	this->ReleaseDC(dc);
	
	CView::OnLButtonUp(nFlags, point);
}



void CMFC_FrameView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (!LBottomDown)
	{
		return;
	}
	Ccircle *circle = NULL;
	Cpolygon * polygon = NULL;
	CMFC_FrameDoc * pDoc = GetDocument();
	CClientDC dc(this);
	SetCursor(m_HCursor);			//���ù����״Ϊʮ��
	CPen pen;
	pen.CreatePen(LineType, LineSize, m_Color);
	dc.SelectObject(pen);

	switch (DrawType)
	{
	case DRAW_LINE:
		dc.SetROP2(R2_NOTXORPEN);
		dc.MoveTo(m_firPoint);
		dc.LineTo(m_secPoint);

		dc.MoveTo(m_firPoint);		//���ģʽ��ȥ��һ���ߣ��ﵽ��Ƥ���
		dc.LineTo(point);			//�����ͬ�������߻���ʧ����ͬ���������Ǹ������Իῴ��һ��һ��
		m_secPoint = point;
		break;
	case DRAW_RECTANGLE:
		dc.SetROP2(R2_NOTXORPEN);
		dc.Rectangle(m_firPoint.x, m_firPoint.y, m_secPoint.x, m_secPoint.y);

		dc.Rectangle(m_firPoint.x, m_firPoint.y, point.x, point.y);
		m_secPoint = point;
		break;
	case DRAW_CIRCLE:
		dc.SetROP2(R2_NOTXORPEN);
		circle->Squaring(m_firPoint, m_secPoint);
		dc.Ellipse(m_firPoint.x, m_firPoint.y, m_secPoint.x, m_secPoint.y);

		circle->Squaring(m_firPoint, point);
		dc.Ellipse(m_firPoint.x, m_firPoint.y, point.x, point.y);
		m_secPoint = point;
		break;
	case DRAW_ELLIPSE:
		dc.SetROP2(R2_NOTXORPEN);
		dc.Ellipse(m_firPoint.x, m_firPoint.y, m_secPoint.x, m_secPoint.y);

		dc.Ellipse(m_firPoint.x, m_firPoint.y, point.x, point.y);
		m_secPoint = point;
		break;
	case DRAW_ARC:
		if (arcnum > 1)
		{
			dc.SetROP2(R2_NOTXORPEN);
			dc.Arc(m_Cenpoint[0].x - R, m_Cenpoint[0].y - R, m_Cenpoint[0].x + R, m_Cenpoint[0].y + R,
				m_Cenpoint[1].x, m_Cenpoint[1].y, point.x, point.y);

			dc.Arc(m_Cenpoint[0].x - R, m_Cenpoint[0].y - R, m_Cenpoint[0].x + R, m_Cenpoint[0].y + R,
				m_Cenpoint[1].x, m_Cenpoint[1].y, point.x, point.y);
		}
		break;
	case DRAW_DOT:
		break;
	case DRAW_POLYGON:
		if (RBottomDown)			//����Ҽ�����,������ʵ�����һ����ͼ
		{
			polygon = new Cpolygon(m_points, m_num, DrawType, LineType, LineSize, m_Color);
			pDoc->AddPoly(polygon);
			dc.MoveTo(m_secPoint);
			dc.LineTo(m_points[0]);
			LBottomDown = false;			//ʹ�䲻ִ��������up�Ĳ���
			RBottomDown = false;			//������λʹ����Ҽ���Ϊ��,����������
			return;
		}
		dc.SetROP2(R2_NOTXORPEN);
		dc.MoveTo(m_firPoint);
		dc.LineTo(m_secPoint);

		dc.MoveTo(m_firPoint);		//���ģʽ��ȥ��һ���ߣ��ﵽ��Ƥ���
		dc.LineTo(point);
		m_secPoint = point;
		break;
	//case DRAW_POLYLINE:
	//	if (RBottomDown)			//����Ҽ�����
	//	{
	//		LBottomDown = false;			//ʹ�䲻ִ��������up�Ĳ���
	//		RBottomDown = false;			//������λʹ����Ҽ���Ϊ������������
	//		return;
	//	}
	//	dc.SetROP2(R2_NOTXORPEN);
	//	dc.MoveTo(m_firPoint);
	//	dc.LineTo(m_secPoint);

	//	dc.MoveTo(m_firPoint);		//���ģʽ��ȥ��һ���ߣ��ﵽ��Ƥ���
	//	dc.LineTo(point);
	//	m_secPoint = point;
	//	break;
	default:
		break;
	}

	CView::OnMouseMove(nFlags, point);
}


void CMFC_FrameView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	RBottomDown = true;
	CView::OnRButtonDown(nFlags, point);
}


BOOL CMFC_FrameView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
