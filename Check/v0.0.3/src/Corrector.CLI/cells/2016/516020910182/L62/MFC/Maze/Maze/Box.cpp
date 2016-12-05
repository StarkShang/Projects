#include "StdAfx.h"
#include "Box.h"


Box::Box(void)
	: m_isSelected(false)
	, m_isEnd(false)
{
}


Box::~Box(void)
{
}


CRect Box::GetContent(void)
{
	return CRect(left+1,top+1,right-1,bottom-1);
}
