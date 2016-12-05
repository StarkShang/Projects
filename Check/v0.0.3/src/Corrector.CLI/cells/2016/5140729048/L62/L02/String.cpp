#include "String.h"
int len(char* str)
{
	int i=0;
	for(i=0;;i++)
	{
	if (str[i]=='\0')
		return i;
	}
}
String::String(char* str)
{
count=len(str);
capacity=count-1;
content=new char[capacity];
content=str;
}
String::String(const String &str)
{
this->count=str.count;
capacity=count-1;
content=new char[capacity];
this->content=str.content;
}
char* String::GetCString()
{
 content[capacity+1]='\0';
 return content;
}