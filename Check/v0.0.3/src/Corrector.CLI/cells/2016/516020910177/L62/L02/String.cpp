#include"String.h"


String::String(char* str)     //��ֵ���캯��
{
	count=0;
    for(int i=0;str[i]!='\0';i++)
	   count++;
    capacity=count+1;
    content =new char [capacity]; //Ϊcontent����new���ڴ�ռ�
    for(int i=0;i<count;i++)
	   content[i]=str[i];  //����Ӧ��Ա��ֵ
}

 String::String(const String& str)      //�������캯��
 {
	 this->count=str.count;      
	 content =new char [count+1];  //Ϊcontent����new���ڴ�ռ�
     for(int i=0;i<count;i++)
	   this->content[i]=str.content[i];   //����Ӧ��Ա��ֵ
	
 }
String::~String()
{ 
	delete []content;     //�ͷſռ�
}
char*String::GetCString()
{ 
	 content[count]='\0';   //content���ַ����ԡ�\0����β
	 return content;        //�����׵�ַ
}
