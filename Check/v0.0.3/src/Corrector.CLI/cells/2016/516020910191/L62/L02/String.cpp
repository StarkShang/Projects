#include"String.h"
String::String(char* str) 
{ content= new  char [1024] ;//new ���洢�ռ�
count=0;
capacity =1024;//��ʼ��
	for(int i  =0; i<capacity;i++)
{if (str [i]!= '\0')
{content[i]=str[i];
count=count+1;
}//������ĩ� ѭ����ֵ
else break;//����break
}
}
String:: String(const String& str) 
	{   content= new  char [1024] ;//new ���洢�ռ�
 capacity= str.capacity ;
count=str.count;//�����������ַ�������
for(int i  =0; i<count;i++)

{content[i]=str.content [i];//ѭ����ֵ
 
}
	}

	    
	 char* String::GetCString() 
	 { 
		content[count+1]='\0';//ĩ���һ��Ϊ\0
		return   content;//����content�׵�ַ
	 }
	String::~String ()
	 {delete content;}//��������