#pragma once
class String
{
private:
	char*content;//˽�г�Ա�������ַ�����
	int capacity;//�ַ���ռ�ռ�
public:
	int count;//�ַ�������
public:
	String(char*str);//��ֵ���캯��
	String(const String&str);//�������캯��
		~String();//��������
		
    char*GetCString();//ת���ַ���
};

