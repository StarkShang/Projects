#include"String.h"
String::String(char* str) 
{ content= new  char [1024] ;//new 出存储空间
count=0;
capacity =1024;//初始化
	for(int i  =0; i<capacity;i++)
{if (str [i]!= '\0')
{content[i]=str[i];
count=count+1;
}//若不到末项， 循环赋值
else break;//否则break
}
}
String:: String(const String& str) 
	{   content= new  char [1024] ;//new 出存储空间
 capacity= str.capacity ;
count=str.count;//拷贝容量和字符串长度
for(int i  =0; i<count;i++)

{content[i]=str.content [i];//循环赋值
 
}
	}

	    
	 char* String::GetCString() 
	 { 
		content[count+1]='\0';//末项后一项为\0
		return   content;//返回content首地址
	 }
	String::~String ()
	 {delete content;}//析构函数