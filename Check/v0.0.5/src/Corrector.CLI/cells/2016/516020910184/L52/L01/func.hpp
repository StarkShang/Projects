int len(char* num)    //�ж����鳤��
{
	int n=0;
	while(num[n]!=NULL)
		n++;
	return n;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len(char* num);//����������
	int i=0,j=0,a=0,b=0,l=0,m,n;//�������
	i=len(num1);
	j=len(num2);//�����������ĳ���
	*(buffer)='0';//��buffer�������Ԫ�ر�Ϊ0
	if(i>=j)//���num1������λ����
	{
		*(buffer+i+1)='\0';//��buffer����ĵ�i+1Ԫ�ر�Ϊ0
		for(;j>=1;i--&&j--)//ѭ���������������غϲ��ָ���Ԫ�غ�
		{
			
			m=(int)(*(num1+i-1));
			n=(int)(*(num2+j-1));
			b=m+n+a-48;
			if(b>=58)//���Ҫ��λ
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+i)=(char)(b);
		}
	
		for(l=(i-j);l>0;l--)//ѭ����������������غϲ��ָ���Ԫ�غ�
		{
			m=(int)(*(num1+l-1));
			b=m+a;
			if(b>=58)
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+l)=(char)(b);
		}
		*buffer=a+48;//������λ�Ƿ��λ
	}
	
	else 
		if(i<j)//���num2������λ����
	{
		*(buffer+j+1)='\0';//��buffer����ĵ�i+1Ԫ�ر�Ϊ0
		for(;i>=1;i--&&j--)//ѭ���������������غϲ��ָ���Ԫ�غ�
		{
			
			m=(int)(*(num1+i-1));
			n=(int)(*(num2+j-1));
			b=m+n+a-48;
			if(b>=58)
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+j)=(char)(b);
		}
	
		for(l=j;l>0;l--)//ѭ����������������غϲ��ָ���Ԫ�غ�
		{
			m=(int)(*(num2+l-1));
			b=m+a;
			if(b>=58)
			{
				b=b-10;
				a=1;
			}
			else 
				a=0;
			*(buffer+l)=(char)(b);
		}
		*buffer=a+48;//������λ�Ƿ��λ
	}
	return (*buffer =='0') ? buffer+1:buffer;//��λΪ0��������

}