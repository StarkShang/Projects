#pragma once
class String
{
private:
	char*content;//字符串内容
	int capacity;//字符串空间
public:
	int count;//字符串长度
	String(char*str);//构造函数
	String(const String& str);//复制构造函数
	~String();//析构函数
	char*GetCString();//返回C类型字符串
	
};


