#pragma once

#include "stdafx.h"		//2015(不包括)以上版本需用#include "pch.h"
#include <afx.h>


class UndoList					//作为处理节点信息的节点，储存每一步操作数据，指向下一个子节点
{
public:

private:

};


class List			//保存每一个绘图类数据，指向下一个父节点
{
public:
	//操作（公共接口）
	virtual void OnDraw(CDC * pDC);
public:
	//特性（变量）
	List * Lnext = NULL;

	UndoList * Nnext = NULL;	//撤回子链表先不操作
	List() {};			
	virtual List * Initialize();					//链表初始化，注意返回值的接受
	virtual void Insert(List * L,int index,int value);		//插入链表
	virtual void Increate(List * L);	//增加链表
	virtual void Delete(List * L);		//删除链表
	virtual List * Find(List * L);		//查找链表
	virtual void DestoryList(List * L);
	virtual void Isempty(List * L);
public:
	//重写
	virtual void Serialize(CArchive  &ar);			//重写这个函数

private:

	CPoint m_DfirPoint, m_DsecPoint;//第一个点，第二个点
	COLORREF m_DColor;				//颜色（后续如需要可细分）
	int m_DLineType;				//线型
	int m_DLineSize;				//线尺寸
	int m_DDrawType;				//画图类型
	int m_DClassType;				//保存的类的类型

};


class DrawShape					//绘图基类
{
public:
	//特性（变量）
	CPoint m_StartPoint;		//起点
	CPoint m_EndPoint;			//终点
	CPoint m_OldPoint;			//上一个点
	COLORREF m_Color;			//颜色（后续如需要可细分）
	int m_LineType;				//线型
	int m_LineSize;				//线尺寸
	int m_DrawType;				//画图类型
public:
	//操作（公共接口）
	DrawShape() {};
	DrawShape(CPoint StartPoint,CPoint EndPoint,CPoint OldPoint,COLORREF Color,
		int LineType,int LineSize,int DrawType);
public:
	//重写（虚函数）
	virtual void OnDraw(CDC * pDC);
	virtual void Serialize(CArchive  &ar);			//重写这个函数

protected:

};



class Cdot :public DrawShape			//点
{
public:
	Cdot() {};
	Cdot(POINT point, int drawtype, int linetype, int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint);
	CPoint m_firpoint;
protected:
	
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
};

class Cline :public DrawShape			//直线
{
public:
	Cline() {};
	Cline(CPoint firPoint, CPoint secPoint, int drawtype, int linetype,
		int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint);
	CPoint m_firpoint, m_secpoint;
protected:
	
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
};

class Crectangle :public DrawShape		//矩形
{
public:
	Crectangle() {};
	Crectangle(POINT firpoint, POINT secpoint, int drawtype, int linetype,
		int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint, CPoint);
	CPoint m_firpoint, m_secpoint;
protected:
	
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
	CDC *pDC;
};

class Ccircle :public DrawShape		//圆
{
public:
	Ccircle() {};
	Ccircle(POINT firpoint, POINT secpoint, int drawtype, int linetype,
		int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint, CPoint);
	void Squaring(CPoint &pFirst, CPoint &pSecond);
	CPoint m_firpoint, m_secpoint;
protected:
	
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
};

class Carc :public DrawShape			//圆弧
{
public:
	Carc() {};

	Carc(CPoint *points, int drawtype, int linetype,
		double R, int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint *point,int R);
	CPoint m_points[3];
protected:
	
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
	double m_R;
};

class Cellipse :public DrawShape		//椭圆
{
public:
	Cellipse() {};
	Cellipse(CPoint firpoint, CPoint secpoint, int drawtype, int linetype,
		int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint, CPoint);
	CPoint m_firpoint, m_secpoint;
protected:
	
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
};

class Cpolygon :public DrawShape		//多边形
{
public:
	Cpolygon() {};
	Cpolygon(CPoint points[50], int num, int drawtype, int linetype,
		int linesize, COLORREF color);
	void OnDraw(CDC *);
	void Change(CPoint * point, int num);
	CPoint m_points[50];
protected:
	
	int m_num;
	CPoint m_firpoint, m_secpoint;
	COLORREF m_color;
	int m_linesize, m_linetype, m_drawtype;
};


