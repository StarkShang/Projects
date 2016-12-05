#include"String.h"
String::String(char*str)
{
	capacity=1025;//空间为1025字符
	content=new char[capacity];//给予空间
	int i=0;//初始化变量
	count=0;//初始化变量
	while (str[i]!='\0')//记录字符串内容，计算长度
	{
		*(content+i)=*(str+i);
		count++;
		i++;
	}
}
String::String(const String& str)
{
	capacity=1025;//空间为1025字符
	content=new char[capacity];//给予空间
	int i=0;//初始化变量
	while (str.content[i]!='\0')//记录字符串内容
	{
		*(content+i)=*(str.content+i);
		i++;
	}
}
char* String::GetCString()
{
	if(*(content+count-1)!='\0')//若字符串结尾不为‘\0’
	{
		if(count<1025)//若不会溢出
		{
			*(content+count)='\0';//转化为c类型字符串
			return content;//返回地址
		}
	
	}
	else //若为‘\0’，直接返回
		return content;
	
}
String::~String()//析构函数
{
	delete []content;
}