char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{   
	int a[1025],b[1025],temp[1026]={0,},sum[1025],m,n,len;  //定义整型数组a[1025],b[1025]来储存num1，num2数字，
	                                                        //a，b分别表示num1，num2的元素个数，len表示和的长度
	for(int i=0;i<1025;i++)      //将a[1025],b[1025]元素全部赋以0的初始值
	{   
		a[i]=0;
		b[i]=0;
	}
	for(int i=0;num1[i]!='\0';i++)   //计算num1的长度
	{   
		m=i+1;
	} 
	for(int i=0;num1[i]!='\0';i++)    //将num1中的元素倒着放入a[1025]中
	{   
		a[m-1-i]=num1[i]-'0';
	}
	for(int i=0;num2[i]!='\0';i++)     //计算num2的长度
	{
		n=i+1;
	}
	for(int i=0;num2[i]!='\0';i++)    //将num2中的元素倒着放入b[1025]中
	{
		b[n-1-i]=num2[i]-'0';
	}
	if(m>n)   len=m;         //计算sum的长度
	else    len=n;

	for(int i=0;i<1025;i++)     //分别对a[1025],b[1025]对应位数的数求和，判断是否要向前进一位
	{
		sum[i]=a[i]+b[i]+temp[i];
		temp[i+1]=sum[i]/10;
		sum[i]=sum[i]%10;
	}
	if(temp[1025]==1)           //判断最后的和是否有1025位，如果有，则不用加终止运算符
	{
		for(int i=0;i<1025;i++)
		{
			buffer[i]=sum[1025-i]+'0';
		}	
	}
	else if(temp[len]==1)       //判断最后结果位数是否比len大一位，如果有，则终止运算符后移一位
	{
		for(int i=0;i<len+1;i++)
		{   
			buffer[i]=sum[len-i]+'0';
	    }
	    buffer[len+1]='\0';
	}
	else                       
	{
		for(int i=0;i<len;i++)
		{
			buffer[i]=sum[len-1-i]+'0';
		}
		buffer[len]='\0';
	}
	return(buffer);   //返回buffer的首地址
}