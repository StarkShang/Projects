char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len_num1,len_num2;//len_num1��len_num2�ֱ�������¼num1��num2��ʵ�ʳ���
	for(int i=0; i<bufferLen; i++)
	{
		if( num1[i] == '\0') len_num1=i;
		if( num2[i] == '\0') len_num2=i;
	}
	int len_num = len_num1 ;//��len_num����ʾ���ܹ���������λ��λ��
	if( len_num1 < len_num2) len_num = len_num2;

	char num_carry[1025];
	num_carry[len_num]  = '0' ; //��carry��������¼��λ
	buffer[len_num + 1] = '\0';
	int temp_num1, temp_num2, temp_carry, temp_sum;
	for (int i=0; ; i++)
	{
		if(len_num1 -1-i <0) temp_num1=0;               //ͨ��askii����ʵ���ַ������ֵ�ת��
		else temp_num1 = num1[len_num1 -1-i] - 48;
		if(len_num2 -1-i <0) temp_num2=0;
		else temp_num2 = num2[len_num2 -1-i] - 48;

		if(len_num1 -1-i <0 && len_num2 -1-i <0) break;
		
		temp_carry = num_carry[len_num - i] - 48;
		temp_sum   = temp_num1 + temp_num2 + temp_carry;
		num_carry[len_num -1- i] = ((temp_sum / 10) + 48);
		buffer[len_num - i]      = ((temp_sum % 10) + 48);
	}
	buffer[0]=num_carry[0];
	if(buffer[0]=='0') return buffer+1; //�������λ��ָ���ƶ�һλ
	else               return buffer;
}