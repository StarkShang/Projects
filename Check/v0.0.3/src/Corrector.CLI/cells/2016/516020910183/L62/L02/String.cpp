#include"String.h"
String::String(char* str)//��ֵ���캯��
{
	int i = 0;//
	for (; *(str + i) != '\0'; i++)//�жϳ���
	{//

	}//
	count = i+1;//
	capacity = i + 2;//
	content = new char[capacity];//��������
	for (int j=0; *(str + j) != '\0'; j++)//ѭ��
	{//
		*(content + j) = *(str + j);//�������Ա��ֵ
	}//
}
String::String(const String&str)//�������캯��
{
	this->count =count;//����count
	this->capacity =  capacity;//����capacity
	this->content = new char[capacity];//��������
	for (int j = 0;j<count; j++)//ѭ��
	{
		*(this->content + j) = *(content + j);//���������Ա
	}

}
String::~String()//��������
{
	delete[] content;//ɾ������
}
char*String::GetCString()//ת������
{
	content[count] = '\0';//����ַ�
	return content;//��������ָ��
}