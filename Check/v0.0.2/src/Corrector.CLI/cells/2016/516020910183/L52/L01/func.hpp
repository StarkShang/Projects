char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i, j,x=0;//�������������xΪ��λ��־�������λ��xΪ1������xΪ2
	for (i = 0; i <= 1023; i++)//ѭ������/0���ҵ�num1������λ��
	{//
		if (num1[i+1] == '\0')//
			break;//
	}//
	for (j = 0; j <= 1023; j++)//ѭ������/0���ҵ�num2������λ��
	{//
		if (num2[j+1] == '\0')//
			break;//
	}//
	if (i == j)//�������λͬλ�������
	{//
		for (int k = i; k >= 0; k--)//�����һλ��ʼѭ��
		{//
			buffer[k] = num1[k] + num2[k] + x-48;//������ASCII����Ӳ����Ͻ�λ��x��48��0��ASCII��
			if (buffer[k] >= 58 && k != 0)//���������Ӵ��ڵ���10
			{//
				buffer[k] = buffer[k] - 10;//��һλ��10
				x = 1;//Ҫ��λ��x����1
			}//
			else//
				x = 0;//�������λ��x=0
		}//
	}//
	//��������ͬλ�����ʱ����λ�������Ϊģ��
	if (i < j)//num1��λ����Сʱ
	{//
		for (int l =0; l <=i; l++)//�Ӻ���ǰѭ��num1��λ���Ĵ���
		{//
			buffer[j-l] = num1[i-l] + num2[j-l] + x-48;//������ASCII����Ӳ����Ͻ�λ��x��48��0��ASCII��
			if (buffer[j-l] >= 58)//���������Ӵ��ڵ���10
			{//
				buffer[j-l] = buffer[j-l] - 10;//��һλ��10
				x = 1;//Ҫ��λ��x����1
			}//
			else//
				x = 0;//�������λ��x=0
		}//
		for (int a = j-i-1; a >= 0; a--)//��num2�������λ�������λ
		{//
			buffer[a] = num2[a] + x;//��һλ������num2����һλ������ǰһλ�Ľ�λ
			if (buffer[a] >= 58)//�������10
			{//
				buffer[a] = buffer[a] - 10;//��һλ������1
				x = 1;//Ҫ��λ��x����1
			}//
			else x = 0;//�������λ��x=0
		}//
	}//
			if (i > j)//num2��λ����Сʱ��*ͬ��*
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
			int max=i;//�жϲ��������λ��Ӻ��λ����λ������ֵ��max
			if (i < j)//
				max = j;//
			buffer[max + 1] = '\0';//�����Ϊ����ӽ�����ʶ
			if (buffer[0] >= 58)//������λ��Ӻ��λ��
			{//
				for (int c = max + 1; c >= 1; c--)//�����������������һλ
					buffer[c + 1] = buffer[c];//
				buffer[1] = buffer[0] - 10;//�ڶ�λ��10
				buffer[0] = 49;//��һλ��Ϊ1
			}//
	return (buffer);//����bufer
}
