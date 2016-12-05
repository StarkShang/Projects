#pragma once
class String//定义STRING类
{
private://字符串内容，容量
	char *content;
	int capacity;
public://构造函数，析构函数，显示函数，长度
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char* GetCString();

};

