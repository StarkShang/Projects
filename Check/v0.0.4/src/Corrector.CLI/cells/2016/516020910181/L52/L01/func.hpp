char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int a, b,len;                               //�������α���
	int c, d, e;                              
	a = strlen(num1);                           //��num1�ĳ��ȸ���a
	b = strlen(num1);                           //��num2�ĳ��ȸ���b
	len = a;
	if (b > a)
		len = b;                                //��a��b�нϴ�ĸ���len
	for (int i = 1; i <= len; i++) {            
		num1[len - i] = num1[a - i];
		num2[len - i] = num2[b - i];
	}                                           //ʹa,b�����
	if (len == a) {                                
		for (int i = 0; i <= a - b - 1; i++)
			num2[i] = '0';
	}
	else {
		for (int i = 0; i <= b - a - 1; i++)
			num1[i] = '0';                      //��λ��0����
	}
	for (int i = 0; i <= len; i++)
		buffer[i] = '0';                        //��λ��0����
	for (int i = len ; i >= 1; i--) {           
		c = int(num1[i-1]) - 48;
		d = int(num2[i-1]) - 48;
		e = c + d;                              //��
		if (e > 9) {
			e -= 10;
			buffer[i] = e + 30 + int(buffer[i]) - 30;
			buffer[i - 1] = '1';                //��Ҫ��λ �ͽ�λ
		}
		else
			buffer[i] = e + 30+int(buffer[i])-30; 
	}
	buffer[len + 1] = '\0';                    //Ϊ�˲�������ô����
	if (buffer[0] == '0') {                    //�����λΪ0
		for (int i = 0; i <= len + 1; i++)     //����֮
			buffer[i] = buffer[i + 1];
	}
	
	return buffer;                                
}