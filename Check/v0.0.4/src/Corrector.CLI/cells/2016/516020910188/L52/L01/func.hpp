char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int a,b;
	for(int i=0;;i++)
		{if(num1[i]=='\0') 
	{a=i;break;} }
	for(int k=0;;k++)
		{if(num2[k]=='\0') 
	{b=k;break;}}//�ж������ַ����ĳ���

	if(a>b)//�����һ������
	{   buffer[0]=48;//����ʼֵ
		for(int p=0;p<=b;p++)
		{buffer[a-p+1]=num1[a-p]+num2[b-p]-48;}//�����ַ����ص����ּӺ�
		for(int w=b+1;w<=a;w++)
		{buffer[a-w+1]=num1[a-w];}//��һ�������ಿ�ֵ�����ֵ
		for(int t=0;t<=(b+1);t++)
			if(buffer[a-t+1]>57)//�ж�ÿһλ������Ƿ����10
			{buffer[a-t+1]=buffer[a-t+1]-10;//����10���ȥ10
		buffer[a-t]=buffer[a-t]+1;//�ҽ���һλ��һ
		}
		//���õ��ĺͼ�����ֹ��
		if(buffer[0]==48)//����Ӻͺ��һλ��0
		{
			for(int k=0;k<a;k++)
				buffer[k]=buffer[k+1];//���ַ�������ǰ��
			buffer[a]='\0';//������ֹ��
		}
		else buffer[a+2]='\0';//������ֹ��
		return buffer;//�����ַ���

	}
	if(b>a)
	{
		 buffer[0]=48;
		for(int d=0;d<=a;d++)
		{buffer[b-d+1]=num1[a-d]+num2[b-d]-48;}
		for(int l=a+1;l<=b;l++)
		{buffer[b-l+1]=num2[b-l];}
		for(int n=0;n<=(a+1);n++)
			{if(buffer[b-n+1]>57)
			{buffer[b-n+1]=buffer[b-n+1]-10;
		buffer[b-n]=buffer[b-n]+1;}}
		if(buffer[0]==48)//����Ӻͺ��һλ��0
		{
			for(int c=0;c<b;c++)
				buffer[c]=buffer[c+1];//���ַ�������ǰ��
			buffer[b]='\0';//������ֹ��
		}
		else buffer[b+2]='\0';
		return buffer;
	}//ԭ��ͬ��

	if(a=b)//����λ�����
	
	{
			for(int p=0;p<=b;p++)
		{buffer[a-p]=num1[a-p]+num2[b-p]-48;}//ʵ��ģ��Ӻ�
		
		for(int t=0;t<b;t++)
			{if(buffer[a-t]>57)
			{buffer[a-t]=buffer[a-t]-10;//ʵ�ֽ�λ
		buffer[a-t-1]=buffer[a-t-1]+1;}}
		buffer[a+1]='\0';
		if(buffer[0]>57)//�жϵ�һλ�ǲ��Ǵ���10
		{for(int q=b+1;q>=1;q--)
		{buffer[q+1]=buffer[q];}
		buffer[1]=buffer[0]-10;
		buffer[0]=49;
		}//����10���ַ����������һλ���ַ�����һλ��Ϊ49
		
		return buffer;
	}
}