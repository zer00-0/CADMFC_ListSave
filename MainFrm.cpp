
// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



void CMainFrame::OnCarc()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_ARC;
}


void CMainFrame::OnCcircle()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_CIRCLE;
}


void CMainFrame::OnCdot()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_DOT;
}


void CMainFrame::OnCellipse()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_ELLIPSE;
}


void CMainFrame::OnCline()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_LINE;
}


void CMainFrame::OnCpolygon()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_POLYGON;
}


void CMainFrame::OnCrectangle()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_RECTANGLE;
}

//对图形进行操作
void CMainFrame::OnCrouse()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_ROUND;
}


void CMainFrame::OnCmove()
{
	// TODO: 在此添加命令处理程序代码
	DrawType =  DRAW_MOVE;
	moveFlag = 2;
	LBottonUpnum = 0;
}


void CMainFrame::OnCbigOrSmall()
{
	// TODO: 在此添加命令处理程序代码
	DrawType = DRAW_BIGORSMALL;
}


void CMainFrame::OnDotline()
{
	// TODO: 在此添加命令处理程序代码
	LineType = PS_DASHDOT;
}


void CMainFrame::OnSolidline()
{
	// TODO: 在此添加命令处理程序代码
	LineType = PS_SOLID;
}


void CMainFrame::OnVirtualline()
{
	// TODO: 在此添加命令处理程序代码
	LineType = PS_DASH;
}


void CMainFrame::OnLineone()
{
	// TODO: 在此添加命令处理程序代码
	LineSize = 1;
}


void CMainFrame::OnLinetwo()
{
	// TODO: 在此添加命令处理程序代码
	LineSize = 2;
}


void CMainFrame::OnLinethree()
{
	// TODO: 在此添加命令处理程序代码
	LineSize = 3;
}


void CMainFrame::OnLinefour()
{
	// TODO: 在此添加命令处理程序代码
	LineSize = 4;
}
