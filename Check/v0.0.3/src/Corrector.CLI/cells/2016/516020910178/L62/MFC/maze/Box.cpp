#include "StdAfx.h"
#include "Box.h"


Box::Box(void)
{
}


Box::~Box(void)
{
}
CRect Box::GetContent()
{
	//ȡ���߿����ڵ�����
	return CRect (left+1,top+1,right-1,bottom-1);
}