char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	for(int n=0;n<=1024;n++)
    { buffer[n]=0;}//清空数组
	int lena=strlen(num1); 
    int lenb=strlen(num2);//计算字符串长度
	bufferLen=(lena>lenb)?lena:lenb;//取两者较长的长度
	int len = bufferLen-1;  //定义并赋值变量
    int p = 0;  //定义变量
    for(; lena > 0 || lenb > 0; lena--, lenb--)//开始循环字符串  
        {  
            if(lena>0&&lenb>0)//当两个字符串均有值
			{  
            buffer[len] = (((num1[lena-1]-'0')+(num2[lenb-1]-'0')+p)%10)+'0';// 对buffer依次赋值 
                p = ((num1[lena-1]-'0')+(num2[lenb-1]-'0')+p)/10;  //判断进位
            }  
            else if(lena<=0)  //当num1的长度小于num2
            {  
                buffer[len] = (((num2[lenb-1]-'0')+p)%10)+'0';// 对num1位数前的buffer进行赋值 
                p = ((num2[lenb-1]-'0')+p)/10;  //判断进位
            }  
            else  //当num2的长度小于num1
            {  
                buffer[len] = (((num1[lena-1]-'0')+p)%10)+'0';  //对num2位数之前的buffer进行赋值
                p = ((num1[lena-1]-'0')+p)/10;  //判断进位
            }  
            len--;  
	}
	if(p>0)//如果全部要向前进1
	{
		for(int i=bufferLen;i>=0;i--)
		{  
			buffer[i+1]=buffer[i];//将字符串向后移动一位
		}
		buffer[0]='1';//插入字符
	}
	return(buffer);//返回字符串
}




