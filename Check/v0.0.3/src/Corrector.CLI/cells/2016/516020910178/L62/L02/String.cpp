#include"String.h"
 String::String(char* str)//赋值构造函数
 {
	 count=0;//初始化赋值
	 int i=0;
	 for(i=0;str[i]!='\0';i++)//得到 char*字符串 str的长度赋值给count
	 {
		count++;
	 }
	 capacity=count+1;//将count+1赋值给capacity
	 content=new char[capacity];//为content变量new 出相应的内存空间
	  
	 for(i=0;i<count;i++)//循环语句为content成员赋值
	 {
		 content[i]=str[i];
		 
	 }
	
 }
 String:: String(const String& str)//拷贝构造函数
 {
	 
	 count=0;
	int i=0;
	this->count=str.count;//得到str的count
	  this->capacity=this->count+1;//计算相应内存空间
	 this->content=new char[capacity];//为content 变量new出相应的内存空间
	 
	 for(i=0;i<count;i++)//循环语句为content成员赋值
	 {
		 this->content[i]=str.content[i];
		
	 }
	
 }
 
   char*String::GetCString()//GetCString函数将当前类转换成 c风格的字符串
   {
	   if(count<capacity)//如果content 中字符串的长度小于容量
	   {
	   content[count]='\0';//将content的最后一个字符后一位赋值为'\0'
	   return content;//返回content 首地址
	   }
	   else//否则强行将容量最后一位变成'\0'
	   {
	   content[capacity-1]='\0';
	   return content;//返回content 首地址
	   }
   }
    String::~String()//析构函数中应释放 content 所占用的空间
  {
	  delete [] content;
  }