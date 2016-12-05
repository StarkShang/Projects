#include"String.h"


String::String(char* str)     //赋值构造函数
{
	count=0;
    for(int i=0;str[i]!='\0';i++)
	   count++;
    capacity=count+1;
    content =new char [capacity]; //为content变量new出内存空间
    for(int i=0;i<count;i++)
	   content[i]=str[i];  //给相应成员赋值
}

 String::String(const String& str)      //拷贝构造函数
 {
	 this->count=str.count;      
	 content =new char [count+1];  //为content变量new出内存空间
     for(int i=0;i<count;i++)
	   this->content[i]=str.content[i];   //给相应成员赋值
	
 }
String::~String()
{ 
	delete []content;     //释放空间
}
char*String::GetCString()
{ 
	 content[count]='\0';   //content内字符串以‘\0’结尾
	 return content;        //返回首地址
}
