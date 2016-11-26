int length(char* num)
{
	int n=0;
	while(num[n]!=NULL)
	n++;
	return n;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i,l1,l2,l;
	l1=length(num1);
	l2=length(num2);
	if(l1>l2)
	{
		for(i=l2;i>=0;i--)
		num2[i+l1-l2]=num2[i];
		for(i=0;i<l1-l2;i++)
		num2[i]='0';
		l=l1;
	}
	else if(l2<l1)
	{
		for(i=l1;i>=0;i--)
		num1[i+l2-l1]=num1[i];
		for(i=0;i<l2-l1;i++)
		num1[i]='0';
		l=l2;
	}
	else
		l=l1;
	int d=0;
	for(i=l;i>=0;i--)
	{
		if((int)num1[i]+(int)num2[i]-96+d>=10)
		{
		buffer[i+1]=(char)((int)num1[i]+(int)num2[i]-48+d-10);
		d=1;
		}
		else
		{
		buffer[i+1]=((int)num1[i]+(int)num2[i]-48+d);
		d=0;
		}
	}
	if(d==1)
		buffer[0]='1';
	else
		buffer[0]='0';
	buffer[l+1]='\0';
	return buffer;
}