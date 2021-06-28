
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFC_Frame.h"
#include "Data.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_Carc, &CMainFrame::OnCarc)
	ON_COMMAND(ID_Ccircle, &CMainFrame::OnCcircle)
	ON_COMMAND(ID_Cdot, &CMainFrame::OnCdot)
	ON_COMMAND(ID_Cellipse, &CMainFrame::OnCellipse)
	ON_COMMAND(ID_Cline, &CMainFrame::OnCline)
	ON_COMMAND(ID_Cpolygon, &CMainFrame::OnCpolygon)
	ON_COMMAND(ID_Crectangle, &CMainFrame::OnCrectangle)
	ON_COMMAND(ID_Crouse, &CMainFrame::OnCrouse)
	ON_COMMAND(ID_Cmove, &CMainFrame::OnCmove)
	ON_COMMAND(ID_Cbig_or_small, &CMainFrame::OnCbigOrSmall)
	ON_COMMAND(ID_dotline, &CMainFrame::OnDotline)
	ON_COMMAND(ID_solidline, &CMainFrame::OnSolidline)
//	ON_COMMAND(ID_rouse, &CMainFrame::OnRouse)
ON_COMMAND(ID_virtualline, &CMainFrame::OnVirtualline)
ON_COMMAND(ID_lineone, &CMainFrame::OnLineone)
ON_COMMAND(ID_linetwo, &CMainFrame::OnLinetwo)
ON_COMMAND(ID_linethree, &CMainFrame::OnLinethree)
ON_COMMAND(ID_linefour, &CMainFrame::OnLinefour)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



void CMainFrame::OnCarc()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_ARC;
}


void CMainFrame::OnCcircle()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_CIRCLE;
}


void CMainFrame::OnCdot()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_DOT;
}


void CMainFrame::OnCellipse()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_ELLIPSE;
}


void CMainFrame::OnCline()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_LINE;
}


void CMainFrame::OnCpolygon()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_POLYGON;
}


void CMainFrame::OnCrectangle()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_RECTANGLE;
}

//��ͼ�ν��в���
void CMainFrame::OnCrouse()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_ROUND;
}


void CMainFrame::OnCmove()
{
	// TODO: �ڴ���������������
	DrawType =  DRAW_MOVE;
	moveFlag = 2;
	LBottonUpnum = 0;
}


void CMainFrame::OnCbigOrSmall()
{
	// TODO: �ڴ���������������
	DrawType = DRAW_BIGORSMALL;
}


void CMainFrame::OnDotline()
{
	// TODO: �ڴ���������������
	LineType = PS_DASHDOT;
}


void CMainFrame::OnSolidline()
{
	// TODO: �ڴ���������������
	LineType = PS_SOLID;
}


void CMainFrame::OnVirtualline()
{
	// TODO: �ڴ���������������
	LineType = PS_DASH;
}


void CMainFrame::OnLineone()
{
	// TODO: �ڴ���������������
	LineSize = 1;
}


void CMainFrame::OnLinetwo()
{
	// TODO: �ڴ���������������
	LineSize = 2;
}


void CMainFrame::OnLinethree()
{
	// TODO: �ڴ���������������
	LineSize = 3;
}


void CMainFrame::OnLinefour()
{
	// TODO: �ڴ���������������
	LineSize = 4;
}
