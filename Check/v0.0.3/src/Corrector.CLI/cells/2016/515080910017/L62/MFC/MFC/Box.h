#pragma once

#ifndef _BOX_H_
#define _BOX_H_

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




#endif