char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{int len1,len2;//������Ҫ�õ��ı���
char*l_num,*s_num;
int l_num_len,s_num_len;
for(int i=0;num1[i]!='\0';i++)//forѭ�����ַ���num1�ĳ���
len1=i;   
for(int i=0;num2[i]!='\0';i++)//forѭ�����ַ���num2�ĳ���
len2=i;   
if(len1<len2)//�Ƚ��ַ������ȵĴ�С
{l_num=num2; 
l_num_len=len2;//���ϳ��ַ������Ƶ�l_num
s_num=num1;
s_num_len=len1;//���϶��ַ������Ƶ�s_num
}
else//ͬ��
{l_num=num1;
l_num_len=len1;//���ϳ��ַ������Ƶ�l_num
s_num=num2;
s_num_len=len2;//���϶��ַ������Ƶ�l_num
}
for(int i=l_num_len,j=s_num_len;j>0;j--,i--)//���ϳ��ַ�����϶��ַ����ұ߶������ģ�����
{if(((int)(l_num[i]-48)+(int)(s_num[j]-48))<=9) //��������Ӳ�����9ʱ
{l_num[i]=(char)(((int)l_num[i]-48)+(int)(s_num[j]-48)+48);//�����ַ����ұ߶������Ԫ����Ӹ�ֵ���ַ���l_num
}
else//��������Ӵ���9ʱ
{l_num[i]=(char)((((int)(l_num[i]-48))+((int)(s_num[j]-48)))%10+48);
l_num[i-1]=(char)((((int)(l_num[i-1])-48)+1)+48);//�����ַ�������Ԫ�����֮�ʹ���9����ǰһλ��1
}
}
if(((int)(l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48))<=9)
{l_num[l_num_len-s_num_len]=(char)(((int)l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48)+48);//��������߶���λ��ֵ��ֵС�ڵ���9��
buffer=l_num;//��l_num���Ƶ�buffer
}
else
{if(l_num_len!=s_num_len)//���ַ������Ȳ���ʱ
{l_num[l_num_len-s_num_len]=(char)(((int)l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48)+48);//��������߶���λ��ֵ��ֵ����9��
l_num[l_num_len-s_num_len-1]=(char)((((int)(l_num[l_num_len-s_num_len-1])-48)+1)+48);//������9����ǰһλ��1
buffer=l_num;//��l_num���Ƶ�buffer
}
else  //���ַ������ʱ
{l_num[0]=(char)((((int)(l_num[0]-48))+((int)(s_num[0]-48)))%10+48);//�жϵ�һλ��û�����
for(int i=0,j=1;i<=l_num_len;i++,j++)//����forѭ�����ַ�˳�κ��ƣ���һλ��һ
{buffer[0]='1';
buffer[l_num_len+2]='\0';//ĩβ����ֹ��
buffer[j]=l_num[i];
}
}
}
return buffer;//����ָ��buffer��ַ
} 