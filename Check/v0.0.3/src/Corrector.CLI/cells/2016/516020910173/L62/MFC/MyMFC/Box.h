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
	CRect Box::GetContent()
	{
		//ȡ���߿���������
		return CRect(left+1,top+1,right-1,bottom-1);
	}
};

