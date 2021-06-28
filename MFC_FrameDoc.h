
// MFC_FrameDoc.h : CMFC_FrameDoc 类的接口
//


#pragma once
#include "MFC_Shape.h"

class CMFC_FrameDoc : public CDocument
{
protected: // 仅从序列化创建
	CMFC_FrameDoc();
	DECLARE_DYNCREATE(CMFC_FrameDoc)
	
// 特性
public:
	LineList m_DataList;
// 操作
public:
	void AddLine(Cline * line);
	void AddArc(Carc * arc);
	void AddPoly(Cpolygon * polygon);
	void AddRect(Crectangle * retangle);
	void AddDot(Cdot * dot);
	void AddElli(Cellipse * ellipse);
	void AddCircle(Ccircle * ciecle);
	int FindPoint(CPoint ,CDC *);			//遍历找点
	DotList * SelectPoint(CPoint );
	LineList * SelectLine(CPoint );
	CircleList * SelectCircle(CPoint );
	ArcList * SelectArc(CPoint );
	EllipseList * SelectEllipse(CPoint );
	RectangleList * SelectRectangle(CPoint );
	PolygonList * SelectPolygon(CPoint );

	void Move(CPoint,CPoint);
	/*void AddPolyline(Cpolyline * polyline);*/
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC_FrameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
