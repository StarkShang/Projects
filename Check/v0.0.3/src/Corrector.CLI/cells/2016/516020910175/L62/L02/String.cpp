#include"String.h"
String::String(char* str)//���캯�������ݲ����ַ�������String�ಢ��ֵ
{
	int i;//����ѭ������
	for(i=0;i<1025;i++)//ѭ���ҵ������ַ����Ľ���λ�ã��õ��ַ�������count
	{
		if(str[i]=='\0') {count=i;break;}
	}
	capacity=count+1;//��count+1λ�ռ��Ա�����
	content=new char[capacity];//�����ڴ�ռ�
	for(i=0;i<count;i++)//���������ֵ
	{
		content[i]=str[i];
	}
}
String::String(const String& str)//�������죬���Ʋ���String��
{
	count=str.count;//��ֵcount
	capacity=count+1;//��ֵcapacity
	content=new char[capacity];//���ٿռ�
	for(int i=0;i<count;i++)//��ֵ
	{
		content[i]=str.content[i];
	}
}
String::~String()//����������delete content������
{
	delete []content;
}
char *String::GetCString()//ת��C�ַ�����������String���ַ�����ΪC�����ַ���
{
	content[count]='\0';//�����һλ��Ϊ\0
	return content;
}