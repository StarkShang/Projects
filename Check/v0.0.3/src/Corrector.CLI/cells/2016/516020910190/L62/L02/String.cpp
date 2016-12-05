#include"String.h"
String::String(char*str)
{   count=0;
 capacity=1024;//初始化数据
 content=new char[1024];//new出空间
for(int i=0;i<capacity;i++)
		{
			if(str[i]!='\0')
			{
					content[i]=str[i];//将字符赋值到content中，去掉‘\0'
			      count+=1;//计算字符长度
			}
			else
			{break;}
	    }
}
String::String(const String &str)
{   content=new char[1024];//new出空间
	capacity=str.capacity;
	for(int i=0;i<count;i++)
	{
	content[i]=str.content[i];
	}
	count=str.count;//拷贝String中成员
}
String::~String()
{
			delete content;//释放空间
		}
char *String::GetCString()
{  
	content[count+1]='\0';//确保字符串以'\0'结尾
	return content;
}
