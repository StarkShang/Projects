#include"String.h"

String::String(char *str)//��ֵ���캯��
{ int i=0;
while(str[i]!='\0') 
{i=i+1;
capacity=i;
}
content=new char[capacity+1];
for(int i=0;i<capacity+1;i++)
{content[i]=str[i];
}
}
String::String(const String& str)//�������캯��
{int j=0;
while(str.content[j]!='\0') 
{j=j+1;
capacity=j;	
}
content=new char[capacity+1];
for(int j=0;j<capacity+1;j++)
{content[j]=str.content[j];
}
}
String::~String()//�ͷ� content
{delete []content;	
}
char* String::GetCString()//���� content �׵�ַ
{return content;
}