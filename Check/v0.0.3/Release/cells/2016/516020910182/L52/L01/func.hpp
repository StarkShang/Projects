#include <string.h>
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int m;
	m=0;
	int m1,m2,len,lm;
	m1=strlen(num1);
	m2=strlen(num2);
	char *nm,*nn;
	if(m1>m2) 
    {
			len=m1,lm=m1-m2;
			
			nm=num1;
			nn=num2;
	}
	else 
	{	
		len=m2,lm=m2-m1;
		nm=num2;
		nn=num1;
	}
	
	for(int i=len-1;i>=lm;i--)
	{
		        if( *(nm+i) + *(nn+i-lm) -96 + m >= 10 )
		        {
                *(buffer+i+1) = *(nm+i) + *(nn+i-lm) -48 + m - 10;
			    m=1;
		        }
		        else 
		        {
			    *(buffer+i+1) = *(nm+i) + *(nn+i-lm) + m -48 ;
			    m=0;
		        }   
		
	}
	for(int t=lm-1;t>=0;t--)
	{
		if( *(nm+t) -48 + m >= 10 )
		{
			 *(buffer+t+1) = *(nm+t)+m-10;
			 m=1;
		}
		else
		{
			*(buffer+t+1) = *(nm+t)+m;
			m=0;
		}
	}
	buffer[0]=m+48;
	buffer[len+1]='\0';
	return buffer;
}

