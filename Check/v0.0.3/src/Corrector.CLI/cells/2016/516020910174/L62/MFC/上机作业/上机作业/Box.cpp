#include"StdAfx.h"
#include "Box.h"


void Box::H()
{
	this->m_isEnd = false;
	this->m_isSelected = false;
}

CRect Box::GetContent()
{
	//ȥ���߿����ڵ�����
	return CRect(left + 1, top + 1, right - 1, bottom - 1);
}
