char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int a[1024],b[1024];
	int Len(char*);
	int m = Len(num1), n = Len(num2);
	if (m > n) //�����������Ҳ����
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
	int c = 0,max=(m>=n?m:n); //�������
	for (; max > 0; max--)   //���㲢ѡ���Ƿ��λ
	{
		if (a[max - 1] + b[max - 1]+c >= 10)  //��Ҫ��λ
		{
			buffer[max] = (char)(a[max - 1] + b[max - 1] +c- 10+48);
			c = 1;
		}
		else   //����Ҫ��λ
		{
			buffer[max] = (char)(a[max - 1] + b[max - 1] + c+48);
			c = 0;
		}
	}
	if(c==0) // �����һλ�Ƿ�Ϊ��
	{
		for (int k = 0; k < (m > n ? m : n); k++)  //��һλΪ�գ���������ǰһ��
		{
			buffer[k] = buffer[k + 1];
		}
		buffer[(m > n ? m : n)] = '\0';
	}
	else  //��һλ��λ��Ϊ1
	{
		buffer[0] = (char)(1+48);
		buffer[(m > n ? m : n) + 1] = '\0';
	}
	return buffer;
}

int Len(char* s)  //���ַ�������
{
	int i = 0;
	while (s[i] != '\0')  //��������ַ�����ĩβĩβ
	{
		i++; //����ĩβƫ��һλ
	}
	return i;  //������ĩβ��-1
}