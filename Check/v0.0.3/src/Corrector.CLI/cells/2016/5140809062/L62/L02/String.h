#pragma once
class String//����STRING��
{
private://�ַ������ݣ�����
	char *content;
	int capacity;
public://���캯����������������ʾ����������
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char* GetCString();

};

