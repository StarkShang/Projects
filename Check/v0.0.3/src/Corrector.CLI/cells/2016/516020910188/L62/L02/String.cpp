
#include"String.h"
String::String(char* str)
{
	for(int i=0;i<1025;i++)
	{
		if(str[i]=='\0') 
		{
			count=i;break;
		}
	}//�����ַ����ĳ���
	content=new char[1025];//�����µ��ڴ�ռ�
	capacity=count;
	for(int i=0;i<count;i++)
	{
		content[i]=str[i];
	}//��content��ֵ
}
String::String(const String& str)
{
	this->content=new char[1025];
	this->count=str.count;
	for(int i=0;i<count;i++)
	{
		this->content[i]=str.content[i];
	}
}//�������캯��
String::~String()
{
	delete []content;
}//��������
char *String::GetCString()
{
	content[count]='\0';
	return content;

}//���'\0'����ȡ�ַ���