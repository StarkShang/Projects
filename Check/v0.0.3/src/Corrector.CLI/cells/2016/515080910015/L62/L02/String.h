#pragma once
class String //声明类String
{
private:
	char* content;  //类成员变量
	int capacity;
public:
	int count;
	String(char* str);  
	String(const String& str); //类构造函数
	~String();  //类析构函数
	char* GetCString(); //类成员函数

};

