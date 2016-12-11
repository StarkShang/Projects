#pragma once
class String

{private:
	char* content;//定义字符数组
	int capacity;//定义内存空间
public://
	int count;//定义长度
	String(char* str);//赋值构造函数
	String(const String&str);//拷贝构造函数
	~String();//析构函数
	char* GetCString();//转换函数
};

