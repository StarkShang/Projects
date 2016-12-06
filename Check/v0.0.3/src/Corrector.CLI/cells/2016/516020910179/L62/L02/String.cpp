#include"String.h"

String::String (char* str)
{
	count=0;//��ʼ��
	for(int i=0;str[i]!='\0';i++)
	{count++;}//���ַ������ַ�����������\0��
	capacity=count+1;//���ֽ���
    content=new char[capacity];//Ϊcontent����new����Ӧ���ڴ�ռ�
	for(int i=0;i<capacity;i++)
	{content[i]=str[i];}//��ֵ
}

String::String (const String&str)
{
	count=0;
	int i=0;
	this->count=str.count;
	this->capacity=str.capacity;
	this->content=new char[capacity];
	for(i;i<count;i++)
	{
		this->content[i]=str.content[i];
	}
	
}

String::~String()
{
	delete[]content;//�ͷ��ڴ�
}

char* String::GetCString()
{
	if(count<capacity)
	{
		content[count]='\0';
	}
	else
		content[capacity]='\0';
	return content;
}
	