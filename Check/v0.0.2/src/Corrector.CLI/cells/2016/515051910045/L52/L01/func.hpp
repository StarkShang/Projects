char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{   
	int a[1025],b[1025],temp[1026]={0,},sum[1025],m,n,len;  //������������a[1025],b[1025]������num1��num2���֣�
	                                                        //a��b�ֱ��ʾnum1��num2��Ԫ�ظ�����len��ʾ�͵ĳ���
	for(int i=0;i<1025;i++)      //��a[1025],b[1025]Ԫ��ȫ������0�ĳ�ʼֵ
	{   
		a[i]=0;
		b[i]=0;
	}
	for(int i=0;num1[i]!='\0';i++)   //����num1�ĳ���
	{   
		m=i+1;
	} 
	for(int i=0;num1[i]!='\0';i++)    //��num1�е�Ԫ�ص��ŷ���a[1025]��
	{   
		a[m-1-i]=num1[i]-'0';
	}
	for(int i=0;num2[i]!='\0';i++)     //����num2�ĳ���
	{
		n=i+1;
	}
	for(int i=0;num2[i]!='\0';i++)    //��num2�е�Ԫ�ص��ŷ���b[1025]��
	{
		b[n-1-i]=num2[i]-'0';
	}
	if(m>n)   len=m;         //����sum�ĳ���
	else    len=n;

	for(int i=0;i<1025;i++)     //�ֱ��a[1025],b[1025]��Ӧλ��������ͣ��ж��Ƿ�Ҫ��ǰ��һλ
	{
		sum[i]=a[i]+b[i]+temp[i];
		temp[i+1]=sum[i]/10;
		sum[i]=sum[i]%10;
	}
	if(temp[1025]==1)           //�ж����ĺ��Ƿ���1025λ������У����ü���ֹ�����
	{
		for(int i=0;i<1025;i++)
		{
			buffer[i]=sum[1025-i]+'0';
		}	
	}
	else if(temp[len]==1)       //�ж������λ���Ƿ��len��һλ������У�����ֹ���������һλ
	{
		for(int i=0;i<len+1;i++)
		{   
			buffer[i]=sum[len-i]+'0';
	    }
	    buffer[len+1]='\0';
	}
	else                       
	{
		for(int i=0;i<len;i++)
		{
			buffer[i]=sum[len-1-i]+'0';
		}
		buffer[len]='\0';
	}
	return(buffer);   //����buffer���׵�ַ
}