#pragma once
class String
{
private:
	char* content;                  //String保存的字符数组
	int capacity;                   //content所占的内存空间

public:
	int count;                     //content中字符串的长度
	String(char* str);             //根据char*字符串str创建String类的对象
	String(const String& str);     //根据String字符串类对象创建String类的对象
	~String();                     //释放content所占用的空间
	char* GetCString();            //将当前类转换成c风格的字符串
};

