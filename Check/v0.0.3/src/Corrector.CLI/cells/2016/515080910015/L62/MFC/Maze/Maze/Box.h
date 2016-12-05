#pragma once
#include "atltypes.h"
class Box :
	public CRect
{
public:
	Box(void);
	bool m_isSelected;
	bool m_isEnd;
	CRect GetContent(); 
	~Box(void);
};

