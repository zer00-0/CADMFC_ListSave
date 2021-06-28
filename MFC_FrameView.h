
// MFC_FrameView.h : CMFC_FrameView 类的接口
//

#pragma once


class CMFC_FrameView : public CView
{
protected: // 仅从序列化创建
	CMFC_FrameView();
	DECLARE_DYNCREATE(CMFC_FrameView)

// 特性
public:
	CMFC_FrameDoc* GetDocument() const;
	CPoint m_firPoint, m_secPoint, m_oldPoint,m_lastPoint;
	CPoint m_Cenpoint[3],m_points[50];
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC_FrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC_FrameView.cpp 中的调试版本
inline CMFC_FrameDoc* CMFC_FrameView::GetDocument() const
   { return reinterpret_cast<CMFC_FrameDoc*>(m_pDocument); }
#endif

