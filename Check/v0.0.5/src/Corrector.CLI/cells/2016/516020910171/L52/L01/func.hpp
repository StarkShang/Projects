#include <string.h>
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	for(int n=0;n<=1024;n++)
	{buffer[n]=0;}//�������
	int i=strlen(num1);//����num1���鳤��
	int k=strlen(num2);//����num2���鳤��
	bufferLen=(i>k)?i:k;//����buffer���鳤��
	int len = bufferLen-1;  
    int p = 0;  
    for(; i > 0 || k > 0; i--, k--)  
        {  
            if(i>0&&k>0)//���
			{  
				buffer[len] = (((num1[i-1]-'0')+(num2[k-1]-'0')+p)%10)+'0';  
                p = ((num1[i-1]-'0')+(num2[k-1]-'0')+p)/10;  //��λ
            }  
            else if(i<=0)  //i<k����µ�i<0
            {  
                buffer[len] = (((num2[k-1]-'0')+p)%10)+'0';  //���
                p = ((num2[k-1]-'0')+p)/10;  
            }  
            else  //k<=i����µ�k<0
            {  
                buffer[len] = (((num1[i-1]-'0')+p)%10)+'0';  //���
                p = ((num1[i-1]-'0')+p)/10;  
            }  
            len--;  
	}
	if(p>0)//���λ��λ
	{
		for(int i=bufferLen;i>=0;i--)
		{buffer[i+1]=buffer[i];}//����������ƶ�һλ
		buffer[0]='1';//��λΪ1
	}
	return buffer;
}
