int max(int,int);//���ֵ��������
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{   int a=0,b=0;
	for(int i=0;i<bufferLen;i++)
	{ 
		if(num1[i]!='\0')
			a+=1;
		else
		{break;}
	}//����num1�������λ��
	
for(int i=0;i<bufferLen;i++)
    {
		if(num2[i]!='\0')
			b+=1;
		else
		{break;}
     }//����num2�������λ��
if(a>b)
{	char c[1025];
   c[a]='0';
		for(int i=1;i<=b;i++)
        c[a-i]=num2[b-i];//��������
		for(int i=0;i<a-b;i++)
			c[i]='0';//���������λ����0���
		num2=c;
}
	if(a<b)
	{
      char c[1025];
   c[b]='0';
		for(int i=1;i<=a;i++)
       c[b-i]=num1[a-i];//������һ
		for(int i=0;i<b-a;i++)
			c[i]='0';//��һ�����λ����0���
		num1=c;
	}//��0��䣬ʹ��һ��������λ�����
int t=0,m=max(a,b);
buffer[m]='\0';
   for(int i=m-1;i>=1;i--)
	 {   
			 buffer[i]=num1[i]+num2[i]+t-'0';//ÿ���ַ����
			 t=0;
			 if(buffer[i]>'9')
			 {
				 t++;//�ʹ���9�ͽ�һλ
				 buffer[i]-=10;//��ȥ10�ñ�λ
			 }

	}
   buffer[0]=num1[0]+num2[0]+t-'0';//���λ���ʱ�ֿ�����
   if(buffer[0]>'9')
   {   buffer[0]-=10;//�����λ��Ӵ���9����ȥ10�ñ�λ����Ҫ��һλ
	   char b[1025];
	   b[m+1]='\0';
     for(int i=m-1;i>=0;i--)
	 {
       b[i+1]=buffer[i];
	 }//��������λ��
	 b[0]='1';//���͵����һλ��Ϊ1������һλ
	 buffer=b;
   }
   return buffer;
}
int max(int a,int b)
{
	return(a>b?a:b);//�����ֵ
}