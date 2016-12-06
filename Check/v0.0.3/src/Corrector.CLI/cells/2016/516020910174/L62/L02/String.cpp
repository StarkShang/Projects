#include <iostream>
#include"String.h"
String::String(char* str)                                   //����char*�ַ���str����String��Ķ���
{
	int i = 0;
	for (i = 0; i < 1025; i++)                              //�����ַ�������
	{
		if (str[i] == '\0') { break; }
	}
	count = i;                                             //��ֵ�ַ�������
	capacity = count * 4;                                  //��ֵ�ڴ�ռ��С
	content = new char[capacity];                          //�����ڴ�ռ�
	for (int j = 0; j < count; j++)                        //����Ӧ�ĳ�Ա��ֵ
	{
		content[j] = str[j];
	}
}

String::String(const String& str)
{
	this->capacity = str.capacity;                          //��ȡ�ڴ�ռ��С
	this->count = str.count;                                //��ȡ�ַ�������
	content = new char[capacity];                           //�����ڴ�ռ�
	for (int j = 0; j < count; j++)                         //����Ӧ�ĳ�Ա��ֵ
	{
		this->content[j] = str.content[j];
	}
}

String::~String()
{
	delete content;                                        //�ͷ��ڴ�ռ�
}

char* String::GetCString()
{
	content[count] = '\0';                                //����ת��C�����ַ���
	return content;                                       //����content�׵�ַ
}