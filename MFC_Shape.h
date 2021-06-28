#pragma once

#include "stdafx.h"		//2015(������)���ϰ汾����#include "pch.h"
#include <afx.h>


class UndoList					//��Ϊ����ڵ���Ϣ�Ľڵ㣬����ÿһ���������ݣ�ָ����һ���ӽڵ�
{
public:

private:

};


class List			//����ÿһ����ͼ�����ݣ�ָ����һ�����ڵ�
{
public:
	//�����������ӿڣ�
	virtual void OnDraw(CDC * pDC);
public:
	//���ԣ�������
	List * Lnext = NULL;

	UndoList * Nnext = NULL;	//�����������Ȳ�����
	List() {};			
	virtual List * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���
	virtual void Insert(List * L,int index,int value);		//��������
	virtual void Increate(List * L);	//��������
	virtual void Delete(List * L);		//ɾ������
	virtual List * Find(List * L);		//��������
	virtual void DestoryList(List * L);
	virtual void Isempty(List * L);
public:
	//��д
	virtual void Serialize(CArchive  &ar);			//��д�������

private:

	CPoint m_DfirPoint, m_DsecPoint;//��һ���㣬�ڶ�����
	COLORREF m_DColor;				//��ɫ����������Ҫ��ϸ�֣�
	int m_DLineType;				//����
	int m_DLineSize;				//�߳ߴ�
	int m_DDrawType;				//��ͼ����
	int m_DClassType;				//������������

};


class DrawShape					//��ͼ����
{
public:
	//���ԣ�������
	CPoint m_StartPoint;		//���
	CPoint m_EndPoint;			//�յ�
	CPoint m_OldPoint;			//��һ����
	COLORREF m_Color;			//��ɫ����������Ҫ��ϸ�֣�
	int m_LineType;				//����
	int m_LineSize;				//�߳ߴ�
	int m_DrawType;				//��ͼ����
public:
	//�����������ӿڣ�
	DrawShape() {};
	DrawShape(CPoint StartPoint,CPoint EndPoint,CPoint OldPoint,COLORREF Color,
		int LineType,int LineSize,int DrawType);
public:
	//��д���麯����
	virtual void OnDraw(CDC * pDC);
	virtual void Serialize(CArchive  &ar);			//��д�������

protected:

};



class Cdot :public DrawShape			//��
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

class Cline :public DrawShape			//ֱ��
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

class Crectangle :public DrawShape		//����
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

class Ccircle :public DrawShape		//Բ
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

class Carc :public DrawShape			//Բ��
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

class Cellipse :public DrawShape		//��Բ
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

class Cpolygon :public DrawShape		//�����
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


//class Cpolyline :public DrawShape		//������
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


//-------	����ͼ������	--------


//ֱ����
//�̳�List������DrawShape��󣬿�������Ӧ����
class LineList :public List
{
public:
	//����
	Cline * line = new(Cline);			//����ռ䱣�洫����DrawShape��
	LineList * linenext;
	int m_Index;				//����ڵ�����¼

public:
	//����
	LineList* Add(Cline *line);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	LineList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���
	//void Insert(LineList * L, int index, int value);		//��������
	//void Increate(LineList * L);	//��������
	//void Delete(LineList * L);		//ɾ������
	//LineList * Find(LineList * L);		//��������
	//void DestoryList(LineList * L);
	//void Isempty(LineList * L);
	//void Serialize(CArchive &ar);
};

//����������
//�̳�List������DrawShape��󣬿�������Ӧ����
class RectangleList :public List
{
public:
	//����
	Crectangle * rectangle = new(Crectangle);			//����ռ䱣�洫����DrawShape��
	RectangleList * rectnext;
	int m_Index;				//����ڵ�����¼

public:
	//����
	RectangleList * Add(Crectangle * rectangle);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	RectangleList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���

};


//Բ������
//�̳�List������DrawShape��󣬿�������Ӧ����
class CircleList :public List
{
public:
	//����
	Ccircle *circle = new(Ccircle);			//����ռ䱣�洫����DrawShape��
	CircleList * circlenext;
	int m_Index;				//����ڵ�����¼

public:
	//����
	CircleList *  Add(Ccircle *circle);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	CircleList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���

};

//Բ��������
//�̳�List������DrawShape��󣬿�������Ӧ����
class ArcList :public List
{
public:
	//����
	Carc * arc = new(Carc);			//����ռ䱣�洫����DrawShape��
	ArcList * arcnext;
	int m_Index;				//����ڵ�����¼

public:
	//����

	ArcList *  Add(Carc * arc);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	ArcList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���
};


//�����������
//�̳�List������DrawShape��󣬿�������Ӧ����
class PolygonList :public List
{
public:
	//����
	Cpolygon * polygon = new(Cpolygon);			//����ռ䱣�洫����DrawShape��
	PolygonList * polynext;
	int m_Index;				//����ڵ�����¼

public:
	//����
	PolygonList * Add(Cpolygon * polygon);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	PolygonList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���

};


//��Բ������
//�̳�List������DrawShape��󣬿�������Ӧ����
class EllipseList :public List
{
public:
	//����
	Cellipse * ellipse = new(Cellipse);			//����ռ䱣�洫����DrawShape��
	EllipseList * ellipsenext;
	int m_Index;				//����ڵ�����¼

public:
	//����
	EllipseList *  Add(Cellipse * ellipse);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	EllipseList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���

};


//��
//�̳�List������DrawShape��󣬿�������Ӧ����
class DotList :public List
{
public:
	//����
	Cdot * dot = new(Cdot);			//����ռ䱣�洫����DrawShape��
	DotList * dotnext;
	int m_Index;				//����ڵ�����¼

public:
	//����
	DotList *  Add(Cdot *dot);		//ͷ�巨�����ܷ������undo��,shapeΪ������Ŀռ�
	DotList * Initialize();					//�����ʼ����ע�ⷵ��ֵ�Ľ���

};





