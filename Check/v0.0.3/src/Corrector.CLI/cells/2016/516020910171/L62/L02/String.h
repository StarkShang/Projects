#pragma once
class String//����������
{
public://����Ϊ����
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char* GetCString();
private://����Ϊ˽�б���
	char* content;
	int capcity;
};

