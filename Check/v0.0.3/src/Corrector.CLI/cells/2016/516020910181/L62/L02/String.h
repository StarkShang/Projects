#pragma once
class String
{
private:
	char* content;                  //String������ַ�����
	int capacity;                   //content��ռ���ڴ�ռ�

public:
	int count;                     //content���ַ����ĳ���
	String(char* str);             //����char*�ַ���str����String��Ķ���
	String(const String& str);     //����String�ַ�������󴴽�String��Ķ���
	~String();                     //�ͷ�content��ռ�õĿռ�
	char* GetCString();            //����ǰ��ת����c�����ַ���
};

