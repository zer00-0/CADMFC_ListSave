
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
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


