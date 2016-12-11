#include"String.h"
String::String(char* str) 
{ 
	content= new  char [1024] ;
    count=0;
    capacity =1024;
	for(int i  =0; i<capacity;i++)
    {
		if (str [i]!= '\0')
        {
			content[i]=str[i];
            count=count+1;
        }
        else break;
    }
}
String:: String(const String& str) 
{
        content= new  char [1024] ;
        capacity= str.capacity ;
        count=str.count;
        for(int i  =0; i<count;i++)
        {
			content[i]=str.content [i];
        }
}	    
char* String::GetCString() 
{ 
    content[count+1]='\0';
	return   content;
}
String::~String ()
{
	delete content;
}