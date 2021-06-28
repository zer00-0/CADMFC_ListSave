
// MFC_FrameDoc.cpp : CMFC_FrameDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_Frame.h"
#endif

#include "MFC_FrameDoc.h"
#include "Data.h"
#include <propkey.h>
#include <afx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC_FrameDoc

IMPLEMENT_DYNCREATE(CMFC_FrameDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_FrameDoc, CDocument)
END_MESSAGE_MAP()


// CMFC_FrameDoc 构造/析构

CMFC_FrameDoc::CMFC_FrameDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFC_FrameDoc::~CMFC_FrameDoc()
{
}

BOOL CMFC_FrameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC_FrameDoc 序列化

//将数据保存到对应链表
void CMFC_FrameDoc::AddLine(Cline * line)
{
	linelink = linelink->Add(line);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}

void CMFC_FrameDoc::AddArc(Carc * arc)
{
	arclink = arclink->Add(arc);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}

void CMFC_FrameDoc::AddDot(Cdot * dot)
{
	dotlink = dotlink->Add(dot);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}

void CMFC_FrameDoc::AddElli(Cellipse * ellipse)
{
	ellipselink = ellipselink->Add(ellipse);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}

void CMFC_FrameDoc::AddPoly(Cpolygon * polygon)
{
	polygonlink = polygonlink->Add(polygon);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}

void CMFC_FrameDoc::AddCircle(Ccircle * circle)
{
	circlelink = circlelink->Add(circle);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}
//void CMFC_FrameDoc::AddPolyline(Cpolyline * polyline)
//{
//	linelink->Add(polyline);
//	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
//							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
//}

void CMFC_FrameDoc::AddRect(Crectangle * rectangle)
{
	rectlink = rectlink->Add(rectangle);
	SetModifiedFlag();		//在对文档作了修改之后调用该函数。连续调用以确保在关闭之前框架提示用户保存这些变化
							//。通常使用bModified参数的缺省值TRUE。要标记文档是未被修改的，调用带FALSE值的函数。
}


int CMFC_FrameDoc::FindPoint(CPoint point,CDC *pDC)			//遍历找点,如找到则设置那个返回值为1，否则为0
{
	dotlist = SelectPoint(point);
	linelist = SelectLine(point);
	circlelist = SelectCircle(point);
	arclist = SelectArc(point);
	ellipselist = SelectEllipse(point);
	rectanglelist = SelectRectangle(point);
	polygonlist = SelectPolygon(point);

	m_Color = RGB(255, 0, 0);
	CPen pen;
	pen.CreatePen(LineType, LineSize, m_Color);			//创建线型，大小，颜色
	CPen *pOldPen = pDC->SelectObject(&pen);				//将笔信息写入设备描述表

	
	if (dotlist != NULL){
		dotlist->dot->OnDraw(pDC);
	}
	if (linelist != NULL){
		linelist->line->OnDraw(pDC);

	}
	if (circlelist != NULL) {
		circlelist->circle->OnDraw(pDC);
	}
	if (arclist != NULL) {
		arclist->arc->OnDraw(pDC);
	}
	if (ellipselist != NULL) {
		ellipselist->ellipse->OnDraw(pDC);
	}

	if (rectanglelist != NULL) {
		rectanglelist->rectangle->OnDraw(pDC);
	}

	if (polygonlist != NULL) {
		polygonlist->polygon->OnDraw(pDC);
	}
	return 1;
}

DotList * CMFC_FrameDoc::SelectPoint(CPoint point)
{
	DotList *temp = dothead;
	while (temp != NULL)
	{
		double distance = sqrt((temp->dot->m_firpoint.x - point.x)*(temp->dot->m_firpoint.x - point.x) +
			(temp->dot->m_firpoint.y - point.y)*(temp->dot->m_firpoint.y - point.y));
		if (distance < 5.0)
			return temp;
		temp = temp->dotnext;
	}

	return temp = NULL;
}

LineList * CMFC_FrameDoc::SelectLine(CPoint point)
{
	LineList *temp = linehead;
	while (temp != NULL)
	{
		double distance1 = sqrt((temp->line->m_firpoint.x - point.x)*(temp->line->m_firpoint.x - point.x) +
			(temp->line->m_firpoint.y - point.y)*(temp->line->m_firpoint.y - point.y));
		double distance2 = sqrt((temp->line->m_secpoint.x - point.x)*(temp->line->m_secpoint.x - point.x) +
			(temp->line->m_secpoint.y - point.y)*(temp->line->m_secpoint.y - point.y));
		if (distance1 < 10.0 || distance2 < 10.0)
			return temp;
		temp = temp->linenext;
	}
	return temp = NULL;
}

