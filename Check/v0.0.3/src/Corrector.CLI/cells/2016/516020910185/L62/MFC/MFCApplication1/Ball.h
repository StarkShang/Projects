#pragma once
#include "atltypes.h"
class Ball :
	public CRect
{
public:
	Ball();
	~Ball();
	int m_rowIndex;
	int m_colIndex;
};

