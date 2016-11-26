char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	
	
	char temp1[1025];  
    char temp2[1025];  //������ʱ�����������
	
    int len1 = 0;  
    int len2 = 0;  //����int��ʾ���鳤��
    int i = 0;  
    int j = 0;  //����ѭ���ı���
    int maxLen = 0;  //��󳤶�
    int nbuffer = 0;  //�����м����
    int nCarryBit = 0;  //С�Ľ�λ
    int nOverFlow = 0;//��Ľ�λ��Ӱ�������ȵ��Ǹ�
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
        temp2[j++] = num2[i];  //�Ȱ����鷴��
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
        temp2[len1] = '\0';  //�������ַ������룬�����ַ����ĸ�λ�á�0������  
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
           buffer[i] = nbuffer + '0';   //��������������ӣ�һλһλ�ļӲ����Ͻ�λ  
        }  
  
    }  
  
    
    if(nOverFlow == 1)  
    {  
        buffer[maxLen++] = nCarryBit + '0';  
    }  
    buffer[maxLen] = '\0';  //�������Ļ���ʾλ������  
  
   
	 for(i = maxLen-1; i >=0; i--)  
        temp1[maxLen-1-i]=buffer[i];
	 for(i = 0; i <maxLen; i++)  
	    buffer[i]=temp1[i]; //�Ӻ���ǰ�����������Ӻ��ֵ  
	
	return buffer;
}