int Len(char*num)
{
	int i = 0;
	while (num[i] != 0)
		i++;
	return i;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int n1 = Len(num1), n2 = Len(num2);
	int sum = 0, i, add = 0;
	int p[1024];
	if (n1 = n2)                                                       //λ����ͬ���
	{
		for (i = 0; i < n1; i++)                                         //��λ������
		{
			sum = (num1[n1 - 1 - i] - 48) + (num2[n2 - 1 - i] - 48) + add;
			if (sum >= 0)                                                //��������ʹ��ڵ���10
			{
				sum = sum - 10;
				add = 1;
			}
			else add = 0;
			p[i] = sum + 48;                                          //��ͽ����������p
		}
		if (add == 0)                                                //�����󲻽�λ
		{
			for (i = 0; i < n1; i++)
				buffer[i] = p[n1 - i];
			buffer[n1] = '\0';
		}
		else                                                      //�����Ҫ��λ
		{
			p[n1] = '1';
			for (i = 0; i < n1 + 1; i++)
			{
				buffer[i] = p[n1 - i];
			}
			buffer[n1 + 1] = '\0';
		}
	}
	if (n1 < n2)                       // λ������ͬ�����
	{
		for (i = 0; i < n1; i++)
		{
			sum = (num1[n1 - 1 - i] - 48) + (num2[n2 - 1 - i] - 48) + add;  //��λ������
			if (sum >= 10)                                                   //��Ҫ��λ�����
			{
				sum -= 10;
				add = 1;
			}
			else
				add = 0;
			p[i] = sum + 48;                    
		}
		for (i=n2; i < n2; i++)                              //֮���λ��ֱ�Ӹ���
		{
			sum = (num2[n2 - 1 - i] - 48) + add;
			if (sum >= 10)
			{
				sum = 0;
				add = 1;
			}
			else
				add = 0;
			p[i] = sum + 48;
		}
		for (int j = 0; j < n2; j++)             //����
			buffer[j] = p[n2 - 1 - j];
		buffer[n2] = '\0';
		if (add == 1)
		{
			p[i++] = '1';
			for (int j = 0; j < n2 + 1; j++)
				buffer[j] = p[n2 - j];
			buffer[n2 + 1] = '\0';
		}
	}
	if (n1 > n2)                       //λ������ͬ��������������ͬ
	{
		for (i = 0; i < n2; i++)
		{
			sum = (num2[n2 - 1 - i] - 48) + (num1[n1 - 1 - i] - 48) + add;
			if (sum >= 10)
			{
				sum -= 10;
				add = 1;
			}
			else
				add = 0;
			p[i] = sum + 48;
		}
		for (; i < n1; i++)
		{
			sum = (num1[n1 - 1 - i] - 48) + add;
			if (sum >= 10)
			{
				sum = 0;
				add = 1;
			}
			else
				add = 0;
			p[i] = sum + 48;
		}
		for (int j = 0; j < n1; j++)
			buffer[j] = p[n1 - 1 - j];
		buffer[n1] = '\0';
		if (add == 1)
		{
			p[i++] = '1';
			for (int j = 0; j < n1 + 1; j++)
				buffer[j] = p[n1 - j];
			buffer[n1 + 1] = '\0';
		}
	}
	return buffer;                           //����buffer��ֵ
}