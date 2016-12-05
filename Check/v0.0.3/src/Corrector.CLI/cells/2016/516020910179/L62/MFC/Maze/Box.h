#pragma once
#include "atltypes.h"

class Box :
	public CRect
{
public:
	Box(void);
	~Box(void);
	bool m_isSelected;
	bool m_isEnd;
	CRect GetContent(); 
};

