#pragma once
class String
{
private:
   char*	content ;     //��ʾ String ������ַ���������
   int   capacity ;       //��ʾ content ��ռ���ڴ�ռ�;
public:
	int  count ;          //�ַ����ĳ���
    String(char* str);    //��ֵ���캯�������� char*�ַ��� str ���� String ��Ķ���
    String(const String& str);  //�������캯�������� String �ַ�������󴴽��µ� String ��Ķ���
    ~String();               //�������������ͷ� content ��ռ�õĿռ�
    char* GetCString();     //����ǰ��ת���� c �����ַ���
};

