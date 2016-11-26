char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int a[1024],b[1024];
	int Len(char*);
	int m = Len(num1), n = Len(num2);
	if (m > n) //将两个数从右侧对齐
	{
		for (int i = 0; i < m-n; i++)
		{
			a[i] = int(num1[i]) - 48;
			b[i] = 0;
		}
		for (int j = m - n; j < m; j++)
		{
			a[j] = int(num1[j]) - 48;
			b[j] = int(num2[j - m + n]) - 48;
		}
	}
	else if (m < n)
	{
		for (int i = 0; i < n - m; i++)
		{
			b[i] = int(num2[i]) - 48;
			a[i] = 0;
		}
		for (int j = n - m; j < n; j++)
		{
			b[j] = int(num2[j]) - 48;
			a[j] = int(num1[j - n + m]) - 48;
		}
	}
	else if (m == n)
	{
		for (int i = 0; i < m; i++)
		{
			a[i] = int(num1[i]) - 48;
			b[i] = int(num2[i]) - 48;
		}
	}
	int c = 0,max=(m>=n?m:n); //定义变量
	for (; max > 0; max--)   //计算并选择是否进位
	{
		if (a[max - 1] + b[max - 1]+c >= 10)  //需要进位
		{
			buffer[max] = (char)(a[max - 1] + b[max - 1] +c- 10+48);
			c = 1;
		}
		else   //不需要进位
		{
			buffer[max] = (char)(a[max - 1] + b[max - 1] + c+48);
			c = 0;
		}
	}
	if(c==0) // 检验第一位是否为空
	{
		for (int k = 0; k < (m > n ? m : n); k++)  //第一位为空，所有数向前一格
		{
			buffer[k] = buffer[k + 1];
		}
		buffer[(m > n ? m : n)] = '\0';
	}
	else  //第一位进位后为1
	{
		buffer[0] = (char)(1+48);
		buffer[(m > n ? m : n) + 1] = '\0';
	}
	return buffer;
}

int Len(char* s)  //求字符串长度
{
	int i = 0;
	while (s[i] != '\0')  //如果不是字符串的末尾末尾
	{
		i++; //则向末尾偏移一位
	}
	return i;  //长度是末尾处-1
}