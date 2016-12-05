#pragma once
class String//字符串类，成员变量：字符串指针，所占空间大小，字符串长度；成员函数：构造，析构，转换成C字符串
{
private:
	char *content;
	int capacity;
public:
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char *GetCString(); 
};