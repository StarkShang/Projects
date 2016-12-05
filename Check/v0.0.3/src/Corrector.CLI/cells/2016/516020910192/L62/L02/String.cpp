#include"String.h"//包含头文件
String::String(char* str)
{
	for(int i=0;i<1024;i++)
	{
		if (str[i]=='\0')
		{count=i;//字符串长度
		capacity=count*4;//内存空间大小
		content = new char [capacity];//new 出相应的内存空间
		break;
		}
	}
	for(int j=0;j<count;j++)//给相应的成员赋值
	{
	{content[j] = str[j];}
}
String::String(const String& str)
{
	this->capacity = str.capacity; //内存空间大小
	this->count = str.count; //字符串长度
	content = new char[capacity]; //new 出相应的内存空间
	for (int j = 0; j < count; j++) //给相应的成员赋值
	{
		this->content[j] = str.content[j];
	}
}
String::~String()
{
	delete content;//释放空间
}
char* String::GetCString()
{
	content[count] = '\0'; //将其转成C风格的字符串
	return content; //返回content首地址
}