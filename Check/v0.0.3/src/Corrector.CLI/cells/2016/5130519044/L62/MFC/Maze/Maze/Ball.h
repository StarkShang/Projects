#pragma once
#include "atltypes.h"
class Ball :
	public CRect
{
public:
	int m_rowIndex;
	int m_colIndex;
public:
	Ball(void);
	~Ball(void);
};

