#include "String.h"
#include <iostream>
#include <string.h>

String::String(char* str)//��ֵ���캯��
{
if (str==NULL){  
        content=new char[1]; //�Կ��ַ����Զ������Ž�����־'\0'�Ŀռ�  
    if (content==NULL)
	{//�ڴ��Ƿ�����ɹ�  
        std::cout<<"�����ڴ�ʧ�ܣ�"<<std::endl;
		exit(1);
    }  
    content[0]='\0';  
    }  
    else{  //�������ڴ�ɹ�
        count=strlen(str);  //����count����ֵ
        content=new char[count+1];  
        if (content==NULL){//�ڴ��Ƿ�����ɹ�  
            std::cout<<"�����ڴ�ʧ�ܣ�"<<std::endl;  
			exit(1);
        }  
        strcpy(content,str);  //���ַ�������������
    }  
}  

String::String(const String& str)//�������캯��
{
	count=strlen(str.content);  //���㳤��
    content=new char[count+1];  
    if (content==NULL)
	{//�ڴ��Ƿ�����ɹ�  
        std::cout<<"ʧ�ܣ�"<<std::endl;  
        exit(1);  
    }  
    strcpy(content,str.content);  //���ƺ���
}  

String::~String()//�����������ͷ�content��ռ�õĿռ�
{
	delete []content;
}

char*String::GetCString()//����ǰ��ת����c�����ַ���
{
	
	if(content[count]!='\0')
		content[count]='\0';
	return content;
}