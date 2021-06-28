#include "stdafx.h"
#include "Data.h"

int LinkFlag = 1;
int DrawType  = 1;
int LineType = 0;		//����
int PenType = 0;			//����
int LineSize = 0;
int moveFlag = 0;
double R = 0;
int arcnum = 0;
int m_num = 0;
int LBottonUpnum = 0;
COLORREF m_Color = RGB(0, 0, 0);
bool LBottomDown = false;		//��갴�±�־λ,��ҪΪȷ��up��mousemove���ٲ���
bool RBottomDown = false;		//��갴�±�־λ����Ҫ��Ϊ���������������Ӻ�ֹͣ��׼

LineList * linehead = new(LineList);		//��¼ͷ���
LineList * linelast = NULL;		//��¼β���
LineList * linelink = new(LineList);		//��¼��ǰ�ڵ�

RectangleList * recthead = new(RectangleList);		//��¼����ͷ���(��ͷ
RectangleList * rectlast = NULL;		//��¼β���
RectangleList * rectlink = new(RectangleList);		//��¼��ǰ�ڵ�

CircleList * circlehead = new(CircleList);		//��¼Բͷ���(��ͷ)
CircleList * circlelast = NULL;		//��¼β���
CircleList * circlelink = new(CircleList);		//��¼��ǰ�ڵ�

ArcList * archead = new(ArcList);		//��¼Բ��ͷ���(��ͷ)
ArcList * arclast = NULL;		//��¼β���
ArcList * arclink = new(ArcList);		//��¼��ǰ�ڵ�

DotList * dothead = new(DotList);		//��¼��ͷ���(��ͷ)
DotList * dotlast = NULL;		//��¼β���
DotList * dotlink = new(DotList);		//��¼��ǰ�ڵ�

EllipseList * ellipsehead = new(EllipseList);		//��¼��Բͷ���(��ͷ)
EllipseList * ellipselast = NULL;		//��¼β���
EllipseList * ellipselink = new(EllipseList);		//��¼��ǰ�ڵ�

PolygonList * polygonhead = new(PolygonList);		//��¼�����ͷ���(��ͷ)
PolygonList * polygonlast = NULL;		//��¼β���
PolygonList * polygonlink = new(PolygonList);		//��¼��ǰ�ڵ�

DotList * dotlist = NULL;
LineList * linelist = NULL;
CircleList * circlelist = NULL;
ArcList * arclist = NULL;
EllipseList * ellipselist = NULL;
RectangleList *  rectanglelist = NULL;
PolygonList *  polygonlist = NULL;

HCURSOR m_HCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);



