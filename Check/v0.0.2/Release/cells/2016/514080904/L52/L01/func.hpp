char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len_num1,len_num2;//len_num1和len_num2分别用来记录num1和num2的实际长度
	for(int i=0; i<bufferLen; i++)
	{
		if( num1[i] == '\0') len_num1=i;
		if( num2[i] == '\0') len_num2=i;
	}
	int len_num = len_num1 ;//用len_num来表示其总共不包含进位的位数
	if( len_num1 < len_num2) len_num = len_num2;

	char num_carry[1025];
	num_carry[len_num]  = '0' ; //用carry数组来记录进位
	buffer[len_num + 1] = '\0';
	int temp_num1, temp_num2, temp_carry, temp_sum;
	for (int i=0; ; i++)
	{
		if(len_num1 -1-i <0) temp_num1=0;               //通过askii码来实现字符与数字的转换
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
	if(buffer[0]=='0') return buffer+1; //如果不进位则指针移动一位
	else               return buffer;
}