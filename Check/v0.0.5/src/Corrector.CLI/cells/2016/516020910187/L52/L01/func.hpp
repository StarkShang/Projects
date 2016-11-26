char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len1, len2;//char字符串长度
	for (int i=0;; i++)
	{
		if (num1[i] == '\0')
		{
			len1 = i; break;
		}
	}
	for (int i = 0;; i++)
	{
		if (num2[i] == '\0')
		{
			len2 = i; break;
		}
	}
	char numdao1[1024];//num字符串的倒序
	char numdao2[1024];
	int maxlen = 0;
	if (len1 > len2)
	{
		maxlen = len1;
	}
	else
	{
		maxlen = len2;
	}

	int j = 0;
		for (int i = len1 - 1; i >= 0; i--)
		{
			numdao1[j++] = num1[i];
		}
		numdao1[j] = '\0';
		j = 0;
		for (int i = len2 - 1; i >= 0; i--)
		{
			numdao2[j++] = num2[i];
}
		numdao2[j] = '\0';
		if (len1 < len2)
	{
		for (int i = len1 ; i < len2; i++)
		{
			numdao1[i] = '0';
		}
		numdao1[len2] = '\0';
	}
	else if (len1 > len2)
	{
		for (int i = len2; i < len1; i++)
		{
			numdao2[i] = '0';
		}
		numdao2[len1] = '\0';//补0
	}
	int a = 0;//进位指示数字
	int b[1024];//用来容纳各个数位数字的整型数组，相当于buffer的前身
	char bufferdao[1024];//buffer数组倒序
	for (int i = 0; i < maxlen; i++)
	{
		b[i] = numdao1[i] - '0' + numdao2[i] - '0' + a;
		if (b[i] > 9)//进位
		{
			if (i == maxlen - 1)//倒序后的最后一位数进位为1
			{
				bufferdao[maxlen] = 1+'0';
			}
			a = 1;
			bufferdao[i] = b[i] - 10 + '0';
		}
		else//不进位
		{
			a = 0;
			bufferdao[i] = b[i] + '0';
		}
	}
	if (bufferdao[maxlen] == 1 + '0')//进位
	{
		maxlen += 1;
	}
	bufferdao[maxlen] = '\0';
	int k = 0;
		for (int i = maxlen - 1; i >= 0; i--)
			buffer[k++] = bufferdao[i];//倒序输出
	buffer[k] = '\0';
	return buffer;
}