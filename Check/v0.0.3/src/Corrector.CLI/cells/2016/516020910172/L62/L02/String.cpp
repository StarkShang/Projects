#include"String.h";
#include<string.h>;
#include <iostream>;//引入头文件
String::String(char* str)//赋值构造函数
{
	capacity=1024;//赋值
	if (str==NULL)
	{  
        content=new char[1]; //对空字符串自动申请存放结束标志'\0'的空间  
    if (content==NULL)
	{//内存是否申请成功  
        std::cout<<"申请内存失败！"<<std::endl;  
        exit(1);  
    }  
    content[0]='\0';  
    }  
    else{  
        count=strlen(str);//取字符串长度
        content=new char[count+1];
        if (content==NULL)
		{//内存是否申请成功  
            std::cout<<"申请内存失败！"<<std::endl;  
            exit(1);  
        }  
        strcpy(content,str);  
    }  

	count=strlen(content);//取字符串长度
}
String::String(const String & str)//复制构造函数
{
	count=strlen(str.content); //取长度
	content=new char[count+1];
    if (content==NULL){//内存是否申请成功  
        std::cout<<"失败！"<<std::endl;  
        exit(1);  
    }  
    strcpy(content,str.content);  

}
String::~String()//析构函数
{
	delete content;
}
char* String::GetCString()//转化字符串为c风格字符串
{  
	if(content[count]!='\0')//判断字符串结尾是否是\0
	{ content[count]='\0';}//不是将最后一个赋值为\0
	
		return content;//返回content
             
}



	

