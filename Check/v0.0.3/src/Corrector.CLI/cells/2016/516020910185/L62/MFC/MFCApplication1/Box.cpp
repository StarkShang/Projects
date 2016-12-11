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
	//去出边框以内的区域
	return CRect(left + 1, top + 1, right - 1, bottom - 1);
}