//class Cpolyline :public DrawShape		//多折线
//{
//public:
//	Cpolyline() {};
//	Cpolyline(POINT points[20], int num, int Width, int Style,
//		COLORREF Color, CDC * dc);
//	void OnDraw();
//
//protected:
//	POINT m_points[50];
//	int m_num;
//	COLORREF m_color;
//	int m_linesize, m_linetype, m_drawtype;
//	CDC *pDC;
//};


//-------	各画图类链表	--------


//直线类
//继承List并且在DrawShape类后，可引用相应对象
class LineList :public List
{
public:
	//特性
	Cline * line = new(Cline);			//申请空间保存传进的DrawShape类
	LineList * linenext;
	int m_Index;				//链表节点数记录

public:
	//操作
	LineList* Add(Cline *line);		//头插法（可能方便后续undo）,shape为以申请的空间
	LineList * Initialize();					//链表初始化，注意返回值的接受
	//void Insert(LineList * L, int index, int value);		//插入链表
	//void Increate(LineList * L);	//增加链表
	//void Delete(LineList * L);		//删除链表
	//LineList * Find(LineList * L);		//查找链表
	//void DestoryList(LineList * L);
	//void Isempty(LineList * L);
	//void Serialize(CArchive &ar);
};

//矩形类链表
//继承List并且在DrawShape类后，可引用相应对象
class RectangleList :public List
{
public:
	//特性
	Crectangle * rectangle = new(Crectangle);			//申请空间保存传进的DrawShape类
	RectangleList * rectnext;
	int m_Index;				//链表节点数记录

public:
	//操作
	RectangleList * Add(Crectangle * rectangle);		//头插法（可能方便后续undo）,shape为以申请的空间
	RectangleList * Initialize();					//链表初始化，注意返回值的接受

};


//圆类链表
//继承List并且在DrawShape类后，可引用相应对象
class CircleList :public List
{
public:
	//特性
	Ccircle *circle = new(Ccircle);			//申请空间保存传进的DrawShape类
	CircleList * circlenext;
	int m_Index;				//链表节点数记录

public:
	//操作
	CircleList *  Add(Ccircle *circle);		//头插法（可能方便后续undo）,shape为以申请的空间
	CircleList * Initialize();					//链表初始化，注意返回值的接受

};

//圆弧类链表
//继承List并且在DrawShape类后，可引用相应对象
class ArcList :public List
{
public:
	//特性
	Carc * arc = new(Carc);			//申请空间保存传进的DrawShape类
	ArcList * arcnext;
	int m_Index;				//链表节点数记录

public:
	//操作

	ArcList *  Add(Carc * arc);		//头插法（可能方便后续undo）,shape为以申请的空间
	ArcList * Initialize();					//链表初始化，注意返回值的接受
};


//多边形类链表
//继承List并且在DrawShape类后，可引用相应对象
class PolygonList :public List
{
public:
	//特性
	Cpolygon * polygon = new(Cpolygon);			//申请空间保存传进的DrawShape类
	PolygonList * polynext;
	int m_Index;				//链表节点数记录

public:
	//操作
	PolygonList * Add(Cpolygon * polygon);		//头插法（可能方便后续undo）,shape为以申请的空间
	PolygonList * Initialize();					//链表初始化，注意返回值的接受

};


//椭圆类链表
//继承List并且在DrawShape类后，可引用相应对象
class EllipseList :public List
{
public:
	//特性
	Cellipse * ellipse = new(Cellipse);			//申请空间保存传进的DrawShape类
	EllipseList * ellipsenext;
	int m_Index;				//链表节点数记录

public:
	//操作
	EllipseList *  Add(Cellipse * ellipse);		//头插法（可能方便后续undo）,shape为以申请的空间
	EllipseList * Initialize();					//链表初始化，注意返回值的接受

};


//点
//继承List并且在DrawShape类后，可引用相应对象
class DotList :public List
{
public:
	//特性
	Cdot * dot = new(Cdot);			//申请空间保存传进的DrawShape类
	DotList * dotnext;
	int m_Index;				//链表节点数记录

public:
	//操作
	DotList *  Add(Cdot *dot);		//头插法（可能方便后续undo）,shape为以申请的空间
	DotList * Initialize();					//链表初始化，注意返回值的接受

};





