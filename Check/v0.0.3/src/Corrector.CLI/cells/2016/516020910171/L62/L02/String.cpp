#include "String.h"
#include <iostream>
#include <string.h>

String::String(char* str)//赋值构造函数
{
if (str==NULL){  
        content=new char[1]; //对空字符串自动申请存放结束标志'\0'的空间  
    if (content==NULL)
	{//内存是否申请成功  
        std::cout<<"申请内存失败！"<<std::endl;
		exit(1);
    }  
    content[0]='\0';  
    }  
    else{  //若申请内存成功
        count=strlen(str);  //计算count的数值
        content=new char[count+1];  
        if (content==NULL){//内存是否申请成功  
            std::cout<<"申请内存失败！"<<std::endl;  
			exit(1);
        }  
        strcpy(content,str);  //将字符串填入数组中
    }  
}  

String::String(const String& str)//拷贝构造函数
{
	count=strlen(str.content);  //计算长度
    content=new char[count+1];  
    if (content==NULL)
	{//内存是否申请成功  
        std::cout<<"失败！"<<std::endl;  
        exit(1);  
    }  
    strcpy(content,str.content);  //复制函数
}  

String::~String()//析构函数，释放content所占用的空间
{
	delete []content;
}

char*String::GetCString()//将当前类转换成c风格的字符串
{
	
	if(content[count]!='\0')
		content[count]='\0';
	return content;
}