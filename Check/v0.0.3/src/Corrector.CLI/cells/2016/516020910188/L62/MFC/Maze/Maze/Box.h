#pragma once
#include "atltypes.h"
class Box :
	public CRect
{
public:
	bool m_isSelected;
	bool m_isEnd;

public:
	CRect GetContent();
	Box(void);
	~Box(void);
};

