#include"String.h"
 String::String(char* str)//��ֵ���캯��
 {
	 count=0;//��ʼ����ֵ
	 int i=0;
	 for(i=0;str[i]!='\0';i++)//�õ� char*�ַ��� str�ĳ��ȸ�ֵ��count
	 {
		count++;
	 }
	 capacity=count+1;//��count+1��ֵ��capacity
	 content=new char[capacity];//Ϊcontent����new ����Ӧ���ڴ�ռ�
	  
	 for(i=0;i<count;i++)//ѭ�����Ϊcontent��Ա��ֵ
	 {
		 content[i]=str[i];
		 
	 }
	
 }
 String:: String(const String& str)//�������캯��
 {
	 
	 count=0;
	int i=0;
	this->count=str.count;//�õ�str��count
	  this->capacity=this->count+1;//������Ӧ�ڴ�ռ�
	 this->content=new char[capacity];//Ϊcontent ����new����Ӧ���ڴ�ռ�
	 
	 for(i=0;i<count;i++)//ѭ�����Ϊcontent��Ա��ֵ
	 {
		 this->content[i]=str.content[i];
		
	 }
	
 }
 
   char*String::GetCString()//GetCString��������ǰ��ת���� c�����ַ���
   {
	   if(count<capacity)//���content ���ַ����ĳ���С������
	   {
	   content[count]='\0';//��content�����һ���ַ���һλ��ֵΪ'\0'
	   return content;//����content �׵�ַ
	   }
	   else//����ǿ�н��������һλ���'\0'
	   {
	   content[capacity-1]='\0';
	   return content;//����content �׵�ַ
	   }
   }
    String::~String()//����������Ӧ�ͷ� content ��ռ�õĿռ�
  {
	  delete [] content;
  }