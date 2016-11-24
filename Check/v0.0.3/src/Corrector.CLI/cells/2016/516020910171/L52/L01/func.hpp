#include <string.h>
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	for(int n=0;n<=1024;n++)
	{buffer[n]=0;}//清空数组
	int i=strlen(num1);//计算num1数组长度
	int k=strlen(num2);//计算num2数组长度
	bufferLen=(i>k)?i:k;//计算buffer数组长度
	int len = bufferLen-1;  
    int p = 0;  
    for(; i > 0 || k > 0; i--, k--)  
        {  
            if(i>0&&k>0)//相加
			{  
				buffer[len] = (((num1[i-1]-'0')+(num2[k-1]-'0')+p)%10)+'0';  
                p = ((num1[i-1]-'0')+(num2[k-1]-'0')+p)/10;  //进位
            }  
            else if(i<=0)  //i<k情况下当i<0
            {  
                buffer[len] = (((num2[k-1]-'0')+p)%10)+'0';  //相加
                p = ((num2[k-1]-'0')+p)/10;  
            }  
            else  //k<=i情况下当k<0
            {  
                buffer[len] = (((num1[i-1]-'0')+p)%10)+'0';  //相加
                p = ((num1[i-1]-'0')+p)/10;  
            }  
            len--;  
	}
	if(p>0)//最高位进位
	{
		for(int i=bufferLen;i>=0;i--)
		{buffer[i+1]=buffer[i];}//所有数向后移动一位
		buffer[0]='1';//首位为1
	}
	return buffer;
}
