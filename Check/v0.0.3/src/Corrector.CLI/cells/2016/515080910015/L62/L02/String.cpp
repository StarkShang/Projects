#include "String.h"

String::String(char* str) //���帳ֵ���캯��
{
	content=new char; //Ϊcontent��new���ڴ�ռ�
	int i=0;
	while(str[i]!='\0')
	{
		content[i]=str[i]; //����Ӧ��Ա��ֵ
		count=i+1; //��Ա����countֵ
		i++;
	}
}

String::String(const String& str)//���忽�����캯��
{
	content=new char; //new���ڴ�ռ�

	content=str.content;//���п���
}

String::~String()//������������
{
	delete content; //�ͷ�content��ռ�ռ�
}

char*String:: GetCString() //���庯��
{
	content[count]='\0'; //ȷ��content��'\0'��β
	return content; //��������content
	
}