#pragma once
class String
{
private:
	char* content;//String������ַ���������
	int capacity;//content�������ڴ�ռ�
public:
	int count;//content���ַ����ĳ���
	String (char* str);//��ֵ���캯�������� char*�ַ��� str ���� String ��Ķ���
	                   //�ڹ��캯����ӦΪ content ���� new ����Ӧ���ڴ�ռ䣬������Ӧ�ĳ�Ա��ֵ; 
	String (const String&str);//�������캯�������� String �ַ�������󴴽��µ� String ��Ķ���
	                          //�ڹ��캯�� ��ӦΪ content ���� new ����Ӧ���ڴ�ռ䣬������Ӧ�ĳ�Ա��ֵ; 
	~String();//������������Ӧ�ͷ� content ��ռ�õĿռ�;
	char* GetCString();//GetCString ����ǰ��ת���� c �����ַ�����
		               //ȷ�� content ���ַ����ԡ�\0����β ������ content �׵�ַ�� 

};

