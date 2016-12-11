#pragma once
#include "atltypes.h"
class Box :
	public CRect
{
public:
	Box();
	~Box();
	bool m_isSelected;
	bool  m_isEnd;
    CRect GetContent();
};

