#include"String.h"
String::String(char*str)
{   count=0;
 capacity=1024;//��ʼ������
 content=new char[1024];//new���ռ�
for(int i=0;i<capacity;i++)
		{
			if(str[i]!='\0')
			{
					content[i]=str[i];//���ַ���ֵ��content�У�ȥ����\0'
			      count+=1;//�����ַ�����
			}
			else
			{break;}
	    }
}
String::String(const String &str)
{   content=new char[1024];//new���ռ�
	capacity=str.capacity;
	for(int i=0;i<count;i++)
	{
	content[i]=str.content[i];
	}
	count=str.count;//����String�г�Ա
}
String::~String()
{
			delete content;//�ͷſռ�
		}
char *String::GetCString()
{  
	content[count+1]='\0';//ȷ���ַ�����'\0'��β
	return content;
}
