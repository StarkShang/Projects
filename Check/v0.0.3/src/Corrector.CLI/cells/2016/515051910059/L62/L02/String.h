#pragma once
class String//����String��
{private:
char* content;
int capacity;
public:
int count;
String(char* str);
String(const String& str);
~String();
char* GetCString();
};

