
// ϰ��4.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cϰ��4App:
// �йش����ʵ�֣������ ϰ��4.cpp
//

class Cϰ��4App : public CWinApp
{
public:
	Cϰ��4App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cϰ��4App theApp;