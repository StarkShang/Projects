#pragma once
class String
{
private:
	char* content;
	int capacity;
public:
	int count;
	String (char* str);
	
	String (const String& str);

	~String()
	{delete [] content;}
	char* GetCString();
	
};

