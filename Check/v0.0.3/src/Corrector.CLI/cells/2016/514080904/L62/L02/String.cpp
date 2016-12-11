#include "String.h"


int len(char* str)//����len������ȡ�ַ����ĳ��Ȳ�����
{
	for(int i=0; ;i++)
	{
		if (str[i]=='\0')
			return i;
	}
}

String::String(char* str)
{
	capacity = count = len(str);//capacity��count�����ڼ�¼�ַ�������
	content = new char[capacity + 1];//������һ�ݿռ� Ϊ\0
	for(int i=0; i<count ;i++)//��ʼ��
	{
		content[i] = str[i];
	}
}
String::String(const String &str)
{
	count = str.count;
	capacity = count;
	content = new char[capacity + 1];
	for(int i=0; i<count ;i++)
	{
		content[i] = str.content[i];
	}
}
String::~String()
{
	delete []content;
}
char* String::GetCString()
{
	content[capacity] = '\0';//��ʱ��\0���ϼ���
	return content;
}