#include "String.h"

String::String(char* str)//���캯����Ϊ��Ӧ��Ա������ֵ������ΪCONTENT����NEW���¿ռ�
{	
	int i;

	for ( i=0;str[i]!='\0';i++)
	{
	}

	count=i+1;
	capacity=i+2;


	content=new char[capacity];
	for (i=0;i<count;i++)
		content[i]=str[i];

}
String::String(const String& str)//���캯��������STRΪ��Ӧ��Ա������ֵ������ΪCONTENT����NEW���¿ռ�
{
	content=new char[str.capacity];
	for (int i=0;i<str.count;i++)
		content[i]=str.content[i];

	capacity=str.capacity;
	count=str.count;
}
String::~String()//��������
{delete content;
}

char* String::GetCString()//��ʾ����
{
	return content;
}