char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i, j,x=0;//�ó���һ�����ĳ���
	for (i = 0; i <= 1023; i++)
	{
		if (num1[i+1] == '\0')
			break;
	}
	for (j = 0; j <= 1023; j++)//�ó��ڶ������ĳ���
	{
		if (num2[j+1] == '\0')
			break;
	}
	if (i == j)
	{
		for (int k = i; k >= 0; k--)
		{
			buffer[k] = num1[k] + num2[k] + x-48;//ASCALL�����
			if (buffer[k] >= 58 && k != 0)//�ж��Ƿ��λ
			{
				buffer[k] = buffer[k] - 10;
				x = 1;//���һλ��һ
			}
			else
				x = 0;
		}
	}
	if (i < j)
	{
		for (int l =0; l <=i; l++)
		{
			buffer[j-l] = num1[i-l] + num2[j-l] + x-48;
			if (buffer[j-l] >= 58)
			{
				buffer[j-l] = buffer[j-l] - 10;
				x = 1;
			}
			else
				x = 0;
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
		}
		int max=i;
		if (i < j)
			max = j;
		buffer[max + 1] = '\0';//�����ַ�����β
		if (buffer[0] >= 58)//����һλ�Ƿ����9
		{
			for (int c = max + 1; c >= 1; c--)
				buffer[c + 1] = buffer[c];
			buffer[1] = buffer[0] - 10;
			buffer[0] = 49;
		}
        return (buffer);

}