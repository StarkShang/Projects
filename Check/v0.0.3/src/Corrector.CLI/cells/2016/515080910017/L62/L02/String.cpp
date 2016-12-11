#include "String.h"

String::String(char* str)
{
	for(int i=0;i<1024;i++)
	{
		if(str[i]=='\0')
			count=i;
	}
	capacity=count+1;
    content=new char[capacity];
	for(int j=0;j<=count;j++)
		content[j]=str[j];
}



String::String(const String& str)
{
	
		content=str.content;
}

char* String::GetCString()
{

	char a[1024];
	  for(int k=0;k<=count;k++)
		  a[k]=content[k];
	     a[count+1]=='\0';
	  return(a);
}
