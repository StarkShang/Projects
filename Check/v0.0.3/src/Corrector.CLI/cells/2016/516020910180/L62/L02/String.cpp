#include"String.h"
String::String(char* str)
{
	count=0;
	while(str[count]!='\0')//������
		count++;
	capacity=count+1;
	content=new char[capacity];//�������ڴ�
	for(int i=0;i<count;i++)//�����ַ���
		content[i]=str[i];
}

String::String(const String&str)//����һ���ַ���
{
	count=str.count;
	capacity=str.capacity;
	content=new char[capacity];//�����ڴ�
	for(int i=0;i<count;i++)//�����ַ���
		content[i]=str.content[i];
}

String::~String()
{
	delete [] content;//�ͷ��ڴ�
}

char* String::GetCString()
{
	content[capacity]='\0';//���ش��ַ���
	return content;
}