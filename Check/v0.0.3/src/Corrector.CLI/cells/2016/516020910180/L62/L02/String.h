#pragma once
class String
{
private:
	char* content;//×Ö·û´®
	int capacity;//ÈÝÁ¿
public:
	int count;//¼ÆÊýÆ÷
	String(char* str);//¸´ÖÆÔ­¾ä
	String(const String&str);//¿½±´×Ö·û´®
	~String();//Îö¹¹
	char* GetCString();//µÃµ½C×Ö·û´®
};

