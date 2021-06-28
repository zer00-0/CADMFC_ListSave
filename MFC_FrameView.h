
// MFC_FrameView.h : CMFC_FrameView ��Ľӿ�
//

#pragma once


class CMFC_FrameView : public CView
{
protected: // �������л�����
	CMFC_FrameView();
	DECLARE_DYNCREATE(CMFC_FrameView)

// ����
public:
	CMFC_FrameDoc* GetDocument() const;
	CPoint m_firPoint, m_secPoint, m_oldPoint,m_lastPoint;
	CPoint m_Cenpoint[3],m_points[50];
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC_FrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // MFC_FrameView.cpp �еĵ��԰汾
inline CMFC_FrameDoc* CMFC_FrameView::GetDocument() const
   { return reinterpret_cast<CMFC_FrameDoc*>(m_pDocument); }
#endif

