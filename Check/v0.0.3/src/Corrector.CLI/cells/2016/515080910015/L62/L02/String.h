#pragma once
class String //������String
{
private:
	char* content;  //���Ա����
	int capacity;
public:
	int count;
	String(char* str);  
	String(const String& str); //�๹�캯��
	~String();  //����������
	char* GetCString(); //���Ա����

};

