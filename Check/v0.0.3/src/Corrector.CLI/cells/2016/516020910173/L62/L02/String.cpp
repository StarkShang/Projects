#include"String.h"
String::String(char*str)
{
	capacity=1025;//�ռ�Ϊ1025�ַ�
	content=new char[capacity];//����ռ�
	int i=0;//��ʼ������
	count=0;//��ʼ������
	while (str[i]!='\0')//��¼�ַ������ݣ����㳤��
	{
		*(content+i)=*(str+i);
		count++;
		i++;
	}
}
String::String(const String& str)
{
	capacity=1025;//�ռ�Ϊ1025�ַ�
	content=new char[capacity];//����ռ�
	int i=0;//��ʼ������
	while (str.content[i]!='\0')//��¼�ַ�������
	{
		*(content+i)=*(str.content+i);
		i++;
	}
}
char* String::GetCString()
{
	if(*(content+count-1)!='\0')//���ַ�����β��Ϊ��\0��
	{
		if(count<1025)//���������
		{
			*(content+count)='\0';//ת��Ϊc�����ַ���
			return content;//���ص�ַ
		}
	
	}
	else //��Ϊ��\0����ֱ�ӷ���
		return content;
	
}
String::~String()//��������
{
	delete []content;
}