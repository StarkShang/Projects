
#include"String.h"
String::String(char* str)
{
	for(int i=0;i<1025;i++)
	{
		if(str[i]=='\0') 
		{
			count=i;break;
		}
	}//计算字符串的长度
	content=new char[1025];//开出新的内存空间
	capacity=count;
	for(int i=0;i<count;i++)
	{
		content[i]=str[i];
	}//给content赋值
}
String::String(const String& str)
{
	this->content=new char[1025];
	this->count=str.count;
	for(int i=0;i<count;i++)
	{
		this->content[i]=str.content[i];
	}
}//拷贝构造函数
String::~String()
{
	delete []content;
}//析构函数
char *String::GetCString()
{
	content[count]='\0';
	return content;

}//添加'\0'，获取字符串