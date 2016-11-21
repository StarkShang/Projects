
// 上机作业.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C上机作业App: 
// 有关此类的实现，请参阅 上机作业.cpp
//

class C上机作业App : public CWinApp
{
public:
	C上机作业App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C上机作业App theApp;