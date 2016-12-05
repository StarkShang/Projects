#include"String.h"
String::String(char* str)//构造函数，根据参数字符串创建String类并赋值
{
	int i;//定义循环变量
	for(i=0;i<1025;i++)//循环找到参数字符串的结束位置，得到字符串长度count
	{
		if(str[i]=='\0') {count=i;break;}
	}
	capacity=count+1;//用count+1位空间以备后用
	content=new char[capacity];//开辟内存空间
	for(i=0;i<count;i++)//给类变量赋值
	{
		content[i]=str[i];
	}
}
String::String(const String& str)//拷贝构造，复制参数String类
{
	count=str.count;//赋值count
	capacity=count+1;//赋值capacity
	content=new char[capacity];//开辟空间
	for(int i=0;i<count;i++)//赋值
	{
		content[i]=str.content[i];
	}
}
String::~String()//析构函数，delete content的内容
{
	delete []content;
}
char *String::GetCString()//转换C字符串函数，把String类字符串改为C语言字符串
{
	content[count]='\0';//把最后一位赋为\0
	return content;
}