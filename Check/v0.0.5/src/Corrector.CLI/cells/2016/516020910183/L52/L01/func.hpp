char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i, j,x=0;//定义变量，其中x为进位标志，若需进位，x为1，不需x为2
	for (i = 0; i <= 1023; i++)//循环到‘/0’找到num1的数字位数
	{//
		if (num1[i+1] == '\0')//
			break;//
	}//
	for (j = 0; j <= 1023; j++)//循环到‘/0’找到num2的数字位数
	{//
		if (num2[j+1] == '\0')//
			break;//
	}//
	if (i == j)//如果是两位同位数的相加
	{//
		for (int k = i; k >= 0; k--)//从最后一位开始循环
		{//
			buffer[k] = num1[k] + num2[k] + x-48;//两数的ASCII码相加并加上进位的x减48（0的ASCII吗）
			if (buffer[k] >= 58 && k != 0)//如果两数相加大于等于10
			{//
				buffer[k] = buffer[k] - 10;//这一位减10
				x = 1;//要进位，x等于1
			}//
			else//
				x = 0;//否则不需进位，x=0
		}//
	}//
	//当两个不同位数相加时，以位数多的作为模板
	if (i < j)//num1的位数较小时
	{//
		for (int l =0; l <=i; l++)//从后往前循环num1的位数的次数
		{//
			buffer[j-l] = num1[i-l] + num2[j-l] + x-48;//两数的ASCII码相加并加上进位的x减48（0的ASCII吗）
			if (buffer[j-l] >= 58)//如果两数相加大于等于10
			{//
				buffer[j-l] = buffer[j-l] - 10;//这一位减10
				x = 1;//要进位，x等于1
			}//
			else//
				x = 0;//否则不需进位，x=0
		}//
		for (int a = j-i-1; a >= 0; a--)//从num2多出来的位数到最高位
		{//
			buffer[a] = num2[a] + x;//这一位数等于num2的这一位数加上前一位的进位
			if (buffer[a] >= 58)//如果大于10
			{//
				buffer[a] = buffer[a] - 10;//这一位的数减1
				x = 1;//要进位，x等于1
			}//
			else x = 0;//否则不需进位，x=0
		}//
	}//
			if (i > j)//num2的位数较小时，*同上*
			{//
				for (int m = 0; m <=j; m++)//
				{//
					buffer[i-m] = num1[i-m] + num2[j-m] + x-48;//
					if (buffer[i-m] >= 58)//
					{//
						buffer[i-m] = buffer[i-m] - 10;//
						x = 1;//
					}//
					else//
						x = 0;//
				}//
				for (int b = i-j-1; b >= 0; b--)//
				{//
					buffer[b] = num1[b] + x;//
					if (buffer[b] >= 58)//
					{//
						buffer[b] = buffer[b] - 10;//
						x = 1;//
					}//
					else x = 0;//
				}//
			}//
			int max=i;//判断不考虑最高位相加后进位的总位数并赋值给max
			if (i < j)//
				max = j;//
			buffer[max + 1] = '\0';//给最低为后添加结束标识
			if (buffer[0] >= 58)//如果最高位相加后进位了
			{//
				for (int c = max + 1; c >= 1; c--)//整个数组整体向后移一位
					buffer[c + 1] = buffer[c];//
				buffer[1] = buffer[0] - 10;//第二位减10
				buffer[0] = 49;//第一位改为1
			}//
	return (buffer);//返回bufer
}