CircleList * CMFC_FrameDoc::SelectCircle(CPoint point)
{
	CircleList *temp = circlehead;
	double distance,Rsize;
	CPoint center;
	while (temp != NULL)
	{
		center.x = (temp->circle->m_firpoint.x + temp->circle->m_secpoint.x) / 2;
		center.y = (temp->circle->m_firpoint.y + temp->circle->m_secpoint.y) / 2;
		Rsize = sqrt((center.x - temp->circle->m_firpoint.x)*(center.x - temp->circle->m_firpoint.x) + 
			(center.y - temp->circle->m_firpoint.y)*(center.y - temp->circle->m_firpoint.y));
		distance = sqrt((center.x -point.x )*(center.x - point.x)+ (center.y - point.y)*(center.y - point.y));
		if ((distance - Rsize)< 10.0)
			return temp;
		temp = temp->circlenext;
	}
	return temp = NULL;
}

ArcList * CMFC_FrameDoc::SelectArc(CPoint point)
{
	ArcList *temp = archead;
	double distance;
	while (temp != NULL)
	{
		for (int i = 1; i < 3; i++) {
			distance = sqrt((temp->arc->m_points[i].x - point.x)*(temp->arc->m_points[i].x - point.x) +
				(temp->arc->m_points[i].y - point.y)*(temp->arc->m_points[i].y - point.y));
			
			if (distance < 10.0)
				return temp;	
		}

		temp = temp->arcnext;
	}
	return temp = NULL;
}

EllipseList * CMFC_FrameDoc::SelectEllipse(CPoint point)
{
	EllipseList *temp = ellipsehead;
	double distance1,distance2, distance3, distance4;
	while (temp != NULL)
	{
		distance1 = sqrt((temp->ellipse->m_firpoint.x - point.x)*(temp->ellipse->m_firpoint.x - point.x) +
			(temp->ellipse->m_firpoint.y - point.y) *(temp->ellipse->m_firpoint.y - point.y));
		distance2 = sqrt((temp->ellipse->m_secpoint.x - point.x)*(temp->ellipse->m_secpoint.x - point.x) +
			(temp->ellipse->m_secpoint.y - point.y) *(temp->ellipse->m_secpoint.y - point.y));

		temp = temp->ellipsenext;
	}
	return temp = NULL;
}

RectangleList * CMFC_FrameDoc::SelectRectangle(CPoint point)
{
	RectangleList *temp = recthead;
	double distance1, distance2;
	while (temp != NULL)
	{
		distance1 = sqrt((temp->rectangle->m_firpoint.x - point.x)*(temp->rectangle->m_firpoint.x - point.x) +
			(temp->rectangle->m_firpoint.y - point.y) *(temp->rectangle->m_firpoint.y - point.y));
		distance2 = sqrt((temp->rectangle->m_secpoint.x - point.x)*(temp->rectangle->m_secpoint.x - point.x) +
			(temp->rectangle->m_secpoint.y - point.y) *(temp->rectangle->m_secpoint.y - point.y));
		temp = temp->rectnext;
	}
	return temp = NULL;
}

PolygonList * CMFC_FrameDoc::SelectPolygon(CPoint point)
{
	PolygonList *temp = polygonhead;
	while (temp != NULL)
	{
		for (int i = 0; i < temp->m_Index; i++)
		{

		}
		temp = temp->polynext;
	}
	return temp = NULL;
}


//平移操作
void CMFC_FrameDoc::Move(CPoint firpoint,CPoint secpoint)
{
	CPoint movesize;
	movesize.x = firpoint.x - secpoint.x;
	movesize.y = firpoint.y - secpoint.y;
	if (linelist != NULL)
	{
		linelist->line->Change(movesize);
	}
}

void CMFC_FrameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
	/*link->Serialize(ar);*/			//（个人理解）调用DataList类中用DrawShape * shape的每一个子类的serialize，保存信息
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC_FrameDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFC_FrameDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC_FrameDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC_FrameDoc 诊断

#ifdef _DEBUG
void CMFC_FrameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_FrameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC_FrameDoc 命令
