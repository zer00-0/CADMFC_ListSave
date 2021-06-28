
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnCarc();
	afx_msg void OnCcircle();
	afx_msg void OnCdot();
	afx_msg void OnCellipse();
	afx_msg void OnCline();
	afx_msg void OnCpolygon();
	afx_msg void OnCrectangle();
	afx_msg void OnCrouse();
	afx_msg void OnCmove();
	afx_msg void OnCbigOrSmall();
	afx_msg void OnDotline();
	afx_msg void OnSolidline();
//	afx_msg void OnRouse();
	afx_msg void OnVirtualline();
	afx_msg void OnLineone();
	afx_msg void OnLinetwo();
	afx_msg void OnLinethree();
	afx_msg void OnLinefour();
};


