#pragma once
class String
{
private:
	char*content;//�ַ�������
	int capacity;//�ַ����ռ�
public:
	int count;//�ַ�������
	String(char*str);//���캯��
	String(const String& str);//���ƹ��캯��
	~String();//��������
	char*GetCString();//����C�����ַ���
	
};


