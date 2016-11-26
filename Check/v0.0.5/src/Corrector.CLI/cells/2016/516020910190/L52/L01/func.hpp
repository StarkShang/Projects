int max(int,int);//最大值函数声明
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{   int a=0,b=0;
	for(int i=0;i<bufferLen;i++)
	{ 
		if(num1[i]!='\0')
			a+=1;
		else
		{break;}
	}//计算num1这个数的位数
	
for(int i=0;i<bufferLen;i++)
    {
		if(num2[i]!='\0')
			b+=1;
		else
		{break;}
     }//计算num2这个数的位数
if(a>b)
{	char c[1025];
   c[a]='0';
		for(int i=1;i<=b;i++)
        c[a-i]=num2[b-i];//复制数二
		for(int i=0;i<a-b;i++)
			c[i]='0';//数二不足的位数用0填充
		num2=c;
}
	if(a<b)
	{
      char c[1025];
   c[b]='0';
		for(int i=1;i<=a;i++)
       c[b-i]=num1[a-i];//复制数一
		for(int i=0;i<b-a;i++)
			c[i]='0';//数一不足的位数用0填充
		num1=c;
	}//用0填充，使数一和数二的位数相等
int t=0,m=max(a,b);
buffer[m]='\0';
   for(int i=m-1;i>=1;i--)
	 {   
			 buffer[i]=num1[i]+num2[i]+t-'0';//每个字符相加
			 t=0;
			 if(buffer[i]>'9')
			 {
				 t++;//和大于9就进一位
				 buffer[i]-=10;//减去10得本位
			 }

	}
   buffer[0]=num1[0]+num2[0]+t-'0';//最高位相加时分开讨论
   if(buffer[0]>'9')
   {   buffer[0]-=10;//若最高位相加大于9，减去10得本位，还要进一位
	   char b[1025];
	   b[m+1]='\0';
     for(int i=m-1;i>=0;i--)
	 {
       b[i+1]=buffer[i];
	 }//复制所有位数
	 b[0]='1';//最后和的最后一位必为1，即进一位
	 buffer=b;
   }
   return buffer;
}
int max(int a,int b)
{
	return(a>b?a:b);//求最大值
}