char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i=0;
	while (num1[i]!='\0')//先求两个数字串的长度，赋值给LEN1,LEN2
	{i++;}
	int len1=i;
	i=0;
	while (num2[i]!='\0')
	{i++;}
	int len2=i;
	
	char b[1025];
	for (int i=0;i<=len1;i++)//为了计算方便，吧两个数字倒序
		b[i]=num1[i];
	for (int i=0;i<=len1;i++)
		num1[i]=b[len1-1-i];

	for (int i=0;i<=len2;i++)
		b[i]=num2[i];
	for (int i=0;i<=len2;i++)
		num2[i]=b[len2-1-i];
	int k=0;//K是进位计数器




	if (len1>len2)//当第一个数更长时
	{
		for (int i=0;i<len2;i++)//在第一位到第LEN2位时
		{
			if(num1[i]+num2[i]-96+k<10)//若无需进位，则直接相加
				{
				buffer[i]=num1[i]+num2[i]-48+k;
				k=0;
				}
			else
				{
				buffer[i]=num1[i]+num2[i]-48-10+k;//若需要进位，则减去10，并且进位计数的K=1
				k=1;
				}
		}
		
		buffer[len2]=num1[len2]+k;//再将LEN2到LEN1的部分赋值到BUFFER
		for (i=len2;i<len1;i++)
			{buffer[i]=num1[i]+k;
				k=0;}

		

	for (int i=0;i<len1;i++)//把得到的BUFFER在倒回正常顺序
		b[i]=buffer[i];
	for (int i=0;i<len1;i++)
		buffer[i]=b[len1-1-i];

	buffer[len1]='\0';//最后一位以\0结尾

	}





		else
		if (len2>len1)//当第二个数更长的情况，内容同上
	{
		for (int i=0;i<len1;i++)
		{
			if(num1[i]+num2[i]-96+k<10)
				{
				buffer[i]=num1[i]+num2[i]-48+k;
				k=0;
				}
			else
				{
				buffer[i]=num1[i]+num2[i]-48-10+k;
				k=1;
				}
		}

		buffer[len1]=num1[len2]+k;
		for (i=len1;i<len2;i++)
			{buffer[i]=num1[i]+k;
				k=0;}

		

	for (int i=0;i<len2;i++)
		b[i]=buffer[i];
	for (int i=0;i<len1;i++)
		buffer[i]=b[len2-1-i];

	buffer[len2]='\0';

	}

		else
	if (len1=len2)//当两数想同时，内容同上
	{
		for (int i=0;i<len2;i++)
		{
			if(num1[i]+num2[i]-96+k<10)
				{
				buffer[i]=num1[i]+num2[i]-48+k;
				k=0;
				}
			else
				{
				buffer[i]=num1[i]+num2[i]-48-10+k;
				k=1;
				}
		}
		buffer[len2]=num1[len2]+k;

		

	for (int i=0;i<len1;i++)
		b[i]=buffer[i];
	for (int i=0;i<len1;i++)
		buffer[i]=b[len1-1-i];

	buffer[len1]='\0';

	}



	return buffer;//返回结果
}
