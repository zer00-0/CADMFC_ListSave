#pragma once

#include "MFC_Shape.h"


extern LineList * linehead;		//记录直线头结点(空头)
extern LineList * linelast;		//记录尾结点
extern LineList * linelink;		//记录当前节点

extern RectangleList * recthead;		//记录矩形头结点(空头)
extern RectangleList * rectlast;		//记录尾结点
extern RectangleList * rectlink;		//记录当前节点

extern CircleList * circlehead;		//记录圆头结点(空头)
extern CircleList * circlelast;		//记录尾结点
extern CircleList * circlelink;		//记录当前节点

extern ArcList * archead;		//记录圆弧头结点(空头)
extern ArcList * arclast;		//记录尾结点
extern ArcList * arclink;		//记录当前节点

extern DotList * dothead;		//记录点头结点(空头)
extern DotList * dotlast;		//记录尾结点
extern DotList * dotlink;		//记录当前节点

extern EllipseList * ellipsehead;		//记录椭圆头结点(空头)
extern EllipseList * ellipselast;		//记录尾结点
extern EllipseList * ellipselink;		//记录当前节点

extern PolygonList * polygonhead;		//记录多边形头结点(空头)
extern PolygonList * polygonlast;		//记录尾结点
extern PolygonList * polygonlink;		//记录当前节点


extern DotList * dotlist;
extern LineList * linelist;
extern CircleList * circlelist;
extern ArcList * arclist;
extern EllipseList * ellipselist;
extern RectangleList *  rectanglelist;
extern PolygonList *  polygonlist;
extern int LinkFlag;		//链表首次执行标志位
extern int DrawType;
extern int LineType;		//线型
extern int PenType;			//笔型
extern int LineSize;
extern int arcnum;		//圆弧点数记录
extern int m_num;		//记录多边形点数
extern int moveFlag;	//平移操作标准位，0为不进行，1为进行,2为中间过渡（即正在进行操作)
extern double R;		//圆弧半径
extern COLORREF m_Color;
extern int LBottonUpnum;
extern bool LBottomDown;		//鼠标按下标志位,主要为确定up后，mousemove不再操作
extern bool RBottomDown;		//鼠标按下标志位，主要作为多折线与多边形连接和停止标准

extern HCURSOR m_HCursor;		//设置光标

extern enum DRAW {
	DRAW_DOT,			//点	0
	DRAW_LINE,			//直线	
	DRAW_RECTANGLE,		//矩形
	DRAW_CIRCLE,		//圆
	DRAW_ELLIPSE,		//椭圆
	DRAW_ARC,			//圆弧
	DRAW_POLYGON,		//多边形
	DRAW_POLYLINE,		//折线	7
	DRAW_CURVE,			//曲线
	DRAW_BIGORSMALL,	//缩放操作
	DRAW_ROUND,			//旋转操作
	DRAW_MOVE			//平移操作
};


