#pragma once
class String

{private:
	char* content;//�����ַ�����
	int capacity;//�����ڴ�ռ�
public://
	int count;//���峤��
	String(char* str);//��ֵ���캯��
	String(const String&str);//�������캯��
	~String();//��������
	char* GetCString();//ת������
};

