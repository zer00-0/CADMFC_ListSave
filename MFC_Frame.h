
// MFC_Frame.h : MFC_Frame Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_FrameApp:
// �йش����ʵ�֣������ MFC_Frame.cpp
//

class CMFC_FrameApp : public CWinAppEx
{
public:
	CMFC_FrameApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_FrameApp theApp;
