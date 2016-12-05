#pragma once
#include "atltypes.h"
class Box :
	public CRect
{
	public:
	Box(void);
	~Box(void);
public:
	bool m_isSelected;
	bool m_isEnd;
public:
	CRect GetContent();
};

