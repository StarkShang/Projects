char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i,j;char x,y;
	for(i=0;i<=1023;i++)
	{
		x=num1[i];
	 if(x=='\0')
		 break;
	}
	for(j=0;j<=1023;j++)
	{
		y=num2[j];
		if(y=='\0')
			break;
	}

	int NUM1[1024];int NUM2[1024];
	for(int a=0;a<=1023;a++)
		{
		NUM1[a]=0;
	    NUM2[a]=0;
	    }
	for(int a=0;a<=i-1;a++)
		NUM1[a]=num1[i-a-1]-48;
	for(int b=0;b<=j-1;b++)
		NUM2[b]=num2[j-b-1]-48;
	int BUFFER[1025];
	for(int a=0;a<=1024;a++)
		{
			BUFFER[a]=0;
	     }
	for(int c=0;c<=1023;c++)
	{
		BUFFER[c]+=NUM1[c]+NUM2[c];
		BUFFER[c+1]+=BUFFER[c]/10;
		BUFFER[c]=BUFFER[c]%10;
	}
	
		int max=(i>j)?i:j;
		if(BUFFER[max]==0)
			max=max-1;
		
		for(int d=0;d<=max;d++)
			buffer[max-d]=BUFFER[d]+48;
		buffer[max+1]='\0';
		return(buffer);

}