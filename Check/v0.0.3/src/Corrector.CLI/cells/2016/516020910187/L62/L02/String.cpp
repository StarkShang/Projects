#include "String.h"
#include <iostream>
String::String(char* str)
{
	count = strlen(str);//����strlen���������ַ�������
	capacity = 4*count;
	content = new char[capacity];//���ٿռ�
	for (int i = 0; i < count; i++)//��ֵ
	{
		content[i] = str[i];
	}
}
String::String(const String& str)
{
	this->capacity = str.capacity; //����thisָ��
	this->count = str.count; 
	content = new char[capacity];
	for (int j = 0; j < count; j++) //��ֵ
	{
		this->content[j] = str.content[j];
	}
}
String::~String()
{
	delete content;
}
char* String::GetCString()
{
	content[count+1] = '\0';//���һ��'\0'
	return content;
}