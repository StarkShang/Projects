char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len1, len2;//char�ַ�������
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
	char numdao1[1024];//num�ַ����ĵ���
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
		numdao2[len1] = '\0';//��0
	}
	int a = 0;//��λָʾ����
	int b[1024];//�������ɸ�����λ���ֵ��������飬�൱��buffer��ǰ��
	char bufferdao[1024];//buffer���鵹��
	for (int i = 0; i < maxlen; i++)
	{
		b[i] = numdao1[i] - '0' + numdao2[i] - '0' + a;
		if (b[i] > 9)//��λ
		{
			if (i == maxlen - 1)//���������һλ����λΪ1
			{
				bufferdao[maxlen] = 1+'0';
			}
			a = 1;
			bufferdao[i] = b[i] - 10 + '0';
		}
		else//����λ
		{
			a = 0;
			bufferdao[i] = b[i] + '0';
		}
	}
	if (bufferdao[maxlen] == 1 + '0')//��λ
	{
		maxlen += 1;
	}
	bufferdao[maxlen] = '\0';
	int k = 0;
		for (int i = maxlen - 1; i >= 0; i--)
			buffer[k++] = bufferdao[i];//�������
	buffer[k] = '\0';
	return buffer;
}