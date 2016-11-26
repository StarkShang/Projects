int len(char* num)    //判断数组长度
{
	int n=0;
	while(num[n]!=NULL)
		n++;
	return n;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len(char* num);//声明函数名
	int i=0,j=0,a=0,b=0,l=0,m,n;//定义变量
	i=len(num1);
	j=len(num2);//获得两个数组的长度
	*(buffer)='0';//将buffer数组的首元素变为0
	if(i>=j)//如果num1的数字位数大
	{
		*(buffer+i+1)='\0';//将buffer数组的第i+1元素变为0
		for(;j>=1;i--&&j--)//循环语句计算两数组重合部分各个元素和
		{
			
			m=(int)(*(num1+i-1));
			n=(int)(*(num2+j-1));
			b=m+n+a-48;
			if(b>=58)//如果要进位
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+i)=(char)(b);
		}
	
		for(l=(i-j);l>0;l--)//循环语句计算两数组非重合部分各个元素和
		{
			m=(int)(*(num1+l-1));
			b=m+a;
			if(b>=58)
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+l)=(char)(b);
		}
		*buffer=a+48;//考虑首位是否进位
	}
	
	else 
		if(i<j)//如果num2的数字位数大
	{
		*(buffer+j+1)='\0';//将buffer数组的第i+1元素变为0
		for(;i>=1;i--&&j--)//循环语句计算两数组重合部分各个元素和
		{
			
			m=(int)(*(num1+i-1));
			n=(int)(*(num2+j-1));
			b=m+n+a-48;
			if(b>=58)
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+j)=(char)(b);
		}
	
		for(l=j;l>0;l--)//循环语句计算两数组非重合部分各个元素和
		{
			m=(int)(*(num2+l-1));
			b=m+a;
			if(b>=58)
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+l)=(char)(b);
		}
		*buffer=a+48;//考虑首位是否进位
	}
	return (*buffer =='0') ? buffer+1:buffer;//首位为0则往后推

}