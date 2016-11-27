char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int a,b;
	for(int i=0;;i++)
		{if(num1[i]=='\0') 
	{a=i;break;} }
	for(int k=0;;k++)
		{if(num2[k]=='\0') 
	{b=k;break;}}//判断两个字符串的长度

	if(a>b)//如果第一个数长
	{   buffer[0]=48;//赋初始值
		for(int p=0;p<=b;p++)
		{buffer[a-p+1]=num1[a-p]+num2[b-p]-48;}//将两字符串重叠部分加和
		for(int w=b+1;w<=a;w++)
		{buffer[a-w+1]=num1[a-w];}//第一个数多余部分单独赋值
		for(int t=0;t<=(b+1);t++)
			if(buffer[a-t+1]>57)//判断每一位运算后是否大于10
			{buffer[a-t+1]=buffer[a-t+1]-10;//大于10则减去10
		buffer[a-t]=buffer[a-t]+1;//且将下一位进一
		}
		//将得到的和加入终止符
		if(buffer[0]==48)//如果加和后第一位是0
		{
			for(int k=0;k<a;k++)
				buffer[k]=buffer[k+1];//则将字符串整体前移
			buffer[a]='\0';//输入终止符
		}
		else buffer[a+2]='\0';//输入中止符
		return buffer;//返回字符串

	}
	if(b>a)
	{
		 buffer[0]=48;
		for(int d=0;d<=a;d++)
		{buffer[b-d+1]=num1[a-d]+num2[b-d]-48;}
		for(int l=a+1;l<=b;l++)
		{buffer[b-l+1]=num2[b-l];}
		for(int n=0;n<=(a+1);n++)
			{if(buffer[b-n+1]>57)
			{buffer[b-n+1]=buffer[b-n+1]-10;
		buffer[b-n]=buffer[b-n]+1;}}
		if(buffer[0]==48)//如果加和后第一位是0
		{
			for(int c=0;c<b;c++)
				buffer[c]=buffer[c+1];//则将字符串整体前移
			buffer[b]='\0';//输入终止符
		}
		else buffer[b+2]='\0';
		return buffer;
	}//原理同上

	if(a=b)//两数位数相等
	
	{
			for(int p=0;p<=b;p++)
		{buffer[a-p]=num1[a-p]+num2[b-p]-48;}//实现模拟加和
		
		for(int t=0;t<b;t++)
			{if(buffer[a-t]>57)
			{buffer[a-t]=buffer[a-t]-10;//实现进位
		buffer[a-t-1]=buffer[a-t-1]+1;}}
		buffer[a+1]='\0';
		if(buffer[0]>57)//判断第一位是不是大于10
		{for(int q=b+1;q>=1;q--)
		{buffer[q+1]=buffer[q];}
		buffer[1]=buffer[0]-10;
		buffer[0]=49;
		}//大于10则字符串整体后退一位，字符串第一位赋为49
		
		return buffer;
	}
}