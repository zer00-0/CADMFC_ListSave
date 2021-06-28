
// MFC_FrameDoc.h : CMFC_FrameDoc ��Ľӿ�
//


#pragma once
#include "MFC_Shape.h"

class CMFC_FrameDoc : public CDocument
{
protected: // �������л�����
	CMFC_FrameDoc();
	DECLARE_DYNCREATE(CMFC_FrameDoc)
	
// ����
public:
	LineList m_DataList;
// ����
public:
	void AddLine(Cline * line);
	void AddArc(Carc * arc);
	void AddPoly(Cpolygon * polygon);
	void AddRect(Crectangle * retangle);
	void AddDot(Cdot * dot);
	void AddElli(Cellipse * ellipse);
	void AddCircle(Ccircle * ciecle);
	int FindPoint(CPoint ,CDC *);			//�����ҵ�
	DotList * SelectPoint(CPoint );
	LineList * SelectLine(CPoint );
	CircleList * SelectCircle(CPoint );
	ArcList * SelectArc(CPoint );
	EllipseList * SelectEllipse(CPoint );
	RectangleList * SelectRectangle(CPoint );
	PolygonList * SelectPolygon(CPoint );

	void Move(CPoint,CPoint);
	/*void AddPolyline(Cpolyline * polyline);*/
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC_FrameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
