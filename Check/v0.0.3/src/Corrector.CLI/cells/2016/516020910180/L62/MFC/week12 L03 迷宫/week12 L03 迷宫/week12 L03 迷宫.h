
// week12 L03 �Թ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cweek12L03�Թ�App:
// �йش����ʵ�֣������ week12 L03 �Թ�.cpp
//

class Cweek12L03�Թ�App : public CWinApp
{
public:
	Cweek12L03�Թ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cweek12L03�Թ�App theApp;