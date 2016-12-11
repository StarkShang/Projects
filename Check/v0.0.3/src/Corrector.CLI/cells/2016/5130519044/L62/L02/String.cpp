#include "String.h"
#include <string>
using namespace std;

String::String(char* str)
{
    count= strlen(str);               //��ֵ�ַ����ĳ���
	capacity = count + 1;             //��ֵ��ռ�ڲ��ռ�
	content = new char[capacity];     //Ϊcontent����new����Ӧ���ڴ�ռ�
	int i;
	for(i=0;i<count;i++) content[i]=str[i];


}
String::String(const String& str)
{
	content = new char[str.capacity];  //new����ͬ�Ŀռ�
	capacity = str.capacity;
	count = str.count;
	int j;
	for(j=count;j>=0;j--) content[j]=str.content[j];//����ǰһ��String������ַ�����
}

char* String::GetCString()
{
	content[count]='\0';   //���ַ�����������'\0'��β
	return content;
}
String::~String()
{
	delete content;
}