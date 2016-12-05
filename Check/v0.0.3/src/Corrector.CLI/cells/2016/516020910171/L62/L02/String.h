#pragma once
class String//声明类类型
{
public://以下为公有
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char* GetCString();
private://以下为私有变量
	char* content;
	int capcity;
};

