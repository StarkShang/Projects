char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i, j,x=0;
	for (i = 0; i <= 1023; i++)
	{
		if (num1[i+1] == '\0')
			break;
	}//计算数字位数
	for (j = 0; j <= 1023; j++)
	{
		if (num2[j+1] == '\0')
			break;
	}//计算数字位数
	if (i == j)//如果位数相等
	{
		for (int k = i; k >= 0; k--)
		{
			buffer[k] = num1[k] + num2[k] + x-48;//从末尾开始相加
			if (buffer[k] >= 58 && k != 0)
			{
				buffer[k] = buffer[k] - 10;
				x = 1;//晋位
			}
			else
				x = 0;//不晋位
		}
	}
	if (i < j)//如果位数不等
	{
		for (int l =0; l <=i; l++)
		{
			buffer[j-l] = num1[i-l] + num2[j-l] + x-48;//末位相加
			if (buffer[j-l] >= 58)
			{
				buffer[j-l] = buffer[j-l] - 10;
				x = 1;//晋位
			}
			else
				x = 0;//不晋位
		}
		for (int a = j-i-1; a >= 0; a--)
		{
			buffer[a] = num2[a] + x;
			if (buffer[a] >= 58)
			{
				buffer[a] = buffer[a] - 10;
				x = 1;
			}
			else x = 0;
		}
	}
			if (i > j)
			{
				for (int m = 0; m <=j; m++)
				{
					buffer[i-m] = num1[i-m] + num2[j-m] + x-48;
					if (buffer[i-m] >= 58)
					{
						buffer[i-m] = buffer[i-m] - 10;
						x = 1;
					}
					else
						x = 0;
				}
				for (int b = i-j-1; b >= 0; b--)
				{
					buffer[b] = num1[b] + x;
					if (buffer[b] >= 58)
					{
						buffer[b] = buffer[b] - 10;
						x = 1;
					}
					else x = 0;
				}
			}//同上
			int max=i;
			if (i < j)
				max = j;
			buffer[max + 1] = '\0';
			if (buffer[0] >= 58)
			{
				for (int c = max + 1; c >= 1; c--)
					buffer[c + 1] = buffer[c];
				buffer[1] = buffer[0] - 10;
				buffer[0] = 49;
			}
	return (buffer);
}