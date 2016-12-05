#pragma once
#include "atltypes.h"
class Box :
	public CRect
{
public:
	Box(void);
	~Box(void);
	 bool m_isSelected,m_isEnd;
	 CRect GetContent();
};

