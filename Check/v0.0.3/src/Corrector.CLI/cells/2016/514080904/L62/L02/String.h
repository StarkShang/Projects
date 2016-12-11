#pragma once
class String
{
private:
	char* content;
	int capacity;
public:
	int count;
public:
	String(char* str);
	String(const String &str);
	~String();
	char* GetCString();
};

