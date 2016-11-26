int len(char *num )//求数组的长度的函数（这里求的是数字个数）
{
	int i;
	for(i=0;i<=1023;i++)
	{
		if(num[i]=='\0')
			break;
	}
	return i;
}
int max(int a,int b)
{
	int max;
	if (a>b)
		max=a;
	else
		max=b;
	return max;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int l1=len(num1);//分别求数组长度
	int l2=len(num2);
	int m=0;
	for(int i=1;i<=max(l1,l2);i++)
	{
		char a,b;
		
		if ((l1-i)<0)
			a='0';
		else 
			a=*(num1+l1-i);
		if((l2-i)<0)
			b='0';
		else
			b=*(num2+l2-i);
	    *(buffer+max(l1,l2)-i)=a+b-48+m;
		if(*(buffer+max(l1,l2)-i)>=58)
		{
			*(buffer+max(l1,l2)-i)=*(buffer+max(l1,l2)-i)-10;
			m=1;
		}
		else m=0;
	}
	
	if(m>0)
	{
		for(int j=max(l1,l2);j>0;j--)
			*(buffer+j)=*(buffer+j-1);
		buffer[0]=49;
		*(buffer+max(l1,l2)+1)='\0';
	}
	else*(buffer+max(l1,l2))='\0';
	return buffer;
}
	


	