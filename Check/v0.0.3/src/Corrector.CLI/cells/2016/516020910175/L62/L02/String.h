#pragma once
class String//�ַ����࣬��Ա�������ַ���ָ�룬��ռ�ռ��С���ַ������ȣ���Ա���������죬������ת����C�ַ���
{
private:
	char *content;
	int capacity;
public:
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char *GetCString(); 
};