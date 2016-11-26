char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i,x,y,j,k,q,w;//定义变量
	char z;
	q=0;//用于进位
	w=0;//用于进位
	x=0;//用于计算字符串长度
	i=0;//用于循环语句
	y=0;//用于计算字符串长度
	j=0;//用于循环语句
	while(num1[i]!='\0')
	{
		x++;
		i++;
	}//计算num1长度
	while(num2[j]!='\0')
	{
		y++;
		j++;
	}//计算num2长度
	if(x>y)
	{
		bufferLen=x;
	}
	else
	{
		bufferLen=y;
	}
	for(int a=0,i=x-1;a<i;a++,i--)
	{
		z=num1[a];
		num1[a]=num1[i];
		num1[i]=z;
	}//num1字符串反转，便于进位
	for(int b=0,i=y-1;b<i;b++,i--)
	{
		z=num2[b];
		num2[b]=num2[i];
		num2[i]=z;
	}//num2字符串反转
	char temp1[1025];
	char temp2[1025];
	int c=0;
	for(int q=x-1;q>=0;q--)
	{
		temp1[c++]=num1[q];
	}
	temp1[c]='\0';//将短字符串的高位用‘\0’补齐
	c=0;
	for(int q=y-1;q>=0;q--)
	{
		temp2[c++]=num2[q];
	}
	temp2[c]='\0';//将短字符串的高位用‘\0’补齐
	if(x<y)
	{
		for(i=x;i<y;i++)
		{
			temp1[i]='0';
		}
		temp1[y]='\0';
	}//填补空位
	else if(x>y)
	{
		for(i=y;i<x;i++)
		{
			temp2[i]='0';
		}
		temp2[x]='\0';
	}//填补空位
	for(i=0;i<bufferLen;i++)
	{
		k=temp1[i]-'0'+temp2[i]-'0'+q;//将字符串转化为数字后计算
		if(k>9)//若需进位
		{
			if(i==(bufferLen-1))
			{
				w=0;
			}
			q=1;
			buffer[i]=k-10+'0';//仅保留个位
		}
		else//若不需进位
		{
			q=0;
			buffer[i]=k+'0';
		}
	}
	buffer[bufferLen]='\0';//填补‘\0’

	return buffer;//返回函数
}