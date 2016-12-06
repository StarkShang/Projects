#include"StdAfx.h"
#include "Box.h"



CRect Box::GetContent()
{
	//去除边框以内的区域
	return CRect(left + 1, top + 1, right - 1, bottom - 1);
}
