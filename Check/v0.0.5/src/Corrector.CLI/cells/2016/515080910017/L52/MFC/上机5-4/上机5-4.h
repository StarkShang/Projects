
// �ϻ�5-4.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ϻ�54App:
// �йش����ʵ�֣������ �ϻ�5-4.cpp
//

class C�ϻ�54App : public CWinApp
{
public:
	C�ϻ�54App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ϻ�54App theApp;