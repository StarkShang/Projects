#include "String.h"
#include <string>
using namespace std;

String::String(char* str)
{
    count= strlen(str);               //赋值字符串的长度
	capacity = count + 1;             //赋值所占内部空间
	content = new char[capacity];     //为content变量new出相应的内存空间
	int i;
	for(i=0;i<count;i++) content[i]=str[i];


}
String::String(const String& str)
{
	content = new char[str.capacity];  //new出相同的空间
	capacity = str.capacity;
	count = str.count;
	int j;
	for(j=count;j>=0;j--) content[j]=str.content[j];//拷贝前一个String对象的字符数组
}

char* String::GetCString()
{
	content[count]='\0';   //在字符数组最后加上'\0'结尾
	return content;
}
String::~String()
{
	delete content;
}