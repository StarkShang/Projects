#pragma once
class String
{
private:
	char*content;            //保存字符组
	int capacity;            // content所占空间
public:
	int count;                  //字符长度
	String(char*str);           //根据char*字符串str创建String类的对象
	String(const String&str);  //根据String字符串类对象创建String类的对象
	~String();                 //释放content所占用的空间
	char* GetCString();       //将当前类转换成c风格的字符串
};

