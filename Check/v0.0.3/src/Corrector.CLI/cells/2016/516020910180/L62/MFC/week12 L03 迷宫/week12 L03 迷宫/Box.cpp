#include "StdAfx.h"
#include "Box.h"

CRect Box::GetContent()
{
	//ȡ���߿����ڵ�����
	return CRect(left+1,top+1,right-1,bottom-1);
}

Box::Box(void)
{
}


Box::~Box(void)
{
}
