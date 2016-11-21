char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	
	
	char temp1[1025];  
    char temp2[1025];  //两个临时数组用来求和
	
    int len1 = 0;  
    int len2 = 0;  //两个int表示数组长度
    int i = 0;  
    int j = 0;  //用来循环的变量
    int maxLen = 0;  //最大长度
    int nbuffer = 0;  //计算中间变量
    int nCarryBit = 0;  //小的进位
    int nOverFlow = 0;//大的进位，影响结果长度的那个
	len1 = strlen(num1);  
    len2 = strlen(num2);  
  
    j = 0;  
    for(i = len1-1; i >= 0; --i)  
    {  
        temp1[j++] = num1[i];  
    }  
    temp1[j] = '\0';  
    j = 0;  
    for(i = len2-1; i >= 0; --i)  
    {  
        temp2[j++] = num2[i];  //先把数组反向
    }  
  
    
    maxLen = (len1 > len2)?len1:len2;  
    if(len1 < len2)  
    {  
        for(i = len1; i < len2; ++i)  
            temp1[i] = '0';  
        temp1[len2] = '\0';  
    }  
    else if(len1 > len2)  
    {  
        for(i = len2; i < len1; ++i)  
            temp2[i] = '0';  
        temp2[len1] = '\0';  //把两个字符串补齐，即短字符串的高位用‘0’补齐  
    }  
  
   
    for(i = 0; i < maxLen; i++)  
    {  
        nbuffer = temp1[i] - '0' + temp2[i] - '0' + nCarryBit;  
  
        if(nbuffer > 9)  
        {  
            if(i == (maxLen-1))  
            {  
                nOverFlow = 1;  
            }  
              
            nCarryBit = 1;  
              
            buffer[i] = nbuffer - 10 + '0';  
        }  
        else  
        {  
            nCarryBit = 0;  
           buffer[i] = nbuffer + '0';   //把两个正整数相加，一位一位的加并加上进位  
        }  
  
    }  
  
    
    if(nOverFlow == 1)  
    {  
        buffer[maxLen++] = nCarryBit + '0';  
    }  
    buffer[maxLen] = '\0';  //如果溢出的话表示位增加了  
  
   
	 for(i = maxLen-1; i >=0; i--)  
        temp1[maxLen-1-i]=buffer[i];
	 for(i = 0; i <maxLen; i++)  
	    buffer[i]=temp1[i]; //从后向前输出，即是相加后的值  
	
	return buffer;
}