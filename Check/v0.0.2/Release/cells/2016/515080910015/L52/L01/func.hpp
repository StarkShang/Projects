char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int num1_len,num2_len;
	char*l_num,*s_num;
	int l_num_len,s_num_len;
	for(int i=0;num1[i]!='\0';i++)
		num1_len=i;   //���ַ���num1�ĳ���
	for(int i=0;num2[i]!='\0';i++)
		num2_len=i;   //���ַ���num2�ĳ���
	if(num1_len<num2_len)//�ж��ַ������ȵĴ�С
	{
		l_num=num2; 
		l_num_len=num2_len;//���ϳ��ַ������Ƶ�l_num
		s_num=num1;
		s_num_len=num1_len;//���϶��ַ������Ƶ�l_num
	}
	else
	{
		l_num=num1;
		l_num_len=num1_len;//���ϳ��ַ������Ƶ�l_num
		s_num=num2;
		s_num_len=num2_len;//���϶��ַ������Ƶ�l_num
	}
	for(int i=l_num_len,j=s_num_len;j>0;j--,i--)//���ϳ��ַ�����϶��ַ����ұ߶������ģ�����
	{
		if(((int)(l_num[i]-48)+(int)(s_num[j]-48))<=9) 
		{
			l_num[i]=(char)(((int)l_num[i]-48)+(int)(s_num[j]-48)+48);//�����ַ����ұ߶������Ԫ����Ӹ�ֵ���ַ���l_num
		}
		else
		{
			l_num[i]=(char)((((int)(l_num[i]-48))+((int)(s_num[j]-48)))%10+48);
			l_num[i-1]=(char)((((int)(l_num[i-1])-48)+1)+48);//�����ַ�������Ԫ�����֮�ʹ���9����ǰһλ��1
		}
	}

	if(((int)(l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48))<=9)
	{
		l_num[l_num_len-s_num_len]=(char)(((int)l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48)+48);//��������߶���λ��ֵ��ֵС�ڵ���9��
		buffer=l_num;//��l_num���Ƶ�buffer
	}
	else
	{
		if(l_num_len!=s_num_len)
		{      //���ַ������Ȳ���ʱ
		l_num[l_num_len-s_num_len]=(char)(((int)l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48)+48);//��������߶���λ��ֵ��ֵ����9��
		l_num[l_num_len-s_num_len-1]=(char)((((int)(l_num[l_num_len-s_num_len-1])-48)+1)+48);//��ǰһλ��1
		buffer=l_num;//��l_num���Ƶ�buffer
		}
		else  //���ַ������ʱ
		{
			l_num[0]=(char)((((int)(l_num[0]-48))+((int)(s_num[0]-48)))%10+48);//�����һλ��ֵ
			for(int i=0,j=1;i<=l_num_len;i++,j++)//��forѭ���ڵ�һλǰ����һλ���������������һλ
			{
				buffer[0]='1';
				buffer[l_num_len+2]='\0';
				buffer[j]=l_num[i];
			}
		}
	}
	return buffer;//����ָ��buffer��ַ
}