
// �ϻ���ҵ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ϻ���ҵApp: 
// �йش����ʵ�֣������ �ϻ���ҵ.cpp
//

class C�ϻ���ҵApp : public CWinApp
{
public:
	C�ϻ���ҵApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ϻ���ҵApp theApp;