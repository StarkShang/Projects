#include"String.h";
#include<string.h>;
#include <iostream>;//����ͷ�ļ�
String::String(char* str)//��ֵ���캯��
{
	capacity=1024;//��ֵ
	if (str==NULL)
	{  
        content=new char[1]; //�Կ��ַ����Զ������Ž�����־'\0'�Ŀռ�  
    if (content==NULL)
	{//�ڴ��Ƿ�����ɹ�  
        std::cout<<"�����ڴ�ʧ�ܣ�"<<std::endl;  
        exit(1);  
    }  
    content[0]='\0';  
    }  
    else{  
        count=strlen(str);//ȡ�ַ�������
        content=new char[count+1];
        if (content==NULL)
		{//�ڴ��Ƿ�����ɹ�  
            std::cout<<"�����ڴ�ʧ�ܣ�"<<std::endl;  
            exit(1);  
        }  
        strcpy(content,str);  
    }  

	count=strlen(content);//ȡ�ַ�������
}
String::String(const String & str)//���ƹ��캯��
{
	count=strlen(str.content); //ȡ����
	content=new char[count+1];
    if (content==NULL){//�ڴ��Ƿ�����ɹ�  
        std::cout<<"ʧ�ܣ�"<<std::endl;  
        exit(1);  
    }  
    strcpy(content,str.content);  

}
String::~String()//��������
{
	delete content;
}
char* String::GetCString()//ת���ַ���Ϊc����ַ���
{  
	if(content[count]!='\0')//�ж��ַ�����β�Ƿ���\0
	{ content[count]='\0';}//���ǽ����һ����ֵΪ\0
	
		return content;//����content
             
}



	

