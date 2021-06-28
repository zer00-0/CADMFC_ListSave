#include "stdafx.h"
#include "Data.h"

int LinkFlag = 1;
int DrawType  = 1;
int LineType = 0;		//线型
int PenType = 0;			//笔型
int LineSize = 0;
int moveFlag = 0;
double R = 0;
int arcnum = 0;
int m_num = 0;
int LBottonUpnum = 0;
COLORREF m_Color = RGB(0, 0, 0);
bool LBottomDown = false;		//鼠标按下标志位,主要为确定up后，mousemove不再操作
bool RBottomDown = false;		//鼠标按下标志位，主要作为多折线与多边形连接和停止标准

LineList * linehead = new(LineList);		//记录头结点
LineList * linelast = NULL;		//记录尾结点
LineList * linelink = new(LineList);		//记录当前节点

RectangleList * recthead = new(RectangleList);		//记录矩形头结点(空头
RectangleList * rectlast = NULL;		//记录尾结点
RectangleList * rectlink = new(RectangleList);		//记录当前节点

CircleList * circlehead = new(CircleList);		//记录圆头结点(空头)
CircleList * circlelast = NULL;		//记录尾结点
CircleList * circlelink = new(CircleList);		//记录当前节点

ArcList * archead = new(ArcList);		//记录圆弧头结点(空头)
ArcList * arclast = NULL;		//记录尾结点
ArcList * arclink = new(ArcList);		//记录当前节点

DotList * dothead = new(DotList);		//记录点头结点(空头)
DotList * dotlast = NULL;		//记录尾结点
DotList * dotlink = new(DotList);		//记录当前节点

EllipseList * ellipsehead = new(EllipseList);		//记录椭圆头结点(空头)
EllipseList * ellipselast = NULL;		//记录尾结点
EllipseList * ellipselink = new(EllipseList);		//记录当前节点

PolygonList * polygonhead = new(PolygonList);		//记录多边形头结点(空头)
PolygonList * polygonlast = NULL;		//记录尾结点
PolygonList * polygonlink = new(PolygonList);		//记录当前节点

DotList * dotlist = NULL;
LineList * linelist = NULL;
CircleList * circlelist = NULL;
ArcList * arclist = NULL;
EllipseList * ellipselist = NULL;
RectangleList *  rectanglelist = NULL;
PolygonList *  polygonlist = NULL;

HCURSOR m_HCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);



