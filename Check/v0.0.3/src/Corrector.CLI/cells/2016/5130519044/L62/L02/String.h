#pragma once
class String
{
public:
	int count;
	String(char* str);
	String(const String& str);
	~String();
	char* GetCString();
private:
	char* content;
	int capacity;
};

