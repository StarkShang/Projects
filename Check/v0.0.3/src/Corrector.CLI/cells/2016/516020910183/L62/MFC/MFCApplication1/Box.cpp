#include "stdafx.h"
#include "Box.h"


Box::Box()
{
}


Box::~Box()
{
}
CRect Box::GetContent()
{
	//ȥ���߿����ڵ�����
	return CRect(left + 1, top + 1, right - 1, bottom - 1);
}