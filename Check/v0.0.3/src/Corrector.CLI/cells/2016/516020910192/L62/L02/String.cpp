#include"String.h"//����ͷ�ļ�
String::String(char* str)
{
	for(int i=0;i<1024;i++)
	{
		if (str[i]=='\0')
		{count=i;//�ַ�������
		capacity=count*4;//�ڴ�ռ��С
		content = new char [capacity];//new ����Ӧ���ڴ�ռ�
		break;
		}
	}
	for(int j=0;j<count;j++)//����Ӧ�ĳ�Ա��ֵ
	{
	{content[j] = str[j];}
}
String::String(const String& str)
{
	this->capacity = str.capacity; //�ڴ�ռ��С
	this->count = str.count; //�ַ�������
	content = new char[capacity]; //new ����Ӧ���ڴ�ռ�
	for (int j = 0; j < count; j++) //����Ӧ�ĳ�Ա��ֵ
	{
		this->content[j] = str.content[j];
	}
}
String::~String()
{
	delete content;//�ͷſռ�
}
char* String::GetCString()
{
	content[count] = '\0'; //����ת��C�����ַ���
	return content; //����content�׵�ַ
}