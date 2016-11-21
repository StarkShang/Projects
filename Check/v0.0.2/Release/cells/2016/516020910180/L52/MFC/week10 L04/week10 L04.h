
// week10 L04.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Cweek10L04App:
// 有关此类的实现，请参阅 week10 L04.cpp
//

class Cweek10L04App : public CWinApp
{
public:
	Cweek10L04App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cweek10L04App theApp;