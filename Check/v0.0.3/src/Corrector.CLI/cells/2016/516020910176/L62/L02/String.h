#pragma once
class String
{
private:
	char*content;            //�����ַ���
	int capacity;            // content��ռ�ռ�
public:
	int count;                  //�ַ�����
	String(char*str);           //����char*�ַ���str����String��Ķ���
	String(const String&str);  //����String�ַ�������󴴽�String��Ķ���
	~String();                 //�ͷ�content��ռ�õĿռ�
	char* GetCString();       //����ǰ��ת����c�����ַ���
};

