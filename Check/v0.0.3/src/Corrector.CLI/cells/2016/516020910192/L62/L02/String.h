#pragma once
class String
{
private:
	char* content;//��ʾ String ������ַ���������
	int capacity;//��ʾ content ��ռ���ڴ�ռ�; 

public:
	int count;//content ���ַ����ĳ���; 
	String(char* str);//��ֵ���캯��
	String(const String& str);//�������캯��
    ~String();//��������
	char*GetCString();//ת������
};

