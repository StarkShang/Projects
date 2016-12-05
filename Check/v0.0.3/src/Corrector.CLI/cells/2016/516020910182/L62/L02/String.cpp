#include "String.h"

String::String(char* str)
{

	count=0;
	int i=0;
    while(*(str+i)!='\0')
	{
		i++;
		count++;
	}
	capacity=count+1;
    content=new char[capacity];
	for(int t=0;t<count;t++)
	{
		*(content+t)=*(str+t);
	}

}
String::String(const String& str)
{
    capacity=str.capacity;
	count=str.count;
    content=new char[capacity];
	for(int t=0;t<count;t++)
	{
		*(content+t)=*((str.content)+t);
	}
	*(content+count)='\0';
}
char* String::GetCString()
{
    return content;
}
String::~String()
{
	delete[] content;
}