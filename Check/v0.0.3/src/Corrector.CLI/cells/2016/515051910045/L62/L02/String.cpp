#include"String.h"

String::String(char *str)
{   int i=0;
	while(str[i]!='\0') 
	{
	    i=i+1;
	    capacity=i;
	}
    content=new char[capacity+1];
	for(int i=0;i<capacity+1;i++)
	{    
		content[i]=str[i];
	}
   
}
String::String(const String& str)
{
	int i=0;
	while(str.content[i]!='\0') 
	{
		i=i+1;
	    capacity=i;	
	}
    content=new char[capacity+1];
	for(int i=0;i<capacity+1;i++)
	{    
		content[i]=str.content[i];
	}
   
}

String::~String()
{	
	delete []content;	
}

char* String::GetCString()
{  
	return content;
}


