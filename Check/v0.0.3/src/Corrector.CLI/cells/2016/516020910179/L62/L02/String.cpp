#include"String.h"

String::String (char* str)
{
	count=0;//初始化
	for(int i=0;str[i]!='\0';i++)
	{count++;}//求字符串中字符个数（不含\0）
	capacity=count+1;//总字节数
    content=new char[capacity];//为content变量new出相应的内存空间
	for(int i=0;i<capacity;i++)
	{content[i]=str[i];}//赋值
}

String::String (const String&str)
{
	count=0;
	int i=0;
	this->count=str.count;
	this->capacity=str.capacity;
	this->content=new char[capacity];
	for(i;i<count;i++)
	{
		this->content[i]=str.content[i];
	}
	
}

String::~String()
{
	delete[]content;//释放内存
}

char* String::GetCString()
{
	if(count<capacity)
	{
		content[count]='\0';
	}
	else
		content[capacity]='\0';
	return content;
}
	