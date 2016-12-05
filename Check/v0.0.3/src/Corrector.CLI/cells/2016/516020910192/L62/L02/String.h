#pragma once
class String
{
private:
	char* content;//表示 String 保存的字符数组数据
	int capacity;//表示 content 所占的内存空间; 

public:
	int count;//content 中字符串的长度; 
	String(char* str);//赋值构造函数
	String(const String& str);//拷贝构造函数
    ~String();//析构函数
	char*GetCString();//转换函数
};

