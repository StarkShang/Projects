
// week10 L04.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cweek10L04App:
// �йش����ʵ�֣������ week10 L04.cpp
//

class Cweek10L04App : public CWinApp
{
public:
	Cweek10L04App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cweek10L04App theApp;