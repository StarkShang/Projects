#pragma once
class String
{
private:
	char*content;//私有成员，保存字符数据
	int capacity;//字符所占空间
public:
	int count;//字符串长度
public:
	String(char*str);//赋值构造函数
	String(const String&str);//拷贝构造函数
		~String();//析构函数
		
    char*GetCString();//转换字符串
};

