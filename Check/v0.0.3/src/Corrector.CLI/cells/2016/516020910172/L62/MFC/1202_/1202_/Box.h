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
CRect Box::GetContent()
{
	//ȡ���߿����ڵ�����
	return CRect(left+1,top+1,right-1,bottom-1 );
}

