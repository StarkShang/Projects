
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int n1 = strlen(num1);
	int n2 = strlen(num2);
	int flag = 0;
	int i;
	int sum = 0;
	int k = 0;
	int add[1024];
	if (n1 == n2)                    //�����ַ���һ������ʱ��
	{
		for (i = 0; i < n1; i++)
		{
			sum = (num1[n1 - 1 - i] - 48) + (num2[n2 - 1 - i] - 48) + flag;
			if (sum >= 10)
			{
				sum -= 10;
				flag = 1;                                                  //���㱾λ�����ж��Ƿ��λ
			}
			else
				flag = 0;
			add[i] = sum + 48;
		}
		for (int j = 0; j<n1; j++)
			buffer[j] = add[n1 - 1 - j];
		buffer[n1] = '\0';                                               //��add����ߵ������
		if (flag == 1)
		{
			add[n1] = '1';                                               //������flag=1�������һλ��
			for (int j = 0; j < n1 + 1; j++)
			{
				buffer[j] = add[n1 - j];
			}
			buffer[n1 + 1] = '\0';
		}
	}
	if (n1 != n2)
	{
		if (n1 < n2)
		{
			for (i = 0; i < n1; i++)
			{
				sum = (num1[n1 - 1 - i] - 48) + (num2[n2 - 1 - i] - 48) + flag;
				if (sum >= 10)
				{
					sum -= 10;
					flag = 1;
				}
				else
					flag = 0;
				add[i] = sum +48;
			}
			for (; i < n2; i++)
			{
				sum = num2[n2 - 1 - i] - 48 + flag;
				if (sum >= 10)
				{
					sum = 0;
					flag = 1;
				}
				else
					flag = 0;
				add[i] = sum + 48;
			}
			for (int j = 0; j<n2 ; j++)
				buffer[j] = add[n2-1 - j];
			buffer[n2] = '\0';
			if (flag == 1)
			{
				add[i++] ='1';
				for (int j = 0; j<n2 + 1; j++)
					buffer[j] = add[n2 - j];
				buffer[n2 + 1] = '\0';
			}
		}
		if (n1 > n2)
		{
			for (i = 0; i < n2; i++)
			{
				sum = (num2[n2 - 1 - i] - 48) + (num1[n1 - 1 - i] - 48) + flag;
				if (sum >= 10)
				{
					sum -= 10;
					flag = 1;
				}
				else
					flag = 0;
				add[i] = sum + 48;
			}
			for (; i < n1; i++)
			{
				sum = (num1[n1 - 1 - i] - 48 )+ flag;
				if (sum >= 10)
				{
					sum = 0;
					flag = 1;
				}
				else
					flag = 0;
				add[i] = sum + 48;
			}
			for (int j = 0; j<n1 ; j++)
				buffer[j] = add[n1 -1- j];
			buffer[n1] = '\0';
			if (flag == 1)
			{
				add[i++] = '1';
				for (int j = 0; j<n1 + 1; j++)
					buffer[j] = add[n1 - j];
				buffer[n1 + 1] = '\0';
			}
		}
	}
	return buffer;
}