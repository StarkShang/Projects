
// MyMFC2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyMFC2App:
// �йش����ʵ�֣������ MyMFC2.cpp
//

class CMyMFC2App : public CWinApp
{
public:
	CMyMFC2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyMFC2App theApp;