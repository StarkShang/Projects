char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i,x,y,j,k,q,w;//�������
	char z;
	q=0;//���ڽ�λ
	w=0;//���ڽ�λ
	x=0;//���ڼ����ַ�������
	i=0;//����ѭ�����
	y=0;//���ڼ����ַ�������
	j=0;//����ѭ�����
	while(num1[i]!='\0')
	{
		x++;
		i++;
	}//����num1����
	while(num2[j]!='\0')
	{
		y++;
		j++;
	}//����num2����
	if(x>y)
	{
		bufferLen=x;
	}
	else
	{
		bufferLen=y;
	}
	for(int a=0,i=x-1;a<i;a++,i--)
	{
		z=num1[a];
		num1[a]=num1[i];
		num1[i]=z;
	}//num1�ַ�����ת�����ڽ�λ
	for(int b=0,i=y-1;b<i;b++,i--)
	{
		z=num2[b];
		num2[b]=num2[i];
		num2[i]=z;
	}//num2�ַ�����ת
	char temp1[1025];
	char temp2[1025];
	int c=0;
	for(int q=x-1;q>=0;q--)
	{
		temp1[c++]=num1[q];
	}
	temp1[c]='\0';//�����ַ����ĸ�λ�á�\0������
	c=0;
	for(int q=y-1;q>=0;q--)
	{
		temp2[c++]=num2[q];
	}
	temp2[c]='\0';//�����ַ����ĸ�λ�á�\0������
	if(x<y)
	{
		for(i=x;i<y;i++)
		{
			temp1[i]='0';
		}
		temp1[y]='\0';
	}//���λ
	else if(x>y)
	{
		for(i=y;i<x;i++)
		{
			temp2[i]='0';
		}
		temp2[x]='\0';
	}//���λ
	for(i=0;i<bufferLen;i++)
	{
		k=temp1[i]-'0'+temp2[i]-'0'+q;//���ַ���ת��Ϊ���ֺ����
		if(k>9)//�����λ
		{
			if(i==(bufferLen-1))
			{
				w=0;
			}
			q=1;
			buffer[i]=k-10+'0';//��������λ
		}
		else//�������λ
		{
			q=0;
			buffer[i]=k+'0';
		}
	}
	buffer[bufferLen]='\0';//���\0��

	return buffer;//���غ���
}