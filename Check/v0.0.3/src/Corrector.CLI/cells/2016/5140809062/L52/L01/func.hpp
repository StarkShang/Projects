char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i=0;
	while (num1[i]!='\0')//�����������ִ��ĳ��ȣ���ֵ��LEN1,LEN2
	{i++;}
	int len1=i;
	i=0;
	while (num2[i]!='\0')
	{i++;}
	int len2=i;
	
	char b[1025];
	for (int i=0;i<=len1;i++)//Ϊ�˼��㷽�㣬���������ֵ���
		b[i]=num1[i];
	for (int i=0;i<=len1;i++)
		num1[i]=b[len1-1-i];

	for (int i=0;i<=len2;i++)
		b[i]=num2[i];
	for (int i=0;i<=len2;i++)
		num2[i]=b[len2-1-i];
	int k=0;//K�ǽ�λ������




	if (len1>len2)//����һ��������ʱ
	{
		for (int i=0;i<len2;i++)//�ڵ�һλ����LEN2λʱ
		{
			if(num1[i]+num2[i]-96+k<10)//�������λ����ֱ�����
				{
				buffer[i]=num1[i]+num2[i]-48+k;
				k=0;
				}
			else
				{
				buffer[i]=num1[i]+num2[i]-48-10+k;//����Ҫ��λ�����ȥ10�����ҽ�λ������K=1
				k=1;
				}
		}
		
		buffer[len2]=num1[len2]+k;//�ٽ�LEN2��LEN1�Ĳ��ָ�ֵ��BUFFER
		for (i=len2;i<len1;i++)
			{buffer[i]=num1[i]+k;
				k=0;}

		

	for (int i=0;i<len1;i++)//�ѵõ���BUFFER�ڵ�������˳��
		b[i]=buffer[i];
	for (int i=0;i<len1;i++)
		buffer[i]=b[len1-1-i];

	buffer[len1]='\0';//���һλ��\0��β

	}





		else
		if (len2>len1)//���ڶ��������������������ͬ��
	{
		for (int i=0;i<len1;i++)
		{
			if(num1[i]+num2[i]-96+k<10)
				{
				buffer[i]=num1[i]+num2[i]-48+k;
				k=0;
				}
			else
				{
				buffer[i]=num1[i]+num2[i]-48-10+k;
				k=1;
				}
		}

		buffer[len1]=num1[len2]+k;
		for (i=len1;i<len2;i++)
			{buffer[i]=num1[i]+k;
				k=0;}

		

	for (int i=0;i<len2;i++)
		b[i]=buffer[i];
	for (int i=0;i<len1;i++)
		buffer[i]=b[len2-1-i];

	buffer[len2]='\0';

	}

		else
	if (len1=len2)//��������ͬʱ������ͬ��
	{
		for (int i=0;i<len2;i++)
		{
			if(num1[i]+num2[i]-96+k<10)
				{
				buffer[i]=num1[i]+num2[i]-48+k;
				k=0;
				}
			else
				{
				buffer[i]=num1[i]+num2[i]-48-10+k;
				k=1;
				}
		}
		buffer[len2]=num1[len2]+k;

		

	for (int i=0;i<len1;i++)
		b[i]=buffer[i];
	for (int i=0;i<len1;i++)
		buffer[i]=b[len1-1-i];

	buffer[len1]='\0';

	}



	return buffer;//���ؽ��
}
