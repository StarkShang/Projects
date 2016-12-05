#pragma once
#include "atltypes.h"
class Ball :
	public CRect
{
public:
	Ball(void);
	~Ball(void);
public:
	int m_rowIndex;
	int m_colIndex;
};

