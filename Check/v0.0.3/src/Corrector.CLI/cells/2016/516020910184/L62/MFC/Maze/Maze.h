
// Maze.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include"Ball.h"
#include"Box.h"

// CMazeApp:
// �йش����ʵ�֣������ Maze.cpp
//

class CMazeApp : public CWinApp
{
public:
	CMazeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMazeApp theApp;