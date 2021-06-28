#pragma once

#include "MFC_Shape.h"


extern LineList * linehead;		//��¼ֱ��ͷ���(��ͷ)
extern LineList * linelast;		//��¼β���
extern LineList * linelink;		//��¼��ǰ�ڵ�

extern RectangleList * recthead;		//��¼����ͷ���(��ͷ)
extern RectangleList * rectlast;		//��¼β���
extern RectangleList * rectlink;		//��¼��ǰ�ڵ�

extern CircleList * circlehead;		//��¼Բͷ���(��ͷ)
extern CircleList * circlelast;		//��¼β���
extern CircleList * circlelink;		//��¼��ǰ�ڵ�

extern ArcList * archead;		//��¼Բ��ͷ���(��ͷ)
extern ArcList * arclast;		//��¼β���
extern ArcList * arclink;		//��¼��ǰ�ڵ�

extern DotList * dothead;		//��¼��ͷ���(��ͷ)
extern DotList * dotlast;		//��¼β���
extern DotList * dotlink;		//��¼��ǰ�ڵ�

extern EllipseList * ellipsehead;		//��¼��Բͷ���(��ͷ)
extern EllipseList * ellipselast;		//��¼β���
extern EllipseList * ellipselink;		//��¼��ǰ�ڵ�

extern PolygonList * polygonhead;		//��¼�����ͷ���(��ͷ)
extern PolygonList * polygonlast;		//��¼β���
extern PolygonList * polygonlink;		//��¼��ǰ�ڵ�


extern DotList * dotlist;
extern LineList * linelist;
extern CircleList * circlelist;
extern ArcList * arclist;
extern EllipseList * ellipselist;
extern RectangleList *  rectanglelist;
extern PolygonList *  polygonlist;
extern int LinkFlag;		//�����״�ִ�б�־λ
extern int DrawType;
extern int LineType;		//����
extern int PenType;			//����
extern int LineSize;
extern int arcnum;		//Բ��������¼
extern int m_num;		//��¼����ε���
extern int moveFlag;	//ƽ�Ʋ�����׼λ��0Ϊ�����У�1Ϊ����,2Ϊ�м���ɣ������ڽ��в���)
extern double R;		//Բ���뾶
extern COLORREF m_Color;
extern int LBottonUpnum;
extern bool LBottomDown;		//��갴�±�־λ,��ҪΪȷ��up��mousemove���ٲ���
extern bool RBottomDown;		//��갴�±�־λ����Ҫ��Ϊ���������������Ӻ�ֹͣ��׼

extern HCURSOR m_HCursor;		//���ù��

extern enum DRAW {
	DRAW_DOT,			//��	0
	DRAW_LINE,			//ֱ��	
	DRAW_RECTANGLE,		//����
	DRAW_CIRCLE,		//Բ
	DRAW_ELLIPSE,		//��Բ
	DRAW_ARC,			//Բ��
	DRAW_POLYGON,		//�����
	DRAW_POLYLINE,		//����	7
	DRAW_CURVE,			//����
	DRAW_BIGORSMALL,	//���Ų���
	DRAW_ROUND,			//��ת����
	DRAW_MOVE			//ƽ�Ʋ���
};


